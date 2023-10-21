#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

void questSantosDumont();

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

    printf("\n\n\t\t\t\t============== 150 Anos de Santos Dumont =============\n\n\n\n");

    printf("\t\t\t\tEscolha uma op��o para explorar cada t�pico e responda um pequeno\n\t\t\t\tquestion�rio sobre o tema para testar seus conhecimentos:\n\n");
    printf("\t\t\t\t1 - Biografia e Trajet�ria de Santos Dumont\n\t\t\t\t2 - Inven��es e Contribui��es\n\t\t\t\t3 - Reconhecimento e Honrarias Recebidos\n\t\t\t\t4 - Impacto no Desenvolvimento da Avia��o Mundial\n\t\t\t\t5 - Question�rio e Avalia��o do Tema\n\t\t\t\t0 - Sair\n\n\t\t\t\tOp��o: ");
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
        case 0:
            printf("\n\t\t\t\tObrigado pela visita!");
            getch();
            exit(0);
            break;

        default:
            printf("\n\t\t\t\tOp��o inv�lida! por favor escolha uma op��o entre 1 e 5 ou 0 para sair.\n\n");
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

    char resp;
    int pontuacao = 0;
    int respostaValida = 0, qtd = 0, qtdAnterior, qtdNova;
    float avaliacao, recomendacao; 
    float percentual, mdPercentual, mdRecomenda, mdAvaliacao, novoPercentual, mdNovaRecomenda, mdNovaAvaliacao;
    float mdAvaliacaoAnterior, mdRecomendaAnterior, percentualAnterior;

    printf("\n\n\t\t\t\t================ Teste seu Conhecimento ===============\n\n\n\n");

    printf("\t\t\t\t1 - Qual foi a contribui��o de Santos Dumont para a avia��o?\n\n");
    printf("\t\t\t\ta)Desenvolvia pe�as para a constru��o de dirig�veis\n\t\t\t\tb)Disponibilizava dinheiro de sua fortuna para projetos de dirig�veis\n\t\t\t\tc)Foi o �nico volunt�rio para fazer o primeiro voo ao ar livre no dirig�vel Demoiselle\n\t\t\t\td)Desenvolveu o dirig�vel e construiu avi�es pioneiros, como o 14-Bis e o Demoiselle\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp); 

    while (!respostaValida) {
        switch (resp) {
            case 'a':
            case 'A':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: d)Santos Dumont desenvolveu o dirig�vel e construiu avi�es pioneiros, como o 14-Bis e o Demoiselle.");
                respostaValida = 1;
                break;

            case 'b':
            case 'B':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: d)Santos Dumont desenvolveu o dirig�vel e construiu avi�es pioneiros, como o 14-Bis e o Demoiselle.");
                respostaValida = 1;
                break;

            case 'c':
            case 'C':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: d)Santos Dumont desenvolveu o dirig�vel e construiu avi�es pioneiros, como o 14-Bis e o Demoiselle.");
                respostaValida = 1;
                break;

            case 'd':
            case 'D':
                printf("\t\t\t\tVoc� Acertou!!!");
                pontuacao++;
                respostaValida = 1;
                break;

            default:
                printf("\n\t\t\t\tOp��o inv�lida! por favor escolha uma alternativa v�lida: ");
                scanf(" %c", &resp);
                break;
        }
    }

    printf("\n\n\t\t\t\t2 - Onde nasceu Santos Dumont?\n\n");
    printf("\t\t\t\ta)Minas Gerais\n\t\t\t\tb)Fran�a\n\t\t\t\tc)S�o Paulo\n\t\t\t\td)Rio de Janeiro\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp);
    getchar();

    respostaValida = 0;
    while (!respostaValida) {
        switch (resp){
            case 'a':
            case 'A':
                printf("\t\t\t\tVoc� Acertou!!!");
                respostaValida = 1;
                pontuacao++;
            break;

            case 'b':
            case 'B':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: a)Minas Gerais.");
                respostaValida = 1;
            break;

            case 'c':
            case 'C':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: a)Minas Gerais.");
                respostaValida = 1;
            break;

            case 'd':
            case 'D':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: a)Minas Gerais.");
                respostaValida = 1;
            break;

            default:
                printf("\n\t\t\t\tOp��o inv�lida! por favor escolha uma alternativa v�lida: ");
                scanf(" %c", &resp);
                break;;
        }
    }

    printf("\n\n\t\t\t\t3 - Quais s�o as inven��es mais conhecidas de Santos Dumont?\n\n");
    printf("\t\t\t\ta) Avi�o e helic�ptero\n\t\t\t\tb) Foguete e dirig�vel\n\t\t\t\tc) Bal�o a g�s e 14-Bis\n\t\t\t\td) Bicicleta voadora e submarino\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp);

    respostaValida = 0;
    while (!respostaValida){
        switch (resp){
            case 'a':
            case 'A':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) Bal�o a g�s e 14-Bis.");
                respostaValida = 1;
            break;

            case 'b':
            case 'B':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) Bal�o a g�s e 14-Bis.");
                respostaValida = 1;
            break;

            case 'c':
            case 'C':
                printf("\t\t\t\tVoc� Acertou!!!");
                respostaValida = 1;
                pontuacao++;
            break;

            case 'd':
            case 'D':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) Bal�o a g�s e 14-Bis.");
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

    resultadosSantosDumont = fopen("Temas/SantosDumont/resultados_santos_dumont.txt", "r");

    if(resultadosSantosDumont == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    fscanf(resultadosSantosDumont, "%d", &qtdAnterior);
    fscanf(resultadosSantosDumont, "\n%.2lf", &percentualAnterior);
    fscanf(resultadosSantosDumont, "\n\n%.2lf", &mdAvaliacaoAnterior);
    fscanf(resultadosSantosDumont, "\n\n\n%.2lf", &mdRecomendaAnterior);

    fclose(resultadosSantosDumont);
    
    resultadosSantosDumont = fopen("Temas/SantosDumont/resultados_santos_dumont.csv", "w");

    if(resultadosSantosDumont == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }
    
    fprintf(resultadosSantosDumont, "An�lise dos Resultados:\nQuantidade question�rios;%d\nPercentual de acertos;%.2f%%\nM�dia da avalia��o;%.2f\nM�dia da recomenda��o;%.2f", qtdNova, novoPercentual, mdNovaAvaliacao, mdNovaRecomenda);
    
    printf("\t\t\t\tQuantidade Avalia��es: %d\n", qtdNova);
    printf("\t\t\t\tPercentual de acertos do question�rio: %.2f%%\n", novoPercentual);
    printf("\t\t\t\tNota m�dia dos visitantes: %.2f\n", mdNovaAvaliacao);

    fclose(resultadosSantosDumont);
}