all:		interval

interval:	main.o
	gcc -shared -o interval.dll -LC:\MINGW\MSYS\1.0\LIB -IC:\MINGW\INCLUDE\GLIB-2.0 -IC:\MINGW\LIB\GLIB-2.0\INCLUDE interval.tab.o lex.yy.o optimize.o tostring.o init.o unify.o intersect.o main.o -lmpfr -lgmp -lfl -lm -lglib-2.0

main.o:		interval.tab.o lex.yy.o optimize.o tostring.o init.o unify.o intersect.o
	gcc -IC:\MINGW\INCLUDE\GLIB-2.0 -IC:\MINGW\LIB\GLIB-2.0\INCLUDE -c main.c

init.o:
	gcc -IC:\MINGW\INCLUDE\GLIB-2.0 -IC:\MINGW\LIB\GLIB-2.0\INCLUDE -c init.c

optimize.o:
	gcc -IC:\MINGW\INCLUDE\GLIB-2.0 -IC:\MINGW\LIB\GLIB-2.0\INCLUDE -c optimize.c

tostring.o:
	gcc -IC:\MINGW\INCLUDE\GLIB-2.0 -IC:\MINGW\LIB\GLIB-2.0\INCLUDE -c tostring.c

unify.o:
	gcc -IC:\MINGW\INCLUDE\GLIB-2.0 -IC:\MINGW\LIB\GLIB-2.0\INCLUDE -c unify.c

intersect.o:
	gcc -IC:\MINGW\INCLUDE\GLIB-2.0 -IC:\MINGW\LIB\GLIB-2.0\INCLUDE -c intersect.c

interval.tab.o:
	bison -d interval.y
	gcc -IC:\MINGW\INCLUDE\GLIB-2.0 -IC:\MINGW\LIB\GLIB-2.0\INCLUDE -c interval.tab.c

lex.yy.o:
	flex --header-file=interval.lex.h lexer.c
	gcc -IC:\MINGW\INCLUDE\GLIB-2.0 -IC:\MINGW\LIB\GLIB-2.0\INCLUDE -c lex.yy.c
