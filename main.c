/*1) Escreva uma função que conte o número de nós de uma árvore binária.


2) Escreva uma função que verifique se uma árvore binária está balanceada.

4) Duas ABBs são IGUAIS se ambas são vazias ou então se armazenam valores iguais em suas raízes, suas subárvores esquerdas são iguais, e suas subárvores direitas são iguais. Implemente a função que verifica se duas árvores são iguais.

5) Escreva uma função que verifique a existência de um valor X em uma árvore binária.*/


//Bom dia professor

#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
  int dado1; 
  struct arv *esq;
  struct arv *dir;
  int altura;
}arvore1;

typedef struct arv2{
  int dado2; 
  struct arv2 *esq;
  struct arv2 *dir;
}arvore2;

arvore1 *criar(arvore1* pRoot1){

  return NULL;
}

arvore2 *criar2(arvore2* pRoot2){

  return NULL;
}

int conta_nos (arvore1 *r) { 
    if (r == NULL){ 
    return 0;
    }else {          
        int conte = conta_nos (r->esq);         
        int contd = conta_nos (r->dir); 
        return conte + contd + 1;   
    }
}//1)

int maior(int a, int b){
    return (a > b)? a: b;
}


int alturaDoNo(arvore1 *no){
    if(no == NULL){
        return -1;
    }else{
        return no->altura;
}
}


int fatorDeBalanceamento(arvore1 *node){
    if(node)
        return (alturaDoNo(node->esq) - alturaDoNo(node->dir));
    else
        return 0;
}//2

//insere na primeira arvore e chama funcoes usadas para calcular o fator de balanceamento
arvore1* insercao1(arvore1 *pRaiz1, int dado) {

    if (pRaiz1 == NULL) {

        printf("Valor inserido! \n");
        pRaiz1 = (arvore1*) calloc(1, sizeof(arvore1));
        pRaiz1->esq = NULL;
        pRaiz1->dir = NULL;
        pRaiz1->dado1 = dado;
        pRaiz1->altura = 0;
    } 
    else {

        if(dado < (pRaiz1->dado1) ) {

          pRaiz1->esq = insercao1(pRaiz1->esq, dado);
        }
        else {

          pRaiz1->dir = insercao1(pRaiz1->dir, dado);
        }
    }
    pRaiz1->altura = maior(alturaDoNo(pRaiz1->esq), alturaDoNo(pRaiz1->dir)) + 1;

    return pRaiz1;
}
//insere na segunda arvore
arvore2* insercao2(arvore2 *pRaiz2, int dado) {

    if (pRaiz2 == NULL) {

      printf("Valor inserido! \n");
      pRaiz2 = (arvore2*) calloc(1, sizeof(arvore2));
      pRaiz2->esq = NULL;
      pRaiz2->dir = NULL;
      pRaiz2->dado2 = dado;
    }else {

        if ( dado < (pRaiz2->dado2) ) {

          pRaiz2->esq = insercao2(pRaiz2->esq, dado);
        }else {

          pRaiz2->dir = insercao2(pRaiz2->dir, dado);
        }
    }

    return pRaiz2;
}

//verifica valores da esquerda
int SimiliarEsq(arvore1 *lista1, arvore2 *lista2){
int flag=0;
flag++;

  if ( (lista1==NULL && lista2==NULL) || (lista1->esq!=NULL && lista2->esq!=NULL && lista1->esq->dado1 == lista2->esq->dado2 )){
return (SimiliarEsq(lista1->esq, lista2->esq));

}else if((lista1->esq!=NULL && lista2->esq!=NULL && lista1->esq->dado1 != lista2->esq->dado2 )){
  flag=0;
}
  if (flag==1){

return 1;

}else{

return 0;
}
}

//Verifica valores da direita
int SimiliarDir(arvore1 *lista1, arvore2 *lista2){
int flag=0;
flag++;

  if ( (lista1==NULL && lista2==NULL) || (lista1->dir!=NULL && lista2->dir!=NULL && lista1->dir->dado1 == lista2->dir->dado2 )){

return (SimiliarDir(lista1->dir, lista2->dir));

}else if((lista1->dir!=NULL && lista2->dir!=NULL && lista1->dir->dado1 != lista2->dir->dado2 )){
  flag=0;
}
  if (flag==1){
  
return 1;

}else{
return 0;
}
}

//Função que irá verificar se os valores da raiz, esquerda e direita são iguais.
int Similar(arvore1 *lista1, arvore2 *lista2){
  if( (lista1->dado1==lista2->dado2) && SimiliarDir(lista1, lista2) && (SimiliarEsq(lista1, lista2))){

return 1;

}else{

return 0;
}
}//4

int EncontrarNaarvore1(arvore1 *t, int num) {
if(t == NULL){
  return 0;
}else if(t->dado1 == num){
  return 1;
}else if(num < t->dado1){
  return EncontrarNaarvore1(t->esq,num);
}else{
  return EncontrarNaarvore1(t->dir,num);
}

}//5

int main(void) {
  int opc = 0, valor = 0, qtdNode = 0, balanceado = 0, valor2 = 0, comparar = 0, encontrado = 0, valorProcurar = 0;
  
  arvore1 *pRaiz = criar(pRaiz);
  arvore2 *pRaiz2 = criar2(pRaiz2);


  do{

    printf("\nDigite 1 para adicionar valor para a arvore1 e arvore2");
    printf("\nDigite 2 para contar o numero de nos da arvore1");
    printf("\nDigite 3 para verificar se a arvore1 esta balanceada");
    printf("\nDigite 4 para verificar se as arvores sao iguais");
    printf("\nDigite 5 para buscar um numero na arvore1\n");
    scanf("%d", &opc);

    switch(opc){
    case 1:
    printf("Digite um valor para a primeira arvore: ");
    scanf("%d", &valor);
    printf("Digite um valor para a segunda arvore: ");
    scanf("%d", &valor2);

    pRaiz = insercao1(pRaiz, valor);
    pRaiz2 = insercao2(pRaiz2, valor2);
    break;

    case 2:
    qtdNode = conta_nos (pRaiz);
    printf("A arvore possui %d noh", qtdNode);    
    break;

    case 3:
      balanceado =fatorDeBalanceamento(pRaiz);
      //printf("%d", balanceado);
      if(balanceado != 1 && balanceado != -1 && balanceado != 0){
        printf("A arvore nao esta balanceada!\n");
      }else{
        printf("A arvore esta balanceada!\n");
      }

    break;

    case 4:
    comparar = Similar(pRaiz,pRaiz2);
    if(comparar == 1){
      printf("As arvores sao iguais!\n");
    }else{
      printf("As arvores nao sao iguais!\n");
    }
    break;

    case 5:
    printf("Digite o valor para buscar na arvore: ");
    scanf("%d", &valorProcurar);
    encontrado = EncontrarNaarvore1(pRaiz, valorProcurar); 
    if(encontrado != 0){
      printf("\nO numero %d pertence a arvore!\n", valorProcurar);
    }else{
      printf("\nValor nao encontrado!\n"); 
    }
    break;      
    
  }
  
}while(opc != 0);
return 0;
}