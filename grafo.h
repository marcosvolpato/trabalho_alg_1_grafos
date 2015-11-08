#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "tipos.h"

/*
======================= FUNÇOES DO TIPO GRAFO =============================================
*/
/*
 * Não recebe parametros, aloca na memoria um novo tipo t_grafo e retorna 
 * seu ponteiro
 */
t_grafo *g_init();

/*
 * Booleano recebe um ponteiro de um t_grafo e retorna 1 se estiver vazio
 */
int g_isEmpty(t_grafo *grafo);

/*
 * Recebe um ponteiro de um t_grafo e retorna e um ponteiro para t_vertice
 * e insere esse ultimo no t_grafo
 */
void g_insert(t_grafo *grafo, t_vertice *vertice);

/*
 * para usar essa função tem que liberar memoria do vetor de ponteiros 
 * g_distancias e dos seus componentes t_f_no
 */
t_f_no **g_distancias(t_grafo *grafo, int id);

/*
 * Recebe um ponteiro de um t_grafo libera a memória de todas as arestas,
 * vertices e do grafo
 */
void g_delete(t_grafo *grafo);

/*
======================= FUNÇOES DO TIPO VERTICE =============================================
*/
/*
 * Recebe um int id, aloca memoria para um novo vertice, atribui  o id a 
 * ele e retorna o ponteiro do vertice
 */
t_vertice *v_create(int id);

/*
 * Recebe um ponteiro t_vertice e retorna 1 se este conter pelo menos uma 
 * aresta
 */
int v_hasAresta(t_vertice *vertice);

/*
 * Recebe um ponteiro de um t_grafo e um int id e retorna 1 se nesse gravo 
 * existir um vertice com esse id
 */
int v_hasVertice(t_grafo *grafo, int id);

/*
 * Recebe um ponteiro de um t_grafo e um id e adiciona ao grafo um novo 
 * vertice com esse id
 */
void v_new(t_grafo *grafo, int id);

/*
 * Recebe um ponteiro de um t_grafo e um id e retorna o ponteiro do vertice
 * que tiver esse id
 */
t_vertice *v_find(t_grafo *grafo, int id);

/*
 * Recebe um ponteiro de um t_grafo e um id e retorna um int com o grau do 
 * vertice desse id
 */
int v_grau(t_grafo *grafo, int id);

/*
 * Recebe um ponteiro de um t_grafo e um id e retorna um double com o grau 
 * medio dos visinhos do vertice com esse id
 */
double v_grau_medio(t_grafo *grafo, int id);

/*
 * Recebe um ponteiro de um t_grafo e dois ids e retorna 1 se os vertices 
 * dos ids forem visinhos
 */
int v_isNeighbor(t_grafo *grafo, int id1, int id2);

/*
 * Recebe um ponteiro de um t_grafo e um id e retorna um double com o 
 * coeficiente de aglomeração
 */
double v_clust_coef(t_grafo *grafo, int id);

/*
 * Recebe um ponteiro de um t_grafo e retorna um int com a quantidade de 
 * vertices no grafo
 */
int v_length(t_grafo *grafo);

/*
 * Recebe um ponteiro de um t_grafo e deleta todos os vertces contidos nele
 */
void v_delete_all(t_grafo *grafo);

/*
======================= FUNÇOES DO TIPO ARESTA =============================================
*/
/*
 * Recebe um ponteiro de um t_grafo e dois ids, verifica se existem 
 * vertices com esses ids se não existir, cria os vertices e as arestas 
 * ligando um ao outro, se existir só cria asarestas inserindo tudo no 
 * grafo
 */
void a_new(t_grafo *grafo, int id1, int id2);

/*
 * Recebe um ponteiro de um t_vertice e um id e retorna 1 se este tiver 
 * uma aresta com esse id
 */
int a_hasAresta(t_vertice *vertice, int id);

/*
 * Recebe um ponteiro de t_vertice e retorna um se esse for vazio
 */
int a_isEmpty(t_vertice *vertice);

/*
 * Recebe um ponteiro de um t_vertice e libera a memoria de todas as 
 * arestas deste
 */
void a_delete_all(t_vertice *vertice);

#endif
