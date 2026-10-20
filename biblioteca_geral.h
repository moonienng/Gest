#ifndef BLISTECA_H_INCLUDED

#define BLISTECA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
/*
# VaziaLista (lista* L) recebe uma lista e devolve  1 caso esteja vazia
# CriaLista() cria uma lista e devolve o endereço (inicio e case 5)
# InsereLista (lista *L,int pos,int n) insere um valor n na posiçao pos na lista L (case 1)
# XapiskaItem (lista *L,int pos) (case 2)deleta o item na posiçao pos da lista L //precisa ou ser por código de solicitação ou a gente cria uma função que procure a posição a partir do código de solicitação
# XapiskaLista (lista *L) deleta a lista L // (case 7)no sair vai precisar; acabei de me tocar que tamo deixando lista aleatória na memória do computador sem poder acessar depois
# ImprimeLista(lista *L) adivinha //(case 6)
# DuplicaLista(lista *L) duplica a lista L e devolve outra identica //não precisa
# BuscaItem(lista *L, int csol) procura um item e devolve o endereço dele // (case 3 e 4)
# Achapos
*/
typedef struct no
{
    int csol; //código da solicitação
    char c_eq[6]; //código do equipamento
    char nome[20]; //nome do equipamento
    int prior; //prioridade do equipamento
    int peri; //período até ficar pronto
    struct no *prox;
}No;

typedef struct lista{
    No *inicio;
} lista;

int VaziaLista (lista* L){
    if (L->inicio==NULL) return 1;
    return 0;

}

lista* CriaLista(){
    lista *L = (lista*) malloc(sizeof(lista));
    L->inicio=NULL;
    return L;
}

void InsereLista (lista *L,int pos,No *novo){
    No* aux=L->inicio;

    if(pos<=1){
        novo->prox=aux;
        L->inicio=novo;
    }else{
        while ((aux->prox!=NULL) && (pos>2)){
                aux=aux->prox;
                pos--;
    }
    novo->prox=aux->prox;
    aux->prox=novo;
    }
    return;
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
        return;
    }
    No *aux=L->inicio;
    int index=1;
    while(aux->prox!=NULL){
            printf("\n\n");
        printf("\ncódigo de solicitaçao numero %d:%d",index,aux->csol);
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

/*lista* DuplicaLista(lista *L){
    int cond=VaziaLista(L);
    if (cond==1){
        return NULL;
    }
    lista *D=CriaLista();
    No *aux=L->inicio;
    D->inicio=(No*)malloc(sizeof(No));
    No *aux2=D->inicio;
    while (aux->prox!=NULL){
        aux2->info=aux->info;
        aux=aux->prox;
        aux2->prox=(No*)malloc(sizeof(No));
        aux2=aux2->prox;
    }
    aux2->prox=NULL;
    aux2->info=aux->info;

    return D;
}

lista* RachaLista (lista *L, int index){
    int cond=VaziaLista(L);
    if (cond==1){
        return NULL;
    }
    lista *D=CriaLista();
    No *aux=L->inicio;
    index=index-2;

    if (index == 0){
    D->inicio=L->inicio;
    free(L);
    return D;
    }

    while((aux->prox!=NULL)&&(index>0)){
        aux=aux->prox;
        index--;
    }
    D->inicio=aux->prox;
    aux->prox=NULL;
    return D;
}*/

void InsereOrdenado(lista *L, No *novo){
    No *aux=L->inicio;
    int cnt=1;

    while((aux!=NULL) && (novo->csol>aux->csol)){
        aux=aux->prox;
        cnt++;
    }
    InsereLista(L,cnt,novo);
    return;
}

#endif // BLISTECA_H_INCLUDED
