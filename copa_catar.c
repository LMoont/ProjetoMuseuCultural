#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

void questCopaCatar();
void centralizarTexto();
void menuEntrada();

void menuCopaCatar(){
    setlocale(LC_ALL, "Portuguese");

    int op;
    char linha[100];

    FILE *preparacao, *finalHistorica, *aspectoSocial, *sustentabilidade;

    preparacao = fopen("Temas/CopaCatar/preparacao.txt", "r");
    finalHistorica = fopen("Temas/CopaCatar/final_historica.txt", "r");
    aspectoSocial = fopen("Temas/CopaCatar/apecto_social.txt", "r");
    sustentabilidade = fopen("Temas/CopaCatar/sustentabilidade.txt", "r");

    if(preparacao == NULL || finalHistorica == NULL ||
    aspectoSocial == NULL || sustentabilidade == NULL){
        printf("Erro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    printf("\n\n\t\t\t\t============== Copa do Mundo Catar 2022 =============\n\n\n\n");

    printf("\t\t\t\tEscolha uma op��o para explorar cada t�pico e responda um pequeno\n\t\t\t\tquestion�rio para testar seus conhecimentos e avaliar a exposi��o:\n\n");
    printf("\t\t\t\t1 - Prepara��o e Infraestrutura\n\t\t\t\t2 - Final Hist�rica\n\t\t\t\t3 - Aspecto Social e Cultural do Pa�s\n\t\t\t\t4 - Sustentabilidade e Legado Ambiental\n\t\t\t\t5 - Question�rio e Avalia��o do Tema\n\t\t\t\t6 - Voltar\n");
    printf("\n\t\t\t\tOp��o: ");
    scanf("%d", &op);

    switch (op){
        case 1:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), preparacao) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuCopaCatar();
            break;

        case 2:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), finalHistorica) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuCopaCatar();
            break;

        case 3:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), aspectoSocial) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuCopaCatar();
            break;

        case 4:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), sustentabilidade) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuCopaCatar();
            break;

        case 5:
            system("cls");
            questCopaCatar();
            printf("\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuCopaCatar();
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
                menuCopaCatar();
            break;
    }

    fclose(preparacao);
    fclose(finalHistorica);
    fclose(aspectoSocial);
    fclose(sustentabilidade);
}

