#ifndef BLISTECA_H_INCLUDED

#define BLISTECA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct no
{
    int csol;
    char c_eq[7];
    char nome[20];
    int prior;
    int peri;
    struct no *prox;
}No;

typedef struct lista
{
    No *inicio;
} lista;

int VaziaLista (lista* L)
{
    if (L->inicio==NULL) return 1;
    return 0;

}

lista* CriaLista()
{
    lista *L = (lista*) malloc(sizeof(lista));
    L->inicio=NULL;
    return L;
}

void InsereLista (lista *L, No *novo){
    No* aux = L->inicio;
    No* ant = NULL;
    while ((aux != NULL) && (novo->csol > aux->csol))
    {
        ant = aux;
        aux = aux->prox;
    }
    if (ant == NULL)
    {
        novo->prox = L->inicio;
        L->inicio = novo;
    }
    else
    {
        ant->prox = novo;
        novo->prox = aux;
    }
}

void XapiskaItem (lista *L,int pos){
    int cond=VaziaLista(L);
    if (cond==1){
        return;
        }
    No *aux=L->inicio;

    if(pos==1){
        L->inicio=aux->prox;
        free(aux);
    }else{
        while((aux->prox!=NULL)&&(pos>2)){
            aux=aux->prox;
            pos--;
    }
        No *aux2=aux->prox;
        aux->prox=aux2->prox;
        free(aux2);
    }

}

lista* XapiskaLista (lista *L){
    int cond=VaziaLista(L);
    if (cond==1){
        free(L);
        return NULL;
    }
    No *aux=L->inicio;
    No *aux2=aux->prox;

    while(aux->prox!=NULL){
        free(aux);
        aux=aux2;
        aux2=aux2->prox;
    }
    free(aux);
    free(L);
    return NULL;
}

void ImprimeLista(lista *L){
     int cond=VaziaLista(L);
    if (cond==1){
        printf("\nLista vazia.");
        return;
    }
    No *aux=L->inicio;
    int index=1;
    while(aux->prox!=NULL){
            printf("\n\n");
        printf("\ncódigo de solicitaçao numero %d:%04d",index,aux->csol);
        printf("\ncódigo de equipamento numero %d:%s",index,aux->c_eq);
        printf("\nnome do equipamento %d:%s",index,aux->nome);
        printf("\nprioridade do equipamento %d:%d",index,aux->prior);
        printf("\nprazo até ficar pronto %d:%d",index,aux->peri);
        aux=aux->prox;
        index++;
    }
            printf("\n\n");
        printf("\ncódigo de solicitaçao numero %d:%d",index,aux->csol);
        printf("\ncódigo de equipamento numero %d:%s",index,aux->c_eq);
        printf("\nnome do equipamento %d:%s",index,aux->nome);
        printf("\nprioridade do equipamento %d:%d",index,aux->prior);
        printf("\nprazo até ficar pronto %d:%d",index,aux->peri);
        aux=aux->prox;
    return;
}

int Achapos (lista *L, int csol){
    int cond=VaziaLista(L);
    if (cond==1){
        return 0;
    }
    No *aux=L->inicio;
    int cnt=1;

    while((aux!=NULL) && (csol!=aux->csol)){
        aux=aux->prox;
        cnt++;
    }
    return cnt;
}

No* BuscaItem(lista *L, int csol){
    int pos=Achapos(L,csol);
    No *aux=L->inicio;

    while(pos>1){
        aux=aux->prox;
        pos--;
    }
    return aux;
}
#endif