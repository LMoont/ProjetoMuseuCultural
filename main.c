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

    printf("\n\n\t\t\t\t=========== BILHETES ADQUIRIDOS ===========\n\n\n");

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
    printf("\n\n\t\t\t\t================================= SOBRE =================================\n\n");
    
    printf("\n\t\t\t\tREGRAS PARA A COMPRA DOS INGRESSOS:");
    printf("\n\t\t\t\tMeia-Entrada: estudantes que apresentarem a carteirinha; PcD ou\n\t\t\t\tidoso (a partir de 60 anos), conforme a lei da meia-entrada.\n");
    printf("\n\t\t\t\tEntrada Gratuita (Isen��o): somente nas ter�as e quintas.\n");
    
    printf("\n\t\t\t\tDADOS DO USU�RIO:");
    printf("\n\t\t\t\tNenhum dado sens�vel ser� coletado. Todos os dados informados pelo usu�rio estar�o\n\t\t\t\tprotegidos pela LGPD.");

    printf("\n\n\t\t\t\tQUESTION�RIOS E AVALIA��ES DAS EXPOSI��ES:");
    printf("\n\t\t\t\tAs respostas coletadas dos question�rios e avalia��es de temas servir�o apenas\n\t\t\t\tpara analisar a aprova��o da obra. Nenhuma resposta ser� vinculada ao respectivo visitante.");

    printf("\n\n\t\t\t\tDESCRI��O DO PROGRAMA:");
    printf("\n\t\t\t\tSoftware de gerenciamento de um museu. Inclui a exposi��o de temas culturais e\n\t\t\t\tatuais, gerenciamento de ingressos, coleta de pesquisas de visitantes e an�lise de dados.");

    printf("\n\n\t\t\t\tAUTOR:");
    printf("\n\t\t\t\tLucas Montino.");

    printf("\n\n\t\t\t\tCOLABORADORES:");
    printf("\n\t\t\t\tBruno Ferreira, Guilherme Fernandez, Gabriel Stangari,\n\t\t\t\tIvan Oliveira e Kaiqui Monteiro.");

    printf("\n\n*Pressione qualquer tecla para voltar*");
    getch();
    menuEntrada();

}

void temas(){
    printf("\n\n\t\t\t\t================================= TEMAS DA EXPOSI��O =================================\n\n");
    
    printf("\n\t\t\t\t100 ANOS DA SEMANA DE ARTE MODERNA:\n");
    printf("\t\t\t\tCelebra o centen�rio da ic�nica Semana de Arte Moderna de 1922, um marco cultural no\n\t\t\t\tBrasil que revolucionou as artes e promoveu a valoriza��oo da cultura nacional.\n");

    printf("\n\t\t\t\t150 ANOS DE SANTOS DUMONT:\n");
    printf("\t\t\t\tUma homenagem ao 150� anivers�rio de Alberto Santos-Dumont, pioneiro da avia��o e\n\t\t\t\tinventor brasileiro, cujas realiza��es revolucionaram a hist�ria da avia��o.\n");

    printf("\n\t\t\t\tJOGOS OL�MPICOS DE PARIS 2024:\n");
    printf("\t\t\t\tPr�xima edi��o dos Jogos Ol�mpicos de Ver�o que ocorrer�o em Paris, Fran�a, em 2024.\n");

    printf("\n\t\t\t\tCOPA DO MUNDO CATAR 2022:\n");
    printf("\t\t\t\tFoi a primeira vez que a Copa do Mundo foi realizada no Oriente M�dio e no final do ano,\n\t\t\t\tdevida a alta temperatura do pa�s. Esses e outros elementos tornaram essa Copa hist�rica.\n");

    printf("\n\n*Pressione qualquer tecla para voltar*");
    getch();
    menuEntrada();
}

void menuEntrada(){
    int op;

    do{
        system("cls");
        
        printf("\n\n\t\t\t\t============== MENU MUSEU DE ARTE MULTITEM�TICO ==============\n\n");
        printf("\n\t\t\t\t1 - Temas\n\t\t\t\t2 - Bilheteria\n\t\t\t\t3 - Visualizar Bilhete\n\t\t\t\t4 - Entrada do Museu\n\t\t\t\t5 - Sobre\n\t\t\t\t6 - Voltar\n");
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
                    visualizarBilhete();
                }else{
                    printf("\n\t\t\t\tPrecisa comprar o ingresso antes!\n\n\n");
                    system("pause");
                    system("cls");
                    dadosUsuario();
                }
            
            case 4:
                if(pagamentoRealizado == 1){
                    system("cls");
                    entradaTema();
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
    //system("color 1F");
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n\t\t\t\t================= BEM-VINDO AO MUSEU MULTITEM�TICO ================\n\n");

    printf("\n\n\n\n\t\t\t\tVeja as op��es dispon�veis no menu\n");
    printf("\n\t\t\t\tAperte qualquer tecla para visualizar o menu ou\n\t\t\t\tEspa�o para sair agora.");
    printf("\n\n\n\t\t\t\t(dica: entre na sess�o 'sobre' e 'temas' antes de ir para a\n\t\t\t\tcompra de ingressos)");

    var = getch();
    if(var == 32){
        printf("\n\t\t\t\tObrigado pela visita e volte sempre.");
        getch();
        exit(0);
        }
    
    menuEntrada();
    
    system("pause");
    
    return 0;
}