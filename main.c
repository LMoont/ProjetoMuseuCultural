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
    printf("\t\t\t\tCódigo: %s\n", ingressos[i].codigoBilhete);
    printf("\t\t\t\tStatus: %s\n", ingressos[i].status);
    }

    printf("\n\n\n");
    system("pause");
    system("cls");
    menuEntrada();
}

void sobre(){
    printf("\n\n\t\t\t\t========================= INFORMAÇÕES ADICIONAIS =========================\n\n\n");
    
    printf("\n\t\t\t\tREGRAS PARA A COMPRA DOS INGRESSOS");
    printf("\n\t\t\t\tMeia-Entrada: estudantes que apresentarem a carteirinha; PcD ou\n\t\t\t\tidoso (a partir de 60 anos), conforme a lei da meia-entrada.\n");
    printf("\t\t\t\tEntrada Gratuita (Isenção): nas terças e quintas.\n\n");
    
    printf("\n\t\t\t\tDADOS DO USUÁRIO:");
    printf("\n\t\t\t\tNenhum dado sensível será coletado. Todos os dados informados pelo usuário\n\t\t\t\testarão protegidos pela LGPD.\n\n");

    printf("\n\t\t\t\tQUESTIONÁRIOS E AVALIAÇÕES DAS EXPOSIÇÕES:");
    printf("\n\t\t\t\tAs respostas coletadas dos questionários e avaliações de temas servirão\n\t\t\t\tapenas para analisar a aprovação da obra. Nenhuma resposta será vinculada\n\t\t\t\tao respectivo visitante.\n\n");

    printf("\n\t\t\t\tDESCRIÇÃO DO PROGRAMA:");
    printf("\n\t\t\t\tSoftware de gerenciamento de um museu. Inclui a exposição de temas culturais\n\t\t\t\te atuais, gerenciamento de ingressos, coleta de pesquisas de visitantes\n\t\t\t\te análise de dados.\n\n");

    printf("\n\t\t\t\tAUTOR:");
    printf("\n\t\t\t\tLucas Montino.\n\n");

    printf("\n\t\t\t\tCOLABORADORES:");
    printf("\n\t\t\t\tBruno Ferreira, Guilherme Fernandez, Gabriel Stangari,\n\t\t\t\tIvan Oliveira e Kaiqui Monteiro.\n\n");

    printf("\n\n*Pressione qualquer tecla para voltar*");
    getch();
    menuEntrada();

}

void temas(){
    printf("\n\n\t\t\t=============================== APRESENTAÇÃO DOS TEMAS ===============================\n\n\n");
    
    printf("\n\t\t\t100 ANOS DA SEMANA DE ARTE MODERNA:\n");
    printf("\t\t\tCelebra o centenário da icônica Semana de Arte Moderna de 1922, um marco cultural no\n\t\t\tBrasil que revolucionou as artes e promoveu a valorizaçãoo da cultura nacional.\n\n");

    printf("\n\t\t\t150 ANOS DE SANTOS DUMONT:\n");
    printf("\t\t\tUma homenagem ao 150° aniversário de Alberto Santos-Dumont, pioneiro da aviação e\n\t\t\tinventor brasileiro, cujas realizações revolucionaram a história da aviação.\n\n");

    printf("\n\t\t\tJOGOS OLÍMPICOS DE PARIS 2024:\n");
    printf("\t\t\tPróxima edição dos Jogos Olímpicos de Verão que ocorrerão em Paris, França, em 2024.\n\n");

    printf("\n\t\t\tCOPA DO MUNDO CATAR 2022:\n");
    printf("\t\t\tFoi a primeira vez que a Copa do Mundo foi realizada no Oriente Médio e no final do ano,\n\t\t\tdevida a alta temperatura do país. Esses e outros elementos tornaram essa Copa histórica.\n\n");

    printf("\n\n\n*Pressione qualquer tecla para voltar*");
    getch();
    menuEntrada();
}

void menuEntrada(){
    int op;

    do{
        system("cls");
        
        printf("\n\n\t\t\t\t============== MENU MUSEU DE ARTE MULTITEMÁTICO ==============\n\n\n\n");
        printf("\n\t\t\t\t1 - Apresentação dos Temas\n\n\t\t\t\t2 - Venda de Ingressos\n\n\t\t\t\t3 - Exibição das Obras\n\n\t\t\t\t4 - Lista de Ingressos Comprados\n\n\t\t\t\t5 - Informações Adicionais e Avisos Importantes\n\n\t\t\t\t6 - Voltar\n\n");
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
                printf("\a\t\t\t\tDigite uma opção válida\n");
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

    printf("\n\n\n\n\n\n\t\t\t\t================= BEM-VINDO AO MUSEU MULTITEMÁTICO ================\n\n\n\n");

    printf("\n\n\n\n\t\t\t\t\t\t Veja as opções disponíveis no menu.\n");
    printf("\n\t\t\t\t\t    Aperte qualquer tecla para visualizar o menu\n\t\t\t\t\t\t     ou Espaço para sair agora.");
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