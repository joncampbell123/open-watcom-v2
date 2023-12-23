/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2002-2023 The Open Watcom Contributors. All Rights Reserved.
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


#include "wradbttn.hpp"


WEXPORT WRadioButton::WRadioButton( WWindow* parent, const WRect& r,
                                    const char *text, WStyle style )
        : WBoolSwitch( parent, GUI_RADIO_BUTTON, r, text, style ) {
/*****************************************************************/

}


WEXPORT WRadioButton::WRadioButton( WStatDialog* parent, WControlId id,
                                    WStyle style )
        : WBoolSwitch( parent, id, style ) {
/******************************************/

}


#ifdef __WATCOMC__
// Complain about defining trivial destructor inside class
#if !defined( BOOTSTRAP )
#pragma disable_message( P656 )
#else
#pragma disable_message( 656 )
#endif
#endif

WEXPORT WRadioButton::~WRadioButton() {
/*************************************/

}
