#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

void questOlimpiadas();

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

    printf("\n\n\t\t\t\t============== Jogos Olímpicos de Paris 2024 =============\n\n\n\n");

    printf("\t\t\t\tEscolha uma opção para explorar cada tópico e responda um pequeno\n\t\t\t\tquestionário para testar seus conhecimentos e avaliar a exposição:\n\n");
    printf("\t\t\t\t1 - Infraestrutura e Preparação\n\t\t\t\t2 - As 5 Modalidades Estreantes\n\t\t\t\t3 - Legado Social, Cultural e Econômico\n\t\t\t\t4 - Expectativas do Brasil nas Olimpíadas\n\t\t\t\t5 - Questionário e Avaliação do Tema\n\t\t\t\t0 - Sair\n\n\t\t\t\tOpção: ");
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
        case 0:
            printf("\n\t\t\t\tObrigado pela visita!");
            getch();
            exit(0);
            break;

        default:
                printf("\n\t\t\t\tOpção inválida! por favor escolha uma opção entre 1 e 5 ou 0 para sair.\n\n");
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

    char resp;
    int pontuacao = 0;
    int respostaValida = 0, qtd = 0, qtdAnterior, qtdNova;
    float avaliacao, recomendacao; 
    float percentual, mdPercentual, mdRecomenda, mdAvaliacao, novoPercentual, mdNovaRecomenda, mdNovaAvaliacao;
    float mdAvaliacaoAnterior, mdRecomendaAnterior, percentualAnterior;

    printf("\n\n\t\t\t\t================ Teste seu Conhecimento ===============\n\n\n\n");

    printf("\t\t\t\t1 - Qual a visão de Paris 2024 para os jogos Olímpicos?\n\n");
    printf("\t\t\t\ta) Paris 2024 tem como objetivo montar o melhor palco para os jogos Olímpicos.\n\t\t\t\tb) Seu objetivo é dificultar o palco para não favorecer os atletas e deixar\n\t\t\t\tas competições um pouco mais difíceis.\n\t\t\t\tc) Paris 2024 tem como objetivo oferecer uma cidade inspiradora e um palco memorável\n\t\t\t\tpara os atletas.\n\t\t\t\td) Paris 2024 tem como objetivo proporcionar os melhores equipamentos para\n\t\t\t\ttodos os atletas.\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp); 

    while (!respostaValida) {
        switch (resp) {
            case 'a':
            case 'A':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) Paris 2024 tem como objetivo oferecer uma cidade inspiradora e um\n\t\t\t\tpalco memorávelpara os atletas.");
                respostaValida = 1;
                break;

            case 'b':
            case 'B':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) Paris 2024 tem como objetivo oferecer uma cidade inspiradora e um\n\t\t\t\tpalco memorável para os atletas.");
                respostaValida = 1;
                break;

            case 'c':
            case 'C':
                printf("\t\t\t\tVocê Acertou!!!");
                pontuacao++;
                respostaValida = 1;
                break;

            case 'd':
            case 'D':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: c) Paris 2024 tem como objetivo oferecer uma cidade inspiradora e um\n\t\t\t\tpalco memorável para os atletas.");
                respostaValida = 1;
                break;

            default:
                printf("\n\t\t\t\tOpção inválida! por favor escolha uma alternativa válida: ");
                scanf(" %c", &resp);
                break;
        }
    }

    printf("\n\n\t\t\t\t2 - Quais são os pontos de referência destacados como parte do palco memorável\n\t\t\t\tpara os atletas nos Jogos Olímpicos de Paris 2024?\n\n");
    printf("\t\t\t\ta) Rio Sena e a Vila Olímpica.\n\t\t\t\tb) Avenida Champs-Élysées e a Catedral de Notre-Dame.\n\t\t\t\tc) Praça da Concórdia e o Museu do Louvre.\n\t\t\t\td) Palácio de Versalhes e o Arco do Triunfo.\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp);
    getchar();

    respostaValida = 0;
    while (!respostaValida) {
        switch (resp){
            case 'a':
            case 'A':
                printf("\t\t\t\tVocê Acertou!!!");
                respostaValida = 1;
                pontuacao++;
            break;

            case 'b':
            case 'B':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: a) Rio Sena e a Vila Olímpica.");
                respostaValida = 1;
            break;

            case 'c':
            case 'C':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: a) Rio Sena e a Vila Olímpica.");
                respostaValida = 1;
            break;

            case 'd':
            case 'D':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: a) Rio Sena e a Vila Olímpica.");
                respostaValida = 1;
            break;

            default:
                printf("\n\t\t\t\tOpção inválida! por favor escolha uma alternativa válida: ");
                scanf(" %c", &resp);
                break;;
        }
    }

    printf("\n\n\t\t\t\t3 - Qual é um dos pilares principais dos Jogos Olímpicos de Paris 2024?\n\n");
    printf("\t\t\t\ta) Desenvolvimento industrial.\n\t\t\t\tb) Promoção cultural.\n\t\t\t\tc) Expansão militar.\n\t\t\t\td) Exploração espacial.\n\n");
    printf("\t\t\t\tResp: ");
    scanf(" %c", &resp);

    respostaValida = 0;
    while (!respostaValida){
        switch (resp){
            case 'a':
            case 'A':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: b) Promoção cultural.");
                respostaValida = 1;
            break;

            case 'b':
            case 'B':
                printf("\t\t\t\tVocê Acertou!!!");
                respostaValida = 1;
                pontuacao++;
            break;

            case 'c':
            case 'C':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: b) Promoção cultural.");
                respostaValida = 1;
            break;

            case 'd':
            case 'D':
                printf("\t\t\t\tResposta Errada!\n\t\t\t\tResposta Correta: b) Promoção cultural.");
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
    scanf("%f", &avaliacao);

    printf("\n\n\t\t\t\tDe 0 a 10, qual a chance de você recomendar a um amigo\n\t\t\t\ta visita a esta exposição?\n\n");
    printf("\t\t\t\tResp: ");
    scanf("%f", &recomendacao);
    qtd++;

    printf("\n\n\t\t\t\tObrigado pela avaliação :)\n\n");

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

    resultadosOlimpiadas = fopen("Temas/Olimpiadas/resultados_olimpiadas.txt", "r");

    if(resultadosOlimpiadas == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }

    fscanf(resultadosOlimpiadas, "%d", &qtdAnterior);
    fscanf(resultadosOlimpiadas, "\n%.2lf", &percentualAnterior);
    fscanf(resultadosOlimpiadas, "\n\n%.2lf", &mdAvaliacaoAnterior);
    fscanf(resultadosOlimpiadas, "\n\n\n%.2lf", &mdRecomendaAnterior);

    fclose(resultadosOlimpiadas);
    
    resultadosOlimpiadas = fopen("Temas/Olimpiadas/resultados_olimpiadas.csv", "w");

    if(resultadosOlimpiadas == NULL){
        printf("\t\t\t\tErro ao abrir o arquivo!");
        getch();
        exit(1);
    }
    
    fprintf(resultadosOlimpiadas, "Análise dos Resultados:\nQuantidade questionários;%d\nPercentual de acertos;%.2f%%\nMédia da avaliação;%.2f\nMédia da recomendação;%.2f", qtdNova, novoPercentual, mdNovaAvaliacao, mdNovaRecomenda);
    
    printf("\t\t\t\tQuantidade Avaliações: %d\n", qtdNova);
    printf("\t\t\t\tPercentual de acertos do questionário: %.2f%%\n", novoPercentual);
    printf("\t\t\t\tNota média dos visitantes: %.2f\n", mdNovaAvaliacao);

    fclose(resultadosOlimpiadas);
}