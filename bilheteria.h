#ifndef BILHETERIA_H
#define BILHETERIA_H

#define MAX_BILHETES 100

void venda_bilhete();
void pagamento_bilhete();

extern char bilhetesDoUsuario[MAX_BILHETES][100], nomeUsuario;
extern int numCompras, idadeUsuario, pcd, estudante;



#endif