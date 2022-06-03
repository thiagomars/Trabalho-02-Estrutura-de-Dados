typedef struct arvb ArvB;

//Funcao que cria uma arvore binaria de busca vazia.
ArvB* arvb_cria_vazia(void);
      
//Testa se uma arvore binaria eh vazia.
int arvb_vazia(ArvB *a);

//Funcao que busca a sub-arvore que contem um inteiro.
ArvB* arvb_busca(ArvB *a, int c);

//Funcao que insere um inteiro em uma arvore.
ArvB* arvb_insere(ArvB *a, int c);

//Funcao que imrpime uma arvore binaria de busca.
void arvb_imprime(ArvB *a);

/*Fun??o que remove um inteiro em uma ?rvore.*/
ArvB* arvb_remove(ArvB *a, int c);

//Funcao que verifica a altura de uma arvore binaria de busca.
int arvb_altura(ArvB *a);

//Libera o espaco alocado para uma arvore.
void arvb_libera(ArvB *a);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//retorne a quantidade de folhas de uma ?rvore bin?ria de busca que possuem o campo info com n divisores positivos
int folhas_ndivp(ArvB * a, int n);

//retorne a quantidade de n?s de uma ?rvore bin?ria de busca que possuem os dois filhos (campos dir e esq diferentes de NULL)
int dois_filhos(ArvB * a);

//dada uma ?rvore bin?ria de busca, retorne a quantidade de n?s cujas sub?rvores esquerda e direita tenham igual altura
int nos_igual_altura(ArvB * a);

//compare se duas ?rvores bin?rias de busca s?o iguais.
//Obs: 1 ? verdadeiro; 0 ? falso.
int arv_iguais(ArvB * a, ArvB * b);

//imprima os elementos de uma ?rvore bin?ria de busca por n?veis.
//void impressao_arv_niveis(ArvB * a);



