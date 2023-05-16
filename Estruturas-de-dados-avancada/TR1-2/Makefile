all:	tabelashash.o 
	gcc -o prog main.c tabelashash.o
	rm -f tabelashash.o 
	./prog array6.txt

tabelashash.o: tabelashash.h
	gcc -c tabelashash.c 