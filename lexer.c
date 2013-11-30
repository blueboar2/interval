%{
#include "interval.tab.h"
#include "main.h"
%}

%%
[0-9]*[\.\,]?[0-9]+([eE][-+]?[0-9]+)?			{ return NUM; }

"+inf"							{ return PLUSINF; }
"-inf"							{ return MINUSINF; }
"U"							{ return UNIF; }

"++"							{ printf ("cannot parse ++\n");
							  exit(4); }
"+-"							{ printf ("cannot parse +-\n");
							  exit(4); }
"-+"							{ printf ("cannot parse -+\n");
							  exit(4); }
"--"							{ printf ("cannot parse --\n");
							  exit(4); }

"<="							{ return LESSEQUAL; }
">="							{ return GREATEREQUAL; }
"<"							{ return LESS; }
">"							{ return GREATER; }

"exp"							{ return EXP; }
"ln"							{ return LN; }
"sin"							{ return SIN; }
"cos"							{ return COS; }
"tan"							{ return TAN; }
"tg"							{ return TAN; }
"cot"							{ return COTAN; }
"ctg"							{ return COTAN; }
"asin"							{ return ARCSIN; }
"arcsin"						{ return ARCSIN; }
"acos"							{ return ARCCOS; }
"arccos"						{ return ARCCOS; }
"atan"							{ return ARCTAN; }
"arctg"							{ return ARCTAN; }

"**"							{ return POWER; }

"+"							{ return PLUS; }
"-"							{ return MINUS; }
"*"							{ return MULTIPLY; }
"/"							{ return DIVIDE; }
"("							{ return OKRSKOB; }
")"							{ return ZKRSKOB; }
"["							{ return OKVSKOB; }
"]"							{ return ZKVSKOB; }
";"							{ return TOZA; }
"^"							{ return POWER; }

"x"							{ return IKS; }

.							{ printf ("cannot parse %s\n", yytext);
							  exit(1); }
%%
