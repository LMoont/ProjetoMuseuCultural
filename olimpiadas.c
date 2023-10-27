#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

void questOlimpiadas();
void menuEntrada();
void centralizarTexto();

void menuOlimpiadas(){
    setlocale(LC_ALL, "Portuguese");

    int op;
    char linha[100];

    FILE *infraestrutura, *modalidadesEstreantes, *legado, *expectativas;

    infraestrutura = fopen("Temas/Olimpiadas/infraestrutura.txt", "r");
    modalidadesEstreantes = fopen("Temas/Olimpiadas/modalidades_estreantes.txt", "r");
    legado = fopen("Temas/Olimpiadas/legado.txt", "r");
    expectativas = fopen("Temas/Olimpiadas/expectativas.txt", "r");

    if(infraestrutura == NULL || modalidadesEstreantes == NULL ||
    legado == NULL || expectativas == NULL){
        printf("Erro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    printf("\n\n\n\t\t\t\t================== Jogos Ol�mpicos de Paris 2024 =================\n\n\n\n");

    printf("\t\t\t\tEscolha uma op��o para explorar cada t�pico e responda um pequeno\n\t\t\t\tquestion�rio para testar seus conhecimentos e avaliar a exposi��o:\n\n\n");
    printf("\t\t\t\t1 - Infraestrutura e Prepara��o\n\n\t\t\t\t2 - As 5 Modalidades Estreantes\n\n\t\t\t\t3 - Legado Social, Cultural e Econ�mico\n\n\t\t\t\t4 - Expectativas do Brasil nas Olimp�adas\n\n\t\t\t\t5 - Question�rio e Avalia��o do Tema\n\n\t\t\t\t6 - Voltar\n\n");
    printf("\n\t\t\t\tOp��o: ");
    scanf("%d", &op);

    switch (op){
        case 1:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), infraestrutura) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuOlimpiadas();
            break;

        case 2:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), modalidadesEstreantes) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuOlimpiadas();
            break;

        case 3:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), legado) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuOlimpiadas();
            break;

        case 4:
            system("cls");
            printf("\n\n");
            while (fgets(linha, sizeof(linha), expectativas) != NULL) {
                centralizarTexto(linha);
            }
            printf("\n\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuOlimpiadas();
            break;

        case 5:
            system("cls");
            questOlimpiadas();
            printf("\n\n*Pressione qualquer tecla para voltar*");
            getch();
            system("cls");
            menuOlimpiadas();
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
                menuOlimpiadas();
            break;
    }

    fclose(infraestrutura);
    fclose(modalidadesEstreantes);
    fclose(legado);
    fclose(expectativas);
}

