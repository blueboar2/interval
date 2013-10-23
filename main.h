#include <stdlib.h>
#include <mpfr.h>
#include <glib.h>
#include <stdio.h>
#include <string.h>

typedef enum { false, true } bool;

struct interval {
    bool openleft;
    bool openright;
    bool leftinf;
    bool rightinf;
    __mpz_struct left;
    __mpz_struct right;
};

struct interval temp1;

GArray *stack;
gint stacksize;

GArray *intervals;
gint intervalsize;

__mpfr_struct result, temp, con1e30;