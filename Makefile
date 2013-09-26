all:		interval

clean:
	rm -rf *.o interval
	rm -rf *.o
	rm -rf lex.yy.*

interval:	lex.yy.o main.o
	gcc -o interval lex.yy.o main.o -lmpfr -lgmp -lfl

main.o:
	gcc -c main.c

lex.yy.o:
	flex --header-file=lex.yy.h lexer.c
	gcc -c lex.yy.c
