/* Infix notation calculator.  */

%{
  #include <math.h>
  #include <stdio.h>
  #include <mpfr.h>
  extern char *yytext;
  extern mpfr_t result;
  int yylex (void);
  #define YYSTYPE int

  mpfr_t stack[100];
  mpfr_ptr sp = stack[0];

%}

/* Bison declarations.  */
//%define api.value.type {mpf_t}

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

exp:
  NUM                      { sp++;
			    mpfr_init (sp);
			    mpfr_set_str (sp, yytext, 10, 0); }
| exp PLUS exp             { sp--; mpfr_add (sp, sp, sp+1, 0);  mpfr_set (result, sp, 0); }
| exp MINUS exp            { sp--; mpfr_sub (sp, sp, sp+1, 0);  mpfr_set (result, sp, 0); }
| exp MULTIPLY exp         { sp--; mpfr_mul (sp, sp, sp+1, 0);  mpfr_set (result, sp, 0); }
| exp DIVIDE exp           { sp--; mpfr_div (sp, sp, sp+1, 0);  mpfr_set (result, sp, 0); }
| MINUS exp  %prec NEG     { mpfr_neg (sp, sp, 0);  mpfr_set (result, sp, 0); }
| exp POWER exp            { sp--; mpfr_pow (sp, sp, sp+1, 0);  mpfr_set (result, sp, 0); }
| OKRSKOB exp ZKRSKOB      // value is on stack
| EXP OKRSKOB exp ZKRSKOB	{ mpfr_exp (sp, sp, 0);  mpfr_set (result, sp, 0);  }
| LN OKRSKOB exp ZKRSKOB	{ mpfr_log (sp, sp, 0);  mpfr_set (result, sp, 0);  }
| SIN OKRSKOB exp ZKRSKOB	{ mpfr_sin (sp, sp, 0);  mpfr_set (result, sp, 0);  }
| COS OKRSKOB exp ZKRSKOB	{ mpfr_cos (sp, sp, 0);  mpfr_set (result, sp, 0);  }
| TAN OKRSKOB exp ZKRSKOB	{ mpfr_tan (sp, sp, 0);  mpfr_set (result, sp, 0);  }
| ARCSIN OKRSKOB exp ZKRSKOB	{ mpfr_asin (sp, sp, 0);  mpfr_set (result, sp, 0);  }
| ARCCOS OKRSKOB exp ZKRSKOB	{ mpfr_acos (sp, sp, 0);  mpfr_set (result, sp, 0);  }
| ARCTAN OKRSKOB exp ZKRSKOB	{ mpfr_atan (sp, sp, 0);  mpfr_set (result, sp, 0);  }
| COTAN OKRSKOB exp ZKRSKOB	{ mpfr_cot (sp, sp, 0);  mpfr_set (result, sp, 0);  }

;
%%

int yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
   return 1;
 }
