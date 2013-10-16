%{
#include "interval.tab.h"
%}

%%
[0-9]*[\.\,]?[0-9]+([eE][-+]?[0-9]+)?			{ mpf_init2(yylval,10000); gmp_sscanf (yytext, "%F", &yylval); return NUM; }
"+inf"							{ return PLUSINF; }
"-inf"							{ return MINUSINF; }
"U"							{ return UNIF; }

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
"cotan"							{ return COTAN; }
"ctan"							{ return COTAN; }
"ctg"							{ return COTAN; }

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

.							{ return 0; }
%%
