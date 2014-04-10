/* Infix notation calculator.  */

%{
  extern char *yytext;
  int yylex (void);
  #define YYSTYPE int
  #include "main.h"

%}

/* Bison declarations.  */
%token OKRSKOB ZKRSKOB OKVSKOB ZKVSKOB
%token LESS GREATER LESSEQUAL GREATEREQUAL
%token PLUSINF MINUSINF UNIF PERE ZAP
%token EXP LN SIN COS TAN COTAN TOZA IKS
%token ARCSIN ARCCOS ARCTAN
%token SQRT ROOT ABS NEG
%token NUM
%left MINUS PLUS
%left MULTIPLY DIVIDE
%left NEG   /* negation--unary minus */
%left PERE UNIF /* unification/intersection is from left to right */
%right POWER        /* exponentiation */

%% /* The grammar follows.  */

intervalloop:      OKRSKOB intervalloop ZKRSKOB				//Do nothing, but do first! (Put on stack)
                 | intervalloop PERE intervalloop			{ intersectinterval(); };
                 | intervalloop UNIF intervalloop			{ unifyinterval(); };
                 | largeinterval
                 | mediuminterval
                 | smallinterval

largeinterval:     kvskob bexp TOZA bexp kvskob {
				mpz_init (&temp1.left);
				mpz_init (&temp1.right);
				
				if ($1 == ZKVSKOB) {temp1.openleft = true;} else {temp1.openleft = false;};
				if ($5 == OKVSKOB) {temp1.openright = true;} else {temp1.openright = false;};
				
				if ($4 == PLUSINF) { mpz_set(&temp1.right, &pcon1e100);};
				if ($4 == MINUSINF) {fprintf(stderr, "Minus infinity at right of interval\n"); exit(10);};
				if (($4 != MINUSINF) && ($4 != PLUSINF))
						    { temp = g_array_index (stack, __mpfr_struct, stack->len-1);
						    stack = g_array_remove_index (stack, stack->len-1);
						    mpfr_mul (&temp, &temp, &con1e30, 0);
						    mpfr_get_z (&temp1.right, &temp, 0); };

				if ($2 == MINUSINF) { mpz_set(&temp1.left, &ocon1e100);};
				if ($2 == PLUSINF) {fprintf(stderr, "Plus infinity at left of interval\n"); exit(20);};
				if (($2 != MINUSINF) && ($1 != PLUSINF)) 
						    { temp = g_array_index (stack, __mpfr_struct, stack->len-1);
						     stack = g_array_remove_index (stack, stack->len-1);
						     mpfr_mul (&temp, &temp, &con1e30, 0);
						     mpfr_get_z (&temp1.left, &temp, 0);
						     };

				if (mpz_cmp(&temp1.left, &temp1.right)>0) {fprintf(stderr, "Right interval must be larger than left\n"); exit(30);};
				if ((mpz_cmp(&temp1.left, &temp1.right) == 0) && ((temp1.openleft == true) || (temp1.openright == true))) 
				                   {fprintf(stderr, "Equal left and right sides must contain equality also\n"); exit(40);};

				uarray = g_array_new(FALSE, FALSE, sizeof(temp1));
				g_array_append_val (uarray, temp1);
				g_array_append_val (intervals, uarray);

				if (($2 == MINUSINF) && (temp1.openleft == FALSE))
				    {fprintf(stderr, "Infinities must be open, not closed\n"); exit(50);};
				if (($4 == PLUSINF) && (temp1.openright == FALSE))
				    {fprintf(stderr, "Infinities must be open, not closed\n"); exit(50);};
				}

