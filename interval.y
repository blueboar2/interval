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
%token PLUSINF MINUSINF UNIF
%token EXP LN SIN COS TAN COTAN TOZA IKS
%token ARCSIN ARCCOS ARCTAN
%token NUM
%left MINUS PLUS
%left MULTIPLY DIVIDE
%precedence NEG   /* negation--unary minus */
%right POWER        /* exponentiation */

%% /* The grammar follows.  */

intervalloop:      smallinterval
                 | mediuminterval
                 | largeinterval
                 | unifiedinterval

unifiedinterval:     OKRSKOB smallinterval ZKRSKOB UNIF intervalloop
                   | OKRSKOB mediuminterval ZKRSKOB UNIF intervalloop
                   | largeinterval UNIF intervalloop

largeinterval:     kvskob bexp TOZA bexp kvskob {
				mpz_init (&temp1.left);
				mpz_init (&temp1.right);
				
				if ($1 == ZKVSKOB) {temp1.openleft = true;} else {temp1.openleft = false;};
				if ($5 == OKVSKOB) {temp1.openright = true;} else {temp1.openright = false;};
				
				if ($4 == PLUSINF) { mpz_set(&temp1.right, &pcon1e100);};
				if ($4 == MINUSINF) {fprintf(stderr, "Minus infinity at right of interval"); exit(10);};
				if (($4 != MINUSINF) && ($4 != PLUSINF))
						    { temp = g_array_index (stack, __mpfr_struct, --stacksize);
						    stack = g_array_remove_index (stack, stacksize);
						    mpfr_mul (&temp, &temp, &con1e30, 0);
						    mpfr_get_z (&temp1.right, &temp, 0); };

				if ($2 == MINUSINF) { mpz_set(&temp1.left, &ocon1e100);};
				if ($2 == PLUSINF) {fprintf(stderr, "Plus infinity at left of interval"); exit(20);};
				if (($2 != MINUSINF) && ($1 != PLUSINF)) 
						    { temp = g_array_index (stack, __mpfr_struct, --stacksize);
						     stack = g_array_remove_index (stack, stacksize);
						     mpfr_mul (&temp, &temp, &con1e30, 0);
						     mpfr_get_z (&temp1.left, &temp, 0);
						     };

				gmp_printf ("Left %Zd\n", &temp1.left);
				gmp_printf ("Right %Zd\n", &temp1.right);

				if (mpz_cmp(&temp1.left, &temp1.right)>0) {fprintf(stderr, "Right interval must be larger than left"); exit(30);};
				if ((mpz_cmp(&temp1.left, &temp1.right) == 0) && ((temp1.openleft == true) || (temp1.openright == true))) 
				                   {fprintf(stderr, "Equal left and right sides must contain equality also"); exit(40);};

				g_array_append_val (intervals, temp1);
				intervalsize++;}

