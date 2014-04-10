#include <stdlib.h>
#include <mpfr.h>
#include <glib.h>
#include <stdio.h>
#include <string.h>

typedef enum { false, true } bool;

char *InputString1;
char *InputString2;

GString *OutputString1;
GString *OutputString2;
GString *tempstring;

struct interval {
    bool openleft;
    bool openright;
    __mpz_struct left;
    __mpz_struct right;
};

struct interval temp1, temp2, temp3;

GArray *stack;
GArray *uarray;
GArray *uarray2; 	//for unifying two
GArray *uarray3; 	//for unifying and intersecting two
GArray *uarray4; 	//temp variable when intersecting
GArray *intervals;

__mpfr_struct result, temp, con1e30, con1, con0;
__mpz_struct ccon1e30, pcon1e100, ocon1e100;

long templong;
