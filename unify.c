#include "main.h"

void unifyinterval ()
	{
	uarray = g_array_index (intervals, GArray *, 0);
	g_array_remove_index(intervals, 0);

	uarray2 = g_array_index (intervals, GArray *, 0);
	g_array_remove_index(intervals, 0);

	while (uarray2->len!=0)
	    {
	    temp2 = g_array_index (uarray2, struct interval, 0);
	    g_array_remove_index(uarray2, 0);
	    g_array_prepend_val(uarray, temp2);
	    };
	
	g_array_free(uarray2, TRUE);
	g_array_prepend_val(intervals, uarray);
	optimize();
	}; // FUNCTION LOOP
