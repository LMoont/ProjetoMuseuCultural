#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

void questArteModrn();
void menuEntrada();

void centralizarTexto(char *texto) {
    printf("\t%s", texto);
    Sleep(100);
}

void menuArteModrn(){
    setlocale(LC_ALL, "Portuguese");

    int op;
    char linha[100];

    FILE *contextoHistorico, *principaisObras, *repercussao, *legado;

    contextoHistorico = fopen("Temas/ArteModerna/contexto_historico.txt", "r");
    principaisObras = fopen("Temas/ArteModerna/principais_obras.txt", "r");
    repercussao = fopen("Temas/ArteModerna/repercussao.txt", "r");
    legado = fopen("Temas/ArteModerna/legado.txt", "r");

    if(contextoHistorico == NULL || principaisObras == NULL ||
    repercussao == NULL || legado == NULL){
        printf("Erro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    printf("\n\n\t\t\t\t============== 100 Anos da Semana de Arte Moderna =============\n\n\n\n");

    printf("\t\t\t\tEscolha uma opção para explorar cada tópico e responda um pequeno\n\t\t\t\tquestionário sobre o tema para testar seus conhecimentos:\n\n");
    printf("\t\t\t\t1 - Contexto Histórico e Cultural\n\t\t\t\t2 - Participantes e Obras Marcantes\n\t\t\t\t3 - Influências e Repercussóes no Cenário Artístico Brasileiro\n\t\t\t\t4 - Relevância e Legado\n\t\t\t\t5 - Questionário e Avaliação do Tema\n\t\t\t\t6 - Voltar\n");
    printf("\n\t\t\t\tOpção: ");
    scanf("%d", &op);

    switch (op){
        case 1:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), contextoHistorico) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuArteModrn();
            break;

        case 2:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), principaisObras) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuArteModrn();
            break;

        case 3:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), repercussao) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuArteModrn();
            break;

        case 4:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), legado) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuArteModrn();
            break;

        case 5:
            system("cls");
            questArteModrn();
            printf("\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuArteModrn();
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
            menuArteModrn();
            break;
    }

    fclose(contextoHistorico);
    fclose(principaisObras);
    fclose(repercussao);
    fclose(legado);
}

