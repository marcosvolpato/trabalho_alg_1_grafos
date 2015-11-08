#include "grafo.h"





/*
======================= FUNÇOES DO TIPO GRAFO =============================================
*/
t_grafo *g_init(){
	t_grafo *grafo = (t_grafo*)malloc(sizeof(t_grafo));
	grafo->v_inicio = NULL;
	return grafo;
}
int g_isEmpty(t_grafo *grafo){
	if(grafo->v_inicio == NULL)
		return 1;
	else
		return 0;
}
void g_insert(t_grafo *grafo, t_vertice *vertice){
	if(!v_hasVertice(grafo, vertice->id)){	
		if(vertice->id < -1){
			t_vertice *aux = grafo->v_inicio;
			if(!g_isEmpty(grafo)){
				if(aux->next != NULL){
					aux = aux->next;
					int setou = 0;
					while(aux->next != NULL){
						if(aux->id != aux->prev->id + 1){
							vertice->id = aux->prev->id + 1;
							vertice->prev = aux->prev;
							vertice->next = aux;
							aux->prev->next = vertice;
							aux->prev = vertice;
							setou = 1;
							break;
						}else
							aux = aux->next;
					}
					if(!setou){
						if(aux->id != aux->prev->id + 1){
							vertice->id = aux->prev->id + 1;
							vertice->prev = aux->prev;
							vertice->next = aux;
							aux->prev->next = vertice;
							aux->prev = vertice;
						}else{
							vertice->id = aux->id + 1;
							vertice->prev = aux;
							vertice->next = NULL;
							aux->next = vertice;
						}
					}
				}else{
					vertice->id = aux->id + 1;
					vertice->prev = aux;
					vertice->next = NULL;
					aux->next = vertice;
				}
			}else{
				vertice->id = 1;
				grafo->v_inicio = vertice;
			}
		}else{
			if(!g_isEmpty(grafo)){
				grafo->v_inicio->prev = vertice;
				vertice->next = grafo->v_inicio;
				grafo->v_inicio = vertice;
			}else{
				grafo->v_inicio = vertice;
			}
		}
	}else{
		
	}
}
int v_isVisited(t_vertice **visitado, int id, int length){
	int j;
	for(j=0;j<length;j++){
		if(visitado[j] == NULL)
			break;
		if(visitado[j]->id == id){
			if(visitado[j] != NULL)
				return 1;
		}
	}
	return 0;
}


t_f_no **g_distancias(t_grafo *grafo, int id){
	int i = 0, length = v_length(grafo), j, dist, k = 0;
	t_fila *fila = f_init();
	t_vertice **visitado = (t_vertice**)malloc(sizeof(t_vertice)*length);
	t_f_no **f_no_vec = (t_f_no**)malloc(sizeof(t_f_no)*length);
	for(j=0;j<length;j++){
		visitado[j] = NULL;
	}
	t_vertice *vert = v_find(grafo, id);
	f_push(fila, vert, -1, 0);
	visitado[i] = vert;
	dist = 0;
	i++;
	while(!f_isEmpty(fila)){
		t_f_no *f_no = f_pop(fila);//liberar f_no
		f_no_vec[k] = f_no;
		k++;
		t_aresta *aresta = f_no->vertice->a_inicio;
		while(aresta != NULL && i < length){
			if(!v_isVisited(visitado, aresta->id, length)){
				t_vertice *vertice = v_find(grafo, aresta->id);
				f_push(fila, vertice, f_no->vertice->id, f_no->distancia+1);
				visitado[i] = vertice;
				i++;
			}
			aresta = aresta->next;
		}
	}
	return f_no_vec;
}
void g_delete(t_grafo *grafo){
	v_delete_all(grafo);
	free(grafo);
}

/*
======================= FUNÇOES DO TIPO VERTICE =============================================
*/


t_vertice *v_create(int id){
	t_vertice *vertice =  (t_vertice*)malloc(sizeof(t_vertice));
	if(id < 0)
		vertice->id = -1;
	else
		vertice->id = id;
	vertice->a_inicio = NULL;
	vertice->next = NULL;
	return vertice;
}
int v_hasAresta(t_vertice *vertice){
	if(vertice->a_inicio == NULL)
		return 1;
	else
		return 0;
}
int v_hasVertice(t_grafo *grafo, int id){
	t_vertice *vertice = grafo->v_inicio;
	while(vertice != NULL){
		if(vertice->id == id)
			return 1;
		vertice = vertice->next;
	}
	return 0;
}
void v_new(t_grafo *grafo, int id){
	t_vertice *v1 = v_create(id);
	g_insert(grafo, v1);
}

t_vertice *v_find(t_grafo *grafo, int id){
	t_vertice *vertice = grafo->v_inicio;
	int added = 0;
	while(vertice != NULL){
		if(vertice->id == id)
			return vertice;
		vertice = vertice->next;
	}
	return NULL;
}

int v_grau(t_grafo *grafo, int id){
	if(!g_isEmpty(grafo)){
		t_vertice *vertice = v_find(grafo, id);
		t_aresta *aresta = vertice->a_inicio;
		int grau = 0;
		while(aresta != NULL){
			grau++;
			aresta = aresta->next;
		}
		return grau;
	}else{
		return 0;
	}
}
double v_grau_medio(t_grafo *grafo, int id){
	if(!g_isEmpty(grafo)){
		t_vertice *vertice = v_find(grafo, id);
		t_aresta *aresta = vertice->a_inicio;
		int grau_m = 0, count = 0;
		while(aresta != NULL){
			count++;
			grau_m = grau_m + v_grau(grafo, aresta->id);
			aresta = aresta->next;
		}
		double grau_m_d = (grau_m*1.0)/(count*1.0);
		return grau_m_d;
	}else{
		return 0.0;
	}
}

