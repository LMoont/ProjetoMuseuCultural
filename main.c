#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include "bilheteria.h"
#include "entrada_temas.h"
#include "arte_moderna.h"
#include "santos_dumont.h"
#include "olimpiadas.h"
#include "copa_catar.h"

void sobre();
void menuEntrada();
void temas();
void visualizarBilhete();
int main();

void visualizarBilhete(){
    int i;

    printf("\n\n\t\t\t\t============ LISTA DE INGRESSOS ============\n\n\n");

    for(i=0; i<numCompras; i++){
    printf("\n\t\t\t\tBilhete: %d\n", i+1);
    printf("\t\t\t\tNome: %s\n", ingressos[i].nome);
    printf("\t\t\t\tIdade: %d\n", ingressos[i].idade);
    printf("\t\t\t\tTema: %s\n", ingressos[i].tema);
    printf("\t\t\t\tC�digo: %s\n", ingressos[i].codigoBilhete);
    printf("\t\t\t\tStatus: %s\n", ingressos[i].status);
    }

    printf("\n\n\n");
    system("pause");
    system("cls");
    menuEntrada();
}

void sobre(){
    printf("\n\n\t\t\t\t========================= INFORMA��ES ADICIONAIS =========================\n\n\n");
    
    printf("\n\t\t\t\tREGRAS PARA A COMPRA DOS INGRESSOS");
    printf("\n\t\t\t\tMeia-Entrada: estudantes que apresentarem a carteirinha; PcD ou\n\t\t\t\tidoso (a partir de 60 anos), conforme a lei da meia-entrada.\n");
    printf("\t\t\t\tEntrada Gratuita (Isen��o): nas ter�as e quintas.\n\n");
    
    printf("\n\t\t\t\tDADOS DO USU�RIO:");
    printf("\n\t\t\t\tNenhum dado sens�vel ser� coletado. Todos os dados informados pelo usu�rio\n\t\t\t\testar�o protegidos pela LGPD.\n\n");

    printf("\n\t\t\t\tQUESTION�RIOS E AVALIA��ES DAS EXPOSI��ES:");
    printf("\n\t\t\t\tAs respostas coletadas dos question�rios e avalia��es de temas servir�o\n\t\t\t\tapenas para analisar a aprova��o da obra. Nenhuma resposta ser� vinculada\n\t\t\t\tao respectivo visitante.\n\n");

    printf("\n\t\t\t\tDESCRI��O DO PROGRAMA:");
    printf("\n\t\t\t\tSoftware de gerenciamento de um museu. Inclui a exposi��o de temas culturais\n\t\t\t\te atuais, gerenciamento de ingressos, coleta de pesquisas de visitantes\n\t\t\t\te an�lise de dados.\n\n");

    printf("\n\t\t\t\tAUTOR:");
    printf("\n\t\t\t\tLucas Montino.\n\n");

    printf("\n\t\t\t\tCOLABORADORES:");
    printf("\n\t\t\t\tBruno Ferreira, Guilherme Fernandez, Gabriel Stangari,\n\t\t\t\tIvan Oliveira e Kaiqui Monteiro.\n\n");

    printf("\n\n*Pressione qualquer tecla para voltar*");
    getch();
    menuEntrada();

}

void temas(){
    printf("\n\n\t\t\t=============================== APRESENTA��O DOS TEMAS ===============================\n\n\n");
    
    printf("\n\t\t\t100 ANOS DA SEMANA DE ARTE MODERNA:\n");
    printf("\t\t\tCelebra o centen�rio da ic�nica Semana de Arte Moderna de 1922, um marco cultural no\n\t\t\tBrasil que revolucionou as artes e promoveu a valoriza��oo da cultura nacional.\n\n");

    printf("\n\t\t\t150 ANOS DE SANTOS DUMONT:\n");
    printf("\t\t\tUma homenagem ao 150� anivers�rio de Alberto Santos-Dumont, pioneiro da avia��o e\n\t\t\tinventor brasileiro, cujas realiza��es revolucionaram a hist�ria da avia��o.\n\n");

    printf("\n\t\t\tJOGOS OL�MPICOS DE PARIS 2024:\n");
    printf("\t\t\tPr�xima edi��o dos Jogos Ol�mpicos de Ver�o que ocorrer�o em Paris, Fran�a, em 2024.\n\n");

    printf("\n\t\t\tCOPA DO MUNDO CATAR 2022:\n");
    printf("\t\t\tFoi a primeira vez que a Copa do Mundo foi realizada no Oriente M�dio e no final do ano,\n\t\t\tdevida a alta temperatura do pa�s. Esses e outros elementos tornaram essa Copa hist�rica.\n\n");

    printf("\n\n\n*Pressione qualquer tecla para voltar*");
    getch();
    menuEntrada();
}

void menuEntrada(){
    int op;

    do{
        system("cls");
        
        printf("\n\n\t\t\t\t============== MENU MUSEU DE ARTE MULTITEM�TICO ==============\n\n\n\n");
        printf("\n\t\t\t\t1 - Apresenta��o dos Temas\n\n\t\t\t\t2 - Venda de Ingressos\n\n\t\t\t\t3 - Exibi��o das Obras\n\n\t\t\t\t4 - Lista de Ingressos Comprados\n\n\t\t\t\t5 - Informa��es Adicionais e Avisos Importantes\n\n\t\t\t\t6 - Voltar\n\n");
        printf("\n\t\t\t\tOp��o: ");
        scanf("%d", &op);
        fflush(stdin);
        
        switch(op){
            case 1:
                system("cls");
                temas();
            break;
            
            case 2:
                system("cls");
                dadosUsuario();
            break;

            case 3:
                if(pagamentoRealizado == 1){
                    system("cls");
                    entradaTema();
                }else{
                    printf("\n\t\t\t\tPrecisa comprar o ingresso antes!\n\n\n");
                    system("pause");
                    system("cls");
                    dadosUsuario();
                }
            
            case 4:
                if(pagamentoRealizado == 1){
                    system("cls");
                    visualizarBilhete();
                }else{
                    printf("\n\t\t\t\tPrecisa comprar o ingresso antes!\n\n\n");
                    system("pause");
                    system("cls");
                    dadosUsuario();
                }
                
            break;

            case 5:
                system("cls");
                sobre();
            break;

            case 6:
                system("cls");
                main();
            break;
            
            default:
                printf("\a\t\t\t\tDigite uma op��o v�lida\n");
                getch();
            }
        }
        while (op);
}

int main ()
{
    int var;
    system("color 0F");
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n\n\n\n\n\t\t\t\t================= BEM-VINDO AO MUSEU MULTITEM�TICO ================\n\n\n\n");

    printf("\n\n\n\n\t\t\t\t\t\t Veja as op��es dispon�veis no menu.\n");
    printf("\n\t\t\t\t\t    Aperte qualquer tecla para visualizar o menu\n\t\t\t\t\t\t     ou Espa�o para sair agora.");
    var = getch();
    if(var == 32){
        printf("\n\n\t\t\t\t\t\tObrigado pela visita e volte sempre.");
        getch();
        exit(0);
        }
    
    menuEntrada();
    
    system("pause");
    
    return 0;
}