# trabalho_alg_1_grafos
Trabalho de ALG-I sobre grafos para curso de sistemas de informação da USP

 Authors:	 	name: Allan Ribeiro da Costa
				uri: https://github.com/allan074
				e-mail: <email>

         		name: Marcos Vinicius Volpato
 				uri: https://github.com/marcosvolpato
				e-mail: volpatomv@gmail.com
				
 Repository: 	https://github.com/marcosvolpato/trabalho_alg_1_grafos
 
 Relatório: 	A aplicação foi dividida em 6 arquivos. O arquivo tipos.h contem as estruturas de dados usadas são elas:
			t_aresta, t_vertice e t_grafo usadas para representar o grafo e nas suas operações, também t_f_no e t_fila,
			usadas respectivamente para representar um nó de uma fila e a fila em si.
			
				Como citado acima, foi usada uma estrutura de fila, descrita em tipos.h e fila.h e implementada em fila.c. 
			A estrutura do nó dessa fila tem um int distancia que guarda a distancia entre o vertice contido no nó em relação
			a um outro vertice usado na busca, e contem um outro int antecessor que guarda um id do anteiror a ele na busca em 
			largura, podendo ser utilizado para recriar os caminhos entre os vertices e possivelmente até otimiza-los. Seu
			uso foi necessário para auxiliar nas buscas pelos caminhos do grafo através de uma busca em largura.
			
				Foram usados estruturas de listas encadeadas para representar o grafo e suas operações utilizaram metodos itertivos.
				
				Os testes manuais e os submetidos no run.codes tiveram êxito em 100% dos casos no estagio de desenvolvimento atual.
				
				Como o grafo foi implementado de forma dinamica, podendo assumir grandes proporções, uma especial atenção foi dada
			ao gerenciamento de memória com metodos(funções) que são capazes de liberar toda a memoria alocada pela aplicação.