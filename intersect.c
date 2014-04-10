#include "main.h"

void intersectinterval ()
	{
	uarray2 = g_array_index (intervals, GArray *, intervals->len-1);
	g_array_remove_index(intervals, intervals->len-1);

	uarray = g_array_index (intervals, GArray *, intervals->len-1);
	g_array_remove_index(intervals, intervals->len-1);

	uarray3 = g_array_new (FALSE, FALSE, sizeof(temp1));

	int uk1 = 0, uk2 = 0;
	mpz_init(&temp3.left);
	mpz_init(&temp3.right);

	while ((uk1!=uarray->len) && (uk2!=uarray2->len))
	    {
	    temp1 = g_array_index (uarray, struct interval, uk1);
	    temp2 = g_array_index (uarray2, struct interval, uk2);

	    if (mpz_cmp(&temp1.left, &temp2.left) < 0)
	    {
	    // SWAP TWO
	    uarray4 = uarray;
	    uarray = uarray2;
	    uarray2 = uarray4;
	    }

	    if (mpz_cmp(&temp1.left, &temp2.left) == 0)
		{
		if (mpz_cmp(&temp1.right, &temp2.right) == 0)
		    {
		    temp3.openleft = FALSE;
		    temp3.openright = FALSE;
		    if ((temp1.openleft == TRUE) || (temp2.openleft == TRUE)) {temp3.openleft = TRUE;};
		    if ((temp1.openright == TRUE) || (temp2.openright == TRUE)) {temp3.openright = TRUE;};
		    mpz_init_set(&temp3.left, &temp1.left);
		    mpz_init_set(&temp3.right, &temp1.right);
		    g_array_prepend_val(uarray3, temp3);
		    uk1++; uk2++;
		    }
		else
		if (mpz_cmp(&temp1.right, &temp2.right) > 0)
		    {
		    temp3.openleft = FALSE;
		    temp3.openright = temp2.openright;
		    if ((temp1.openleft == TRUE) || (temp2.openleft == TRUE)) {temp3.openleft = TRUE;};
		    mpz_init_set(&temp3.left, &temp1.left);
		    mpz_init_set(&temp3.right, &temp2.right);
		    g_array_prepend_val(uarray3, temp3);
		    uk2++;
		    }
		else //<0
		    {
		    temp3.openleft = FALSE;
		    temp3.openright = temp1.openright;
		    if ((temp1.openleft == TRUE) || (temp2.openleft == TRUE)) {temp3.openleft = TRUE;};
		    mpz_init_set(&temp3.left, &temp1.left);
		    mpz_init_set(&temp3.right, &temp1.right);
		    g_array_prepend_val(uarray3, temp3);
		    uk1++;
		    };
		}
	    else
	    if (mpz_cmp(&temp1.left, &temp2.left) > 0)
		{
		if (mpz_cmp(&temp2.right, &temp1.left) < 0)
			{ uk2++; }
		else
		if (mpz_cmp(&temp2.right, &temp1.left) == 0)
		    {
		    if ((temp1.openleft == FALSE) && (temp2.openright == FALSE)) {
		    temp3.openleft = FALSE;
		    temp3.openright = FALSE;
		    mpz_init_set(&temp3.left, &temp1.left);
		    mpz_init_set(&temp3.right, &temp1.left);
		    g_array_prepend_val(uarray3, temp3); };	// else it is one opened number
		    uk2++;
		    }
		else //temp2.right > temp1.left
		    {
			if (mpz_cmp(&temp2.right, &temp1.right) < 0)
			{
			temp3.openleft = temp1.openleft;
			temp3.openright = temp2.openright;
			mpz_init_set(&temp3.left, &temp1.left);
			mpz_init_set(&temp3.right, &temp2.right);
			g_array_prepend_val(uarray3, temp3);
			uk2++;
			}
			else
			if (mpz_cmp(&temp2.right, &temp1.right) == 0)
			{
			temp3.openleft = temp1.openleft;
			temp3.openright = FALSE;
			if ((temp1.openright == TRUE) || (temp2.openright == TRUE)) {temp3.openright = TRUE; };
			mpz_init_set(&temp3.left, &temp1.left);
			mpz_init_set(&temp3.right, &temp2.right);
			g_array_prepend_val(uarray3, temp3);
			uk1++; uk2++;
			}
			else	//temp2.right > temp1.right
			{
			temp3.openleft = temp1.openleft;
			temp3.openright = temp1.openright;
			mpz_init_set(&temp3.left, &temp1.left);
			mpz_init_set(&temp3.right, &temp1.right);
			g_array_prepend_val(uarray3, temp3);
			uk1++;
			}; //END SUBCASE
		    }; //END CASE
		};
	    }; // END WHILE LOOP
	g_array_free(uarray, TRUE);
	g_array_free(uarray2, TRUE);
	g_array_prepend_val(intervals, uarray3);
	optimize();
	}; // FUNCTION LOOP
