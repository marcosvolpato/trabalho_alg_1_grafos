all:	grafos_alg_1
	
grafos_alg_1:	main.o grafo.o fila.o
	gcc main.o grafo.o fila.o -lm -o grafos_alg_1
	rm *.o

main.o:	main.c
	gcc -c main.c
	
grafo.o:	grafo.c	grafo.h fila.h
	gcc -c grafo.c
	
fila.o:	fila.c	fila.h grafo.h
	gcc -c fila.c
	
clean:
	rm *.o

run:
	./grafos_alg_1


