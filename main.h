#include <stdlib.h>
#include <mpfr.h>
#include <glib.h>
#include <stdio.h>
#include <string.h>

typedef enum { false, true } bool;

struct interval {
    bool openleft;
    bool openright;
    __mpz_struct left;
    __mpz_struct right;
};

struct interval temp1, temp2;

GArray *stack;
gint stacksize;

GArray *intervals;
gint intervalsize;

__mpfr_struct result, temp, con1e30;
__mpz_struct pcon1e100, ocon1e100;
