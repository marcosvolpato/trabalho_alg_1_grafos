#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "tipos.h"

/*
 *========================== Tipo de dados ===========================
 */
//typedef struct t_vertice t_vertice;



/*
 *========================== Operações ===========================
 */
 //aloca uma nova fila vazia e retorna seu ponteiro
t_fila *f_init();
//booleano que retorna 1 se a fila estiver vazia
int f_isEmpty(t_fila *fila);
//esvazia a fila liberando a memoria de cada nó
void f_empty(t_fila *fila);
//insere um ponteiro de vertice na fila
void f_push(t_fila *fila, t_vertice *vertice, int antecessor, int distancia);
int f_hasVertice(t_fila *fila, int id);
t_f_no *f_pop(t_fila *fila);
//int getNum(pilha *p);
void f_deleta(t_fila *fila);

#endif
