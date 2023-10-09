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
    printf("============== BEM-VINDO AO MUSEU MULTITEMÁTICO =============\n");
    printf("=============================================================\n\n");

    printf("TEMAS DA EXPOSIÇÃO:\n\n");
    
    printf("100 Anos da Semana de Arte Moderna:\n");
    printf("Celebra o centenário da icônica Semana de Arte Moderna de 1922, um marco cultural no Brasil\nque revolucionou as artes e promoveu a valorização da cultura nacional.\n");

    printf("\n150 anos de Santos Dumont:\n");
    printf("Uma homenagem ao 150º aniversário de Alberto Santos-Dumont, pioneiro da aviação e inventor \nbrasileiro, cujas realizações revolucionaram a história da aviação.\n");

    printf("\nJogos Olímpicos de Paris 2024:\n");
    printf("Refere-se à próxima edição dos Jogos Olímpicos de Verão que ocorrerão em Paris, França, em 2024.\n\n");

    venda_bilhete();
    pagamento_bilhete();
}