mediuminterval:    bexp leq IKS leq bexp	{
				mpz_init (&temp1.left);
				mpz_init (&temp1.right);

				if ($2 == LESS) {temp1.openleft = true;} else {temp1.openleft = false;};
				if ($4 == LESS) {temp1.openright = true;} else {temp1.openright = false;};

				if ($5 == PLUSINF) { mpz_set(&temp1.right, &pcon1e100);};
				if ($5 == MINUSINF) {fprintf(stderr, "Minus infinity at right of interval\n"); exit(10);};
				if (($5 != MINUSINF) && ($5 != PLUSINF))
						    { temp = g_array_index (stack, __mpfr_struct, stack->len-1);
						    stack = g_array_remove_index (stack, stack->len-1);
						    mpfr_mul (&temp, &temp, &con1e30, 0);
						    mpfr_get_z (&temp1.right, &temp, 0); };

				if ($1 == MINUSINF) {mpz_set(&temp1.left, &ocon1e100);};
				if ($1 == PLUSINF) {fprintf(stderr, "Plus infinity at left of interval\n"); exit(20);};
				if (($1 != MINUSINF) && ($1 != PLUSINF)) 
						    { temp = g_array_index (stack, __mpfr_struct, stack->len-1);
						     stack = g_array_remove_index (stack, stack->len-1);
						     mpfr_mul (&temp, &temp, &con1e30, 0);
						     mpfr_get_z (&temp1.left, &temp, 0);
						     };

				if (mpz_cmp(&temp1.left, &temp1.right)>0) {fprintf(stderr, "Right interval must be larger than left\n"); exit(30);};
				if ((mpz_cmp(&temp1.left, &temp1.right) == 0) && ((temp1.openleft == true) || (temp1.openright == true))) 
				                   {fprintf(stderr, "Equal left and right sides must contain equality also\n"); exit(40);};

				uarray = g_array_new(FALSE, FALSE, sizeof(temp1));
				g_array_append_val (uarray, temp1);
				g_array_append_val (intervals, uarray);

				if (($1 == MINUSINF) && (temp1.openleft == FALSE))
				    {fprintf(stderr, "Infinities must be open, not closed\n"); exit(50);};
				if (($5 == PLUSINF) && (temp1.openright == FALSE))
				    {fprintf(stderr, "Infinities must be open, not closed\n"); exit(50);};
				
				}
                 | bexp geq IKS geq bexp	{
				mpz_init (&temp1.left);
				mpz_init (&temp1.right);

				if ($2 == GREATER) {temp1.openleft = true;} else {temp1.openleft = false;};
				if ($4 == GREATER) {temp1.openright = true;} else {temp1.openright = false;};

				if ($5 == MINUSINF) { mpz_set(&temp1.left, &ocon1e100);};
				if ($5 == PLUSINF) {fprintf(stderr, "Plus infinity at left of interval\n"); exit(10);};
				if (($5 != MINUSINF) && ($5 != PLUSINF))
						    { temp = g_array_index (stack, __mpfr_struct, stack->len-1);
						    stack = g_array_remove_index (stack, stack->len-1);
						    mpfr_mul (&temp, &temp, &con1e30, 0);
						    mpfr_get_z (&temp1.left, &temp, 0); };

				if ($1 == PLUSINF) {mpz_set(&temp1.right, &pcon1e100);};
				if ($1 == MINUSINF) {fprintf(stderr, "Minus infinity at right of interval\n"); exit(20);};
				if (($1 != MINUSINF) && ($1 != PLUSINF)) 
						    { temp = g_array_index (stack, __mpfr_struct, stack->len-1);
						     stack = g_array_remove_index (stack, stack->len-1);
						     mpfr_mul (&temp, &temp, &con1e30, 0);
						     mpfr_get_z (&temp1.right, &temp, 0);
						     };


				if (mpz_cmp(&temp1.left, &temp1.right)>0) {fprintf(stderr, "Right interval must be smaller than left\n"); exit(30);};
				if ((mpz_cmp(&temp1.left, &temp1.right) == 0) && ((temp1.openleft == true) || (temp1.openright == true))) 
				                   {fprintf(stderr, "Equal left and right sides must contain equality also\n"); exit(40);};

				uarray = g_array_new(FALSE, FALSE, sizeof(temp1));
				g_array_append_val (uarray, temp1);
				g_array_append_val (intervals, uarray);

				if (($5 == MINUSINF) && (temp1.openleft == FALSE))
				    {fprintf(stderr, "Infinities must be open, not closed\n"); exit(50);};
				if (($1 == PLUSINF) && (temp1.openright == FALSE))
				    {fprintf(stderr, "Infinities must be open, not closed\n"); exit(50);};
				}

