#include "main.h"

void tostring ()
	{
	int i;
	char sstr[20000];
	tempstring = g_string_new(NULL);

	uarray = g_array_index (intervals, GArray *, 0);

	if (uarray->len!=0)	//EMPTY INTERVAL LOOP
	{

	for (i=0; i<=uarray->len-1; i++)
	    {
	    temp1 = g_array_index (uarray, struct interval, i);

	    if (temp1.openleft == TRUE) {g_string_append(tempstring,"]");} else {g_string_append(tempstring,"[");}
	    if (mpz_cmp (&temp1.left, &ocon1e100) == 0) {g_string_append(tempstring,"-inf");} else 
		    {
		    mpfr_set_z (&temp, &temp1.left, 0);
		    mpfr_div (&temp, &temp, &con1e30, 0);
		    mpfr_sprintf(sstr, "%.30RNf", &temp);
		    g_string_append(tempstring,sstr);
		    };
	    g_string_append(tempstring,";");
	    if (mpz_cmp (&temp1.right, &pcon1e100) == 0) {g_string_append(tempstring,"+inf");} else 
		    {
		    mpfr_set_z (&temp, &temp1.right, 0);
		    mpfr_div (&temp, &temp, &con1e30, 0);
		    mpfr_sprintf(sstr, "%.30RNf", &temp);
		    g_string_append(tempstring,sstr);
		    };
	    if (temp1.openright == TRUE) {g_string_append(tempstring,"[");} else {g_string_append(tempstring,"]");}

	    if (i!=uarray->len-1) {g_string_append(tempstring,"U"); }
	    }
	    } //EMPTY INTERVAL LOOP
	    else
	    {
	    sprintf (sstr, "NONE");
	    g_string_append(tempstring,sstr);
	    };
	};