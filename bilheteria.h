#ifndef BILHETERIA_H
#define BILHETERIA_H

#define MAX_BILHETES 100

// Declaração de função para venda de bilhetes
void venda_bilhete();

// Declaração do array para armazenar os bilhetes comprados

extern char bilhetesDoUsuario[MAX_BILHETES][100];

// Variável para rastrear o número de bilhetes comprados
extern int numCompras;

#endif