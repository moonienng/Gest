#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "biblioteca_geral.h"

void NovaSolic(lista *L,int cods, char *codeq, char *nome,int pri,int per)
{
    No *novo;
    //cria um elemento novo
    novo = (No *) malloc(sizeof(No));
    //guarda o código da solicitação
    novo->csol=cods;
    //guarda o código do equipamento
    for(int i = 0; i<6; i++)
    {
       novo->c_eq[i] = codeq[i];
    }
    //guarda o nome do equipamento
    strcpy(novo->nome,nome);
    //guarda o período e a prioridade
    novo->peri = per;
    novo->prior = pri;
    novo->prox = NULL;
    InsereOrdenado(L,novo);
}
//função que cria uma nova solicitação:
// 1- cria o registro e preenche, codigo de solicitação, codigo do equipamento e nome
// 2- é chamado pela de cima, altera o período e prioridade
// 3- insere na lista na posição correta
    int main()
    {
        setlocale(LC_ALL, "Portuguese");
        int op;
        char conf;
        lista *L = NULL;
        L = CriaLista();

        /*
        \nMenu:
        \n1 - Criar nova solicitação
        \n2 - Apagar Solicitação
        \n3 - Consultar solicitação
        \n4 - Editar solicitação
        \n5 - Exibir fila de manutenção
        \n6 - Exibir solicitações
        \n7 - Sair

        - Cada código é referente a uma função do sistema
        - Para as funções funcionarem é necessário uma biblioteca com funções básicas de lista
        */
         do
            {
         op=0;
         printf("\nSistema de manutenção");
         printf("\nMenu: \n1 - Criar nova solicitação\n2 - Apagar Solicitação\n3 - Consultar solicitação\n4 - Editar solicitação\n5 - Exibir fila de manutenção\n6 - Exibir solicitações\n7 - Sair");
            printf("\nDigite o código:");
            while (scanf("%i",&op) == 0)
                {
                printf("Código inválido. Tente novamente!");
                while (getchar() != '\n');
            }


         system("cls");
         switch(op)
         {
             case 1:
                 //variáveis que eu preciso coletar pra criar
                 int cods; //código da solicitação
                 char codeq[6] = "AAA111"; //código do equipamento
                 char nome[20]; //nome do equipamento
                 int pri; //prioridade do equipamento
                 int per; //período até ficar pronto

                 printf("\t\t==================== Criar nova solicitação ====================");
                 //pedir codigo de solicitação
                 printf("\nDigite o código de solicitação:");
                 scanf("%d",&cods);
                 getchar();

                 //pedir pedir código do equipamento
                 printf("\nDigite o código do equipamento:");

                 //pedir nome do equipamento
                 printf("\nDigite o nome do equipamento:");
                 fgets(nome, sizeof(nome), stdin);

                 //pedir prioridade da solicitação
                 printf("\nRelação de prioridades:");
                 printf("\n1  -> Alta: manutenção urgente\n2  -> Média: deve ser feita em breve\n3 -> Baixa: pode aguardar");
                 printf("\nDigite a prioridade do equipamento:");
                 scanf("%d",&pri);

                 //pedir período até estar pronto
                 printf("\nRelação de períodos:");
                 printf("\nPrioridade 1  -> entre 1 e 7 dias\nPrioridade 2  -> entre 1 e 15 dias\nPrioridade 3 -> entre 1 e 20 dias");
                 printf("\nDigite o período de manutenção:");
                 scanf("%d",&per);

                 NovaSolic(L,cods,codeq,nome,pri,per);
             break;
             case 2:
                 printf("Apagar solicitação");
                 //ApagarSolic();
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