mediuminterval:    bexp leq IKS leq bexp	{
				mpz_init (&temp1.left);
				mpz_init (&temp1.right);

				if ($2 == LESS) {temp1.openleft = true;} else {temp1.openleft = false;};
				if ($4 == LESS) {temp1.openright = true;} else {temp1.openright = false;};

				if ($5 == PLUSINF) { mpz_set(&temp1.right, &pcon1e100);};
				if ($5 == MINUSINF) {fprintf(stderr, "Minus infinity at right of interval"); exit(10);};
				if (($5 != MINUSINF) && ($5 != PLUSINF))
						    { temp = g_array_index (stack, __mpfr_struct, --stacksize);
						    stack = g_array_remove_index (stack, stacksize);
						    mpfr_mul (&temp, &temp, &con1e30, 0);
						    mpfr_get_z (&temp1.right, &temp, 0); };

				if ($1 == MINUSINF) {mpz_set(&temp1.left, &ocon1e100);};
				if ($1 == PLUSINF) {fprintf(stderr, "Plus infinity at left of interval"); exit(20);};
				if (($1 != MINUSINF) && ($1 != PLUSINF)) 
						    { temp = g_array_index (stack, __mpfr_struct, --stacksize);
						     stack = g_array_remove_index (stack, stacksize);
						     mpfr_mul (&temp, &temp, &con1e30, 0);
						     mpfr_get_z (&temp1.left, &temp, 0);
						     };

				if (mpz_cmp(&temp1.left, &temp1.right)>0) {fprintf(stderr, "Right interval must be larger than left"); exit(30);};
				if ((mpz_cmp(&temp1.left, &temp1.right) == 0) && ((temp1.openleft == true) || (temp1.openright == true))) 
				                   {fprintf(stderr, "Equal left and right sides must contain equality also"); exit(40);};

				g_array_append_val (intervals, temp1);
				intervalsize++;}
                 | bexp geq IKS geq bexp	{
				mpz_init (&temp1.left);
				mpz_init (&temp1.right);

				if ($2 == GREATER) {temp1.openleft = true;} else {temp1.openleft = false;};
				if ($4 == GREATER) {temp1.openright = true;} else {temp1.openright = false;};

				if ($5 == MINUSINF) { mpz_set(&temp1.left, &ocon1e100);};
				if ($5 == PLUSINF) {fprintf(stderr, "Plus infinity at left of interval"); exit(10);};
				if (($5 != MINUSINF) && ($5 != PLUSINF))
						    { temp = g_array_index (stack, __mpfr_struct, --stacksize);
						    stack = g_array_remove_index (stack, stacksize);
						    mpfr_mul (&temp, &temp, &con1e30, 0);
						    mpfr_get_z (&temp1.left, &temp, 0); };

				if ($1 == PLUSINF) {mpz_set(&temp1.right, &pcon1e100);};
				if ($1 == MINUSINF) {fprintf(stderr, "Minus infinity at right of interval"); exit(20);};
				if (($1 != MINUSINF) && ($1 != PLUSINF)) 
						    { temp = g_array_index (stack, __mpfr_struct, --stacksize);
						     stack = g_array_remove_index (stack, stacksize);
						     mpfr_mul (&temp, &temp, &con1e30, 0);
						     mpfr_get_z (&temp1.right, &temp, 0);
						     };


				if (mpz_cmp(&temp1.left, &temp1.right)>0) {fprintf(stderr, "Right interval must be smaller than left"); exit(30);};
				if ((mpz_cmp(&temp1.left, &temp1.right) == 0) && ((temp1.openleft == true) || (temp1.openright == true))) 
				                   {fprintf(stderr, "Equal left and right sides must contain equality also"); exit(40);};

				g_array_append_val (intervals, temp1);
				intervalsize++;}

smallinterval:   IKS otnos exp
			    {
			    mpz_init (&temp1.left);
			    mpz_init (&temp1.right);
			
			    if (($2 == GREATER) || ($2 == GREATEREQUAL)) {
			     temp = g_array_index (stack, __mpfr_struct, --stacksize);
			     stack = g_array_remove_index (stack, stacksize);
			     mpfr_mul (&temp, &temp, &con1e30, 0);
			     mpfr_get_z (&temp1.left, &temp, 0);
			     temp1.openright = false;
			     mpz_set(&temp1.right, &pcon1e100);
			     if ($2 == GREATER) {temp1.openleft = false;} else {temp1.openleft = true;};
			    }
			    else
			    {
			     temp = g_array_index (stack, __mpfr_struct, --stacksize);
			     stack = g_array_remove_index (stack, stacksize);
			     mpfr_mul (&temp, &temp, &con1e30, 0);
			     mpfr_get_z (&temp1.right, &temp, 0);
			     temp1.openleft = false;
			     mpz_set(&temp1.left, &ocon1e100);
			     if ($2 == LESS) {temp1.openright = false;} else {temp1.openright = true;};
			    }

			    g_array_append_val (intervals, temp1);
			    intervalsize++;
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
			    stacksize++;
			    }
        | exp PLUS exp             { 
			    temp = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_add (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | exp MINUS exp            {
			    temp = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_sub (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | exp MULTIPLY exp          {
			    temp = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_mul (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | exp DIVIDE exp            {
			    temp = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_div (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | exp POWER exp             {
			    temp = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_pow (&result, &result, &temp, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | MINUS exp  %prec NEG     { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_neg (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | OKRSKOB exp ZKRSKOB      // value is on stack
        | EXP OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_exp (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | LN OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_log (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | SIN OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_sin (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | COS OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_cos (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | TAN OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_tan (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | ARCSIN OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_asin (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | ARCCOS OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_acos (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | ARCTAN OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_atan (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }
        | COTAN OKRSKOB exp ZKRSKOB   { 
			    result = g_array_index (stack, __mpfr_struct, --stacksize);
			    stack = g_array_remove_index (stack, stacksize);
			    mpfr_cot (&result, &result, 0);
			    g_array_append_val (stack, result);
			    stacksize++;
			    }

;
%%

int yyerror (char const *s) {
   fprintf (stderr, "%s near symbol %s\n", s, yytext);
   exit (2);
 }
