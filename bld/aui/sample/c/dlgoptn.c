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
* Description:  WHEN YOU FIGURE OUT WHAT THIS MODULE DOES, PLEASE
*               DESCRIBE IT HERE!
*
****************************************************************************/


#include "app.h"
#include "dlgoptn.h"

typedef struct dlg_window_set {
    bool        cancel;
} dlg_window_set;

static void SetDlgStatus( gui_window *gui )
{
    GUISetChecked( gui, CTL_OPT_AUTO,     false );
    GUISetChecked( gui, CTL_OPT_BELL,     true );
    GUISetChecked( gui, CTL_OPT_IMPLICIT, false );
    GUISetChecked( gui, CTL_OPT_RECURSE,  true );
    GUISetChecked( gui, CTL_OPT_FLIP,     false );
    GUISetChecked( gui, CTL_OPT_CASE,     true );
}


static bool OptSetEvent( gui_window * gui, gui_event gui_ev, void * param )
{
    gui_ctl_id      id;
    dlg_window_set  *optset;

    optset = GUIGetExtra( gui );
    switch( gui_ev ) {
    case GUI_INIT_DIALOG:
        SetDlgStatus( gui );
        return( true );
    case GUI_CONTROL_CLICKED :
        GUI_GETID( param, id );
        switch( id ) {
        case CTL_OPT_OK:
            optset->cancel = false;
            GUICloseDialog( gui );
            break;
        case CTL_OPT_CANCEL:
            optset->cancel = true;
            GUICloseDialog( gui );
            break;
        case CTL_OPT_DEFAULTS:
            SetDlgStatus( gui );
            break;
        default :
            break;
        }
        return( true );
    default :
        break;
    }
    return( false );
}


bool    DlgOptions( void )
{
    dlg_window_set      optset;

    optset.cancel = true;
    ResDlgOpen( &OptSetEvent, &optset, GUI_MAKEINTRESOURCE( DLG_OPTIONS ) );
    return( !optset.cancel );
}
