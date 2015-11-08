#include "fila.h"


t_fila *f_init(){
	t_fila *fila = (t_fila*)malloc(sizeof(t_fila));
	fila->back = NULL;
	fila->front = NULL;
	return fila;
}

int f_isEmpty(t_fila *fila){
	if(fila->front == NULL)
		return 1;
	else
		return 0;
}

void f_empty(t_fila *fila){
	while(!f_isEmpty(fila))
		free(f_pop(fila));
}

t_f_no *f_pop(t_fila *fila){
	if(!f_isEmpty(fila)){
		t_vertice *vertice = fila->front->vertice;
		t_f_no *f_no = fila->front;
		if(fila->back != fila->front){
			fila->front = fila->front->next;
		}else{
			fila->front = NULL;
			fila->back = NULL;
		}
		//free(f_no);
		return f_no;
	}
	return NULL;
}
void f_push(t_fila *fila, t_vertice *vertice, int antecessor, int distancia){
	t_f_no *f_no = (t_f_no*)malloc(sizeof(t_f_no));
	f_no->vertice = vertice;
	f_no->next = NULL;
	f_no->antecessor = antecessor;
	f_no->distancia = distancia;
	if(!f_isEmpty(fila)){
		fila->back->next = f_no;
	}else{
		fila->front = f_no;
	}
	fila->back = f_no;
}
int f_hasVertice(t_fila *fila, int id){
	t_f_no *f_no = fila->front;
	while(f_no != NULL){
		if(f_no->vertice->id == id)
			return 1;
		f_no = f_no->next;
	}
	return 0;
}
void f_deleta(t_fila *fila){
	f_empty(fila);
	free(fila);
}
