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
    printf("\t\t\t\tCódigo: %s\n", ingressos[i].codigoBilhete);
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
    printf("\n\t\t\t\tEntrada Gratuita (Isenção): somente nas terças e quintas.\n");
    
    printf("\n\t\t\t\tDADOS DO USUÁRIO:");
    printf("\n\t\t\t\tNenhum dado sensível será coletado. Todos os dados informados pelo usuário estarão\n\t\t\t\tprotegidos pela LGPD.");

    printf("\n\n\t\t\t\tQUESTIONÁRIOS E AVALIAÇÕES DAS EXPOSIÇÕES:");
    printf("\n\t\t\t\tAs respostas coletadas dos questionários e avaliações de temas servirão apenas\n\t\t\t\tpara analisar a aprovação da obra. Nenhuma resposta será vinculada ao respectivo visitante.");

    printf("\n\n\t\t\t\tDESCRIÇÃO DO PROGRAMA:");
    printf("\n\t\t\t\tSoftware de gerenciamento de um museu. Inclui a exposição de temas culturais e\n\t\t\t\tatuais, gerenciamento de ingressos, coleta de pesquisas de visitantes e análise de dados.");

    printf("\n\n\t\t\t\tAUTOR:");
    printf("\n\t\t\t\tLucas Montino.");

    printf("\n\n\t\t\t\tCOLABORADORES:");
    printf("\n\t\t\t\tBruno Ferreira, Guilherme Fernandez, Gabriel Stangari,\n\t\t\t\tIvan Oliveira e Kaiqui Monteiro.");

    printf("\n\n*Pressione qualquer tecla para voltar*");
    getch();
    menuEntrada();

}

void temas(){
    printf("\n\n\t\t\t\t================================= TEMAS DA EXPOSIÇÃO =================================\n\n");
    
    printf("\n\t\t\t\t100 ANOS DA SEMANA DE ARTE MODERNA:\n");
    printf("\t\t\t\tCelebra o centenário da icônica Semana de Arte Moderna de 1922, um marco cultural no\n\t\t\t\tBrasil que revolucionou as artes e promoveu a valorizaçãoo da cultura nacional.\n");

    printf("\n\t\t\t\t150 ANOS DE SANTOS DUMONT:\n");
    printf("\t\t\t\tUma homenagem ao 150° aniversário de Alberto Santos-Dumont, pioneiro da aviação e\n\t\t\t\tinventor brasileiro, cujas realizações revolucionaram a história da aviação.\n");

    printf("\n\t\t\t\tJOGOS OLÍMPICOS DE PARIS 2024:\n");
    printf("\t\t\t\tPróxima edição dos Jogos Olímpicos de Verão que ocorrerão em Paris, França, em 2024.\n");

    printf("\n\t\t\t\tCOPA DO MUNDO CATAR 2022:\n");
    printf("\t\t\t\tFoi a primeira vez que a Copa do Mundo foi realizada no Oriente Médio e no final do ano,\n\t\t\t\tdevida a alta temperatura do país. Esses e outros elementos tornaram essa Copa histórica.\n");

    printf("\n\n*Pressione qualquer tecla para voltar*");
    getch();
    menuEntrada();
}

void menuEntrada(){
    int op;

    do{
        system("cls");
        
        printf("\n\n\t\t\t\t============== MENU MUSEU DE ARTE MULTITEMÁTICO ==============\n\n");
        printf("\n\t\t\t\t1 - Temas\n\t\t\t\t2 - Bilheteria\n\t\t\t\t3 - Visualizar Bilhete\n\t\t\t\t4 - Entrada do Museu\n\t\t\t\t5 - Sobre\n\t\t\t\t6 - Voltar\n");
        printf("\n\t\t\t\tOpção: ");
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
                printf("\a\t\t\t\tDigite uma opção válida\n");
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

    printf("\n\n\t\t\t\t================= BEM-VINDO AO MUSEU MULTITEMÁTICO ================\n\n");

    printf("\n\n\n\n\t\t\t\tVeja as opções disponíveis no menu\n");
    printf("\n\t\t\t\tAperte qualquer tecla para visualizar o menu ou\n\t\t\t\tEspaço para sair agora.");
    printf("\n\n\n\t\t\t\t(dica: entre na sessão 'sobre' e 'temas' antes de ir para a\n\t\t\t\tcompra de ingressos)");

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