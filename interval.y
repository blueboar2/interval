/* Infix notation calculator.  */

%{
  #define YYSTYPE mpf_t
  #include <math.h>
  #include <stdio.h>
  #include <gmp.h>
  extern mpf_t result;
  int yylex (void);

%}

/* Bison declarations.  */
//%define api.value.type {mpf_t}
%token OKRSKOB ZKRSKOB OKVSKOB ZKVSKOB
%token LESS GREATER LESSEQUAL GREATEREQUAL
%token PLUSINF MINUSINF UNIF
%token EXP LN SIN COS TAN COTAN TOZA
%token NUM IKS
%left MINUS PLUS
%left MULTIPLY DIVIDE
%precedence NEG   /* negation--unary minus */
%right POWER        /* exponentiation */

%% /* The grammar follows.  */

exp:
  NUM                   { mpf_init2($$, 10000); mpf_set($$,yylval); mpf_set(result,$$); }
//| exp PLUS exp          { $$ = $1 + $3;  result = $$;     }
//| exp MINUS exp         { $$ = $1 - $3;  result = $$;     }
//| exp MULTIPLY exp      { $$ = $1 * $3;  result = $$;     }
//| exp DIVIDE exp        { $$ = $1 / $3;  result = $$;     }
//| MINUS exp  %prec NEG  { $$ = -$2;  result = $$;         }
//| exp POWER exp         { $$ = pow ($1, $3); result = $$; }
//| OKRSKOB exp ZKRSKOB   { $$ = $2; result = $$;           }
//| EXP exp               { $$ = exp($2); result = $$;      }
//| LN exp		{ $$ = log($2); result = $$;      }
//| SIN exp		{ $$ = sin($2); result = $$;      }
//| COS exp		{ $$ = cos($2); result = $$;      }
//| TAN exp		{ $$ = tan($2); result = $$;      }
//| COTAN exp		{ $$ = 1/tan($2); result = $$;    }

;
%%

int yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
   return 1;
 }