void questCopaCatar(){

    char resp;
    int pontuacao = 0;
    int respostaValida = 0, qtd = 0, qtdAnterior, qtdNova;
    float avaliacao, recomendacao; 
    float percentual, mdPercentual, mdRecomenda, mdAvaliacao, novoPercentual, mdNovaRecomenda, mdNovaAvaliacao;
    float mdAvaliacaoAnterior, mdRecomendaAnterior, percentualAnterior;

    printf("\n\n\t\t\t\t================ Teste seu Conhecimento ===============\n\n\n\n");

    printf("\t\t\t\t1 - Quantos est�dios foram utilizados na Copa do Mundo no Catar em 2022?\n\n");
    printf("\t\t\t\ta) 15 est�dios.\n\t\t\t\tb) 14 est�dios.\n\t\t\t\tc) 8 est�dios.\n\t\t\t\td) 12 est�dios.\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp); 

    while (!respostaValida) {
        switch (resp) {
            case 'a':
            case 'A':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) 8 est�dios.");
                respostaValida = 1;
                break;

            case 'b':
            case 'B':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) 8 est�dios.");
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
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) 8 est�dios.");
                respostaValida = 1;
                break;

            default:
                printf("\n\t\t\t\tOp��o inv�lida! por favor escolha uma alternativa v�lida: ");
                scanf(" %c", &resp);
                break;
        }
    }

    printf("\n\n\t\t\t\t2 - Qual elemento � fundamental na cultura catariana?\n\n");
    printf("\t\t\t\ta) Inova��o tecnol�gica.\n\t\t\t\tb) Hospitalidade.\n\t\t\t\tc) Urbaniza��o acelerada.\n\t\t\t\td) Conservadorismo social.\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp);
    getchar();

    respostaValida = 0;
    while (!respostaValida) {
        switch (resp){
            case 'a':
            case 'A':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: b) Hospitalidade.");
                respostaValida = 1;
            break;

            case 'b':
            case 'B':
                printf("\t\t\t\tResposta Correta!!!");
                respostaValida = 1;
                pontuacao++;
            break;

            case 'c':
            case 'C':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: b) Hospitalidade.");
                respostaValida = 1;
            break;

            case 'd':
            case 'D':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: b) Hospitalidade.");
                respostaValida = 1;
            break;

            default:
                printf("\n\t\t\t\tOp��o inv�lida! por favor escolha uma alternativa v�lida: ");
                scanf(" %c", &resp);
                break;;
        }
    }

    printf("\n\n\t\t\t\t3 - Quem foi reconhecido como o Melhor Jogador da Copa do Mundo de 2022?\n\n");
    printf("\t\t\t\ta) Cristiano Ronaldo.\n\t\t\t\tb) Lionel Messi.\n\t\t\t\tc) Neymar Jr.\n\t\t\t\td) Kylian Mbapp�.\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp);

    respostaValida = 0;
    while (!respostaValida){
        switch (resp){
            case 'a':
            case 'A':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: b) Lionel Messi.");
                respostaValida = 1;
            break;

            case 'b':
            case 'B':
                printf("\t\t\t\tResposta Correta!!!");
                respostaValida = 1;
                pontuacao++;
            break;

            case 'c':
            case 'C':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: b) Lionel Messi.");
                respostaValida = 1;
            break;

            case 'd':
            case 'D':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: b) Lionel Messi.");
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
    scanf("%f", &avaliacao);

    printf("\n\n\t\t\t\tDe 0 a 10, qual a chance de voc� recomendar a um amigo\n\t\t\t\ta visita a esta exposi��o?\n\n");
    printf("\t\t\t\tResp: ");
    scanf("%f", &recomendacao);
    qtd++;

    printf("\n\n\t\t\t\tObrigado pela avalia��o :)\n\n");

    percentual = (pontuacao/3.0)*100;

    FILE *resultadosCopaCatar = fopen("Temas/CopaCatar/resultados_catar.txt", "r");

    if(resultadosCopaCatar == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    fscanf(resultadosCopaCatar, "%d", &qtdAnterior);
    fscanf(resultadosCopaCatar, "\n%f", &percentualAnterior);
    fscanf(resultadosCopaCatar, "\n\n%f", &mdAvaliacaoAnterior);
    fscanf(resultadosCopaCatar, "\n\n\n%f", &mdRecomendaAnterior);

    fclose(resultadosCopaCatar);

    resultadosCopaCatar = fopen("Temas/CopaCatar/resultados_catar.txt", "w");

    if(resultadosCopaCatar == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    qtdNova = qtd + qtdAnterior;
    novoPercentual = (percentualAnterior + percentual) / 2;
    mdNovaAvaliacao = (mdAvaliacaoAnterior + avaliacao) / 2;
    mdNovaRecomenda = (mdRecomendaAnterior + recomendacao) / 2;

    fprintf(resultadosCopaCatar, "%d\n%.2f\n%.2f\n%.2f", qtdNova, novoPercentual, mdNovaAvaliacao, mdNovaRecomenda);

    fclose(resultadosCopaCatar);

    resultadosCopaCatar = fopen("Temas/CopaCatar/resultados_catar.txt", "r");

    if(resultadosCopaCatar == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    fscanf(resultadosCopaCatar, "%d", &qtdAnterior);
    fscanf(resultadosCopaCatar, "\n%.2lf", &percentualAnterior);
    fscanf(resultadosCopaCatar, "\n\n%.2lf", &mdAvaliacaoAnterior);
    fscanf(resultadosCopaCatar, "\n\n\n%.2lf", &mdRecomendaAnterior);

    fclose(resultadosCopaCatar);
    
    resultadosCopaCatar = fopen("Temas/CopaCatar/resultados_catar.csv", "w");

    if(resultadosCopaCatar == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }
    
    fprintf(resultadosCopaCatar, "An�lise dos Resultados:\nQuantidade question�rios;%d\nPercentual de acertos;%.2f%%\nM�dia da avalia��o;%.2f\nM�dia da recomenda��o;%.2f", qtdNova, novoPercentual, mdNovaAvaliacao, mdNovaRecomenda);
    
    printf("\t\t\t\tQuantidade Avalia��es: %d\n", qtdNova);
    printf("\t\t\t\tPercentual de acertos do question�rio: %.2f%%\n", novoPercentual);
    printf("\t\t\t\tNota m�dia dos visitantes: %.2f\n", mdNovaAvaliacao);

    fclose(resultadosCopaCatar);
}