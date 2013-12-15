#include "main.h"

char* inputString (unsigned int realloc_size)
{
    unsigned int current_size = 0;
    char *pStr = malloc(realloc_size);
    current_size = realloc_size;

    if(pStr != NULL)
    {
    int c = EOF;
    unsigned int i =0;
        //accept user input until hit enter or end of file
    while (( c = getchar() ) != '\n' && c != EOF)
    {
        pStr[i++]=(char)c;

        //if i reached maximize size then realloc size
        if(i == current_size)
        {
            current_size = i+realloc_size;
            pStr = realloc(pStr, current_size);
        }
    }

    pStr[i] = '\0';
    }

    return pStr;
}


int main () {
    char *str_divided;

    init_state();
    puts ("Input first string");
    InputString1 = inputString(10);
    yy_scan_string (InputString1);
    yyparse();
    optimize();
    tostring();
    OutputString1 = g_string_new (tempstring->str);
    init_state();
    puts ("Input second string");
    InputString2 = inputString(10);
    yy_scan_string (InputString2);
    yyparse();
    optimize();
    tostring();
    OutputString2 = g_string_new (tempstring->str);

    printf ("Calculated first string: %s\n", OutputString1->str);
    printf ("Calculated second string: %s\n", OutputString2->str);

    if (g_strcmp0(OutputString1->str, OutputString2->str) == 0)
	{printf ("Intervals are IDENTICAL\n"); }
	else {printf ("Intervals are NOT identical\n"); }

    free (InputString1);
    free (InputString2);

    return 0;
    }
