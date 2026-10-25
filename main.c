#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "biblioteca_geral.h"
#include "biblioteca_sia.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op = 7;
    char conf;
    lista *L = NULL;
    L = CriaLista();
    do
    {
        system("cls");
        printf("\nSistema de manutenção");
        printf("\nMenu: \n1 - Criar nova solicitação\n2 - Apagar Solicitação\n3 - Consultar solicitação\n4 - Editar solicitação\n5 - Exibir fila de manutenção\n6 - Exibir solicitações\n0 - Sair");
        printf("\nDigite o código:");
        int res = VerificaTipo(scanf("%i", &op));
        while (res != 0)
        {
            printf("Código inválido. Tente novamente!");
            while (getchar() != '\n')
                ;
            res = VerificaTipo(scanf("%i", &op));
        }

        system("cls");
        switch (op)
        {
        case 1:
            int cods;   
            char codeq[7]; 
            char nome[21]; 
            int pri;
            int per;

            printf("\t\t==================== Criar nova solicitação ====================");
            int res;
            do
            {
                printf("\nDigite o código de solicitação:");
                res = VerificaTipo(scanf("%d", &cods));
                while (getchar() != '\n');
                while (res != 0)
                {
                    printf("Entrada inválida. Tente novamente!");
                    while (getchar() != '\n');
                    res = VerificaTipo(scanf("%d", &cods));
                }

                res = VerificarCSol(L, cods);
            } while (res == 1);

            printf("\nDigite o código do equipamento:");
            do
            {
            fgets(codeq, sizeof(codeq), stdin);
            while (getchar() != '\n');
            res = VerificaEquipamento(codeq); 
            if (res != 0)
                {
                    printf("Entrada inválida. Tente novamente!");
                }

            } while (res == 1);

            printf("\nDigite o nome do equipamento:");
            fgets(nome, sizeof(nome), stdin);

            printf("\nRelação de prioridades:");
            printf("\n1  -> Alta: manutenção urgente\n2  -> Média: deve ser feita em breve\n3 -> Baixa: pode aguardar");
            printf("\nDigite a prioridade do equipamento:");
            res = VerificaTipo(scanf("%d", &pri));
            while (res != 0)
            {
                printf("Entrada inválida. Tente novamente!");
                while (getchar() != '\n');
                res = VerificaTipo(scanf("%d", &pri));
            }

            printf("\nRelação de períodos:");
            printf("\nPrioridade 1  -> entre 1 e 7 dias\nPrioridade 2  -> entre 1 e 15 dias\nPrioridade 3 -> entre 1 e 20 dias");
            printf("\nDigite o período de manutenção:");
            res = VerificaTipo(scanf("%d", &per));
            while (res != 0)
            {
                printf("Entrada inválida. Tente novamente!");
                while (getchar() != '\n')
                    ;
                res = VerificaTipo(scanf("%d", &per));
            }
            NovaSolic(L, cods, codeq, nome, pri, per);
            system("pause");
            break;
        case 2:
            int solap;
            char conf;
            printf("\t\t==================== Apagar solicitação ====================");
            int v = VaziaLista(L);
            if(v == 1)
            {
                printf("Não há itens a serem apagados");
            }
            else
            {
            ImprimeLista(L);
            No *xapiscado = NULL;
            int pos;
            do
            {
                printf("\n\nDigite o código do item a ser apagado");
                res = VerificaTipo(scanf("%d", &solap));
                while (res != 0)
                {
                    printf("Entrada inválida. Tente novamente!");
                    while (getchar() != '\n')
                        ;
                    res = VerificaTipo(scanf("%d", &solap));
                }
                pos = Achapos(L, solap);
                xapiscado = BuscaItem(L, solap);
                if(xapiscado == NULL)
                {
                    printf("Solicitação não encontrada.");
                }
            }while(xapiscado == NULL);
            ConsultarSolic(L, xapiscado->csol);
            printf("\nVocê tem certeza de que deseja deletar este item?[s/n]");
            res = VerificaTipo(scanf(" %c", &conf));
            while (res != 0)
            {
                printf("Entrada inválida. Tente novamente!");
                while (getchar() != '\n')
                    ;
                res = VerificaTipo(scanf(" %c", &conf));
            }
            if (tolower(conf) == 's')
            {
                XapiskaItem(L, pos);
            }
            else
            {
                printf("\nOperação cancelada");
            }
            }
            system("pause");
            break;
        case 3:
            int cod;
            printf("\t\t==================== Consultar solicitação ====================");
            printf("\nDigite o código de solicitação:");
            res = VerificaTipo(scanf("%d", &cod));
            while (res != 0)
            {
                printf("Entrada inválida. Tente novamente!");
                while (getchar() != '\n')
                    ;
                res = VerificaTipo(scanf("%d", &cod));
            }
            ConsultarSolic(L, cod);
            system("pause");
            break;
        case 4:
            int pra;
            printf("\t\t==================== Editar solicitação ====================");
            printf("\nDigite o código de solicitação:");
            res = VerificaTipo(scanf("%d", &cod));
            while (res != 0)
            {
                printf("Entrada inválida. Tente novamente!");
                while (getchar() != '\n')
                    ;
                printf("\nDigite o código de solicitação:");
                res = VerificaTipo(scanf("%d", &cod));
            }
            ConsultarSolic(L, cod);
            do
            {
                printf("\nDigite a nova prioridade: ");
                res = VerificaTipo(scanf("%d", &pri));
                while (res != 0)
                {
                    printf("Entrada inválida. Tente novamente!");
                    while (getchar() != '\n')
                        ;
                    printf("\nDigite a nova prioridade: ");
                    res = VerificaTipo(scanf("%d", &pri));
                }
                printf("\nDigite o novo prazo: ");
                res = VerificaTipo(scanf("%d", &pra));
                while (res != 0)
                {
                    printf("Entrada inválida. Tente novamente!");
                    while (getchar() != '\n')
                        ;
                    printf("\nDigite o novo prazo: ");
                    res = VerificaTipo(scanf("%d", &pra));
                }
                res = VerificarIntervalo(pri, pra);
            } while (res == 1);

            EditarSolic(L, cod, pri, pra);
            printf("\nSolicitação após alteração:");
            ConsultarSolic(L, cod);
            system("pause");
            break;
        case 5:
            printf("\t\t==================== Lista de manutenção ====================");
            ListaManutencao(L);
            system("pause");
            break;
        case 6:
            printf("\t\t==================== Lista de solicitações ====================");
            ImprimeLista(L);
            system("pause");
            break;
        case 0:
            printf("Tem certeza que gostaria de sair?[s/n]:");
            scanf(" %c", &conf);
            if (tolower(conf) == 's')
            {
                XapiskaLista(L);
                printf("Até mais!");
            }
            else
            {
                op = 7;
            }
            break;
        default:
            printf("Código inválido. Tente novamente!");
        }
    } while (op != 0);
    return 0;
}