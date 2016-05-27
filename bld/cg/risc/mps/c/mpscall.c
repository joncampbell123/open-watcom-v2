/****************************************************************************
*
*                            Open Watcom Project
*
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  MIPS subroutine call generation.
*
****************************************************************************/


#include "cgstd.h"
#include "coderep.h"
#include "cgdefs.h"
#include "cgaux.h"
#include "zoiks.h"
#include "data.h"
#include "bldins.h"
#include "makeins.h"
#include "types.h"
#include "makeaddr.h"
#include "namelist.h"

extern  bool            AssgnParms( cn, bool );
extern  type_class_def  AddCallBlock( cg_sym_handle, type_def * );
extern  hw_reg_set      StackReg( void );
extern  name            *AllocRegName( hw_reg_set );
extern  name            *SAllocIndex( name *, name *, type_length, type_class_def, type_length );
extern  name            *AllocIndex( name *, name *, type_length, type_class_def );
extern  void            AddCallIns( instruction *, cn );
extern  void            AddIns( instruction * );
extern  type_def        *QParmType( cg_sym_handle, cg_sym_handle, type_def * );
extern  name            *AllocRegName( hw_reg_set );
extern  type_length     PushSize( type_length );
extern  type_class_def  TypeClass( type_def * );
extern  hw_reg_set      ParmReg( type_class_def, type_length, type_length, call_state *);
extern  instruction     *SuffixIns( instruction *, instruction * );
extern  type_def        *ClassType( type_class_def );
extern  type_class_def  ReturnClass( type_def *, call_attributes );


extern an BGCall( cn call, bool use_return, bool in_line )
/********************************************************/
{
    instruction         *call_ins;
    instruction         *conv_ins;
    call_state          *state;
    name                *result;
    hw_reg_set          ret_addr;
    instruction         *ins;


    call_ins = call->ins;
    state = call->state;

    if( state->attr & ROUTINE_MODIFIES_NO_MEMORY ) {
        call_ins->flags.call_flags |= CALL_WRITES_NO_MEMORY;
    }
    if( state->attr & ROUTINE_READS_NO_MEMORY ) {
        call_ins->flags.call_flags |= CALL_READS_NO_MEMORY;
    }
    if( state->attr & ROUTINE_IS_SETJMP ) {
        call_ins->flags.call_flags |= CALL_IS_SETJMP;
    }
    if( use_return == false ) {
        call_ins->flags.call_flags |= CALL_IGNORES_RETURN;
    }

    result = BGNewTemp( call->tipe );
    if( call_ins->type_class == XX ) {
        call_ins->result = result;
        ret_addr = ParmReg( CP, 4, 8, state );
        ins = MakeUnary( OP_LA, result, AllocRegName( ret_addr ), CP );
        AddIns( ins );
    } else {
        call_ins->result = AllocRegName( state->return_reg );
    }
    AssgnParms( call, in_line );
    AddCallIns( call_ins, call );
    if( use_return ) {
        if( call_ins->type_class != XX ) {
            conv_ins = MakeConvert( call_ins->result, result, TypeClass( call->tipe ), ReturnClass( call->tipe, call->state->attr ) );
            AddIns( conv_ins );
        } else {
            // conv_ins = MakeMove( call_result, result, XX );
        }
    }
    return( MakeTempAddr( result ) );
}


extern void BGProcDecl( cg_sym_handle sym, type_def *tipe )
/******************************************************/
{
    type_class_def      class;
    name                *temp;
    hw_reg_set          reg;

    class = AddCallBlock( sym, tipe );
    SaveTargetModel = TargetModel;
    if( tipe != TypeNone ) {
        if( class == XX ) {
            // Handle structure returns - we need to "eat up" the first
            // register used for argument passing here, so that it isn't
            // used for passing actual arguments. NB: Must also bump
            // parm.offset here so that arguments end up in the right
            // locations.
            reg = HW_D4;
            temp = AllocTemp( WD );
            temp->v.usage |= USE_IN_ANOTHER_BLOCK;
            AddIns( MakeMove( AllocRegName( reg ), temp, WD ) );
            HW_TurnOn( CurrProc->state.parm.used, reg );
// TODO: need to do anything here?
//            HW_CTurnOn( CurrProc->state.parm.used, HW_F16 );
            CurrProc->targ.return_points = temp;
            CurrProc->state.parm.offset += REG_SIZE;
        }
    }
}


extern type_def *PassParmType( cg_sym_handle func, type_def* tipe, call_class class )
/********************************************************************************/
{
    class = class;
    tipe = QParmType( func, NULL, tipe );
    return( tipe );
}


extern instruction *PushOneParm( instruction *ins, name *curr,
                                 type_class_def class,
                                 type_length offset,
                                 call_state *state )
/************************************************************/
{
    instruction *new;
    name        *dst;
    name        *stack_reg;

    state = state;
    stack_reg = AllocRegName( StackReg() );
    dst = AllocIndex( stack_reg, NULL, offset, class );
    new = MakeMove( curr, dst, class );
    SuffixIns( ins, new );
    return( new );
}


extern name *StReturn( an retval, type_def *tipe, instruction **pins )
/********************************************************************/
{
    name        *index;

    retval = retval;
    pins = pins;
    index = AllocIndex( CurrProc->targ.return_points, NULL, 0, TypeClass( tipe ) );
    return( index );
}


extern void InitTargProc( void )
/******************************/
{
    CurrProc->targ.debug = NULL;
    // For d1+ or higher, force accesses to locals to go through $fp since frame
    // pointer is what the DWARF debug info is currently referencing.
    if( _IsModel( DBG_LOCALS ) )
        CurrProc->targ.base_is_fp = true;
    else
        CurrProc->targ.base_is_fp = false;
}


extern void SaveToTargProc( void )
/********************************/
{
    CurrProc->targ.max_stack = MaxStack;
}


extern void RestoreFromTargProc( void )
/*************************************/
{
    MaxStack = CurrProc->targ.max_stack;
}

extern reg_set_index CallIPossible( instruction *ins )
/****************************************************/
{
     ins = ins;
     return( RL_DWORD );
}
