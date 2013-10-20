/* Infix notation calculator.  */

%{
  #include <stdio.h>
  extern char *yytext;
  int yylex (void);
  #define YYSTYPE int
  #include <mpfr.h>
  #include <glib.h>
  #include <assert.h>
  extern __mpfr_struct result, temp;
  extern GArray *stack;
  extern gint stacksize;

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
  NUM                      {
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
