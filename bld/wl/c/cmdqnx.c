/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2002-2020 The Open Watcom Contributors. All Rights Reserved.
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
* Description:  WHEN YOU FIGURE OUT WHAT THIS FILE DOES, PLEASE
*               DESCRIBE IT HERE!
*
****************************************************************************/


/*
 *  CMDQNX : command line parsing for the QNX load file format.
*/

#include <string.h>
#include "linkstd.h"
#include "alloc.h"
#include "command.h"
#include "cmdline.h"
#include "msg.h"
#include "objfree.h"
#include "exeqnx.h"
#include "loadqnx.h"
#include "wlnkmsg.h"
#include "cmdqnx.h"
#include "cmdall.h"     // for ChkBase


bool ProcQNX( void )
/*************************/
{
    if( !ProcOne( QNXFormats, SEP_NO, false ) ) {
        HintFormat( MK_QNX_16 );        // set to 16-bit qnx mode
    }
    return( true );
}

bool ProcQNXFlat( void )
/*****************************/
{
    return( true );
}

void SetQNXFmt( void )
/***************************/
{
    Extension = E_QNX;
    FmtData.u.qnx.flags = 0;
    FmtData.u.qnx.priv_level = 0;
    FmtData.u.qnx.seg_flags = NULL;
    FmtData.u.qnx.heapsize = 4096;
    FmtData.u.qnx.gen_seg_relocs = true;
    FmtData.u.qnx.gen_linear_relocs = false;
    ChkBase( _4KB );
}

void FreeQNXFmt( void )
/****************************/
{
    FreeSegFlags( (xxx_seg_flags *)FmtData.u.qnx.seg_flags );
}

void CmdQNXFini( void )
/****************************/
{
    if( !FmtData.u.qnx.gen_linear_relocs && !FmtData.u.qnx.gen_seg_relocs ) {
        LinkState &= ~LS_MAKE_RELOCS;
    }
}

static bool getSegFlags( void )
/*****************************/
{
    bool            isclass;
    qnx_seg_flags   *entry;

    Token.thumb = true;
    isclass = ProcOne( QNXSegDesc, SEP_NO, false );
    if( !GetToken( SEP_NO, TOK_INCLUDE_DOT ) ){
        return( false );
    }
    _ChkAlloc( entry, sizeof( qnx_seg_flags ) );
    entry->flags = 0;
    entry->name = tostring();
    entry->type = ( isclass ) ? SEGFLAG_CLASS : SEGFLAG_SEGMENT;
    entry->next = FmtData.u.qnx.seg_flags;
    FmtData.u.qnx.seg_flags = entry;
    return( ProcOne( QNXSegModel, SEP_NO, false ) );
}

bool ProcQNXSegment( void )
/********************************/
{
    return( ProcArgList( getSegFlags, TOK_INCLUDE_DOT ) );
}

bool ProcQNXClass( void )
/******************************/
// All processing done for this already.
{
    return( true );
}

bool ProcQNXExecuteonly( void )
/************************************/
{
    FmtData.u.qnx.seg_flags->flags = QNX_EXEC_ONLY;
    return( true );
}

bool ProcQNXExecuteread( void )
/************************************/
{
    FmtData.u.qnx.seg_flags->flags = QNX_EXEC_READ;
    return( true );
}

bool ProcQNXReadOnly( void )
/*********************************/
{
    FmtData.u.qnx.seg_flags->flags = QNX_READ_ONLY;
    return( true );
}

bool ProcQNXReadWrite( void )
/**********************************/
{
    FmtData.u.qnx.seg_flags->flags = QNX_READ_WRITE;
    return( true );
}

bool ProcLongLived( void )
/********************************/
{
    FmtData.u.qnx.flags |= _TCF_LONG_LIVED;
    return( true );
}

bool ProcQNXNoRelocs( void )
/*********************************/
{
    FmtData.u.qnx.gen_seg_relocs = false;
    return( true );
}

bool ProcLinearRelocs( void )
/*********************************/
{
    FmtData.u.qnx.gen_linear_relocs = true;
    return( true );
}

bool ProcQNXHeapSize( void )
/*********************************/
{
    ord_state           ret;
    unsigned_32         value;

    if( !HaveEquals( TOK_NORMAL ) ) return( false );
    ret = getatol( &value );
    if( ret != ST_IS_ORDINAL || value == 0 ) {
        LnkMsg( LOC+LINE+WRN+MSG_VALUE_INCORRECT, "s", "heapsize" );
    } else {
        FmtData.u.qnx.heapsize = value;
    }
    return( true );
}

bool ProcQNXPrivilege( void )
/**********************************/
{
    ord_state           ret;
    unsigned_16         value;

    if( !HaveEquals( TOK_NORMAL ) ) return( false );
    ret = getatoi( &value );
    if( ret != ST_IS_ORDINAL || value > 3 ) {
        LnkMsg( LOC+LINE+WRN+MSG_VALUE_INCORRECT, "s", "privilege" );
    } else {
        FmtData.u.qnx.priv_level = value;
    }
    return( true );
}
