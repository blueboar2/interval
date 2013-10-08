#include <stdio.h>
#include <glib.h>

#include "lex.yy.h"
#include "parse_string.h"

GList * parse_string (char * neravenstvo)
    {
    GList *answer = NULL;
    int token;

    yy_scan_string(neravenstvo);
    while ((token = yylex()) > 0)
	{
	answer = g_list_append(answer, GINT_TO_POINTER(token));
	printf ("Token: %i, \"%s\"\n", token, yytext);
	}

    return 0;
    }