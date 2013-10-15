all:		interval

clean:
	rm -rf *.o interval
	rm -rf *.o
	rm -rf lex.yy.*
	rm -rf interval.lex.*
	rm -rf interval.tab.*

interval:	main.o
	gcc -o interval -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include interval.tab.o lex.yy.o main.o -lmpfr -lgmp -lfl -lm -lglib-2.0

main.o:		interval.tab.o lex.yy.o
	gcc -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -c main.c

interval.tab.o:
	bison -d interval.y
	gcc -c interval.tab.c

lex.yy.o:
	flex --header-file=interval.lex.h lexer.c
	gcc -c lex.yy.c
