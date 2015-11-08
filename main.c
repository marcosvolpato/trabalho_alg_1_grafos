/*
 * Title: 		Grafo ALG-I 
 *
 * Date: 		07/11/2015
 *
 * Description: entrada:
 * 
 *				A primeira linha da entrada consiste no número do vértice a ser analisado.
 *				A segunda linha indica a quantidade N de arestas que serão lidas.
 *				A terceira linha para frente apresenta cada uma das N arestas, da 
 *				seguinte forma:
 *				x y
 * 
 *				Saída:
 *				
 *				Será composta pelo resultado de cada uma das medidas. Cada resultado deve ser apresentado em uma linha
 *				diferente, seguindo a ordem de apresentação das medidas (Primeira linha o grau, segunda linha o grau médio dos
 *				vizinhos...)
 *
 *				
 * Usage:		Exemplo de entrada:
 *
 *				1
 *				14
 *				1 2
 *				1 3
 *				1 4
 *				1 5
 *				1 6
 *				1 7
 *				2 8
 *				3 8
 *				4 5
 *				4 9
 *				5 9
 *				5 6
 *				6 10
 *				7 10
 * 
 * 				resulta na saída:
 * 				
 * 				6
 *				2.66
 *				0.13
 *				3
 *
 * Repository: 	https://github.com/marcosvolpato/trabalho_alg_1_grafos
 *
 * Authors:	 	name: Allan Ribeiro da Costa
 *				uri: https://github.com/allan074
 *				e-mail: <email>
 *
 *         		name: Marcos Vinicius Volpato
 * 				uri: https://github.com/marcosvolpato
 *				e-mail: volpatomv@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"
#include "tipos.h"

int main(int argc, char *argv[]) {

/*
 *=============== ENTRADA ========================================
 */
	t_grafo *grafo = g_init();
	int id, id1, id2, qtdd, i, h = 2;
	scanf("%d", &id);
	scanf("%d", &qtdd);
	
	if(qtdd > 0)
		v_new(grafo, id);
	
	for(i = 0; i < qtdd; i++){
		scanf("%d %d", &id1, &id2);
		v_new(grafo, id1);
		v_new(grafo, id2);
		a_new(grafo, id1, id2);
	}
	
/*
 *=============== SAIDA =========================================
 */
	printf("%d\n", v_grau(grafo, id));
	printf("%.2lf\n", v_grau_medio(grafo, id));
	printf("%.2lf\n", v_clust_coef(grafo, id));
	printf("%d", v_grau_hie(grafo, id, h));
	g_delete(grafo);
	//system("pause");
	return 0;
}
