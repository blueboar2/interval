#include "main.h"

void init_state () {

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
    }
