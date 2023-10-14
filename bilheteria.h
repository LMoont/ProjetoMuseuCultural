#ifndef BILHETERIA_H
#define BILHETERIA_H

#define MAX_BILHETES 50

void venda_bilhete();
void pagamento_bilhete();
void gerarCod_bilhete();

extern char temasDoUsuario[MAX_BILHETES][40], nomeUsuario[30], codigo[5];
extern int numCompras, idadeUsuario, estudante, temaEscolhido;

struct Registros{
        int numBilhete;
        char    nome[50];
        int     idade;
        char    tema[MAX_BILHETES][50];
        char    codigoBilhete[MAX_BILHETES][5];
        char    status[MAX_BILHETES][10];
    };
    
struct Registros ingressos[MAX_BILHETES];
    
#endif 