int v_isNeighbor(t_grafo *grafo, int id1, int id2){
	t_vertice *vertice = v_find(grafo, id1);
	t_aresta *aresta = vertice->a_inicio;
	while(aresta != NULL){
		if(aresta->id == id2)
			return 1;
		aresta = aresta->next;
	}
	return 0;
}
double v_clust_coef(t_grafo *grafo, int id){
	if(!g_isEmpty(grafo)){
		t_vertice *vertice = v_find(grafo, id);
		t_aresta *aresta = vertice->a_inicio;
		int count_e = 0;
		double coef, grau;
		t_aresta *aresta_2 = aresta->next;
		while(aresta->next != NULL){
			while(aresta_2 != NULL){
				if(v_isNeighbor(grafo, aresta->id, aresta_2->id))
					count_e++;
				aresta_2 = aresta_2->next;
			}
			aresta = aresta->next;
			aresta_2 = aresta->next;
		}
		grau = v_grau(grafo, id)*1.0;
		coef = (2*(count_e*1.0))/(grau*(grau-1));
		if(count_e > 0)
			return coef;
		else
			return 0.0;
	}else{
		return 0.0;
	}
}

int v_length(t_grafo *grafo){
	t_vertice *vertice = grafo->v_inicio;
	int i = 0;
	while(vertice != NULL){
		i++;
		vertice = vertice->next;
	}
	return i;
}
int v_grau_hie(t_grafo *grafo, int id, int h){
	if(!g_isEmpty(grafo)){
		int i = 0, length = v_length(grafo), j, dist, k = 0;
		t_fila *fila = f_init();
		t_vertice **visitado = (t_vertice**)malloc(sizeof(t_vertice)*length);
		t_f_no **f_no_vec = (t_f_no**)malloc(sizeof(t_f_no)*length);
		for(j=0;j<length;j++){
			visitado[j] = NULL;
		}
		t_vertice *vert = v_find(grafo, id);
		f_push(fila, vert, -1, 0);
		visitado[i] = vert;
		dist = 0;
		i++;
		while(!f_isEmpty(fila)){
			t_f_no *f_no = f_pop(fila);
			if(f_no->distancia == h){
				k++;
			}
			t_aresta *aresta = f_no->vertice->a_inicio;
			while(aresta != NULL && i < length){
				if(!v_isVisited(visitado, aresta->id, length)){
					t_vertice *vertice = v_find(grafo, aresta->id);
					f_push(fila, vertice, f_no->vertice->id, f_no->distancia+1);
					visitado[i] = vertice;
					i++;
				}
				aresta = aresta->next;
			}
			free(f_no);
		}
		return k;
	}else{
		return 0;
	}
}
void v_delete_all(t_grafo *grafo){
	t_vertice *vertice = grafo->v_inicio;
	t_vertice *aux;
	while(vertice != NULL){
		aux = vertice;
		a_delete_all(vertice);
		vertice = vertice->next;
		free(aux);
	}
}
/*
======================= FUNÇOES DO TIPO ARESTA =============================================
*/
void a_new(t_grafo *grafo, int id1, int id2){
	t_aresta *aresta_1 = (t_aresta*)malloc(sizeof(t_aresta));
	t_aresta *aresta_2 = (t_aresta*)malloc(sizeof(t_aresta));
	aresta_1->id = id2;
	aresta_2->id = id1;
	t_vertice *vertice = grafo->v_inicio;
	int added = 0;
	while(vertice != NULL){
		if(vertice->id == id1){
			if(!a_hasAresta(vertice, id2)){
				if(a_isEmpty(vertice)){
					aresta_1->next = NULL;
					aresta_1->prev = NULL;
					vertice->a_inicio = aresta_1;
				}else{
					vertice->a_inicio->prev = aresta_1;
					aresta_1->prev = NULL;
					aresta_1->next = vertice->a_inicio;
					vertice->a_inicio = aresta_1;
				}
			}
			
			added++;
		}
		if(vertice->id == id2){
			if(!a_hasAresta(vertice, id1)){
				if(a_isEmpty(vertice)){
					aresta_2->next = NULL;
					aresta_2->prev = NULL;
					vertice->a_inicio = aresta_2;
				}else{
					vertice->a_inicio->prev = aresta_2;
					aresta_2->prev = NULL;
					aresta_2->next = vertice->a_inicio;
					vertice->a_inicio = aresta_2;
				}
			}
			added++;
		}
		if(added > 1)
			break;
		vertice = vertice->next;
	}
}
int a_hasAresta(t_vertice *vertice, int id){
	t_aresta *aresta = vertice->a_inicio;
	while(aresta != NULL){
		if(aresta->id == id)
			return 1;
		aresta = aresta->next;
	}
	return 0;
}
int a_isEmpty(t_vertice *vertice){
	if(vertice->a_inicio == NULL)
		return 1;
	else
		return 0;
}
void a_delete_all(t_vertice *vertice){
	t_aresta *aresta = vertice->a_inicio;
	t_aresta *aux;
	while(aresta != NULL){
		aux = aresta;
		aresta = aresta->next;
		free(aux);
	}
}
