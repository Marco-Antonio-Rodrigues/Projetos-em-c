all:	heap.o 
	gcc -o prog_heap main.c heap.o
	rm -f heap.o
	./prog_heap

heap.o: heap.h
	gcc -c heap.c 