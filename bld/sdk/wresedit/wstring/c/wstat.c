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


#include "commonui.h"
#include <string.h>
#include <mbstring.h>
#include <stdio.h>
#include "watcom.h"
#include "wglbl.h"
#include "wmsg.h"
#include "wmain.h"
#include "wstat.h"
#include "ldstr.h"
#include "rcstr.gh"

/****************************************************************************/
/* macro definitions                                                        */
/****************************************************************************/
#define STATUS_FONTFACENAME     "Helv"
#define STATUS_FONTPOINTSIZE    8
#define STATUS_LINE_PAD         4
#define STATUS1_WIDTH           160

/****************************************************************************/
/* type definitions                                                         */
/****************************************************************************/

/****************************************************************************/
/* external function prototypes                                             */
/****************************************************************************/
bool WStatusWndProc( HWND, UINT, WPARAM, LPARAM );

/****************************************************************************/
/* static function prototypes                                               */
/****************************************************************************/
static bool WDisplayStatusText( WStatBar * );

/****************************************************************************/
/* static variables                                                         */
/****************************************************************************/
static int      WStatusDepth  = 0;
static HFONT    WStatusFont   = NULL;

bool WInitStatusLines( HINSTANCE inst )
{
    LOGFONT             lf;
    TEXTMETRIC          tm;
    HFONT               old_font;
    HDC                 dc;
    char                *font_facename;
    char                *cp;
    int                 font_pointsize;
    bool                use_default;

    memset( &lf, 0, sizeof( LOGFONT ) );
    dc = GetDC( (HWND)NULL );
    lf.lfWeight = FW_BOLD;
    use_default = true;

    font_facename = AllocRCString( W_STATUSFONT );
    if( font_facename != NULL ) {
        cp = (char *)_mbschr( (unsigned char const *)font_facename, '.' );
        if( cp != NULL ) {
            *cp = '\0';
            strcpy( lf.lfFaceName, font_facename );
            cp++;
            font_pointsize = atoi( cp );
            use_default = false;
        }
        FreeRCString( font_facename );
    }

    if( use_default ) {
        strcpy( lf.lfFaceName, STATUS_FONTFACENAME );
        font_pointsize = STATUS_FONTPOINTSIZE;
    }

    lf.lfHeight = -MulDiv( font_pointsize, GetDeviceCaps( dc, LOGPIXELSY ), 72 );
    WStatusFont = CreateFontIndirect( &lf );
    old_font = SelectObject( dc, WStatusFont );
    GetTextMetrics( dc, &tm );
    SelectObject( dc, old_font );
    ReleaseDC( (HWND)NULL, dc );

    WStatusDepth = tm.tmHeight + STATUS_LINE_PAD + VERT_BORDER * 2;

    StatusWndInit( inst, WStatusWndProc, 0, NULL );

    return( true );
}

void WFiniStatusLines( void )
{
    if( WStatusFont != (HFONT)NULL ) {
        DeleteObject( WStatusFont );
    }

    StatusWndFini();
}

int WGetStatusDepth( void )
{
    return( WStatusDepth );
}

void WResizeStatusWindows( WStatBar *wsb, RECT *rect )
{
    if( wsb->win != NULL ) {
        int height;

        height = ( rect->bottom - rect->top ) - WStatusDepth;
        if( height < 0 )
            height = 0;
        MoveWindow( wsb->win, 0, height, rect->right - rect->left, WStatusDepth, TRUE );
    }
}

void WDestroyStatusLine( WStatBar *wsb )
{
    if( wsb != NULL ) {
        StatusWndDestroy( wsb->stat );
        WRMemFree( wsb );
    }
}

