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

    }
}

void validaBilhete(){
    setlocale(LC_ALL, "Portuguese");
    int cont = 0, retorno = 1, encontrado = 0;
    int i;

    FILE *bilhetes;
    bilhetes = fopen("bilhetes.csv", "r");
    if(bilhetes == NULL){
        printf("Erro ao abrir o arquivo!");
        getch();
        exit(1);
    }

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
        if (strcmp(nomeUsuario, validarNome) == 0 && validarIdade == idadeUsuario &&
            strcmp(temasDoUsuario[i], validarTema) == 0 && strcmp(ingressos[i].codigoBilhete, validarCod) == 0) {
            encontrado = 1;
    }
}

    if (encontrado) {
        printf("Bilhete válido!\n");
        getch();
        alterarStatusBilhete();
    } else {
        printf("Bilhete inválido!\n");
        printf("Tente Novamente.");
        getch();
        validaBilhete();
    }

    fclose(bilhetes);
}

void alterarStatusBilhete() {
    FILE *arquivoOriginal, *arquivoTemporario;
    char linha[100];
    char ultimaLinha[100];
    int contador = 0;

    arquivoOriginal = fopen("bilhetes.csv", "r");
    arquivoTemporario = fopen("status_bilhetes.csv", "w");

    if(arquivoOriginal == NULL || arquivoTemporario == NULL){
        perror("Erro ao abrir o arquivo!");
        return;
    }

    // Ler linha por linha do arquivo original
    while (fgets(linha, sizeof(linha), arquivoOriginal) != NULL) {
        contador++;

        // Salvar a última linha
        strcpy(ultimaLinha, linha);

        // Copiar todas as linhas, exceto a última, para o arquivo temporário
        if (!feof(arquivoOriginal)) {
            fputs(linha, arquivoTemporario);
        }
    }

    // Escrever a última linha com status "Inativo"
    fprintf(arquivoTemporario, "%s; %d; %s; %s; %s\n", validarNome, validarIdade, validarTema, validarCod, "Inativo");

    // Fechar os arquivos
    fclose(arquivoOriginal);
    fclose(arquivoTemporario);

    // Verificar se há erros ao remover e renomear os arquivos
    if(remove("bilhetes.csv") != 0) {
        perror("Erro ao remover o arquivo original");
        getch();
    }

    if(rename("status_bilhetes.csv", "bilhetes.csv") != 0) {
        perror("Erro ao renomear o arquivo temporário");
        getch();
    }

    printf("Linha substituída com sucesso!\n");
}
