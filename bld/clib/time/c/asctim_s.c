/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2002-2018 The Open Watcom Contributors. All Rights Reserved.
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
* Description:  Implementation of asctime_s() - bounds-checking asctime().
*               Wrapper for _asctime().
*
****************************************************************************/


#include "variety.h"
#include "widechar.h"
#include "saferlib.h"
#include <time.h>
#include "libwchar.h"


_WCRTLINK errno_t __F_NAME(asctime_s,_wasctime_s)( CHAR_TYPE *s,
                            rsize_t maxsize, const struct tm *timeptr )
/*********************************************************************/
{
    errno_t     rc = -1;
    char        *msg = NULL;

    // Verify runtime-constraints
    // s       not NULL
    // timeptr not NULL
    // 26 <= maxsize      <= RSIZE_MAX
    // 0  <= timeptr.year <= 9999
    if( __check_constraint_nullptr_msg( msg, s ) &&
        __check_constraint_nullptr_msg( msg, timeptr ) &&
        __check_constraint_maxsize_msg( msg, maxsize ) &&
        __check_constraint_a_gt_b_msg( msg, 26, maxsize ) &&
        __check_constraint_a_gt_b_msg( msg, 0, timeptr->tm_year ) &&
        __check_constraint_a_gt_b_msg( msg, timeptr->tm_year, 9999  ) ) {

        // Parameters validated, now call 'normal' _asctime
        __F_NAME(_asctime,__wasctime)( timeptr, s );
        rc = 0;
    }

    if( msg != NULL ) {
        // Runtime-constraint violated, store zero in receiving field if possible
        if( (s != NULL) && (maxsize > 0) && __lte_rsizmax( maxsize ) ) {
            *s = NULLCHAR;
        }
        // Now call the handler
        __rtct_fail( __func__, msg, NULL );
    }

    return( rc );
}
