/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2017-2024 The Open Watcom Contributors. All Rights Reserved.
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


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "bool.h"
#include "stdui.h"
#include "tixparse.h"
#include "trie.h"
#include "doparse.h"

#include "clibext.h"


static FILE     *out_file= NULL;

#include "_doparse.c"

bool TrieAdd( ui_event ui_ev, const char *input )
{
    fprintf( out_file, "'\\x%2.2x', '\\x%2.2x',    ", ui_ev & 0xff, (ui_ev >> 8) & 0xff );
    for( ;; ) {
        fprintf( out_file, "'\\x%2.2x', ", *(unsigned char *)input );
        if( *input == '\0' )
            break;
        ++input;
    }
    fprintf( out_file, "\n" );
    return( true );
}

void tix_error( const char *str )
{
    fprintf( stderr, "\nError: %s\n", str );
}

void ti_map_display_code( char c, bool alt_map )
{
    /* unused parameters */ (void)c; (void)alt_map;
}

int main( int argc, char *argv[] )
{
    FILE    *in_file;
    int     rc;

    if( argc != 3 ) {
        fprintf( stderr, "Usage: buildesc <in-tix-file> <out-c-file>\n" );
        return( 1 );
    }
    in_file = fopen( argv[1], "r" );
    if( in_file == NULL ) {
        fprintf( stderr, "Can't open %s: %s\n", argv[0], strerror( errno ) );
        return( 1 );
    }

    out_file = fopen( argv[2], "w" );
    if( out_file == NULL ) {
        fclose( in_file );
        fprintf( stderr, "Can't open %s: %s\n", argv[0], strerror( errno ) );
        return( 1 );
    }
    fprintf( out_file, "\n\n\t// File generated by BUILDESC.C\n\n" );
    fprintf( out_file, "static const char ConEscapes[] = {\n" );
    rc = do_parse( in_file );
    fclose( in_file );
    if( rc ) {
       fprintf( out_file, "};\n" );
       return( 0 );
    }
    return( 1 );
}