void questOlimpiadas(){

    char resp, input[5];
    int pontuacao = 0;
    int respostaValida = 0, qtd = 0, qtdAnterior, qtdNova;
    float avaliacao, recomendacao; 
    float percentual, mdPercentual, mdRecomenda, mdAvaliacao, novoPercentual, mdNovaRecomenda, mdNovaAvaliacao;
    float mdAvaliacaoAnterior, mdRecomendaAnterior, percentualAnterior;

    printf("\n\n\n\t\t\t\t========================= Teste seu Conhecimento ========================\n\n\n\n\n\n");

    printf("\t\t\t\t1 - QUAL A VIS�O DE PARIS PARA OS JOGOS OL�MPICOS 2024?\n\n\n");
    printf("\t\t\t\ta) Paris 2024 tem como objetivo montar o melhor palco para os jogos\n\t\t\t\tOl�mpicos.\n\n"); 
    printf("\t\t\t\tb) Seu objetivo � dificultar o palco para n�o favorecer os atletas e\n\t\t\t\tdeixar as competi��es um pouco mais dif�ceis.\n\n");
    printf("\t\t\t\tc) Paris 2024 tem como objetivo oferecer uma cidade inspiradora e um\n\t\t\t\tpalco memor�vel para os atletas.\n\n");
    printf("\t\t\t\td) Paris 2024 tem como objetivo proporcionar os melhores equipamentos\n\t\t\t\tpara todos os atletas.\n\n");
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
                printf("\n\t\t\t\tResposta Correta!!!");
                pontuacao++;
                respostaValida = 1;
                break;

            case 'd':
            case 'D':
                printf("\n\t\t\t\tResposta Errada!");
                respostaValida = 1;
                break;

            default:
                printf("\n\t\t\t\tOp��o inv�lida! por favor escolha uma alternativa v�lida: ");
                scanf(" %c", &resp);
                break;
        }
    }

    printf("\n\n\n");
    system("pause");
    system("cls");

    printf("\n\n\n\t\t\t\t======================== Teste seu Conhecimento =======================\n\n\n\n\n\n");

    printf("\t\t\t\t2 - Quais s�o os pontos de refer�ncia destacados como parte do palco\n\t\t\t\tmemor�vel para os atletas nos Jogos Ol�mpicos de Paris 2024?\n\n\n");
    printf("\t\t\t\ta) Rio Sena e a Vila Ol�mpica.\n\n");
    printf("\t\t\t\tb) Avenida Champs-�lys�es e a Catedral de Notre-Dame.\n\n");
    printf("\t\t\t\tc) Pra�a da Concordia e o Museu do Louvre.\n\n");
    printf("\t\t\t\td) Palacio de Versalhes e o Arco do Triunfo.\n\n");
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
                printf("\n\t\t\t\tOp��o inv�lida! por favor escolha uma alternativa v�lida: ");
                scanf(" %c", &resp);
                break;;
        }
    }

    printf("\n\n\n");
    system("pause");
    system("cls");

    printf("\n\n\n\t\t\t\t======================== Teste seu Conhecimento =======================\n\n\n\n\n\n");

    printf("\t\t\t\t3 - Qual � um dos pilares principais dos Jogos Ol�mpicos de Paris 2024?\n\n\n");
    printf("\t\t\t\ta) Desenvolvimento industrial.\n\n");
    printf("\t\t\t\tb) Promo��o cultural.\n\n");
    printf("\t\t\t\tc) Expans�o militar.\n\n");
    printf("\t\t\t\td) Explora�ao espacial.\n\n");
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
                printf("\n\t\t\t\tResposta Correta!!!");
                respostaValida = 1;
                pontuacao++;
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
                printf("\n\t\t\t\tOp��o inv�lida! por favor escolha uma alternativa v�lida: ");
                scanf(" %c", &resp);
                break;
        }
    }

    printf("\n\n\t\t\t\tPontuacao Total: %d/3\n", pontuacao);

    if(pontuacao == 3){
        printf("\n\n\t\t\t\tParab�ns, voc� acertou todas!!!");
    }
    
    printf("\n\n\n");
    system("pause");
    system("cls");

   printf("\n\n\n\t\t\t\t================ Avalie sua Experi�ncia ===============\n\n\n\n\n\n");

    fflush(stdin);

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

    printf("\n\n\t\t\t\tObrigado pela avalia��o :)\n\n");

    percentual = (pontuacao/3.0)*100;

    FILE *resultadosOlimpiadas = fopen("Temas/Olimpiadas/resultados_olimpiadas.txt", "r");

    if(resultadosOlimpiadas == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    fscanf(resultadosOlimpiadas, "%d", &qtdAnterior);
    fscanf(resultadosOlimpiadas, "\n%f", &percentualAnterior);
    fscanf(resultadosOlimpiadas, "\n\n%f", &mdAvaliacaoAnterior);
    fscanf(resultadosOlimpiadas, "\n\n\n%f", &mdRecomendaAnterior);

    fclose(resultadosOlimpiadas);

    resultadosOlimpiadas = fopen("Temas/Olimpiadas/resultados_olimpiadas.txt", "w");

    if(resultadosOlimpiadas == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    qtdNova = qtd + qtdAnterior;
    novoPercentual = (percentualAnterior + percentual) / 2;
    mdNovaAvaliacao = (mdAvaliacaoAnterior + avaliacao) / 2;
    mdNovaRecomenda = (mdRecomendaAnterior + recomendacao) / 2;

    fprintf(resultadosOlimpiadas, "%d\n%.2f\n%.2f\n%.2f", qtdNova, novoPercentual, mdNovaAvaliacao, mdNovaRecomenda);

    fclose(resultadosOlimpiadas);
    
    resultadosOlimpiadas = fopen("Temas/Olimpiadas/resultados_olimpiadas.csv", "w");

    if(resultadosOlimpiadas == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }
    
    fprintf(resultadosOlimpiadas, "An�lise dos Resultados\nQuantidade question�rios;%d\nPercentual de acertos;%.2f%%\nM�dia da avalia��o;%.2f\nM�dia da recomenda��o;%.2f", qtdNova, novoPercentual, mdNovaAvaliacao, mdNovaRecomenda);
    
    printf("\t\t\t\tQuantidade Avalia��es: %d\n", qtdNova);
    printf("\t\t\t\tPercentual de acertos do question�rio: %.2f%%\n", novoPercentual);
    printf("\t\t\t\tNota m�dia da exposi��o: %.2f\n", mdNovaAvaliacao);
    printf("\t\t\t\tM�dia da recomenda��o: %.2f\n", mdNovaRecomenda);

    fclose(resultadosOlimpiadas);
}