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
    int retval = 1;

    while (retval != 0)
    {
    init_state();
    puts ("Input first string");
    InputString1 = inputString(10);
    yy_scan_string (InputString1);
    retval = yyparse();
    if (retval == 0)
    {
    optimize();
    tostring();
    OutputString1 = g_string_new (tempstring->str);
    }
    else {printf ("Error! Code=%i\n", retval); };
    }

    retval = 1;

    while (retval != 0)
    {
    init_state();
    puts ("Input second string");
    InputString2 = inputString(10);
    yy_scan_string (InputString2);
    retval = yyparse();
    if (retval == 0)
    {
    optimize();
    tostring();
    OutputString2 = g_string_new (tempstring->str);
    }
    else {printf ("Error! Code=%i\n", retval); };
    }

    printf ("Calculated first string: %s\n", OutputString1->str);
    printf ("Calculated second string: %s\n", OutputString2->str);

    if (g_strcmp0(OutputString1->str, OutputString2->str) == 0)
	{printf ("Intervals are IDENTICAL\n"); }
	else {printf ("Intervals are NOT identical\n"); }

    free (InputString1);
    free (InputString2);

    return 0;
    }

extern int getfirststring(char * String1)
    {
    init_state();
    InputString1 = String1;
    yy_scan_string (InputString1);
    int retval = yyparse();
    if (retval == 0) {
    optimize();
    tostring();
    OutputString1 = g_string_new (tempstring->str);
    return 0;
    }
	else {return retval;};
    }

extern int getsecondstring(char * String2)
    {
    init_state();
    InputString2 = String2;
    yy_scan_string (InputString2);
    int retval = yyparse();
    if (retval == 0) {
    optimize();
    tostring();
    OutputString2 = g_string_new (tempstring->str);
    return 0;
    }
	else {return retval;};
    }

extern int compare()
    {
    if (g_strcmp0(OutputString1->str, OutputString2->str) == 0)
	{return 1; } else {return 0; }
    }

extern void outputfirstinterval()
	{
	printf ("Calculated first string: %s\n", OutputString1->str);
	}

extern void outputsecondinterval()
	{
    	printf ("Calculated second string: %s\n", OutputString2->str);
	}
