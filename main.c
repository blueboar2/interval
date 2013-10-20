#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glib.h>
#include <mpfr.h>

    char *InputString1;
    char *InputString2;

    __mpfr_struct result, temp;
    GArray *stack;
    gint stacksize;

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

    stack = g_array_new (FALSE, FALSE, sizeof(__mpfr_struct));
    stacksize = 0;
    mpfr_set_default_prec(20000);
    mpfr_init (&result);
    mpfr_init (&temp);

    puts ("Input first string");
    InputString1 = inputString(10);
//    puts ("Input second string");
//    InputString2 = inputString(10);

//    printf ("\nYour first string is %s\nYour second string is %s\n", InputString1, InputString2);

    
    yy_scan_string (InputString1);
    yyparse();
    result = g_array_index(stack, __mpfr_struct, 0);
    stack = g_array_remove_index(stack, 0);
    mpfr_printf ("%.100Rg", &result);

    // here is some interesting code

    free (InputString1);
    free (InputString2);

    //mpfr_init2 (s, 200);
    //mpfr_set_d (s, 1.0, MPFR_RNDD);
    //mpfr_out_str (stdout, 10, 0, s, MPFR_RNDD);
    //mpfr_clear (s);
    return 0;
    }
