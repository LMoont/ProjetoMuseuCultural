#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

void questSantosDumont();
void menuEntrada();
void centralizarTexto();

void menuSantosDumont(){
    setlocale(LC_ALL, "Portuguese");

    int op;
    char linha[100];

    FILE *biografia, *invencoes, *honrarias, *impacto;

    biografia = fopen("Temas/SantosDumont/biografia.txt", "r");
    invencoes = fopen("Temas/SantosDumont/invencoes.txt", "r");
    honrarias = fopen("Temas/SantosDumont/honrarias.txt", "r");
    impacto = fopen("Temas/SantosDumont/impacto.txt", "r");

    if(biografia == NULL || invencoes == NULL ||
    honrarias == NULL || impacto == NULL){
        printf("Erro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    printf("\n\n\n\t\t\t\t================= 150 Anos de Santos Dumont ================\n\n\n\n\n\n");

    printf("\t\t\t\tEscolha uma opção para explorar cada tópico e responda um pequeno\n\t\t\t\tquestionário sobre o tema para testar seus conhecimentos:\n\n\n");
    printf("\t\t\t\t1 - Biografia e Trajetória de Santos Dumont\n\n\t\t\t\t2 - Invenções e Contribuições\n\n\t\t\t\t3 - Reconhecimento e Honrarias Recebidas\n\n\t\t\t\t4 - Impacto no Desenvolvimento da Aviação Mundial\n\n\t\t\t\t5 - Questionário e Avaliação do Tema\n\n\t\t\t\t6 - Voltar\n\n");
    printf("\n\t\t\t\tOpção: ");
    scanf("%d", &op);

    switch (op){
        case 1:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), biografia) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuSantosDumont();
            break;

        case 2:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), invencoes) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuSantosDumont();
            break;

        case 3:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), honrarias) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuSantosDumont();
            break;

        case 4:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), impacto) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuSantosDumont();
            break;

        case 5:
            system("cls");
            questSantosDumont();
            printf("\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuSantosDumont();
            break;
        case 6:
            printf("\n\t\t\t\tObrigado pela visita!");
            getch();
            system("cls");
            menuEntrada();
            break;

        default:
            printf("\n\t\t\t\tOpção inválida! por favor escolha uma opção entre 1 e 5 ou 6 para voltar.\n\n");
            system("pause");
            system("cls");
            menuSantosDumont();
            break;
    }

    fclose(biografia);
    fclose(invencoes);
    fclose(honrarias);
    fclose(impacto);
}