WStatBar *WCreateStatusLine( HWND parent, HINSTANCE inst )
{
    WStatBar            *wsb;
    RECT                rect;
    status_block_desc   sbd;

    wsb = (WStatBar *)WRMemAlloc( sizeof( WStatBar ) );
    if( wsb != NULL ) {
        wsb->stat = StatusWndStart();
        if( wsb->stat == NULL ) {
            return( NULL );
        }
    } else {
        return( NULL );
    }

    GetClientRect( parent, &rect );

    rect.top = rect.bottom - WStatusDepth;

    sbd.separator_width = STATUS_LINE_PAD;
    sbd.width = STATUS1_WIDTH;
    sbd.width_is_percent = FALSE;
    sbd.width_is_pixels = TRUE;

    StatusWndSetSeparators( wsb->stat, 1, &sbd );

    if( (wsb->win = StatusWndCreate( wsb->stat, parent, &rect, inst, NULL )) == NULL ) {
        WDisplayErrorMsg( W_STATUSNOTCREATED );
        WDestroyStatusLine( wsb );
        return( NULL );
    }

    WSetStatusReadyText( wsb );

    GetWindowRect( wsb->win, &rect );
    WStatusDepth = rect.bottom - rect.top;

    return( wsb );
}

bool WSetStatusReadyText( WStatBar *wsb )
{
    WSetStatusText( wsb, NULL, "" );
    return( WSetStatusByID( wsb, W_READYMSG, 0 ) );
}

bool WSetStatusByID( WStatBar *wsb, msg_id id1, msg_id id2 )
{
    char        *str1;
    char        *str2;
    bool        ret;

    ret = false;
    str1 = NULL;
    str2 = NULL;

    if( id1 > 0 ) {
        str1 = AllocRCString( id1 );
    }

    if( id2 > 0 ) {
        str2 = AllocRCString( id2 );
    }

    ret = WSetStatusText( wsb, str1, str2 );

    if( str1 != NULL ) {
        FreeRCString( str1 );
    }

    if( str2 != NULL ) {
        FreeRCString( str2 );
    }

    return( ret );
}

bool WSetStatusText( WStatBar *wsb, const char *s1, const char *s2 )
{
    size_t          len;
    size_t          pos;
    WStringEditInfo *einfo;

    if( wsb == NULL ) {
        einfo = WGetCurrentEditInfo();
        if( einfo != NULL ) {
            wsb = einfo->wsb;
            if( wsb == NULL ) {
                return( false );
            }
        } else {
            return( false );
        }
    }

    if( wsb->win == (HWND)NULL ) {
        return( true );
    }

    if( s1 != NULL ) {
        len = strlen( s1 );
        if( len > MAX_STATUS_TEXT )
            len = MAX_STATUS_TEXT;
        if( len != 0 ) {
            memcpy( wsb->text, s1, len );
            pos = len;
        } else {
            wsb->text[0] = ' ';
            pos = 1;
        }
    } else {
        pos = 0;
    }

    if( s2 != NULL ) {
        wsb->text[pos++] = STATUS_ESC_CHAR;
        wsb->text[pos++] = STATUS_NEXT_BLOCK;
        len = strlen( s2 );
        if( len > MAX_STATUS_TEXT )
            len = MAX_STATUS_TEXT;
        if( len != 0 ) {
            memcpy( wsb->text + pos, s2, len );
            wsb->text[pos + len] = '\0';
        } else {
            wsb->text[pos++] = ' ';
            wsb->text[pos] = '\0';
        }
    } else {
        wsb->text[pos++] = '\0';
    }

    if( s1 != NULL || s2 != NULL ) {
        return( WDisplayStatusText( wsb ) );
    }

    return( true );
}

bool WStatusWndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    /* touch unused vars to get rid of warning */
    _wtouch( hWnd );
    _wtouch( wParam );
    _wtouch( lParam );
    _wtouch( msg );

    return( false );
}

bool WDisplayStatusText( WStatBar *wsb )
{
    HDC hdc;

    hdc = GetDC( wsb->win );
    if( hdc != (HDC)NULL ) {
        StatusWndDrawLine( wsb->stat, hdc, WStatusFont, wsb->text, DT_ESC_CONTROLLED );
        ReleaseDC( wsb->win, hdc );
    }

    return( true );
}
