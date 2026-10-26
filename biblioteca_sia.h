#ifndef BIBLIOTECA_SIA_INCLUDED
#define BIBLIOTECA_SIA_INCLUDED
#include <stdio.h>
#include <stdlib.h>
void NovaSolic(lista *L, int cods, char *codeq, char *nome, int pri, int per)
{
    No *novo;
    novo = (No *)malloc(sizeof(No));
    novo->csol = cods;
    strcpy(novo->c_eq, codeq);
    strcpy(novo->nome, nome);
    novo->peri = per;
    novo->prior = pri;
    novo->prox = NULL;
    InsereLista(L, novo);
}
void ConsultarSolic(lista *L, int cod)
{
    No *consu = BuscaItem(L, cod);
    if(consu == NULL)
    {
        printf("Solicitação não encontrada.");
        return;
    }
    printf("\nCódigo de solicitação: %04d", consu->csol);
    printf("\nNome do equipamento: ");
    puts(consu->nome);
    printf("\nCódigo do equipamento: ");
    puts(consu->c_eq);
    printf("\nPrioridade da solicitação: %d", consu->prior);
    printf("Prazo de manutenção: %d dias\n", consu->peri);
}
void EditarSolic(lista *L, int cod, int pri, int pra)
{
    No *item = BuscaItem(L, cod);
    if(item == NULL)
    {
        printf("Solicitação não encontrada.");
        return;
    }
    item->prior = pri;
    item->peri = pra;
}
void ListaManutencao(lista *L)
{
    if (VaziaLista(L) == 1)
    {
        printf("\nNenhuma solicitação cadastrada.");
        return;
    }
    No *aux1 = L->inicio;
    lista *M = CriaLista();
    No *aux2 = M->inicio;
    No *aux3 = NULL;
    int aval;
    while (aux1 != NULL)
    {
        No *novo = (No *) malloc(sizeof(No));
        novo->csol = aux1->csol;
        strcpy(novo->c_eq, aux1->c_eq);
        strcpy(novo->nome, aux1->nome);
        novo->prior = aux1->prior;
        novo->peri = aux1->peri;
        novo->prox = NULL;

        aux2 = M->inicio;
        aux3 = NULL;
        aval = 0;

        while ((aux2 != NULL) && (aval == 0))
        {
            if (novo->prior < aux2->prior)
            {
                aval = 1;
            }
            else if (novo->prior > aux2->prior)
            {
                aval = 0;
            }
            else
            {
                if (novo->peri < aux2->peri)
                {
                    aval = 1;
                }
                else if (novo->peri > aux2->peri)
                {
                    aval = 0;
                }
                else
                {
                    if (novo->csol < aux2->csol)
                    {
                        aval = 1;
                    }
                }
            }

            if (aval == 0)
            {
                aux3 = aux2;
                aux2 = aux2->prox;
            }
        }
        if (aux3 == NULL)
        {
            novo->prox = M->inicio;
            M->inicio = novo;
        }
        else
        {
            aux3->prox = novo;
            novo->prox = aux2;
        }
        aux1 = aux1->prox;
    }
    ImprimeLista(M);
    XapiskaLista(M);
}
int VerificaTipo(int tipo)
{
    if (tipo > 0)
    {
        return 0;
    }
    return 1;
}
int VerificaEquipamento (char c_eq[7]){
    int cnt=0;
    while (cnt<3){
        if (!isalpha(c_eq[cnt])){
            return 1;
        }
        cnt++;
    }
    while (cnt<6){
        if (!isdigit(c_eq[cnt])){
            return 1;
        }
        cnt++;
    }
    return 0;
}
int VerificarCSol(lista *L, int csol)
{
    No *ver = BuscaItem(L, csol);
    if (ver != NULL)
    {
        printf("O código digitado já existe. Tente novamente!");
        return 1;
    }
    if ((csol < 1) || (csol > 9999))
    {
        printf("Formato do código incorreto. Tente Novamente!");
        return 1;
    }
    return 0;
}
int VerificarIntervalo(int pri, int pra)
{
    if ((pri > 3) || (pri < 1) || (pra <= 0) || (pra > 20))
    {
        printf("Entradas inválidas. Tente novamente!");
        return 1;
    }
    if (((pri == 1) && (pra > 7)) || ((pri == 2) && (pra > 15)))
    {
        printf("O prazo informado é incompatível com a prioridade. Tente novamente!");
        return 1;
    }
    return 0;
}
#endif
