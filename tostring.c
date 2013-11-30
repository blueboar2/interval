#include "main.h"

void tostring ()
	{
	int i;
	char sstr[200];
	tempstring = g_string_new(NULL);
	
	for (i=0; i<=intervalsize-1; i++)
	    {
	    temp1 = g_array_index (intervals, struct interval, i);

	    if (temp1.openleft == TRUE) {g_string_append(tempstring,"]");} else {g_string_append(tempstring,"[");}
	    if (mpz_cmp (&temp1.left, &ocon1e100) == 0) {g_string_append(tempstring,"-inf");} else 
		    {
		    mpfr_set_z (&temp, &temp1.left, 0);
		    mpfr_div (&temp, &temp, &con1e30, 0);
		    mpfr_sprintf(sstr, "%RNg", &temp);
		    g_string_append(tempstring,sstr);
		    };
	    g_string_append(tempstring,";");
	    if (mpz_cmp (&temp1.right, &pcon1e100) == 0) {g_string_append(tempstring,"+inf");} else 
		    {
		    mpfr_set_z (&temp, &temp1.right, 0);
		    mpfr_div (&temp, &temp, &con1e30, 0);
		    mpfr_sprintf(sstr, "%RNg", &temp);
		    g_string_append(tempstring,sstr);
		    };
	    if (temp1.openright == TRUE) {g_string_append(tempstring,"[");} else {g_string_append(tempstring,"]");}

	    if (i!=intervalsize-1) {g_string_append(tempstring,"U"); }
	    }
	};