void questArteModrn(){

    char resp, input[100];
    int pontuacao = 0;
    int respostaValida = 0, qtd = 0, qtdAnterior, qtdNova;
    float avaliacao, recomendacao; 
    float percentual, mdPercentual, mdRecomenda, mdAvaliacao, novoPercentual, mdNovaRecomenda, mdNovaAvaliacao;
    float mdAvaliacaoAnterior, mdRecomendaAnterior, percentualAnterior;

    printf("\n\n\t\t\t\t================ Teste seu Conhecimento ===============\n\n\n\n");

    printf("\t\t\t\t1 - Em que cidade ocorreu a Semana de Arte Moderna em 1922?\n\n");
    printf("\t\t\t\ta) Belo Horizonte\n\t\t\t\tb) Rio de Janeiro\n\t\t\t\tc) São Paulo\n\t\t\t\td) Salvador\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp); 

    while (!respostaValida) {
        switch (resp) {
            case 'a':
            case 'A':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) São Paulo.");
                respostaValida = 1;
                break;

            case 'b':
            case 'B':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) São Paulo.");
                respostaValida = 1;
                break;

            case 'c':
            case 'C':
                printf("\t\t\t\tResposta Correta!!!");
                pontuacao++;
                respostaValida = 1;
                break;

            case 'd':
            case 'D':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) São Paulo.");
                respostaValida = 1;
                break;

            default:
                printf("\n\t\t\t\tOpção inválida! por favor escolha uma alternativa válida: ");
                scanf(" %c", &resp);
                break;
        }
    }

    printf("\n\n\t\t\t\t2 - Qual foi um dos principais objetivos da Semana de Arte Moderna?\n\n");
    printf("\t\t\t\ta) Romper com o academicismo vigente na arte brasileira\n\t\t\t\tb) Incentivar a segregação das manifestações populares e regionais\n\t\t\t\tc) Introduzir as técnicas de pintura renascentista nas produções artísticas\n\t\t\t\td) Promover a venda de obras de arte moderna exclusivamente para a elite brasileira\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp);
    getchar();

    respostaValida = 0;
    while (!respostaValida) {
        switch (resp){
            case 'a':
            case 'A':
                printf("\t\t\t\tResposta Correta!!!");
                respostaValida = 1;
                pontuacao++;
            break;

            case 'b':
            case 'B':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: a)Romper com o academicismo vigente na arte brasileira.");
                respostaValida = 1;
            break;

            case 'c':
            case 'C':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: a)Romper com o academicismo vigente na arte brasileira.");
                respostaValida = 1;
            break;

            case 'd':
            case 'D':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: a)Romper com o academicismo vigente na arte brasileira.");
                respostaValida = 1;
            break;

            default:
                printf("\n\t\t\t\tOpção inválida! por favor escolha uma alternativa válida: ");
                scanf(" %c", &resp);
                break;;
        }
    }

    printf("\n\n\t\t\t\t3 - Qual foi a reação inicial do público em relação às obras e performances\n\t\t\t\tapresentadas?\n\n");
    printf("\t\t\t\ta) Aceitação imediata e entusiasmo generalizado\n\t\t\t\tb) Aplausos unânimes e apoio incondicional\n\t\t\t\tc) Ressentimentos e rejeições intensas\n\t\t\t\td) Indiferençaa e falta de interesse\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp);

    respostaValida = 0;
    while (!respostaValida){
        switch (resp){
            case 'a':
            case 'A':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c)Ressentimentos e rejeições intensas.");
                respostaValida = 1;
            break;

            case 'b':
            case 'B':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c)Ressentimentos e rejeições intensas.");
                respostaValida = 1;
            break;

            case 'c':
            case 'C':
                printf("\t\t\t\tResposta Correta!!!");
                respostaValida = 1;
                pontuacao++;
            break;

            case 'd':
            case 'D':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c)Ressentimentos e rejeições intensas.");
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
    
    printf("\n\n");
    system("pause");
    system("cls");

    printf("\n\n\t\t\t\t================ Avalie sua Experiência ===============\n\n\n\n");

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

    printf("\n\n\t\t\t\tObrigado pela avaliação :)");

    percentual = (pontuacao/3.0)*100;

    FILE *resultadosArteModrn = fopen("Temas/ArteModerna/resultados_arte_moderna.txt", "r");

    if(resultadosArteModrn == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    fscanf(resultadosArteModrn, "%d", &qtdAnterior);
    fscanf(resultadosArteModrn, "\n%f", &percentualAnterior);
    fscanf(resultadosArteModrn, "\n\n%f", &mdAvaliacaoAnterior);
    fscanf(resultadosArteModrn, "\n\n\n%f", &mdRecomendaAnterior);

    fclose(resultadosArteModrn);

    resultadosArteModrn = fopen("Temas/ArteModerna/resultados_arte_moderna.txt", "w");

    if(resultadosArteModrn == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    qtdNova = qtd + qtdAnterior;
    novoPercentual = (percentualAnterior + percentual) / 2;
    mdNovaAvaliacao = (mdAvaliacaoAnterior + avaliacao) / 2;
    mdNovaRecomenda = (mdRecomendaAnterior + recomendacao) / 2;

    fprintf(resultadosArteModrn, "%d\n%.2f\n%.2f\n%.2f", qtdNova, novoPercentual, mdNovaAvaliacao, mdNovaRecomenda);

    fclose(resultadosArteModrn);

    resultadosArteModrn = fopen("Temas/ArteModerna/resultados_arte_moderna.txt", "r");

    if(resultadosArteModrn == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    fscanf(resultadosArteModrn, "%d", &qtdAnterior);
    fscanf(resultadosArteModrn, "\n%.2lf", &percentualAnterior);
    fscanf(resultadosArteModrn, "\n\n%.2lf", &mdAvaliacaoAnterior);
    fscanf(resultadosArteModrn, "\n\n\n%.2lf", &mdRecomendaAnterior);

    fclose(resultadosArteModrn);
    
    resultadosArteModrn = fopen("Temas/ArteModerna/resultados_arte_moderna.csv", "w");

    if(resultadosArteModrn == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }
    
    fprintf(resultadosArteModrn, "Análise dos Resultados:\nQuantidade questionários;%d\nPercentual de acertos;%.2f%%\nMédia da avaliação;%.2f\nMédia da recomendação;%.2f", qtdNova, novoPercentual, mdNovaAvaliacao, mdNovaRecomenda);
    
    printf("\t\t\t\tQuantidade Avaliações: %d\n", qtdNova);
    printf("\t\t\t\tPercentual de acertos do questionário: %.2f%%\n", novoPercentual);
    printf("\t\t\t\tNota média dos visitantes: %.2f\n", mdNovaAvaliacao);

    fclose(resultadosArteModrn);
}