all:		interval

clean:
	rm -rf *.o interval
	rm -rf *.o
	rm -rf lex.yy.*

interval:	main.o
	gcc -o interval -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include lex.yy.o simple_interval.o parse_string.o main.o -lmpfr -lgmp -lfl -lglib-2.0

main.o:		simple_interval.o parse_string.o
	gcc -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -c main.c

parse_string.o:	lex.yy.o
	gcc -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -c parse_string.c

simple_interval.o:
	gcc -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -c simple_interval.c

lex.yy.o:
	flex --header-file=lex.yy.h lexer.c
	gcc -c lex.yy.c
