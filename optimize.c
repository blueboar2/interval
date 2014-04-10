#include "main.h"

void optimize ()
	{
	int i,j;
	int cur_pol;

	// INITIALIZATION
	mpz_init(&temp1.left);
	mpz_init(&temp1.right);
	mpz_init(&temp2.left);
	mpz_init(&temp2.right);

	uarray = g_array_index (intervals, GArray *, 0);
	if (uarray->len > 0)
	{ // empty interval is interval too

	// SORTING
	for (i=1; i<=uarray->len-1; i++)
	  {
	  for (j=i+1; j<=uarray->len; j++)
	    {
	      temp1 = g_array_index (uarray, struct interval, i-1);
	      temp2 = g_array_index (uarray, struct interval, j-1);

	      if (mpz_cmp(&temp1.left, &temp2.left)>0)
		{
		g_array_remove_index (uarray, i-1);
		g_array_insert_val (uarray, i-1, temp2);
		g_array_remove_index (uarray, j-1);
		g_array_insert_val (uarray, j-1, temp1);
		};
	    };
	  };

	//OPTIMIZING
	cur_pol = 1;
	
	while (cur_pol+1<=uarray->len)
	    {
		temp1 = g_array_index (uarray, struct interval, cur_pol-1);
		temp2 = g_array_index (uarray, struct interval, cur_pol);
		g_array_remove_index(uarray, cur_pol-1);
		g_array_remove_index(uarray, cur_pol-1);

		if (mpz_cmp(&temp1.left, &temp2.left) == 0)
		    {
		    if (mpz_cmp(&temp1.right, &temp2.right) < 0)
			{
			    if (temp1.openleft == FALSE) {temp2.openleft = FALSE; };
			    g_array_insert_val(uarray, cur_pol-1, temp2);
			}
		    else if (mpz_cmp(&temp1.right, &temp2.right) > 0)
			{
			    if (temp2.openleft == FALSE) {temp1.openleft = FALSE; };
			    g_array_insert_val(uarray, cur_pol-1, temp1);
			}
		    else if (mpz_cmp(&temp1.right, &temp2.right) == 0)
			{
			    if (temp2.openleft == FALSE) {temp1.openleft = FALSE; };
			    if (temp2.openright == FALSE) {temp1.openright = FALSE; };
			    g_array_insert_val(uarray, cur_pol-1, temp1);
			}
		    }
		else // SECOND INTERVAL BEGINNING IS BIGGER THAN FIRST
		if (mpz_cmp(&temp2.left, &temp1.right) < 0)
			{
			    if (mpz_cmp(&temp2.right, &temp1.right) < 0)
				{
				    g_array_insert_val(uarray, cur_pol-1, temp1);
				}
			    else if (mpz_cmp(&temp2.right, &temp1.right) == 0)
				{
				    if (temp2.openright == FALSE) {temp1.openright = FALSE; };
				    g_array_insert_val(uarray, cur_pol-1, temp1);
				}
			    else if (mpz_cmp(&temp2.right, &temp1.right) > 0)
				{
				    temp1.right = temp2.right;
				    temp1.openright = temp2.openright;
				    g_array_insert_val(uarray, cur_pol-1, temp1);
				}
			}
		else // CHECK THAT SECOND BEGINS WHERE FIRST ENDS
		if (mpz_cmp(&temp2.left, &temp1.right) == 0)
			{
			    if ((temp1.openright == FALSE) || (temp2.openleft == FALSE))
				{
				    if (mpz_cmp(&temp2.right, &temp1.right) == 0)
					{
					    if (temp2.openright == FALSE) {temp1.openright = FALSE; };
					    g_array_insert_val(uarray, cur_pol-1, temp1);
					}
				    else if (mpz_cmp(&temp2.right, &temp1.right) > 0)
					{
					    temp1.right = temp2.right;
					    temp1.openright = temp2.openright;
					    g_array_insert_val(uarray, cur_pol-1, temp1);
					}
				}
				else
				{
				    g_array_insert_val(uarray, cur_pol-1, temp2);
				    g_array_insert_val(uarray, cur_pol-1, temp1);
				    cur_pol++;	//TO NEXT INTERVAL
				}
			}
		else // CHECK THAT FIRST AND SECOND INTERVALS DO NOT INTERSECT
		if (mpz_cmp(&temp2.left, &temp1.right) > 0)
			{
			    g_array_insert_val(uarray, cur_pol-1, temp2);
			    g_array_insert_val(uarray, cur_pol-1, temp1);
			    cur_pol++;	//TO NEXT INTERVAL
			}
	    } // WHILE LOOP

g_array_remove_index (intervals, 0);
g_array_prepend_val (intervals, uarray);

	}; // EMPTY INTERVAL LOOP
	}; // FUNCTION LOOP