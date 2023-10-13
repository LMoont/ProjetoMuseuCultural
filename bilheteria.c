#include "bilheteria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <conio.h>

#define MAX_BILHETES 50

char temasDoUsuario[MAX_BILHETES][40], nomeUsuario[30];
int numCompras = 0, idadeUsuario, pcd;
int temaEscolhido;
char codigo[5];

void venda_bilhete() {
    setlocale(LC_ALL, "Portuguese");

    int i;

    for (int i = 0; i < MAX_BILHETES; i++) {
    strcpy(temasDoUsuario[i], "");  // Inicializa com uma string vazia
}

    printf("============== BILHETERIA =============\n\n");

    printf("Informe o seu nome: ");
    gets(nomeUsuario);

    printf("Informe a sua idade: ");
    scanf("%d", &idadeUsuario);

    printf("Você possui alguma deficiência? (1-NÃO / 2-SIM): ");
    scanf("%d", &pcd);

    while (getchar() != '\n');

    if (pcd < 1 || pcd > 2){
        printf("Opção Inválida!");
        exit(1);
    }

    printf("\nEscolha o tema que deseja visitar:\n");

    do{
        printf("\n1- 100 Anos da Semana de Arte Moderna\n");
        printf("2- 150 anos de Santos Dumont\n");
        printf("3- Jogos Olímpicos de Paris 2024\n");
        printf("4- Copa do Mundo Qatar 2022\n\n");
        printf("5- Finalizar Compra\n\n");
        printf("Escolha um tema (1 a 4) ou 5 para finalizar: ");
        scanf("%d", &temaEscolhido);

        switch(temaEscolhido){
            case 1:
                strcpy(temasDoUsuario[numCompras], "100 Anos da Semana de Arte Moderna");
                numCompras++;
            break;

            case 2:
                strcpy(temasDoUsuario[numCompras], "150 anos de Santos Dumont");
                numCompras++;
            break;

            case 3:
                strcpy(temasDoUsuario[numCompras], "Jogos Olímpicos de Paris 2024");
                numCompras++;
            break;

            case 4:
                strcpy(temasDoUsuario[numCompras], "Copa do Mundo Qatar 2022");
                numCompras++;
            break;

            case 5:
                if(numCompras == 0){
                    printf("Você não escolheu nenhum tema!\n");
                    system("pause");
                    venda_bilhete();
                }else{
                    printf("Você será direcionado ao pagamento\n\n");
                }
            break;

            default:
                printf("Opção Inválida!\n");
                system("pause");
                venda_bilhete();
            break;
        }
    }while(temaEscolhido != 5);

    printf("Tema(s) escolhido(s):\n");

    for(i=0; i<numCompras; i++){
        printf("%s\n", temasDoUsuario[i]);
    }
    
}

char ComprarMais() {
    char op;
    do {
        printf("\nDeseja adquirir mais ingressos? (S / N): ");
        op = getch();
        printf("\n");
    } while (op != 's' && op != 'n');
    return op;
}

