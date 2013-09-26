#include <stdio.h>

#include <gmp.h>
#include <mpfr.h>

int main () {
    mpfr_t s;

    mpfr_init2 (s, 200);
    mpfr_set_d (s, 1.0, MPFR_RNDD);
    mpfr_out_str (stdout, 10, 0, s, MPFR_RNDD);
    mpfr_clear (s);
    return 0;
    }
