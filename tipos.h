#ifndef TIPOS_H
#define TIPOS_H

#include <stdio.h>
#include <stdlib.h>


/*
 *========================== Tipos de dados ===========================
 */
//typedef struct t_vertice t_vertice;
typedef struct t_aresta{
	int id;
	struct t_aresta *next, *prev;
}t_aresta;


typedef struct t_vertice{
	int id;
	t_aresta *a_inicio;
	struct t_vertice *next, *prev;
}t_vertice;

typedef struct t_grafo{
	t_vertice *v_inicio;
}t_grafo;

typedef struct t_f_no{
	t_vertice *vertice;
	int distancia, antecessor;
	struct t_f_no *next;
}t_f_no;

typedef struct t_fila{
	struct t_f_no *back, *front;
}t_fila;


#endif
