#include "bilheteria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>

#define MAX_BILHETES 50

void escolhaTema();
void menuEntrada();

char temasDoUsuario[MAX_BILHETES][40], nomeUsuario[30];
int numCompras = 0, qtd = 0;
int temaEscolhido, idadeUsuario;
char codigo[5], pcd;
int pagamentoRealizado = 0;

void dadosUsuario() {

    int i;
    int op;

    printf("\n\n\n\t\t\t\t======================= BILHETERIA ======================\n\n\n");

    printf("\n\t\t\t\tInsira as informações solicitadas antes de escolher o tema.\n\n\n");

    printf("\t\t\t\tNome: ");
    gets(nomeUsuario);

    for (int i = 0; nomeUsuario[i]; i++) {
        nomeUsuario[i] = toupper(nomeUsuario[i]);
    }

    printf("\n\t\t\t\tIdade: ");
    scanf("%d", &idadeUsuario);

    printf("\n\t\t\t\tPossui alguma deficiência? (s/n): ");
    scanf(" %c", &pcd);

    while ((pcd != 's') && (pcd != 'S') && (pcd != 'n') && (pcd != 'N')){
        printf("\n\t\t\t\tOpção inválida! por favor digite S (Sim) ou N (Não): ");
        scanf(" %c", &pcd);
    }

    do{
        printf("\n\n\t\t\t\tDigite 1 para continuar ou 2 para alterar algum dado: ");
        scanf("%d", &op);
        fflush(stdin);

        if(op == 2){
            system("cls");
            dadosUsuario();
        }else if(op == 1){
            system("cls");
            escolhaTema();
        }
    }while(op != 1 && op != 2);
}
    
void escolhaTema(){
    int i;
    char op = 's';

    printf("\n\n\t\t\t\t============== BILHETERIA =============\n\n\n");

    printf("\n\t\t\t\tEscolha o tema que deseja visitar:\n\n");

        printf("\n\t\t\t\t1 - 100 ANOS DA SEMANA DE ARTE MODERNA\n");
        printf("\n\t\t\t\t2 - 150 ANOS DE SANTOS DUMONT\n");
        printf("\n\t\t\t\t3 - JOGOS OLIMPICOS PARIS 2024\n");
        printf("\n\t\t\t\t4 - COPA DO MUNDO CATAR 2022\n\n");
        printf("\t\t\t\tOpção: ");
        scanf("%d", &temaEscolhido);

        switch(temaEscolhido){
            case 1:
                strcpy(ingressos[numCompras].tema, "100 ANOS DA SEMANA DE ARTE MODERNA");
                strcpy(ingressos[numCompras].status, "Ativo");
                strcpy(temasDoUsuario[numCompras], "100 ANOS DA SEMANA DE ARTE MODERNA");
                strcpy(ingressos[numCompras].nome, nomeUsuario);
                ingressos[numCompras].idade = idadeUsuario;
                numCompras++;
                qtd++;
            break;

            case 2:
                strcpy(ingressos[numCompras].tema, "150 ANOS DE SANTOS DUMONT");
                strcpy(ingressos[numCompras].status, "Ativo");
                strcpy(ingressos[numCompras].nome, nomeUsuario);
                ingressos[numCompras].idade = idadeUsuario;
                strcpy(temasDoUsuario[numCompras], "150 ANOS DE SANTOS DUMONT");
                numCompras++;
                qtd++;
            break;

            case 3:
                strcpy(ingressos[numCompras].tema, "JOGOS OLIMPICOS PARIS 2024");
                strcpy(ingressos[numCompras].status, "Ativo");
                strcpy(temasDoUsuario[numCompras], "JOGOS OLIMPICOS PARIS 2024");
                strcpy(ingressos[numCompras].nome, nomeUsuario);
                ingressos[numCompras].idade = idadeUsuario;
                numCompras++;
                qtd++;
            break;

            case 4:
                strcpy(ingressos[numCompras].tema, "COPA DO MUNDO CATAR 2022");
                strcpy(ingressos[numCompras].status, "Ativo");
                strcpy(temasDoUsuario[numCompras], "COPA DO MUNDO CATAR 2022");
                strcpy(ingressos[numCompras].nome, nomeUsuario);
                ingressos[numCompras].idade = idadeUsuario;
                numCompras++;
                qtd++;
            break;

            default:
                printf("\t\t\t\tOpção Inválida! Escolha uma opção entre 1 e 4.\n");
                getch();
                system("cls");
                escolhaTema();
            break;
    }

    printf("\n\t\t\t\tTema(s) escolhido(s):\n\n");

    for(i=0; i<numCompras; i++){
        printf("\t\t\t\t%s\n", temasDoUsuario[i]);
    }

    do{
    printf("\n\t\t\t\tDeseja adquirir mais ingressos? (s/n): ");
    scanf(" %c", &op);
        if (op == 's' || op == 'S') {
            system("cls");
            escolhaTema();
        }else if(op == 'n' || op == 'N'){
            printf("\n\n\t\t\t\tVocê será direcionado ao pagamento!\n\n\n");
            system("pause");
            system("cls");
            pagamento();
        }
    }while(op != 's' && op != 'S' && op != 'n' && op != 'N');

}

