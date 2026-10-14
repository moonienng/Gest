#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include "biblioteca_geral.h"

typedef struct reg
{
    int csol; //código da solicitação
    char c_eq[6]; //código do equipamento
    char nome[20]; //nome do equipamento
    int prior; //prioridade do equipamento
    int peri; //período até ficar pronto
    struct reg *prox;
}reg

void NovaSolic(int cods, char codeq[], char nome[],int pri,int per)
{
    reg novo = (reg *) malloc(sizeof(reg));
    reg->csol = cods;
    for(int i = 0; i<6; i++)
    {
       reg->c_eq[i] = codeq[i];
    }
    for(int i = 0; i<6; i++)
    {
       reg->nome[i] = nome[i];
    }
    //
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
                 printf("Criar nova solicitação");
                 //pedir codigo de solicitação
                 //pedir pedir código do equipamento
                 //pedir nome do equipamento
                 //pedir prioridade da solicitação
                 //pedir período até estar pronto
                 //NovaSolic(cods,codeq[],nome[],pri,per);
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
                 //ExibirFSoli();
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
