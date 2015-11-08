#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "tipos.h"
/*
======================= TIPO DE DADOS =============================================
*/



//typedef struct t_f_no t_f_no;

/*
======================= FUNÇOES DO TIPO GRAFO =============================================
*/
t_grafo *g_init();
int g_isEmpty(t_grafo *grafo);
void g_insert(t_grafo *grafo, t_vertice *vertice);

/*
 * para usar essa função tem que liberar memoria do vetor de ponteiros g_distancias
 * e dos seus componentes t_f_no
 */
t_f_no **g_distancias(t_grafo *grafo, int id);
void g_delete(t_grafo *grafo);
/*
======================= FUNÇOES DO TIPO VERTICE =============================================
*/
t_vertice *v_create(int id);
int v_hasAresta(t_vertice *vertice);
int v_hasVertice(t_grafo *grafo, int id);
void v_new(t_grafo *grafo, int id);
t_vertice *v_find(t_grafo *grafo, int id);
int v_grau(t_grafo *grafo, int id);
double v_grau_medio(t_grafo *grafo, int id);
int v_isNeighbor(t_grafo *grafo, int id1, int id2);
double v_clust_coef(t_grafo *grafo, int id);
int v_length(t_grafo *grafo);
void v_delete_all(t_grafo *grafo);
/*
======================= FUNÇOES DO TIPO ARESTA =============================================
*/
void a_new(t_grafo *grafo, int id1, int id2);
int a_hasAresta(t_vertice *vertice, int id);
int a_isEmpty(t_vertice *vertice);
void a_delete_all(t_vertice *vertice);


#endif