void pagamento(){
    srand(time(NULL));

    char carterinhaEstudante, formaPagamento;
    int diaAleatorio, entradaGratuita;
    float valorIngresso = 30, meiaEntrada = 15, totalPagar;
    char *diasDaSemana[] = {"Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sábado"};

    printf("\n\n\n\t\t\t\t================= BILHETERIA ================\n\n\n\n");
    
    diaAleatorio = rand() % 7;
    printf("\n\t\t\t\tHoje é %s.\n\n", diasDaSemana[diaAleatorio]);

   switch (diaAleatorio) {
    case 2:
    case 4:
        printf("\n\t\t\t\tA entrada é gratuita!\n\n");
        entradaGratuita = 1;
        pagamentoRealizado = 1;
        qtd = 0;
    default:
    break;
   }
        if(entradaGratuita != 1){
            if (idadeUsuario >= 60) {
            printf("\n\t\t\t\tTem direito a meia-entrada devido a idade.\n\n");
            totalPagar = qtd * meiaEntrada;
            printf("\n\t\t\t\tTotal a Pagar: R$%.2f\n", totalPagar);
        } else if (pcd == 's' || pcd == 'S') {
            printf("\n\t\t\t\tTem direito a meia-entrada devido a ser PcD.\n");
            totalPagar = qtd * meiaEntrada;
            printf("\n\t\t\t\tTotal a Pagar: R$%.2f\n", totalPagar);
        } else {
            while (carterinhaEstudante != 's' && carterinhaEstudante != 'S' &&
                    carterinhaEstudante != 'n' && carterinhaEstudante != 'N') {
                printf("\n\t\t\t\tPossui carteirinha de estudante? (s/n): ");
                scanf(" %c", &carterinhaEstudante);
        }
        
            switch (carterinhaEstudante) {
                case 's':
                case 'S':
                    printf("\n\t\t\t\tTem direito a meia-entrada!\n");
                    totalPagar = qtd * meiaEntrada;
                    printf("\n\t\t\t\tTotal a Pagar: R$%.2f\n", totalPagar);
                    break;
                case 'n':
                case 'N':
                    printf("\n\t\t\t\tNão tem direito a meia-entrada!\n");
                    totalPagar = qtd * valorIngresso;
                    printf("\n\t\t\t\tTotal a Pagar: R$%.2f\n\n", totalPagar);
                    break;
                default:
                    printf("\n\t\t\t\tOpção Inválida!\n");
            }
        }
    }

    printf("\n\t\t\t\t---------------------------------------------\n\n");

            if(entradaGratuita != 1){
                while ((formaPagamento != '1') && (formaPagamento != '2') && (formaPagamento != '3')) {
                    printf("\n\t\t\t\tQual a forma de pagamento?\n\n");
                    printf("\t\t\t\t1 - Cartão de Crédito\n\n");
                    printf("\t\t\t\t2 - Dinheiro\n\n");
                    printf("\t\t\t\t3 - Pix\n\n");
                    printf("\n\t\t\t\tOpção: ");
                    scanf("%s", &formaPagamento);

                    switch (formaPagamento) {
                        case '1':
                        case '2':
                        case '3':
                            pagamentoRealizado = 1;
                            qtd = 0;
                            printf("\n\t\t\t\tPagamento realizado com sucesso!");
                            break;
                        default:
                            printf("\n\t\t\t\tDigite uma opção válida!\n");
                        }
                    }
                }

    for (int i = 0; i < MAX_BILHETES; i++) {
        memset(temasDoUsuario[i], 0, 40 * sizeof(char));
}
            
        printf("\n\n\n");
        system("pause");
        system("cls");
        gerarCod(pagamentoRealizado, entradaGratuita);
}

void gerarCod(int pagamentoRealizado, int entradaGratuita) {
    int i;

    printf("\n\n\n\t\t\t\t================= BILHETERIA ================\n\n\n\n");

    FILE *bilhetes;
    bilhetes = fopen("bilhetes.txt", "wb");

    if (bilhetes == NULL) {
        printf("\t\t\t\tErro ao abrir o arquivo\n\n");
        getch();
        exit(1);
    }

    srand(time(NULL));

    char letras[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int numeros[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(i = 0; i < numCompras; i++) { 
        if(pagamentoRealizado){
            codigo[0] = letras[rand() % 26];
            codigo[1] = letras[rand() % 26];
            codigo[2] = '0' + numeros[rand() % 10];
            codigo[3] = '0' + numeros[rand() % 10];
            codigo[4] = '\0';

            strcpy(ingressos[i].codigoBilhete, codigo);

            printf("\n\t\t\t\tBilhete: %d\n", i+1);
            printf("\t\t\t\tNome: %s\n", ingressos[i].nome);
            printf("\t\t\t\tIdade: %d\n", ingressos[i].idade);
            printf("\t\t\t\tTema: %s\n", ingressos[i].tema);
            printf("\t\t\t\tCódigo: %s\n", ingressos[i].codigoBilhete);
            printf("\t\t\t\tStatus: %s\n", ingressos[i].status);

            fwrite(&ingressos[i], sizeof(struct Registros), numCompras, bilhetes);

    }
    }

    if(pagamentoRealizado){
        printf("\n\t\t\t\tTodos os bilhetes foram gerados com sucesso!\n");
    } 

    printf("\n\t\t\t\tVocê poderá visualizar o(s) seu(s) ingresso(s)\n\t\t\t\tquando quiser no menu principal.");

    fclose(bilhetes);

    printf("\n\n\n");
    system("pause");
    system("cls");
    menuEntrada();

}