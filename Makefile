all:		interval

clean:
	rm -rf *.o interval

interval:	main.o
	gcc -lgmp -lmpfr main.o -o interval
	rm -rf *.o

main.o:
	gcc -c main.c
