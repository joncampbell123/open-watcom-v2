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
* Description:  WHEN YOU FIGURE OUT WHAT THIS FILE DOES, PLEASE
*               DESCRIBE IT HERE!
*
****************************************************************************/


//
// FCDBG     : generate debugging information
//

#include "ftnstd.h"
#include "global.h"
#include "rtconst.h"
#include "wf77cg.h"
#include "wf77defs.h"
#include "wf77auxd.h"
#include "fcjmptab.h"
#include "fcrtns.h"
#include "emitobj.h"
#include "cgswitch.h"
#include "cgprotos.h"


void    FCDbgLine( void ) {
//====================

// Generate line # information.

    unsigned_16 line_num;

    line_num = GetU16();
    if( ( SubProgId->u.ns.flags & SY_SUBPROG_TYPE ) == SY_BLOCK_DATA )
        return;
    DBLineNum( line_num );
}


void    FCSetLine( void ) {
//===================

// Generate run-time call to ISN routine.

    call_handle call;
    unsigned_16 line_num;

    line_num = GetU16();
    if( ( SubProgId->u.ns.flags & SY_SUBPROG_TYPE ) == SY_BLOCK_DATA )
        return;
    call = InitCall( RT_SET_LINE );
    CGAddParm( call, CGInteger( line_num, TY_INTEGER ), TY_INTEGER );
    CGDone( CGCall( call ) );
}
