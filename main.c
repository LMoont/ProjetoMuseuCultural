#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "bilheteria.h"

main ()
{
    setlocale(LC_ALL, "Portuguese");

    printf("\n=============================================================\n");
    printf("============== BEM-VINDO AO MUSEU MULTITEM�TICO =============\n");
    printf("=============================================================\n\n");

    printf("TEMAS DA EXPOSI��O:\n\n");
    
    printf("100 Anos da Semana de Arte Moderna:\n");
    printf("Celebra o centen�rio da ic�nica Semana de Arte Moderna de 1922, um marco cultural no Brasil\nque revolucionou as artes e promoveu a valoriza��o da cultura nacional.\n");

    printf("\n150 anos de Santos Dumont:\n");
    printf("Uma homenagem ao 150� anivers�rio de Alberto Santos-Dumont, pioneiro da avia��o e inventor \nbrasileiro, cujas realiza��es revolucionaram a hist�ria da avia��o.\n");

    printf("\nJogos Ol�mpicos de Paris 2024:\n");
    printf("Refere-se � pr�xima edi��o dos Jogos Ol�mpicos de Ver�o que ocorrer�o em Paris, Fran�a, em 2024.\n\n");

    venda_bilhete();
    pagamento_bilhete();
}

