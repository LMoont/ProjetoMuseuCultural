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

    printf("\t\t\t\tEscolha uma op��o para explorar cada t�pico e responda um pequeno\n\t\t\t\tquestion�rio sobre o tema para testar seus conhecimentos:\n\n");
    printf("\t\t\t\t1 - Contexto Hist�rico e Cultural\n\t\t\t\t2 - Participantes e Obras Marcantes\n\t\t\t\t3 - Influ�ncias e Repercuss�es no Cen�rio Art�stico Brasileiro\n\t\t\t\t4 - Relev�ncia e Legado\n\t\t\t\t5 - Question�rio e Avalia��o do Tema\n\t\t\t\t6 - Voltar\n");
    printf("\n\t\t\t\tOp��o: ");
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
            printf("\n\t\t\t\tOp��o inv�lida! por favor escolha uma op��o entre 1 e 5 ou 6 para voltar.\n\n");
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
    printf("\t\t\t\ta) Belo Horizonte\n\t\t\t\tb) Rio de Janeiro\n\t\t\t\tc) S�o Paulo\n\t\t\t\td) Salvador\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp); 

    while (!respostaValida) {
        switch (resp) {
            case 'a':
            case 'A':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) S�o Paulo.");
                respostaValida = 1;
                break;

            case 'b':
            case 'B':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) S�o Paulo.");
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
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) S�o Paulo.");
                respostaValida = 1;
                break;

            default:
                printf("\n\t\t\t\tOp��o inv�lida! por favor escolha uma alternativa v�lida: ");
                scanf(" %c", &resp);
                break;
        }
    }

    printf("\n\n\t\t\t\t2 - Qual foi um dos principais objetivos da Semana de Arte Moderna?\n\n");
    printf("\t\t\t\ta) Romper com o academicismo vigente na arte brasileira\n\t\t\t\tb) Incentivar a segrega��o das manifesta��es populares e regionais\n\t\t\t\tc) Introduzir as t�cnicas de pintura renascentista nas produ��es art�sticas\n\t\t\t\td) Promover a venda de obras de arte moderna exclusivamente para a elite brasileira\n\n");
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
                printf("\n\t\t\t\tOp��o inv�lida! por favor escolha uma alternativa v�lida: ");
                scanf(" %c", &resp);
                break;;
        }
    }

    printf("\n\n\t\t\t\t3 - Qual foi a rea��o inicial do p�blico em rela��o �s obras e performances\n\t\t\t\tapresentadas?\n\n");
    printf("\t\t\t\ta) Aceita��o imediata e entusiasmo generalizado\n\t\t\t\tb) Aplausos un�nimes e apoio incondicional\n\t\t\t\tc) Ressentimentos e rejei��es intensas\n\t\t\t\td) Indiferen�aa e falta de interesse\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp);

    respostaValida = 0;
    while (!respostaValida){
        switch (resp){
            case 'a':
            case 'A':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c)Ressentimentos e rejei��es intensas.");
                respostaValida = 1;
            break;

            case 'b':
            case 'B':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c)Ressentimentos e rejei��es intensas.");
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
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c)Ressentimentos e rejei��es intensas.");
                respostaValida = 1;
            break;

            default:
                printf("\n\t\t\t\tOp��o inv�lida! por favor escolha uma alternativa v�lida: ");
                scanf(" %c", &resp);
                break;
        }
    }

    printf("\n\n\t\t\t\tPontuacao Total: %d/3\n", pontuacao);

    if(pontuacao == 3){
        printf("\n\n\t\t\t\tParab�ns, voc� acertou todas!!!");
    }
    
    printf("\n\n");
    system("pause");
    system("cls");

    printf("\n\n\t\t\t\t================ Avalie sua Experi�ncia ===============\n\n\n\n");

    printf("\t\t\t\tDe 0 a 10, qual a sua avalia��o quanto a qualidade da\n\t\t\t\texposi��o e organiza��o da obra?\n\n");
    printf("\t\t\t\tResp: ");

     while (1) {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%f", &avaliacao) == 1 && avaliacao >= 0 && avaliacao <= 10) {
            break;
        }
        printf("\n\n\t\t\t\tOp��o inv�lida! por favor avalie com um numero entre 0 e 10: ");
    }

    printf("\n\n\t\t\t\tDe 0 a 10, qual a chance de voc� recomendar a um amigo\n\t\t\t\ta visita a esta exposi��o?\n\n");
    printf("\t\t\t\tResp: ");

     while (1) {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%f", &recomendacao) == 1 && recomendacao >= 0 && recomendacao <= 10) {
            break;
        }
        printf("\n\n\t\t\t\tOp��o inv�lida! por favor avalie com um numero entre 0 e 10: ");
    }
    qtd++;

    printf("\n\n\t\t\t\tObrigado pela avalia��o :)");

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
    
    fprintf(resultadosArteModrn, "An�lise dos Resultados:\nQuantidade question�rios;%d\nPercentual de acertos;%.2f%%\nM�dia da avalia��o;%.2f\nM�dia da recomenda��o;%.2f", qtdNova, novoPercentual, mdNovaAvaliacao, mdNovaRecomenda);
    
    printf("\t\t\t\tQuantidade Avalia��es: %d\n", qtdNova);
    printf("\t\t\t\tPercentual de acertos do question�rio: %.2f%%\n", novoPercentual);
    printf("\t\t\t\tNota m�dia dos visitantes: %.2f\n", mdNovaAvaliacao);

    fclose(resultadosArteModrn);
}