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
	
	// SORTING
	for (i=1; i<=intervalsize-1; i++)
	  {
	  for (j=i+1; j<=intervalsize; j++)
	    {
	      temp1 = g_array_index (intervals, struct interval, i-1);
	      temp2 = g_array_index (intervals, struct interval, j-1);

	      if (mpz_cmp(&temp1.left, &temp2.left)>0)
		{
		g_array_insert_val (intervals, i-1, temp2);
		g_array_insert_val (intervals, j-1, temp1);
		};
	    };
	  };
	
	//OPTIMIZING
	cur_pol = 1;
	
	while (cur_pol+1<=intervalsize)
	    {
		temp1 = g_array_index (intervals, struct interval, cur_pol-1);
		temp2 = g_array_index (intervals, struct interval, cur_pol);
		g_array_remove_index(intervals, cur_pol-1);
		g_array_remove_index(intervals, cur_pol-1);
		
		    printf ("Intervalsize: %d\n", intervalsize);
		    printf ("Cur_pol: %d\n", cur_pol);
		    gmp_printf("Temp1 Left: %Zd\n", &temp1.left);
		    gmp_printf("Temp1 Right: %Zd\n", &temp1.right);
		    gmp_printf("Temp2 Left: %Zd\n", &temp2.left);
		    gmp_printf("Temp2 Right: %Zd\n", &temp2.right);


		if (mpz_cmp(&temp1.left, &temp2.left) == 0)
		    {
		    if (mpz_cmp(&temp1.right, &temp2.right) < 0)
			{
			    if (temp1.openleft == FALSE) {temp2.openleft = FALSE; };
			    g_array_insert_val(intervals, cur_pol-1, temp2);
			    intervalsize--;
			}
		    else if (mpz_cmp(&temp1.right, &temp2.right) > 0)
			{
			    if (temp2.openleft == FALSE) {temp1.openleft = FALSE; };
			    g_array_insert_val(intervals, cur_pol-1, temp1);
			    intervalsize--;
			}
		    else if (mpz_cmp(&temp1.right, &temp2.right) == 0)
			{
			    if (temp2.openleft == FALSE) {temp1.openleft = FALSE; };
			    if (temp2.openright == FALSE) {temp1.openright = FALSE; };
			    g_array_insert_val(intervals, cur_pol-1, temp1);
			    intervalsize--;
			}
		    }
		else // SECOND INTERVAL BEGINNING IS BIGGER THAN FIRST
		if (mpz_cmp(&temp2.left, &temp1.right) < 0)
			{
			    if (mpz_cmp(&temp2.right, &temp1.right) < 0)
				{
				    intervalsize--;
				}
			    else if (mpz_cmp(&temp2.right, &temp1.right) == 0)
				{
				    if (temp2.openright == FALSE) {temp1.openright = FALSE; };
				    g_array_insert_val(intervals, cur_pol-1, temp1);
				    intervalsize--;
				}
			    else if (mpz_cmp(&temp2.right, &temp1.right) > 0)
				{
				    temp1.right = temp2.right;
				    temp1.openright = temp2.openright;
				    g_array_insert_val(intervals, cur_pol-1, temp1);
				    intervalsize--;
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
					    g_array_insert_val(intervals, cur_pol-1, temp1);
					    intervalsize--;
					}
				    else if (mpz_cmp(&temp2.right, &temp1.right) > 0)
					{
					    temp1.right = temp2.right;
					    temp1.openright = temp2.openright;
					    g_array_insert_val(intervals, cur_pol-1, temp1);
					    intervalsize--;
					}
				}
				else
				{
				    g_array_insert_val(intervals, cur_pol-1, temp2);
				    g_array_insert_val(intervals, cur_pol-1, temp1);
				    cur_pol++;	//TO NEXT INTERVAL
				}
			}
		else // CHECK THAT FIRST AND SECOND INTERVALS DO NOT INTERSET
		if (mpz_cmp(&temp2.left, &temp1.right) > 0)
			{
			    g_array_insert_val(intervals, cur_pol-1, temp2);
			    g_array_insert_val(intervals, cur_pol-1, temp1);
			    cur_pol++;	//TO NEXT INTERVAL
			}
	    }
	};
