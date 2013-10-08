#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tokens.h"

#include <glib.h>
#include <gmp.h>
#include <mpfr.h>

#include "simple_interval.h"
#include "parse_string.h"

    char *InputString1;
    char *InputString2;

    GList * stack;

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
    //mpfr_t s;

    puts ("Input first string");
    InputString1 = inputString(10);
    puts ("Input second string");
    InputString2 = inputString(10);

    printf ("\nYour first string is %s\nYour second string is %s\n", InputString1, InputString2);

    stack = parse_string (InputString1);

    // is it a complex string
    if (strstr(InputString1, "U") != NULL) 
		{
		printf ("%s","Complex String");
		// divide_string(InputString1);
		}
	else
    {
	if (strstr(InputString1, ";") != NULL)
		{
		// it is one interval
		printf ("%s","Simple String");
		// one_interval(InputString1);
		}
		else
		{
		// it is something like 5<=x<=6
		simple_interval(InputString1);
		}
    };

    free (InputString1);
    free (InputString2);

    //mpfr_init2 (s, 200);
    //mpfr_set_d (s, 1.0, MPFR_RNDD);
    //mpfr_out_str (stdout, 10, 0, s, MPFR_RNDD);
    //mpfr_clear (s);
    return 0;
    }
