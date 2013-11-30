#include "main.h"

    char *InputString1;
    char *InputString2;

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
    intervals = g_array_new (FALSE, FALSE, sizeof(temp1));
    intervalsize = 0;

    mpfr_set_default_prec(20000);
    mpfr_init (&result);
    mpfr_init (&temp);

    mpfr_init (&con1e30);
    mpfr_set_str (&con1e30, "1e30", 10, 0);

    mpz_init (&pcon1e100);
    mpz_set_str (&pcon1e100, "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 10);

    mpz_init (&ocon1e100);
    mpz_set_str (&ocon1e100, "-1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 10);

    puts ("Input first string");
    InputString1 = inputString(10);

    yy_scan_string (InputString1);
    yyparse();
    optimize();
    //tostring(String1?);

//    puts ("Input second string");
//    InputString2 = inputString(10);
//    yy_scan_string (InputString2);
//    yyparse();
//    optimize();
//    tostring(String2?);

//    printf ("\nYour first string is %s\nYour second string is %s\n", InputString1, InputString2);

    temp1 = g_array_index(intervals, struct interval, 0);
    gmp_printf ("Left: %Zd\n", &temp1.left);
    gmp_printf ("Right: %Zd\n", &temp1.right);

    // here is some interesting code to unify inequalities

    free (InputString1);
    free (InputString2);

    return 0;
    }
