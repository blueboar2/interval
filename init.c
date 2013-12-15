#include "main.h"

void init_state () {

    stack = g_array_new (FALSE, FALSE, sizeof(__mpfr_struct));
    stacksize = 0;
    intervals = g_array_new (FALSE, FALSE, sizeof(temp1));
    intervalsize = 0;

    mpfr_set_emax(1000000);
    mpfr_set_default_prec(1000000);
    mpfr_init (&result);
    mpfr_init (&temp);

    mpfr_init (&con1e30);
    mpfr_set_str (&con1e30, "1e30", 10, 0);

    mpz_init(&ccon1e30);
    mpz_set_str(&ccon1e30, "1000000000000000000000000000000", 10);

    mpz_init (&pcon1e100);
    mpz_mul(&pcon1e100, &ccon1e30, &ccon1e30);		//1E60
    mpz_mul(&pcon1e100, &pcon1e100, &pcon1e100);	//1E120
    mpz_mul(&pcon1e100, &pcon1e100, &pcon1e100);	//1E240
    mpz_mul(&pcon1e100, &pcon1e100, &pcon1e100);	//1E480

    mpz_init (&ocon1e100);
    mpz_neg(&ocon1e100, &pcon1e100);		//-1E480
    }