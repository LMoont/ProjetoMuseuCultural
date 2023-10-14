#include "bilheteria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

char validarTema[40];
void alterarStatusBilhete();
void validaBilhete();

char validarNome[40], validarCod[6];
int validarIdade;

void entradaTema(){ 
 
    printf("Em qual tema deseja entrar?\n\n");

    printf("1-100 Anos da Semana de Arte Moderna\n2-150 anos de Santos Dumont\n3-Jogos Olímpicos de Paris 2024\n4-Copa do Mundo Qatar 2022\n\n");
    scanf("%d", &temaEscolhido);
    switch (temaEscolhido) {
        case 1:
            strcpy(validarTema, "100 Anos da Semana de Arte Moderna");
            validaBilhete();
            break;
        case 2:
            strcpy(validarTema, "150 anos de Santos Dumont");
            validaBilhete();
            break;
        case 3:
            strcpy(validarTema, "Jogos Olímpicos de Paris 2024");
            validaBilhete();
            break;
        case 4:
            strcpy(validarTema, "Copa do Mundo Qatar 2022");
            validaBilhete();
            break;
        default:
            printf("Opção Inválida! Escolha uma opção entre 1 e 4.\n\n");
            entradaTema();
    }
}

void validaBilhete(){
    setlocale(LC_ALL, "Portuguese");
    int cont = 0, retorno = 1, encontrado = 0;
    int i;

    printf("Insira as informações presentes no seu bilhete:\n\n");

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("Nome: ");
    fgets(validarNome, sizeof(validarNome), stdin);
    // Remove the trailing newline character
    validarNome[strcspn(validarNome, "\n")] = 0;

    printf("Idade: ");
    scanf("%d", &validarIdade);
    
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("Código: ");
    fgets(validarCod, sizeof(validarCod), stdin);
    
    validarCod[strcspn(validarCod, "\n")] = 0;

    for (int i = 0; i < numCompras; i++) {
        if (strcmp(ingressos[0].nome, validarNome) == 0 && validarIdade == ingressos[0].idade &&
            strcmp(ingressos[i].tema[i], validarTema) == 0 && strcmp(ingressos[i].codigoBilhete[i], validarCod) == 0 &&
            strcmp(ingressos[i].status[i], "Ativo") == 0 ){
            encontrado = 1;
    }
}

    if (encontrado) {
        printf("Bilhete válido!\n");
        getch();
        alterarStatusBilhete();
    } else {
        printf("Bilhete inválido!\n");
        printf("Tente Novamente.\n\n");
        getch();
        validaBilhete();
    }

}

void alterarStatusBilhete() {
    int i;

    FILE *bilhetes;
    bilhetes = fopen("bilhetes.csv", "w");
    if(bilhetes == NULL){
        printf("Erro ao abrir o arquivo!");
        getch();
        exit(1);
    }
    
    for (i = 0; i < numCompras; i++) {
    if (strcmp(ingressos[i].codigoBilhete[i], validarCod) == 0) {
        strcpy(ingressos[i].status[i], "Inativo");
        break;  // Sai do loop após encontrar o código desejado
    }
}

    for(i=0; i < numCompras; i++){
        fprintf(bilhetes, "%s; %d; %s; %s; %s\n",
        ingressos[0].nome, ingressos[0].idade, ingressos[i].tema[i], 
        ingressos[i].codigoBilhete[i], ingressos[i].status[i]);
    }
    
    fclose(bilhetes);
    printf("Gravação feita com sucesso!\n");
    getch();
}
