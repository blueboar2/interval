all:		interval

clean:
	rm -rf *.o interval
	rm -rf *.o
	rm -rf lex.yy.*
	rm -rf interval.lex.*
	rm -rf interval.tab.*
	rm -rf *.so

interval:	main.o
	gcc -shared -o interval.so -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include unify.o intersect.o interval.tab.o lex.yy.o optimize.o tostring.o init.o main.o -lmpfr -lgmp -lfl -lm -lglib-2.0

main.o:		interval.tab.o lex.yy.o optimize.o tostring.o init.o unify.o intersect.o
	gcc  -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -fpic -c main.c

init.o:
	gcc  -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -fpic -c init.c

unify.o:
	gcc  -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -fpic -c unify.c

intersect.o:
	gcc  -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -fpic -c intersect.c

optimize.o:
	gcc  -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -fpic -c optimize.c

tostring.o:
	gcc  -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -fpic -c tostring.c

interval.tab.o:
	bison -d interval.y
	gcc -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -fpic -c interval.tab.c

lex.yy.o:
	flex --header-file=interval.lex.h lexer.c
	gcc  -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -fpic -c lex.yy.c
