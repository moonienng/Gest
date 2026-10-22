#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "biblioteca_geral.h"

//criação de novas solicitações
void NovaSolic(lista *L,int cods, char *codeq, char *nome,int pri,int per)
{
    No *novo;
    //cria um elemento novo
    novo = (No *) malloc(sizeof(No));
    //guarda o código da solicitação
    novo->csol=cods;
    //guarda o código do equipamento
    strcpy(novo->c_eq,codeq);
    //guarda o nome do equipamento
    strcpy(novo->nome,nome);
    //guarda o período e a prioridade
    novo->peri = per;
    novo->prior = pri;
    //deixa o prox nulo
    novo->prox = NULL;
    InsereLista(L,novo);
}


//TODO: consultar solicitação (void)
/*
    preciso que na biblioteca tenha uma função que a partir do código de solicitação retorne o endereço do item
    *antes da função
    1 - pede código
    2 - buscaitem
    *função
    3 - printf em todas as informações a partir do endereço
*/
//TODO: editar solicitação (void)
/*
    *antes da função
    1 - pega o código de solicitação
    2 - pergunta se a alteração é na prioridade ou no prazo
    3 - pega o valor que é pra ser alterado
    *Verifica se o valor é possível e compativel
    *função
    4 - buscaitem
    5 - usa o endereço pra acessar o campo que deve ser alterado e altera
*/
//TODO: fila de manutenção (void)
/*
    aqui o filho chora e a mãe não vê
    cara
    1 - precisa criar uma lista nova
    2 - adicionar os itens da lista de solicitações na nova lista a partir da prioridade e prazo
    4 - mostra a lista
    5 - apaga a lista
*/
//TODO: VerificaTipo (int)
/*
    1 - recebe o retorno de um scanf
    2 - verifica se o retorno está certo
    3 - retorna 0 para quando tá certo e 1 para quando está errado
*/
int VerificaTipo (int tipo)
{
    if(tipo>0)
    {
        return 0;
    }
    return 1;
}
//TODO: VerificarEEntrada (int)
/*
    1 - recebe o código do equipamento
    2 - verifica se os 3 primeiros são letras
    3 - verifica se os 3 ultimos são números
    4 - retorna 0 para quando tá certo e 1 para quando está errado
*/
// TODO: VerificarIntervalo (int)
/*
    1 - recebe a prioridade e o prazo
    2 - confere se o prazo está de acordo com a prioridade
    3 - retorna 0 caso não haja problema e 1 caso haja
*/

    int main()
    {
        setlocale(LC_ALL, "Portuguese");
        int op=0;
        char conf;
        lista *L = NULL;
        L = CriaLista();

        /*
        \nMenu:
        \n1 - Criar nova solicitação
        \n2 - Apagar Solicitação (função da biblioteca)
        \n3 - Consultar solicitação
        \n4 - Editar solicitação
        \n5 - Exibir fila de manutenção
        \n6 - Exibir solicitações (função da biblioteca)
        \n7 - Sair

        - Cada código é referente a uma função do sistema
        - Para as funções funcionarem é necessário uma biblioteca com funções básicas de lista
        */
       do{
        printf("\nSistema de manutenção");
        printf("\nMenu: \n1 - Criar nova solicitação\n2 - Apagar Solicitação\n3 - Consultar solicitação\n4 - Editar solicitação\n5 - Exibir fila de manutenção\n6 - Exibir solicitações\n7 - Sair");
        printf("\nDigite o código:");
        int res = VerificaTipo(scanf("%i", &op));
        while (res != 0)
        {
            printf("Código inválido. Tente novamente!");
            while (getchar() != '\n');
            res = VerificaTipo(scanf("%i", &op));
        }


         system("cls");
         switch(op)
         {
             case 1:
                 //variáveis que eu preciso coletar pra criar
                 int cods; //código da solicitação
                 char codeq[7]; //código do equipamento
                 char nome[21]; //nome do equipamento
                 int pri; //prioridade do equipamento
                 int per; //período até ficar pronto

                 printf("\t\t==================== Criar nova solicitação ====================");
                 //pedir codigo de solicitação
                 printf("\nDigite o código de solicitação:");
                 int res = VerificaTipo(scanf("%d",&cods));
                 while (res != 0)
                {
                    printf("Entrada inválida. Tente novamente!");
                    while (getchar() != '\n');
                    res = VerificaTipo(scanf("%d",&cods));
                }

                 //pedir pedir código do equipamento
                 printf("\nDigite o código do equipamento:");
                 fgets(codeq, sizeof(codeq), stdin);

                 //pedir nome do equipamento
                 printf("\nDigite o nome do equipamento:");
                 fgets(nome, sizeof(nome), stdin);

                 //pedir prioridade da solicitação
                 printf("\nRelação de prioridades:");
                 printf("\n1  -> Alta: manutenção urgente\n2  -> Média: deve ser feita em breve\n3 -> Baixa: pode aguardar");
                 printf("\nDigite a prioridade do equipamento:");
                 res = VerificaTipo(scanf("%d",&pri));
                 while (res != 0)
                {
                    printf("Entrada inválida. Tente novamente!");
                    while (getchar() != '\n');
                    res = VerificaTipo(scanf("%d",&pri));
                }

                 //pedir período até estar pronto
                 printf("\nRelação de períodos:");
                 printf("\nPrioridade 1  -> entre 1 e 7 dias\nPrioridade 2  -> entre 1 e 15 dias\nPrioridade 3 -> entre 1 e 20 dias");
                 printf("\nDigite o período de manutenção:");
                 res = VerificaTipo(scanf("%d",&per));
                 while (res != 0)
                {
                    printf("Entrada inválida. Tente novamente!");
                    while (getchar() != '\n');
                    res = VerificaTipo(scanf("%d",&per));
                }
                 NovaSolic(L,cods,codeq,nome,pri,per);
             break;
             case 2:
                 int solap;
                 char conf;
                 printf("\t\t==================== Apagar solicitação ====================");
                 ImprimeLista(L);
                 printf("\n\nDigite o código do item a ser apagado");
                 res = VerificaTipo(scanf("%d",&solap));
                 while (res != 0)
                {
                    printf("Entrada inválida. Tente novamente!");
                    while (getchar() != '\n');
                    res = VerificaTipo(scanf("%d",&solap));
                }
                 int pos = Achapos(L,solap);
                 No *xapiscado = BuscaItem(L,solap);
                 printf("\n%d", xapiscado ->csol);
                 puts(xapiscado->nome);
                 printf("\n%s", xapiscado->c_eq);
                 printf("\n%d", xapiscado->prior);
                 printf("\n%d", xapiscado->peri);
                 printf("\nVocê tem certeza de que deseja deletar este item?[s/n]");
                 res = VerificaTipo(scanf(" %c",&conf));
                 while (res != 0)
                {
                    printf("Entrada inválida. Tente novamente!");
                    while (getchar() != '\n');
                    res = VerificaTipo(scanf(" %c",&conf));
                }
                 if(tolower(conf) == 's')
                 {
                    XapiskaItem(L,pos);
                 }
                 else
                 {
                    printf("\nOperação cancelada");
                 }
             break;
             case 3:
                 printf("Consultar solicitação");
                 //ConsultarSolic);
             break;
             case 4:
                 printf("Editar solicitação");
                 //EditarSolic();
             break;
             case 5:
                 printf("Exibir lista solicitação");
                 ImprimeLista(L);
             break;
             case 6:
                 printf("Exibir todas solicitação");
                 //ExibirSolic();
             break;
             case 7:
                    printf("Tem certeza que gostaria de sair?[s/n]");
                    scanf(" %c",&conf);
                    if(tolower(conf) == 's')
                    {
                        XapiskaLista(L);
                        printf("Até mais!");

                    }
                    else
                    {
                        op = 0;
                    }
             break;
             default:
                printf("Código inválido. Tente novamente!");
         }
        }while(op!=7);



        return 0;

    }
