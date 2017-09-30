/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2017-2017 The Open Watcom Contributors. All Rights Reserved.
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
* Description:  Message table for the spy.
*
****************************************************************************/



/* message with hard coded constants are undocumented messages
   taken from       "Undocumented Windows" */

/*        watch stopon ID                              text ID                           type class   count */
msgpick1( true, false, WM_ACTIVATE,                    "WM_ACTIVATE",                    MC_WINDOW,   0L )
msgpick1( true, false, WM_ACTIVATEAPP,                 "WM_ACTIVATEAPP",                 MC_WINDOW,   0L )
msgpick1( true, false, WM_ACTIVATESHELLWINDOW,         "WM_ACTIVATESHELLWINDOW",         MC_WINDOW,   0L )
msgpick1( true, false, WM_ATTABACTIVE,                 "WM_ALTTABACTIVE",                MC_INPUT,    0L )
msgpick1( true, false, WM_APP,                         "WM_APP",                         MC_APPL,     0L )
msgpick2( true, false, WM_APPCOMMAND,                  "WM_APPCOMMAND",                  MC_INPUT,    0L )
msgpick1( true, false, WM_ASKCBFORMATNAME,             "WM_ASKCBFORMATNAME",             MC_CLIPBRD,  0L )
msgpick1( true, false, WM_BEGINDRAG,                   "WM_BEGINDRAG",                   MC_INPUT,    0L )
msgpick2( true, false, WM_CANCELJOURNAL,               "WM_CANCELJOURNAL",               MC_SYSTEM,   0L )
msgpick1( true, false, WM_CANCELMODE,                  "WM_CANCELMODE",                  MC_WINDOW,   0L )
msgpick2( true, false, WM_CAPTURECHANGED,              "WM_CAPTURECHANGED",              MC_MOUSE,    0L )
msgpick1( true, false, WM_CHANGECBCHAIN,               "WM_CHANGECBCHAIN",               MC_CLIPBRD,  0L )
msgpick2( true, false, WM_CHANGEUISTATE,               "WM_CHANGEUISTATE",               MC_OTHER,    0L )
msgpick1( true, false, WM_CHAR,                        "WM_CHAR",                        MC_INPUT,    0L )
msgpick1( true, false, WM_CHARTOITEM,                  "WM_CHARTOITEM",                  MC_INPUT,    0L )
msgpick1( true, false, WM_CHILDACTIVATE,               "WM_CHILDACTIVATE",               MC_WINDOW,   0L )
msgpick1( true, false, WM_CLEAR,                       "WM_CLEAR",                       MC_CLIPBRD,  0L )
msgpick2( true, false, WM_CLIPBOARDUPDATE,             "WM_CLIPBOARDUPDATE",             MC_CLIPBRD,  0L )
msgpick1( true, false, WM_CLOSE,                       "WM_CLOSE",                       MC_WINDOW,   0L )
msgpick1( true, false, WM_COALESCE_FIRST,              "WM_COALESCE_FIRST",              MC_OTHER,    0L )
msgpick1( true, false, WM_COALESCE_LAST,               "WM_COALESCE_LAST",               MC_OTHER,    0L )
msgpick1( true, false, WM_COMMAND,                     "WM_COMMAND",                     MC_INPUT,    0L )
msgpick1( true, false, WM_COMMNOTIFY,                  "WM_COMMNOTIFY",                  MC_OTHER,    0L )
msgpick1( true, false, WM_COMPACTING,                  "WM_COMPACTING",                  MC_SYSTEM,   0L )
msgpick1( true, false, WM_COMPAREITEM,                 "WM_COMPAREITEM",                 MC_WINDOW,   0L )
msgpick2( true, false, WM_CONTEXTMENU,                 "WM_CONTEXTMENU",                 MC_INPUT,    0L )
msgpick1( true, false, WM_CONVERTREQUEST,              "WM_CONVERTREQUEST",              MC_OTHER,    0L )
msgpick1( true, false, WM_CONVERTRESULT,               "WM_CONVERTRESULT",               MC_OTHER,    0L )
msgpick1( true, false, WM_COPY,                        "WM_COPY",                        MC_CLIPBRD,  0L )
msgpick2( true, false, WM_COPYDATA,                    "WM_COPYDATA",                    MC_INPUT,    0L )
msgpick1( true, false, WM_CREATE,                      "WM_CREATE",                      MC_WINDOW,   0L )
msgpick1( true, false, WM_CTLCOLOR,                    "WM_CTLCOLOR",                    MC_WINDOW,   0L )
msgpick2( true, false, WM_CTLCOLORBTN,                 "WM_CTLCOLORBTN",                 MC_WINDOW,   0L )
msgpick2( true, false, WM_CTLCOLORDLG,                 "WM_CTLCOLORDLG",                 MC_WINDOW,   0L )
msgpick2( true, false, WM_CTLCOLOREDIT,                "WM_CTLCOLOREDIT",                MC_WINDOW,   0L )
msgpick2( true, false, WM_CTLCOLORLISTBOX,             "WM_CTLCOLORLISTBOX",             MC_WINDOW,   0L )
msgpick2( true, false, WM_CTLCOLORMSGBOX,              "WM_CTLCOLORMSGBOX",              MC_WINDOW,   0L )
msgpick2( true, false, WM_CTLCOLORSCROLLBAR,           "WM_CTLCOLORSCROLLBAR",           MC_WINDOW,   0L )
msgpick2( true, false, WM_CTLCOLORSTATIC,              "WM_CTLCOLORSTATIC",              MC_WINDOW,   0L )
msgpick1( true, false, WM_CUT,                         "WM_CUT",                         MC_CLIPBRD,  0L )
msgpick1( true, false, WM_DDE_ACK,                     "WM_DDE_ACK",                     MC_DDE,      0L )
msgpick1( true, false, WM_DDE_ADVISE,                  "WM_DDE_ADVISE",                  MC_DDE,      0L )
msgpick1( true, false, WM_DDE_DATA,                    "WM_DDE_DATA",                    MC_DDE,      0L )
msgpick1( true, false, WM_DDE_EXECUTE,                 "WM_DDE_EXECUTE",                 MC_DDE,      0L )
msgpick1( true, false, WM_DDE_INITIATE,                "WM_DDE_INITIATE",                MC_DDE,      0L )
msgpick1( true, false, WM_DDE_POKE,                    "WM_DDE_POKE",                    MC_DDE,      0L )
msgpick1( true, false, WM_DDE_REQUEST,                 "WM_DDE_REQUEST",                 MC_DDE,      0L )
msgpick1( true, false, WM_DDE_TERMINATE,               "WM_DDE_TERMINATE",               MC_DDE,      0L )
msgpick1( true, false, WM_DDE_UNADVISE,                "WM_DDE_UNADVISE",                MC_DDE,      0L )
msgpick1( true, false, WM_DEADCHAR,                    "WM_DEADCHAR",                    MC_INPUT,    0L )
msgpick1( true, false, WM_DELETEITEM,                  "WM_DELETEITEM",                  MC_WINDOW,   0L )
msgpick1( true, false, WM_DESTROY,                     "WM_DESTROY",                     MC_WINDOW,   0L )
msgpick1( true, false, WM_DESTROYCLIPBOARD,            "WM_DESTROYCLIPBOARD",            MC_CLIPBRD,  0L )
msgpick2( true, false, WM_DEVICECHANGE,                "WM_DEVICECHANGE",                MC_SYSTEM,   0L )
msgpick1( true, false, WM_DEVMODECHANGE,               "WM_DEVMODECHANGE",               MC_SYSTEM,   0L )
msgpick2( true, false, WM_DISPLAYCHANGE,               "WM_DISPLAYCHANGE",               MC_SYSTEM,   0L )
msgpick1( true, false, WM_DRAGLOOP,                    "WM_DRAGLOOP",                    MC_INPUT,    0L )
msgpick1( true, false, WM_DRAGMOVE,                    "WM_DRAGMOVE",                    MC_INPUT,    0L )
msgpick1( true, false, WM_DRAGSELECT,                  "WM_DRAGSELECT",                  MC_INPUT,    0L )
msgpick1( true, false, WM_DRAWCLIPBOARD,               "WM_DRAWCLIPBOARD",               MC_CLIPBRD,  0L )
msgpick1( true, false, WM_DRAWITEM,                    "WM_DRAWITEM",                    MC_WINDOW,   0L )
msgpick1( true, false, WM_DROPFILES,                   "WM_DROPFILES",                   MC_OTHER,    0L )
msgpick1( true, false, WM_DROPOBJECT,                  "WM_DROPOBJECT",                  MC_INPUT,    0L )
msgpick2( true, false, WM_DWMCOMPOSITIONCHANGED,       "WM_DWMCOMPOSITIONCHANGED",       MC_WINDOW,   0L )
msgpick2( true, false, WM_DWMNCRENDERINGCHANGED,       "WM_DWMNCRENDERINGCHANGED",       MC_WINDOW,   0L )
msgpick2( true, false, WM_DWMCOLORIZATIONCOLORCHANGED, "WM_DWMCOLORIZATIONCOLORCHANGED", MC_WINDOW,   0L )
msgpick2( true, false, WM_DWMWINDOWMAXIMIZEDCHANGE,    "WM_DWMWINDOWMAXIMIZEDCHANGE",    MC_WINDOW,   0L )
msgpick1( true, false, WM_ENABLE,                      "WM_ENABLE",                      MC_WINDOW,   0L )
msgpick1( true, false, WM_ENDSESSION,                  "WM_ENDSESSION",                  MC_SYSTEM,   0L )
msgpick1( true, false, WM_ENTERIDLE,                   "WM_ENTERIDLE",                   MC_SYSTEM,   0L )
msgpick1( true, false, WM_ENTERMENULOOP,               "WM_ENTERMENULOOP",               MC_SYSTEM,   0L )
msgpick1( true, false, WM_ENTERSIZEMOVE,               "WM_ENTERSIZEMOVE",               MC_WINDOW,   0L )
msgpick1( true, false, WM_ERASEBKGND,                  "WM_ERASEBKGND",                  MC_WINDOW,   0L )
msgpick1( true, false, WM_EXITMENULOOP,                "WM_EXITMENULOOP",                MC_SYSTEM,   0L )
msgpick1( true, false, WM_EXITSIZEMOVE,                "WM_EXITSIZEMOVE",                MC_INPUT,    0L )
msgpick1( true, false, WM_FILESYSCHANGE,               "WM_FILESYSCHANGE",               MC_SYSTEM,   0L )
msgpick1( true, false, WM_FONTCHANGE,                  "WM_FONTCHANGE",                  MC_WINDOW,   0L )
msgpick1( true, false, WM_GETDLGCODE,                  "WM_GETDLGCODE",                  MC_WINDOW,   0L )
msgpick1( true, false, WM_GETFONT,                     "WM_GETFONT",                     MC_WINDOW,   0L )
msgpick1( true, false, WM_GETHOTKEY,                   "WM_GETHOTKEY",                   MC_WINDOW,   0L )
msgpick2( true, false, WM_GETICON,                     "WM_GETICON",                     MC_WINDOW,   0L )
msgpick1( true, false, WM_GETMINMAXINFO,               "WM_GETMINMAXINFO",               MC_WINDOW,   0L )
msgpick1( true, false, WM_GETTEXT,                     "WM_GETTEXT",                     MC_WINDOW,   0L )
msgpick1( true, false, WM_GETTEXTLENGTH,               "WM_GETTEXTLENGTH",               MC_WINDOW,   0L )
msgpick2( true, false, WM_GETTITLEBARINFOEX,           "WM_GETTITLEBARINFOEX",           MC_WINDOW,   0L )
msgpick2( true, false, WM_HELP,                        "WM_HELP",                        MC_INPUT,    0L )
msgpick1( true, false, WM_HSCROLL,                     "WM_HSCROLL",                     MC_INPUT,    0L )
msgpick1( true, false, WM_HSCROLLCLIPBOARD,            "WM_HSCROLLCLIPBOARD",            MC_CLIPBRD,  0L )
msgpick1( true, false, WM_ICONERASEBKGND,              "WM_ICONERASEBKGND",              MC_WINDOW,   0L )
msgpick2( true, false, WM_IME_STARTCOMPOSITION,        "WM_IME_STARTCOMPOSITION",        MC_IME,      0L )
msgpick2( true, false, WM_IME_ENDCOMPOSITION,          "WM_IME_ENDCOMPOSITION",          MC_IME,      0L )
msgpick2( true, false, WM_IME_COMPOSITION,             "WM_IME_COMPOSITION",             MC_IME,      0L )
msgpick2( true, false, WM_IME_KEYLAST,                 "WM_IME_KEYLAST",                 MC_IME,      0L )
msgpick2( true, false, WM_IME_SETCONTEXT,              "WM_IME_SETCONTEXT",              MC_IME,      0L )
msgpick2( true, false, WM_IME_NOTIFY,                  "WM_IME_NOTIFY",                  MC_IME,      0L )
msgpick2( true, false, WM_IME_CONTROL,                 "WM_IME_CONTROL",                 MC_IME,      0L )
msgpick2( true, false, WM_IME_COMPOSITIONFULL,         "WM_IME_COMPOSITIONFULL",         MC_IME,      0L )
msgpick2( true, false, WM_IME_SELECT,                  "WM_IME_SELECT",                  MC_IME,      0L )
msgpick2( true, false, WM_IME_CHAR,                    "WM_IME_CHAR",                    MC_IME,      0L )
msgpick2( true, false, WM_IME_KEYDOWN,                 "WM_IME_KEYDOWN",                 MC_IME,      0L )
msgpick2( true, false, WM_IME_KEYUP,                   "WM_IME_KEYUP",                   MC_IME,      0L )
msgpick2( true, false, WM_IME_SYSTEM,                  "WM_IME_SYSTEM",                  MC_IME,      0L )
msgpick2( true, false, WM_IME_REQUEST,                 "WM_IME_REQUEST",                 MC_IME,      0L )
msgpick1( true, false, WM_INITDIALOG,                  "WM_INITDIALOG",                  MC_INIT,     0L )
msgpick1( true, false, WM_INITMENU,                    "WM_INITMENU",                    MC_INIT,     0L )
msgpick1( true, false, WM_INITMENUPOPUP,               "WM_INITMENUPOPUP",               MC_INIT,     0L )
msgpick2( true, false, WM_INPUT,                       "WM_INPUT",                       MC_INPUT,    0L )
msgpick2( true, false, WM_INPUT_DEVICE_CHANGE,         "WM_INPUT_DEVICE_CHANGE",         MC_INPUT,    0L )
msgpick2( true, false, WM_INPUTLANGCHANGE,             "WM_INPUTLANGCHANGE",             MC_INPUT,    0L )
msgpick2( true, false, WM_INPUTLANGCHANGEREQUEST,      "WM_INPUTLANGCHANGEREQUEST",      MC_INPUT,    0L )
msgpick1( true, false, WM_INTERIM,                     "WM_INTERIM",                     MC_OTHER,    0L )
msgpick1( true, false, WM_ISACTIVEICON,                "WM_ISACTIVEICON",                MC_MDI,      0L )
msgpick1( true, false, WM_KEYDOWN,                     "WM_KEYDOWN",                     MC_INPUT,    0L )
msgpick1( true, false, WM_KEYUP,                       "WM_KEYUP",                       MC_INPUT,    0L )
msgpick1( true, false, WM_KILLFOCUS,                   "WM_KILLFOCUS",                   MC_WINDOW,   0L )
msgpick2( true, false, WM_KLUDGEMINRECT,               "WM_KLUDGEMINRECT",               MC_OTHER,    0L )
msgpick1( true, false, WM_LBUTTONDBLCLK,               "WM_LBUTTONDBLCLK",               MC_MOUSE,    0L )
msgpick1( true, false, WM_LBUTTONDOWN,                 "WM_LBUTTONDOWN",                 MC_MOUSE,    0L )
msgpick1( true, false, WM_LBUTTONUP,                   "WM_LBUTTONUP",                   MC_MOUSE,    0L )
msgpick1( true, false, WM_LBTRACKPOINT,                "WM_LBTRACKPOINT",                MC_INPUT,    0L )
msgpick1( true, false, WM_MBUTTONDBLCLK,               "WM_MBUTTONDBLCLK",               MC_MOUSE,    0L )
msgpick1( true, false, WM_MBUTTONDOWN,                 "WM_MBUTTONDOWN",                 MC_MOUSE,    0L )
msgpick1( true, false, WM_MBUTTONUP,                   "WM_MBUTTONUP",                   MC_MOUSE,    0L )
msgpick1( true, false, WM_MDIACTIVATE,                 "WM_MDIACTIVATE",                 MC_MDI,      0L )
msgpick1( true, false, WM_MDICASCADE,                  "WM_MDICASCADE",                  MC_MDI,      0L )
msgpick1( true, false, WM_MDICREATE,                   "WM_MDICREATE",                   MC_MDI,      0L )
msgpick1( true, false, WM_MDIDESTROY,                  "WM_MDIDESTROY",                  MC_MDI,      0L )
msgpick1( true, false, WM_MDIGETACTIVE,                "WM_MDIGETACTIVE",                MC_MDI,      0L )
msgpick1( true, false, WM_MDIICONARRANGE,              "WM_MDIICONARRANGE",              MC_MDI,      0L )
msgpick1( true, false, WM_MDIMAXIMIZE,                 "WM_MDIMAXIMIZE",                 MC_MDI,      0L )
msgpick1( true, false, WM_MDINEXT,                     "WM_MDINEXT",                     MC_MDI,      0L )
msgpick1( true, false, WM_MDIRESTORE,                  "WM_MDIRESTORE",                  MC_MDI,      0L )
msgpick1( true, false, WM_MDISETMENU,                  "WM_MDISETMENU",                  MC_MDI,      0L )
msgpick1( true, false, WM_MDITILE,                     "WM_MDITILE",                     MC_MDI,      0L )
msgpick1( true, false, WM_MEASUREITEM,                 "WM_MEASUREITEM",                 MC_WINDOW,   0L )
msgpick1( true, false, WM_MENUCHAR,                    "WM_MENUCHAR",                    MC_INPUT,    0L )
msgpick2( true, false, WM_MENUCOMMAND,                 "WM_MENUCOMMAND",                 MC_INPUT,    0L )
msgpick2( true, false, WM_MENUDRAG,                    "WM_MENUDRAG",                    MC_INPUT,    0L )
msgpick2( true, false, WM_MENUGETOBJECT,               "WM_MENUGETOBJECT",               MC_INPUT,    0L )
msgpick2( true, false, WM_MENURBUTTONUP,               "WM_MENURBUTTONUP",               MC_INPUT,    0L )
msgpick1( true, false, WM_MENUSELECT,                  "WM_MENUSELECT",                  MC_INPUT,    0L )
msgpick1( true, false, WM_MOUSEACTIVATE,               "WM_MOUSEACTIVATE",               MC_MOUSE,    0L )
msgpick2( true, false, WM_MOUSEHOVER,                  "WM_MOUSEHOVER",                  MC_MOUSE,    0L )
msgpick2( true, false, WM_MOUSEHWHEEL,                 "WM_MOUSEHWHEEL",                 MC_MOUSE,    0L )
msgpick2( true, false, WM_MOUSELEAVE,                  "WM_MOUSELEAVE",                  MC_MOUSE,    0L )
msgpick1( true, false, WM_MOUSEMOVE,                   "WM_MOUSEMOVE",                   MC_MOUSE,    0L )
msgpick2( true, false, WM_MOUSEWHEEL,                  "WM_MOUSEWHEEL",                  MC_MOUSE,    0L )
msgpick1( true, false, WM_MOVE,                        "WM_MOVE",                        MC_WINDOW,   0L )
msgpick2( true, false, WM_MOVING,                      "WM_MOVING",                      MC_WINDOW,   0L )
msgpick1( true, false, WM_NCACTIVATE,                  "WM_NCACTIVATE",                  MC_NC_MISC,  0L )
msgpick1( true, false, WM_NCCALCSIZE,                  "WM_NCCALCSIZE",                  MC_NC_MISC,  0L )
msgpick1( true, false, WM_NCCREATE,                    "WM_NCCREATE",                    MC_NC_MISC,  0L )
msgpick1( true, false, WM_NCDESTROY,                   "WM_NCDESTROY",                   MC_NC_MISC,  0L )
msgpick1( true, false, WM_NCHITTEST,                   "WM_NCHITTEST",                   MC_NC_MOUSE, 0L )
msgpick1( true, false, WM_NCLBUTTONDBLCLK,             "WM_NCLBUTTONDBLCLK",             MC_NC_MOUSE, 0L )
msgpick1( true, false, WM_NCLBUTTONDOWN,               "WM_NCLBUTTONDOWN",               MC_NC_MOUSE, 0L )
msgpick1( true, false, WM_NCLBUTTONUP,                 "WM_NCLBUTTONUP",                 MC_NC_MOUSE, 0L )
msgpick1( true, false, WM_NCMBUTTONDBLCLK,             "WM_NCMBUTTONDBLCLK",             MC_NC_MOUSE, 0L )
msgpick1( true, false, WM_NCMBUTTONDOWN,               "WM_NCMBUTTONDOWN",               MC_NC_MOUSE, 0L )
msgpick1( true, false, WM_NCMBUTTONUP,                 "WM_NCMBUTTONUP",                 MC_NC_MOUSE, 0L )
msgpick2( true, false, WM_NCMOUSEHOVER,                "WM_NCMOUSEHOVER",                MC_NC_MOUSE, 0L )
msgpick2( true, false, WM_NCMOUSELEAVE,                "WM_NCMOUSELEAVE",                MC_NC_MOUSE, 0L )
msgpick1( true, false, WM_NCMOUSEMOVE,                 "WM_NCMOUSEMOVE",                 MC_NC_MOUSE, 0L )
msgpick1( true, false, WM_NCPAINT,                     "WM_NCPAINT",                     MC_NC_MISC,  0L )
msgpick1( true, false, WM_NCRBUTTONDBLCLK,             "WM_NCRBUTTONDBLCLK",             MC_NC_MOUSE, 0L )
msgpick1( true, false, WM_NCRBUTTONDOWN,               "WM_NCRBUTTONDOWN",               MC_NC_MOUSE, 0L )
msgpick1( true, false, WM_NCRBUTTONUP,                 "WM_NCRBUTTONUP",                 MC_NC_MOUSE, 0L )
msgpick2( true, false, WM_NCUAHDRAWCAPTION,            "WM_NCUAHDRAWCAPTION",            MC_NC_MISC,  0L )
msgpick2( true, false, WM_NCUAHDRAWFRAME,              "WM_NCUAHDRAWFRAME",              MC_NC_MISC,  0L )
msgpick2( true, false, WM_NCXBUTTONDBLCLK,             "WM_NCXBUTTONDBLCLK",             MC_NC_MOUSE, 0L )
msgpick2( true, false, WM_NCXBUTTONDOWN,               "WM_NCXBUTTONDOWN",               MC_NC_MOUSE, 0L )
msgpick2( true, false, WM_NCXBUTTONUP,                 "WM_NCXBUTTONUP",                 MC_NC_MOUSE, 0L )
msgpick1( true, false, WM_NEXTDLGCTL,                  "WM_NEXTDLGCTL",                  MC_WINDOW,   0L )
msgpick1( true, false, WM_NEXTMENU,                    "WM_NEXTMENU",                    MC_INPUT,    0L )
msgpick2( true, false, WM_NOTIFY,                      "WM_NOTIFY",                      MC_INPUT,    0L )
msgpick2( true, false, WM_NOTIFYFORMAT,                "WM_NOTIFYFORMAT",                MC_INPUT,    0L )
msgpick1( true, false, WM_NULL,                        "WM_NULL",                        MC_SYSTEM,   0L )
msgpick1( true, false, WM_OTHERWINDOWCREATED,          "WM_OTHERWINDOWCREATED",          MC_WINDOW,   0L )
msgpick1( true, false, WM_OTHERWINDOWDESTROYED,        "WM_OTHERWINDOWDESTROYED",        MC_WINDOW,   0L )
msgpick1( true, false, WM_PAINT,                       "WM_PAINT",                       MC_WINDOW,   0L )
msgpick1( true, false, WM_PAINTCLIPBOARD,              "WM_PAINTCLIPBOARD",              MC_CLIPBRD,  0L )
msgpick1( true, false, WM_PAINTICON,                   "WM_PAINTICON",                   MC_WINDOW,   0L )
msgpick1( true, false, WM_PALETTECHANGED,              "WM_PALETTECHANGED",              MC_WINDOW,   0L )
msgpick1( true, false, WM_PALETTEISCHANGING,           "WM_PALETTEISCHANGING",           MC_WINDOW,   0L )
msgpick1( true, false, WM_PARENTNOTIFY,                "WM_PARENTNOTIFY",                MC_WINDOW,   0L )
msgpick1( true, false, WM_PASTE,                       "WM_PASTE",                       MC_CLIPBRD,  0L )
msgpick1( true, false, WM_PENWINFIRST,                 "WM_PENWINFIRST",                 MC_OTHER,    0L )
msgpick1( true, false, WM_PENWINLAST,                  "WM_PENWINLAST",                  MC_OTHER,    0L )
msgpick1( true, false, WM_POWER,                       "WM_POWER",                       MC_SYSTEM,   0L )
msgpick2( true, false, WM_POWERBROADCAST,              "WM_POWERBROADCAST",              MC_SYSTEM,   0L )
msgpick2( true, false, WM_PRINT,                       "WM_PRINT",                       MC_OTHER,    0L )
msgpick2( true, false, WM_PRINTCLIENT,                 "WM_PRINTCLIENT",                 MC_OTHER,    0L )
msgpick1( true, false, WM_QUERYDRAGICON,               "WM_QUERYDRAGICON",               MC_WINDOW,   0L )
msgpick1( true, false, WM_QUERYDROPOBJECT,             "WM_QUERYDROPOBJECT",             MC_INPUT,    0L )
msgpick1( true, false, WM_QUERYENDSESSION,             "WM_QUERYENDSESSION",             MC_WINDOW,   0L )
msgpick1( true, false, WM_QUERYNEWPALETTE,             "WM_QUERYNEWPALETTE",             MC_WINDOW,   0L )
msgpick1( true, false, WM_QUERYOPEN,                   "WM_QUERYOPEN",                   MC_WINDOW,   0L )
msgpick1( true, false, WM_QUERYPARKICON,               "WM_QUERYPARKICON",               MC_WINDOW,   0L )
msgpick1( true, false, WM_QUERYSAVESTATE,              "WM_QUERYSAVESTATE",              MC_OTHER,    0L )
msgpick2( true, false, WM_QUERYUISTATE,                "WM_QUERYUISTATE",                MC_OTHER,    0L )
msgpick1( true, false, WM_QUEUESYNC,                   "WM_QUEUESYNC",                   MC_OTHER,    0L )
msgpick1( true, false, WM_QUIT,                        "WM_QUIT",                        MC_WINDOW,   0L )
msgpick1( true, false, WM_RBUTTONDBLCLK,               "WM_RBUTTONDBLCLK",               MC_MOUSE,    0L )
msgpick1( true, false, WM_RBUTTONDOWN,                 "WM_RBUTTONDOWN",                 MC_MOUSE,    0L )
msgpick1( true, false, WM_RBUTTONUP,                   "WM_RBUTTONUP",                   MC_MOUSE,    0L )
msgpick1( true, false, WM_RENDERALLFORMATS,            "WM_RENDERALLFORMATS",            MC_CLIPBRD,  0L )
msgpick1( true, false, WM_RENDERFORMAT,                "WM_RENDERFORMAT",                MC_CLIPBRD,  0L )
msgpick1( true, false, WM_SETCURSOR,                   "WM_SETCURSOR",                   MC_MOUSE,    0L )
msgpick1( true, false, WM_SETFOCUS,                    "WM_SETFOCUS",                    MC_WINDOW,   0L )
msgpick1( true, false, WM_SETFONT,                     "WM_SETFONT",                     MC_WINDOW,   0L )
msgpick1( true, false, WM_SETHOTKEY,                   "WM_SETHOTKEY",                   MC_WINDOW,   0L )
msgpick2( true, false, WM_SETICON,                     "WM_SETICON",                     MC_WINDOW,   0L )
msgpick1( true, false, WM_SETREDRAW,                   "WM_SETREDRAW",                   MC_WINDOW,   0L )
msgpick1( true, false, WM_SETTEXT,                     "WM_SETTEXT",                     MC_WINDOW,   0L )
msgpick1( true, false, WM_SETVISIBLE,                  "WM_SETVISIBLE",                  MC_WINDOW,   0L )
msgpick1( true, false, WM_SHOWWINDOW,                  "WM_SHOWWINDOW",                  MC_WINDOW,   0L )
msgpick1( true, false, WM_SIZE,                        "WM_SIZE",                        MC_WINDOW,   0L )
msgpick1( true, false, WM_SIZECLIPBOARD,               "WM_SIZECLIPBOARD",               MC_CLIPBRD,  0L )
msgpick1( true, false, WM_SIZEWAIT,                    "WM_SIZEWAIT",                    MC_OTHER,    0L )
msgpick2( true, false, WM_SIZING,                      "WM_SIZING",                      MC_WINDOW,   0L )
msgpick1( true, false, WM_SPOOLERSTATUS,               "WM_SPOOLERSTATUS",               MC_SYSTEM,   0L )
msgpick2( true, false, WM_STYLECHANGED,                "WM_STYLECHANGED",                MC_WINDOW,   0L )
msgpick2( true, false, WM_STYLECHANGING,               "WM_STYLECHANGING",               MC_WINDOW,   0L )
msgpick1( true, false, WM_SYNCPAINT,                   "WM_SYNCPAINT",                   MC_WINDOW,   0L )
msgpick1( true, false, WM_SYNCTASK,                    "WM_SYNCTASK",                    MC_OTHER,    0L )
msgpick1( true, false, WM_SYSCHAR,                     "WM_SYSCHAR",                     MC_SYSTEM,   0L )
msgpick1( true, false, WM_SYSCOLORCHANGE,              "WM_SYSCOLORCHANGE",              MC_SYSTEM,   0L )
msgpick1( true, false, WM_SYSCOMMAND,                  "WM_SYSCOMMAND",                  MC_SYSTEM,   0L )
msgpick1( true, false, WM_SYSDEADCHAR,                 "WM_SYSDEADCHAR",                 MC_SYSTEM,   0L )
msgpick1( true, false, WM_SYSKEYDOWN,                  "WM_SYSKEYDOWN",                  MC_SYSTEM,   0L )
msgpick1( true, false, WM_SYSKEYUP,                    "WM_SYSKEYUP",                    MC_SYSTEM,   0L )
msgpick1( true, false, WM_SYSTEMERROR,                 "WM_SYSTEMERROR",                 MC_SYSTEM,   0L )
msgpick1( true, false, WM_SYSTIMER,                    "WM_SYSTIMER",                    MC_SYSTEM,   0L )
msgpick2( true, false, WM_TCARD,                       "WM_TCARD",                       MC_INPUT,    0L )
msgpick1( true, false, 0x0040,                         "WM_TESTING",                     MC_OTHER,    0L )
msgpick2( true, false, WM_THEMECHANGED,                "WM_THEMECHANGED",                MC_SYSTEM,   0L )
msgpick1( true, false, WM_TIMECHANGE,                  "WM_TIMECHANGE",                  MC_SYSTEM,   0L )
msgpick1( true, false, WM_TIMER,                       "WM_TIMER",                       MC_SYSTEM,   0L )
msgpick2( true, false, WM_UAHDESTROYWINDOW,            "WM_UAHDESTROYWINDOW",            MC_WINDOW,   0L )
msgpick2( true, false, WM_UAHDRAWMENU,                 "WM_UAHDRAWMENU",                 MC_WINDOW,   0L )
msgpick2( true, false, WM_UAHDRAWMENUITEM,             "WM_UAHDRAWMENUITEM",             MC_WINDOW,   0L )
msgpick2( true, false, WM_UAHINITMENU,                 "WM_UAHINITMENU",                 MC_INIT,     0L )
msgpick2( true, false, WM_UAHMEASUREMENUITEM,          "WM_UAHMEASUREMENUITEM",          MC_WINDOW,   0L )
msgpick2( true, false, WM_UAHNCPAINTMENUPOPUP,         "WM_UAHNCPAINTMENUPOPUP",         MC_WINDOW,   0L )
msgpick1( true, false, WM_UNDO,                        "WM_UNDO",                        MC_CLIPBRD,  0L )
msgpick2( true, false, WM_UNICHAR,                     "WM_UNICHAR",                     MC_INPUT,    0L )
msgpick2( true, false, WM_UNINITMENUPOPUP,             "WM_UNINITMENUPOPUP",             MC_INIT,     0L )
msgpick2( true, false, WM_UPDATEUISTATE,               "WM_UPDATEUISTATE",               MC_OTHER,    0L )
msgpick1( true, false, WM_USER,                        "WM_USER",                        MC_USER,     0L )
msgpick2( true, false, WM_USERCHANGED,                 "WM_USERCHANGED",                 MC_SYSTEM,   0L )
msgpick1( true, false, WM_VKEYTOITEM,                  "WM_VKEYTOITEM",                  MC_WINDOW,   0L )
msgpick1( true, false, WM_VSCROLL,                     "WM_VSCROLL",                     MC_INPUT,    0L )
msgpick1( true, false, WM_VSCROLLCLIPBOARD,            "WM_VSCROLLCLIPBOARD",            MC_CLIPBRD,  0L )
msgpick1( true, false, WM_WINDOWPOSCHANGED,            "WM_WINDOWPOSCHANGED",            MC_WINDOW,   0L )
msgpick1( true, false, WM_WINDOWPOSCHANGING,           "WM_WINDOWPOSCHANGING",           MC_WINDOW,   0L )
msgpick1( true, false, WM_WININICHANGE,                "WM_WININICHANGE",                MC_SYSTEM,   0L )
msgpick2( true, false, WM_WTSSESSION_CHANGE,           "WM_WTSSESSION_CHANGE",           MC_SYSTEM,   0L )
msgpick2( true, false, WM_XBUTTONDBLCLK,               "WM_XBUTTONDBLCLK",               MC_MOUSE,    0L )
msgpick2( true, false, WM_XBUTTONDOWN,                 "WM_XBUTTONDOWN",                 MC_MOUSE,    0L )
msgpick2( true, false, WM_XBUTTONUP,                   "WM_XBUTTONUP",                   MC_MOUSE,    0L )
msgpick1( true, false, WM_YOMICHAR,                    "WM_YOMICHAR",                    MC_OTHER,    0L )
