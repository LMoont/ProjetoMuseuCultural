#include "bilheteria.h"
#include "arte_moderna.h"
#include "santos_dumont.h"
#include "olimpiadas.h"
#include "copa_catar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

#define MAX_LINHA 1024

char validarTema[40];
void alterarStatusBilhete();
void validaBilhete();
void menuEntrada();
void visualizarBilhete();

char validarNome[40], validarCod[6];
int validarIdade;

void entradaTema(){

    printf("\n\n\t\t\t\t============== BEM-VINDO AO MUSEU CULTURAL ==============\n\n");
 
    printf("\n\t\t\t\tPor favor, escolha um tema para a sua visita.\n\n");

    printf("\n\t\t\t\t1 - 100 ANOS DA SEMANA DE ARTE MODERNA\n\t\t\t\t2 - 150 ANOS DE SANTOS DUMONT\n\t\t\t\t3 - JOGOS OLIMPICOS PARIS 2024\n\t\t\t\t4 - COPA DO MUNDO CATAR 2022\n\t\t\t\t5 - Voltar\n\n");
    printf("\t\t\t\tOpção: ");
    scanf("%d", &temaEscolhido);
    switch (temaEscolhido) {
        case 1:
            strcpy(validarTema, "100 ANOS DA SEMANA DE ARTE MODERNA");
            system("cls");
            validaBilhete();
            system("cls");
            menuArteModrn();
            break;
        case 2:
            strcpy(validarTema, "150 ANOS DE SANTOS DUMONT");
            system("cls");
            validaBilhete();
            system("cls");
            menuSantosDumont();
            break;
        case 3:
            strcpy(validarTema, "JOGOS OLIMPICOS PARIS 2024");
            system("cls");
            validaBilhete();
            system("cls");
            menuOlimpiadas();
            break;
        case 4:
            strcpy(validarTema, "COPA DO MUNDO CATAR 2022");
            system("cls");
            validaBilhete();
            system("cls");
            menuCopaCatar();
            break;
        case 5:
            system("cls");
            menuEntrada();
        default:
            printf("\n\n\t\t\t\tOpção Inválida! Escolha uma opção entre 1 e 4.\n\n");
            getch();
            system("cls");
            entradaTema();
    }
}

void validaBilhete(){
    setlocale(LC_ALL, "Portuguese");
    int cont = 0, retorno = 1, encontrado = 0;
    int i;
    char linha[MAX_LINHA];
    char *token;

    printf("\n\n\t\t\t\t============== BEM-VINDO AO MUSEU CULTURAL ==============\n\n");

    printf("\n\t\t\t\tInsira as informações presentes no seu bilhete:\n\n");

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("\n\t\t\t\tNome: ");
    fgets(validarNome, sizeof(validarNome), stdin);

    validarNome[strcspn(validarNome, "\n")] = 0;

    for (int i = 0; validarNome[i]; i++){
        validarNome[i] = toupper(validarNome[i]);
    }

    printf("\n\t\t\t\tIdade: ");
    scanf("%d", &validarIdade);
    
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("\n\t\t\t\tCódigo: ");
    fgets(validarCod, sizeof(validarCod), stdin);
    
    validarCod[strcspn(validarCod, "\n")] = 0;

    for (int i = 0; validarCod[i]; i++){
        validarCod[i] = toupper(validarCod[i]);
    }

    FILE *bilhetes = fopen("bilhetes.txt", "r");

    if(bilhetes == NULL){
        printf("Erro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    struct Registros registro[MAX_BILHETES];
    
    while (fread(&registro, sizeof(struct Registros), 1, bilhetes)){
    for (int i = 0; i < MAX_BILHETES; i++) {
        if (strcmp(registro[i].nome, validarNome) == 0 && registro[i].idade == validarIdade &&
            strcmp(registro[i].tema, validarTema) == 0 && strcmp(registro[i].codigoBilhete, validarCod) == 0 &&
            strcmp(registro[i].status, "Ativo") == 0) {
            encontrado = 1;
            break;
        }
    }
}

if (encontrado) {
    printf("\n\t\t\t\tBilhete válido!\n");
    getch();
    alterarStatusBilhete();
} else {
    printf("\n\t\t\t\tBilhete inválido!\n");
    printf("\n\t\t\t\tVisualize as informações do seu bilhete novamente para garantir\n\t\t\t\tque nenhuma informação está sendo digitada incorretamente.");
    getch();
    system("cls");
    visualizarBilhete();
}

fclose(bilhetes);

}

void alterarStatusBilhete() {
    int i;

    FILE *bilhetesCsv, *bilhetesTxt;
    bilhetesCsv = fopen("bilhetes.csv", "w");
    bilhetesTxt = fopen("bilhetes.txt", "ab");
    if(bilhetesCsv == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }
    
    for (i = 0; i < numCompras; i++) {
        if (strcmp(ingressos[i].codigoBilhete, validarCod) == 0) {
            strcpy(ingressos[i].status, "Inativo");
            fseek(bilhetesTxt, i * sizeof(struct Registros), SEEK_SET);
            fwrite(&ingressos[i], sizeof(struct Registros), 1, bilhetesTxt);
            break; 
        }
    } 

    for(i=0; i < numCompras; i++){
        fprintf(bilhetesCsv, "%s; %d; %s; %s; %s\n",
        ingressos[i].nome, ingressos[i].idade, ingressos[i].tema, 
        ingressos[i].codigoBilhete, ingressos[i].status);
    }
    
    fclose(bilhetesCsv);
    fclose(bilhetesTxt);
    printf("\n\t\t\t\tO status do bilhete foi alterado!\n");
    getch();
}
