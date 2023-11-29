#ifndef BILHETERIA_H
#define BILHETERIA_H

#define MAX_BILHETES 50

void escolhaTema();
void dadosUsuario();
void pagamento();
void gerarCod();

extern char nomeUsuario[30], codigo[5];
extern int numCompras, idadeUsuario, estudante, temaEscolhido, pagamentoRealizado, qtd;

struct Registros{
        int     numBilhete;
        char    nome[50];
        int     idade;
        char    tema[50];
        char    codigoBilhete[5];
        char    status[10];
    };
    
struct Registros ingressos[MAX_BILHETES];
    
#endif 