smallinterval:   IKS otnos exp
			    {
			    mpz_init (&temp1.left);
			    mpz_init (&temp1.right);
			
			    if (($2 == GREATER) || ($2 == GREATEREQUAL)) {
			     temp = g_array_index (stack, __mpfr_struct, stack->len-1);
			     stack = g_array_remove_index (stack, stack->len-1);
			     mpfr_mul (&temp, &temp, &con1e30, 0);
			     mpfr_get_z (&temp1.left, &temp, 0);
			     temp1.openright = true;
			     mpz_set(&temp1.right, &pcon1e100);
			     if ($2 == GREATER) {temp1.openleft = true;} else {temp1.openleft = false;};
			    }
			    else
			    {
			     temp = g_array_index (stack, __mpfr_struct, stack->len-1);
			     stack = g_array_remove_index (stack, stack->len-1);
			     mpfr_mul (&temp, &temp, &con1e30, 0);
			     mpfr_get_z (&temp1.right, &temp, 0);
			     temp1.openleft = true;
			     mpz_set(&temp1.left, &ocon1e100);
			     if ($2 == LESS) {temp1.openright = true;} else {temp1.openright = false;};
			    }

				uarray = g_array_new(FALSE, FALSE, sizeof(temp1));
				g_array_append_val (uarray, temp1);
				g_array_append_val (intervals, uarray);
			    }

otnos:    LESS 			   {$$ = LESS;}
        | GREATER		   {$$ = GREATER;}
        | LESSEQUAL		   {$$ = LESSEQUAL;}
        | GREATEREQUAL		   {$$ = GREATEREQUAL;}

kvskob:   OKVSKOB		   {$$ = OKVSKOB;}
        | ZKVSKOB		   {$$ = ZKVSKOB;}

geq:      GREATER		   {$$ = GREATER;}
        | GREATEREQUAL		   {$$ = GREATEREQUAL;}

leq:      LESS			   {$$ = LESS;}
        | LESSEQUAL		   {$$ = LESSEQUAL;}

bexp:     exp			   {$$ = NUM;}
        | MINUSINF		   {$$ = MINUSINF;}
        | PLUSINF		   {$$ = PLUSINF;}

exp:      NUM                      {
			    mpfr_init (&temp);
			    mpfr_set_str (&temp, yytext, 10, 0);
			    g_array_append_val (stack, temp);
			    }
        | exp PLUS exp             { 
			    temp = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_add (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    }
        | exp MINUS exp            {
			    temp = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_sub (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    }
        | exp MULTIPLY exp          {
			    temp = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_mul (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    }
        | exp DIVIDE exp            {
			    temp = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_div (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    }
        | exp POWER exp             {
			    temp = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_pow (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    }
        | MINUS exp         { 
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_neg (&result, &result, 0);
			    g_array_append_val (stack, result);
			    }
        | OKRSKOB exp ZKRSKOB      // value is on stack
        | ROOT OKRSKOB exp ZAP exp ZKRSKOB
			    {
			    temp = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    if (mpfr_cmp(&temp, &con0)<=0) {fprintf(stderr, "error, root: negative power or zero\n"); exit(1500);};
			    if (mpfr_cmp(&result, &con0)<=0)
			    {
			    templong = mpfr_get_si (&temp, 0);
			    mpfr_root(&result, &result, templong, 0);
			    }
			    else
			    {
			    mpfr_div(&temp, &con1, &temp, 0);
			    mpfr_pow (&result, &result, &temp, 0);
			    };
			    g_array_append_val (stack, result);
			    }
        | EXP OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_exp (&result, &result, 0);
			    g_array_append_val (stack, result);
			    }
        | LN OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_log (&result, &result, 0);
			    g_array_append_val (stack, result);
			    }
        | SIN OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_sin (&result, &result, 0);
			    g_array_append_val (stack, result);
			    }
        | COS OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_cos (&result, &result, 0);
			    g_array_append_val (stack, result);
			    }
        | TAN OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_tan (&result, &result, 0);
			    g_array_append_val (stack, result);
			    }
        | ARCSIN OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_asin (&result, &result, 0);
			    g_array_append_val (stack, result);
			    }
        | ARCCOS OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_acos (&result, &result, 0);
			    g_array_append_val (stack, result);
			    }
        | ARCTAN OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_atan (&result, &result, 0);
			    g_array_append_val (stack, result);
			    }
        | COTAN OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_cot (&result, &result, 0);
			    g_array_append_val (stack, result);
			    }
        | SQRT OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_sqrt (&result, &result, 0);
			    g_array_append_val (stack, result);
			    }
        | ABS OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_abs (&result, &result, 0);
			    g_array_append_val (stack, result);
			    }
        | NEG OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, stack->len-1);
			    stack = g_array_remove_index (stack, stack->len-1);
			    mpfr_neg (&result, &result, 0);
			    g_array_append_val (stack, result);
			    }
;
%%

int yyerror (char const *s) {
   fprintf (stderr, "%s near symbol %s\n", s, yytext);
   exit (2);
 }
