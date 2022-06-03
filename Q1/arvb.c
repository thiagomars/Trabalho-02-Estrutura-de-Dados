#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arvb.h"

typedef struct arvb{
	int info;
	ArvB * esq;
	ArvB * dir;
} ArvB;

ArvB * arvb_cria_vazia(void){
	return NULL;
}

//Testa se uma arvore binaria eh vazia.
int arvb_vazia(ArvB * a){
	return a == NULL;
}

//Funcao que busca a sub-arvore que contem um inteiro.
ArvB * arvb_busca(ArvB * a, int c){
	if(arvb_vazia(a))
		return NULL;
	else if(a -> info < c)
		return arvb_busca(a -> dir, c);
	else if(a -> info > c)
		return arvb_busca(a -> esq, c);
	else //(a->info == c)
		return a;
}

//Funcao que insere um inteiro em uma arvore.
ArvB * arvb_insere(ArvB * a, int num){
	if(a == NULL){
		a = (ArvB *)malloc(sizeof(ArvB));
		a -> info = num;
		a -> esq = NULL;
		a -> dir = NULL;
	} 
	else if (a -> info > num)
		a -> esq = arvb_insere(a -> esq, num);
	else if (a -> info < num)
		a -> dir = arvb_insere(a -> dir, num);
	else
		printf("\n Elemento ja pertence a arvore");
		
	return a;
}

//Funcao que imrpime uma arvore binaria de busca.
void arvb_imprime(ArvB * a){
	if(!arvb_vazia(a)){
		arvb_imprime(a -> esq);
		printf("%d", a -> info);
		arvb_imprime(a -> dir);
	}
}

ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c)
			a->esq = arvb_remove(a->esq,c);
		else if (a->info < c)
			a->dir = arvb_remove(a->dir,c);
		else{
			ArvB* t;
			if (a->esq == NULL){
				t = a; a = a->dir;
				free(t);
			}else if (a->dir == NULL){
				t = a; a = a->esq;
				free(t);
			}else{
				t = a->esq;
				while(t->dir!=NULL)
				t = t->dir;
				a->info = t->info; t->info = c;
				a->esq = arvb_remove(a->esq,c);
			}
		}
	}
	return a;
}

//Funcao que verifica a altura de uma arvore binaria de busca.
int arvb_altura(ArvB * a){
	if(arvb_vazia(a))
		return -1;
	else{
		int hSAE = arvb_altura(a -> esq);
		int hSAD = arvb_altura(a -> dir);
		
		if(hSAE > hSAD)
			return 1 + hSAE;
		else
			return 1 + hSAD;
	}
}

//Libera o espaco alocado para uma arvore.
void arvb_libera(ArvB * a){
	if(!arvb_vazia(a)){
		arvb_libera(a -> esq);
		arvb_libera(a -> dir);
		
		free(a);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//retorne a quantidade de folhas de uma arvore binaria de busca que possuem o campo info com n divisores positivos
int folhas_ndivp(ArvB * a, int n){
	if(arvb_vazia(a)){
		return 0;
	}
	
	//se for uma folha e divis?vel por n, chama a fun??o com incremento
	if(a->dir == NULL && a->esq == NULL && a->info % n >= 1){
		return folhas_ndivp(a->esq, n) + folhas_ndivp(a->dir, n) + 1;
	}
		
	return folhas_ndivp(a->esq, n) + folhas_ndivp(a->dir, n);
}

//retorne a quantidade de n?s de uma ?rvore bin?ria de busca que possuem os dois filhos (campos dir e esq diferentes de NULL)
int dois_filhos(ArvB * a){
	if (a == NULL){
		return 0;
	} else{
    	int cont;
    
		int conte = dois_filhos (a->esq);
        int contd = dois_filhos (a->dir);
    	
    	if(conte == contd){	
    	    cont = conte + contd + 1;
		} else{
			return cont;
		}
        
    }
}

//dada uma ?rvore bin?ria de busca, retorne a quantidade de n?s cujas sub?rvores esquerda e direita tenham igual altura
int nos_igual_altura(ArvB * a){
	
}

//compare se duas ?rvores bin?rias de busca s?o iguais.
//Obs: 1 ? verdadeiro; 0 ? falso.
int arv_iguais(ArvB * a, ArvB * b){
	if(a == NULL && b == NULL){
		return 1;
	} else{
		return ((a -> info == b -> info) && (arv_iguais(a->esq, b->esq) && arv_iguais(a->dir, b->dir)));
	}
}

//imprima os elementos de uma ?rvore bin?ria de busca por n?veis.
void impressao_arv_niveis(ArvB * a){
//	ArvB *elemento;
//	int fila, ini, fim, qnt_elementos, nivel = 0;
//	int nivel_current = 0, altura = arvb_altura(a);
//	
//	qnt_elementos = pow(2, altura + 1) - 1;
//	
//	fila = (ArvB*)malloc(qnt_elementos * sizeof (ArvB));
//	
//	fila[0] = a; 
//	ini = 0; fim = 1;
//	
//	printf("nivel %d: ", nivel_current);
//	
//	while (fim > ini) {
//		//claculo do n?vel
//		nivel = floor(log10(ini+1) / log10(2));  // log2(x)
//		
//		if(nivel > altura)
//			break;
//		
//		elemento = (ArvB *)fila[ini++];
//		
//		//impress?o do n?vel
//		if (nivel != nivel_current) {
//			nivel_current = nivel;
//			printf("\nnivel %d: ", nivel_current);
//		}
//		
//		//impress?o dos elementos do n?vel
//		if (elemento != NULL)
//			printf("%d ", elemento->info);
//		
//		if (elemento == NULL && nivel != altura)  //caso para n?s nulos
//			fila[fim++] = NULL;
//		else if (elemento == NULL && nivel == altura)  //caso para folhas nulas
//			continue;
//		else if (elemento->esq != NULL)  	//caso para filhos de n?s != de nulos
//			fila[fim++] = elemento->esq;
//		else   								//demais casos
//			fila[fim++] = NULL;
//		
//		if (elemento == NULL && nivel != altura)
//			fila[fim++] = NULL;
//		else if (elemento == NULL && nivel == altura)
//			continue;
//		else if (elemento->dir != NULL)
//			fila[fim++] = elemento->dir;
//		else
//			fila[fim++] = NULL;
//	}
//	
//	puts("\n");
//		
//	free(fila);
}







