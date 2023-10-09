#include "bilheteria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BILHETES 100

char bilhetesDoUsuario[MAX_BILHETES][100];
int numCompras = 0;

void venda_bilhete() {
    int temaEscolhido;
    int i;

    FILE *bilhetes;
    bilhetes = fopen("bilhetes.txt", "w");

    if (bilhetes == NULL) {
        printf("Erro ao abrir o arquivo\n\n");
        return 1;
    }

    printf("============== BILHETERIA =============\n");

    while (numCompras < MAX_BILHETES) {
        printf("Digite o número correspondente do tema que deseja visitar ou 0 (zero) para finalizar a compra:\n\n");
        printf("1- 100 Anos da Semana de Arte Moderna;\n");
        printf("2- 150 anos de Santos Dumont;\n");
        printf("3- Jogos Olímpicos de Paris 2024;\n");
        printf("4- Copa do Mundo Qatar 2022;\n");

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
                strcpy(bilhetesDoUsuario[numCompras], "Jogos Olímpicos de Paris 2024");
                numCompras++;
                break;
            case 4:
                strcpy(bilhetesDoUsuario[numCompras], "Copa do Mundo Qatar 2022");
                numCompras++;
                break;
            case 0:
                printf("Compra finalizada!\n");
                break;
            default:
                printf("Opção inválida. Por favor, escolha um número de 1 a 4 ou 0 para finalizar a compra.\n");
                break;
        }

        if (temaEscolhido == 0) {
            break;
        }
    }

    for(i = 0; i < numCompras; i++) { 
        printf("\n%s", bilhetesDoUsuario[i]); 
        fprintf(bilhetes, "\n%s", bilhetesDoUsuario[i]); 
    }

    fclose(bilhetes);

}