#include "bilheteria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAX_BILHETES 100

char bilhetesDoUsuario[MAX_BILHETES][100], nomeUsuario;
int numCompras = 0, idadeUsuario, pcd;

void venda_bilhete() {
    setlocale(LC_ALL, "Portuguese");

    int temaEscolhido;
    int i;

    printf("============== BILHETERIA =============\n\n");

    printf("Informe o seu nome: ");
    scanf("%s", &nomeUsuario);

    printf("Informe a sua idade: ");
    scanf("%d", &idadeUsuario);

    printf("Voc� possui alguma defici�ncia? (1-N�O / 2-SIM): ");
    scanf("%d", &pcd);

    if (pcd < 1 || pcd > 2){
        printf("Op��o Inv�lida!");
        exit(1);
    }

    printf("\nEscolha o(s) tema(s) que deseja visitar:\n");

    while (numCompras < MAX_BILHETES) {
        printf("\n1- 100 Anos da Semana de Arte Moderna\n");
        printf("2- 150 anos de Santos Dumont\n");
        printf("3- Jogos Ol�mpicos de Paris 2024\n");
        printf("4- Copa do Mundo Qatar 2022\n\n");
        printf("Digite o n�mero correspondente do tema que deseja visitar ou 0 (zero) para finalizar a compra: ");

        scanf("%d", &temaEscolhido);

        switch (temaEscolhido) {
            case 1:
                strcpy(bilhetesDoUsuario[numCompras], "100 Anos da Semana de Arte Moderna");
                numCompras++;
                break;
            case 2:
                strcpy(bilhetesDoUsuario[numCompras], "150 anos de Santos Dumont");
                numCompras++;
                break;
            case 3:
                strcpy(bilhetesDoUsuario[numCompras], "Jogos Ol�mpicos de Paris 2024");
                numCompras++;
                break;
            case 4:
                strcpy(bilhetesDoUsuario[numCompras], "Copa do Mundo Qatar 2022");
                numCompras++;
                break;
            case 0:
                printf("\nIngresso(s) adquirido(s): \n");
                break;
            default:
                printf("\nOp��o inv�lida. Por favor, escolha um n�mero de 1 a 4 ou 0 para finalizar a compra.\n\n");
                break;
        }

        if (temaEscolhido == 0) {
            break;
        }
    }

    if(numCompras == 0){
        printf("\nVoc� n�o escolheu nenhum tema!\n\n");
        exit(1);
    }

    for(i = 0; i < numCompras; i++) { 
        printf("%s\n", bilhetesDoUsuario[i]); 

    }   
    
}

void pagamento_bilhete(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int diaAleatorio, carterinhaEstudante, formaPagamento;
    float valorIngresso = 50, meiaEntrada = 25, totalPagar;
    char *diasDaSemana[] = {"Domingo", "Segunda-feira", "Ter�a-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "S�bado"};

    printf("\nRegras para os ingressos:\n\n");
    printf("Meia-Entrada: estudantes que apresentarem a carteirinha, PcD ou idoso (a partir de 60 anos).\n");
    printf("Entrada Gratuita: somente nas ter�as e quintas.\n");

    diaAleatorio = rand() % 7;
    printf("\nHoje � %s.\n", diasDaSemana[diaAleatorio]);

   switch (diaAleatorio) {
    case 2:
    case 4:
        printf("\nA entrada � gratuita!\n\n");
        break;
    default:
        if (idadeUsuario >= 60) {
            printf("\nPossui direito a meia-entrada devido � idade.\n\n");
            totalPagar = numCompras * meiaEntrada;
            printf("\nTotal a Pagar: R$%.2f\n", totalPagar);
        } else if (pcd == 2) {
            printf("Possui direito a meia-entrada devido a ser PcD.\n");
            totalPagar = numCompras * meiaEntrada;
            printf("\nTotal a Pagar: R$%.2f\n", totalPagar);
        } else {
            while (carterinhaEstudante < 1 || carterinhaEstudante > 2) {
                printf("\nVoc� possui a carteirinha de estudante? (1-N�O / 2-SIM): ");
                scanf("%d", &carterinhaEstudante);

                switch (carterinhaEstudante) {
                    case 2:
                        printf("\nVoc� possui direito a pagar meia-entrada!\n");
                        totalPagar = numCompras * meiaEntrada;
                        printf("\nTotal a Pagar: R$%.2f\n", totalPagar);
                        break;
                    case 1:
                        printf("\nVoc� n�o possui direito a meia-entrada!\n");
                        totalPagar = numCompras * valorIngresso;
                        printf("\nTotal a Pagar: R$%.2f\n", totalPagar);
                        break;
                    default:
                        printf("\nOp��o Inv�lida!\n");
                }
            }
        }

            while (formaPagamento < 1 || formaPagamento > 3) {
                printf("\nQual a forma de pagamento?\n");
                printf("1 - Cart�o de Cr�dito\n");
                printf("2 - Dinheiro\n");
                printf("3 - Pix\n");
                printf("\nDigite o n�mero correspondente � forma de pagamento desejada: ");
                scanf("%d", &formaPagamento);

                switch (formaPagamento) {
                    case 1:
                    case 2:
                    case 3:
                        printf("\nPagamento realizado com sucesso!");
                        break;
                    default:
                        printf("\nDigite uma op��o v�lida!\n");
                }
            }
        
        break;
}

printf("\n\n");
system("pause");

}