void pagamento_bilhete(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int diaAleatorio, carterinhaEstudante, formaPagamento, pagamentoRealizado, entradaGratuita;
    float valorIngresso = 50, meiaEntrada = 25, totalPagar;
    char *diasDaSemana[] = {"Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sábado"};

    printf("\nRegras para os ingressos:\n\n");
    printf("Meia-Entrada: estudantes que apresentarem a carteirinha, PcD ou idoso (a partir de 60 anos).\n");
    printf("Entrada Gratuita: somente nas terças e quintas.\n");

    diaAleatorio =  4;  //rand() % 7;
    printf("\nHoje é %s.\n", diasDaSemana[diaAleatorio]);

   switch (diaAleatorio) {
    case 2:
    case 4:
        printf("\nA entrada é gratuita!\n\n");
        entradaGratuita = 1;
    default:
    break;
   }
        if(entradaGratuita != 1){
            if (idadeUsuario >= 60) {
            printf("\nPossui direito a meia-entrada devido à idade.\n\n");
            totalPagar = numCompras * meiaEntrada;
            printf("\nTotal a Pagar: R$%.2f\n", totalPagar);
        } else if (pcd == 2) {
            printf("\nPossui direito a meia-entrada devido a ser PcD.\n");
            totalPagar = numCompras * meiaEntrada;
            printf("\nTotal a Pagar: R$%.2f\n", totalPagar);
        } else {
            while (carterinhaEstudante < 1 || carterinhaEstudante > 2) {
                printf("\nVocê possui a carteirinha de estudante? (1-NÃO / 2-SIM): ");
                scanf("%d", &carterinhaEstudante);
        }
        
            switch (carterinhaEstudante) {
                case 2:
                    printf("\nVocê possui direito a pagar meia-entrada!\n");
                    totalPagar = numCompras * meiaEntrada;
                    printf("\nTotal a Pagar: R$%.2f\n", totalPagar);
                    break;
                case 1:
                    printf("\nVocê não possui direito a meia-entrada!\n");
                    totalPagar = numCompras * valorIngresso;
                    printf("\nTotal a Pagar: R$%.2f\n", totalPagar);
                    break;
                default:
                    printf("\nOpção Inválida!\n");
            }
        }
    }

            if(entradaGratuita != 1){
                while (formaPagamento < 1 || formaPagamento > 3) {
                    printf("\nQual a forma de pagamento?\n");
                    printf("1 - Cartão de Crédito\n");
                    printf("2 - Dinheiro\n");
                    printf("3 - Pix\n");
                    printf("\nDigite o número correspondente à forma de pagamento desejada: ");
                    scanf("%d", &formaPagamento);

                    switch (formaPagamento) {
                        case 1:
                        case 2:
                        case 3:
                            pagamentoRealizado = 1;
                            printf("\nPagamento realizado com sucesso!\n\n");
                            break;
                        default:
                            printf("\nDigite uma opção válida!\n");
                        }
                    }
                }
            
        
        gerarCod_bilhete(pagamentoRealizado, entradaGratuita);
}

void gerarCod_bilhete(int pagamentoRealizado, int entradaGratuita) {
    int i;
    char letras[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int numeros[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    srand(time(NULL));

    FILE *bilhetes;
    bilhetes = fopen("bilhetes.csv", "a");

    if (bilhetes == NULL) {
        printf("Erro ao abrir o arquivo\n\n");
        getch();
        exit(1);
    }

    for(i = 0; i < numCompras; i++) { 
        if(pagamentoRealizado){
            codigo[0] = letras[rand() % 26];
            codigo[1] = letras[rand() % 26];
            codigo[2] = '0' + numeros[rand() % 10];
            codigo[3] = '0' + numeros[rand() % 10];
            codigo[4] = '\0';

            ingressos[i].numBilhete = i+1;
            strcpy(ingressos[i].nome, nomeUsuario);
            ingressos[i].idade = idadeUsuario;
            strncpy(ingressos[i].tema, temasDoUsuario[i], sizeof(ingressos[i].tema) - 1);
            ingressos[i].tema[sizeof(ingressos[i].tema) - 1] = '\0';
            strcpy(ingressos[i].codigoBilhete, codigo);
            strcpy(ingressos[i].status, "Ativo");

            printf("\nBilhete: %d\n", i+1);
            printf("Nome: %s\n", ingressos[i].nome);
            printf("Idade: %d\n", ingressos[i].idade);
            printf("Tema: %s\n", ingressos[i].tema);
            printf("Código: %s\n", ingressos[i].codigoBilhete);

            fprintf(bilhetes, "%s; %d; %s; %s; %s\n",
            ingressos[i].nome, ingressos[i].idade, ingressos[i].tema, 
            ingressos[i].codigoBilhete, ingressos[i].status);

    }
    }

if(pagamentoRealizado){
    printf("\nTodos os bilhetes foram gerados com sucesso!\n");
} 

fclose(bilhetes);

printf("\n\n");
system("pause");

}