void questSantosDumont(){

    char resp, input[5];
    int pontuacao = 0;
    int respostaValida = 0, qtd = 0, qtdAnterior, qtdNova;
    float avaliacao, recomendacao; 
    float percentual, mdPercentual, mdRecomenda, mdAvaliacao, novoPercentual, mdNovaRecomenda, mdNovaAvaliacao;
    float mdAvaliacaoAnterior, mdRecomendaAnterior, percentualAnterior;

    printf("\n\n\n\t\t\t\t==================== Teste seu Conhecimento ===================\n\n\n\n\n\n");

    printf("\t\t\t\t1 - Qual foi a contribuição de Santos Dumont para a aviação?\n\n\n");
    printf("\t\t\t\ta) Desenvolvia peças para a construção de dirigíveis.\n\n");
    printf("\t\t\t\tb) Disponibilizava dinheiro de sua fortuna para projetos de\n\t\t\t\tdirigíveis\n\n");
    printf("\t\t\t\tc) Foi o único voluntário para fazer o primeiro voo ao ar livre\n\t\t\t\tno dirigível Demoiselle\n\n");
    printf("\t\t\t\td) Desenvolveu o dirigível e construiu aviões pioneiros, como\n\t\t\t\to 14-Bis e o Demoiselle\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp); 

    while (!respostaValida) {
        switch (resp) {
            case 'a':
            case 'A':
                printf("\n\t\t\t\tResposta Errada!");
                respostaValida = 1;
                break;

            case 'b':
            case 'B':
                printf("\n\t\t\t\tResposta Errada!");
                respostaValida = 1;
                break;

            case 'c':
            case 'C':
                printf("\n\t\t\t\tResposta Errada!");
                respostaValida = 1;
                break;

            case 'd':
            case 'D':
                printf("\n\t\t\t\tResposta Correta!!!");
                pontuacao++;
                respostaValida = 1;
                break;

            default:
                printf("\n\t\t\t\tOpção inválida! por favor escolha uma alternativa válida: ");
                scanf(" %c", &resp);
                break;
        }
    }

    printf("\n\n\n");
    system("pause");
    system("cls");

    printf("\n\n\n\t\t\t\t==================== Teste seu Conhecimento ===================\n\n\n\n\n\n");

    printf("\t\t\t\t2 - Onde nasceu Santos Dumont?\n\n\n");
    printf("\t\t\t\ta) Minas Gerais.");
    printf("\n\t\t\t\tb) França.\n\n");
    printf("\t\t\t\tc) São Paulo.\n\n");
    printf("\t\t\t\td) Rio de Janeiro.\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp);
    getchar();

    respostaValida = 0;
    while (!respostaValida) {
        switch (resp){
            case 'a':
            case 'A':
                printf("\n\t\t\t\tResposta Correta!!!");
                respostaValida = 1;
                pontuacao++;
            break;

            case 'b':
            case 'B':
                printf("\n\t\t\t\tResposta Errada!");
                respostaValida = 1;
            break;

            case 'c':
            case 'C':
                printf("\n\t\t\t\tResposta Errada!");
                respostaValida = 1;
            break;

            case 'd':
            case 'D':
                printf("\n\t\t\t\tResposta Errada!");
                respostaValida = 1;
            break;

            default:
                printf("\n\t\t\t\tOpção inválida! por favor escolha uma alternativa válida: ");
                scanf(" %c", &resp);
                break;;
        }
    }

    printf("\n\n\n");
    system("pause");
    system("cls");

    printf("\n\n\n\t\t\t\t==================== Teste seu Conhecimento ===================\n\n\n\n\n\n");

    printf("\n\n\t\t\t\t3 - Quais são as invenções mais conhecidas de Santos Dumont?\n\n\n");
    printf("\t\t\t\ta) Avião e helicóptero.\n\n");
    printf("\t\t\t\tb) Foguete e dirigível.\n\n");
    printf("\t\t\t\tc) Balão a gás e 14-Bis.\n\n");
    printf("\t\t\t\td) Bicicleta voadora e submarino.\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp);

    respostaValida = 0;
    while (!respostaValida){
        switch (resp){
            case 'a':
            case 'A':
                printf("\n\t\t\t\tResposta Errada!");
                respostaValida = 1;
            break;

            case 'b':
            case 'B':
                printf("\n\t\t\t\tResposta Errada!");
                respostaValida = 1;
            break;

            case 'c':
            case 'C':
                printf("\n\t\t\t\tResposta Correta!!!");
                respostaValida = 1;
                pontuacao++;
            break;

            case 'd':
            case 'D':
                printf("\n\t\t\t\tResposta Errada!");
                respostaValida = 1;
            break;

            default:
                printf("\n\t\t\t\tOpção inválida! por favor escolha uma alternativa válida: ");
                scanf(" %c", &resp);
                break;
        }
    }

    printf("\n\n\t\t\t\tPontuacao Total: %d/3\n", pontuacao);

    if(pontuacao == 3){
        printf("\n\n\t\t\t\tParabéns, você acertou todas!!!");
    }
    
    printf("\n\n\n");
    system("pause");
    system("cls");

    printf("\n\n\n\t\t\t\t================ Avalie sua Experiência ===============\n\n\n\n");

    fflush(stdin);

    printf("\t\t\t\tDe 0 a 10, qual a sua avaliação quanto a qualidade da\n\t\t\t\texposição e organização da obra?\n\n");
    printf("\t\t\t\tResp: ");

     while (1) {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%f", &avaliacao) == 1 && avaliacao >= 0 && avaliacao <= 10) {
            break;
        }
        printf("\n\n\t\t\t\tOpção inválida! por favor avalie com um numero entre 0 e 10: ");
    }

    printf("\n\n\t\t\t\tDe 0 a 10, qual a chance de você recomendar a um amigo\n\t\t\t\ta visita a esta exposição?\n\n");
    printf("\t\t\t\tResp: ");

     while (1) {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%f", &recomendacao) == 1 && recomendacao >= 0 && recomendacao <= 10) {
            break;
        }
        printf("\n\n\t\t\t\tOpção inválida! por favor avalie com um numero entre 0 e 10: ");
    }
    qtd++;

    printf("\n\n\t\t\t\tObrigado pela avaliação :)\n\n");

    percentual = (pontuacao/3.0)*100;

    FILE *resultadosSantosDumont = fopen("Temas/SantosDumont/resultados_santos_dumont.txt", "r");

    if(resultadosSantosDumont == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    fscanf(resultadosSantosDumont, "%d", &qtdAnterior);
    fscanf(resultadosSantosDumont, "\n%f", &percentualAnterior);
    fscanf(resultadosSantosDumont, "\n\n%f", &mdAvaliacaoAnterior);
    fscanf(resultadosSantosDumont, "\n\n\n%f", &mdRecomendaAnterior);

    fclose(resultadosSantosDumont);

    resultadosSantosDumont = fopen("Temas/SantosDumont/resultados_santos_dumont.txt", "w");

    if(resultadosSantosDumont == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    qtdNova = qtd + qtdAnterior;
    novoPercentual = (percentualAnterior + percentual) / 2;
    mdNovaAvaliacao = (mdAvaliacaoAnterior + avaliacao) / 2;
    mdNovaRecomenda = (mdRecomendaAnterior + recomendacao) / 2;

    fprintf(resultadosSantosDumont, "%d\n%.2f\n%.2f\n%.2f", qtdNova, novoPercentual, mdNovaAvaliacao, mdNovaRecomenda);

    fclose(resultadosSantosDumont);
    
    resultadosSantosDumont = fopen("Temas/SantosDumont/resultados_santos_dumont.csv", "w");

    if(resultadosSantosDumont == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }
    
    fprintf(resultadosSantosDumont, "Análise dos Resultados\nQuantidade questionários;%d\nPercentual de acertos;%.2f%%\nMédia da avaliação;%.2f\nMédia da recomendação;%.2f", qtdNova, novoPercentual, mdNovaAvaliacao, mdNovaRecomenda);
    
    printf("\t\t\t\tQuantidade Avaliações: %d\n", qtdNova);
    printf("\t\t\t\tPercentual de acertos do questionário: %.2f%%\n", novoPercentual);
    printf("\t\t\t\tNota média da exposição: %.2f\n", mdNovaAvaliacao);
    printf("\t\t\t\tMédia da recomendação: %.2f\n", mdNovaRecomenda);

    fclose(resultadosSantosDumont);
}