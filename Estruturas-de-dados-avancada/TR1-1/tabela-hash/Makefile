all:	tabelashash.o 
	gcc -o prog main.c tabelashash.o
	rm -f tabelashash.o 
	./prog array200000.txt
	./prog array400000.txt
	./prog array600000.txt
	./prog array800000.txt
	./prog array1000000.txt


tabelashash.o: tabelashash.h
	gcc -c tabelashash.c 