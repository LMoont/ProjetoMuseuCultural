#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

void centralizarTexto(char *texto) {
    printf("\t%s", texto);
    Sleep(100); // Atraso de 100 milissegundos
}

void exibirArteModrn(){
    setlocale(LC_ALL, "Portuguese");

    int op;
    char linha[100];

    FILE *contextoHistorico;

    contextoHistorico = fopen("Temas/ArteModerna/contexto_historico.txt", "r");

    if(contextoHistorico == NULL){
        printf("Erro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    printf("\n\n\t\t\t\t============== 100 Anos da Semana de Arte Moderna =============\n\n\n\n");

    printf("\t\t\t\tNavegue e explore os seguintes tópicos:\n\n");
    printf("\t\t\t\t1 - Contexto Histórico e Cultural\n\t\t\t\t2 - Participantes e Obras Marcantes\n\t\t\t\t3 - Impacto e Legado da Semana de Arte Moderna\n\t\t\t\t4 - Principais Características do Modernismo Brasileiro\n\t\t\t\t0 - Sair\n\n\t\t\t\tOp: ");
    scanf("%d", &op);

    switch (op){
        case 1:
            system("cls");
            printf("\n\n\n\n");
            while (fgets(linha, sizeof(linha), contextoHistorico) != NULL) {
                centralizarTexto(linha);
            }
            getch();
            system("cls");

            break;

        case 2:
            // Lógica para o caso 2
            break;

        case 3:
            // Lógica para o caso 3
            break;

        case 4:
            // Lógica para o caso 4
            break;

        case 0:
            printf("\n\t\t\t\tObrigado pela visita!");
            getch();
            exit(0);
            break;

        default:
            while (op < 1 || op > 4){
                printf("\n\t\t\t\tOpção inválida! por favor escolha uma opção entre 1 e 4: ");
                scanf("%d", &op);
            }
            break;
    }

    fclose(contextoHistorico);
}
