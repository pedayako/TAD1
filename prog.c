/* Universidade Federal do Maranhão
  Disciplina: Estrutura de Dados 1
  Professor: Anselmo Paiva
  Alunos: Pedro Alexandre Ferreira França e  Valter Abreu Silva Junior
                            Trabalho de Implementação 
*/

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <locale.h>
#include "cofo.h"

void separar(){
    printf("\n\n");
    printf("------------------------------------");
    printf("\n\n");  
}

int main(void) {
    setlocale(LC_ALL, "pt-BR");
    COFO *meuCofo;
    int tamanhoCofo;

    while(true){
        printf("Digite tamanho do cofo: ");
        scanf("%d", &tamanhoCofo);
        if(tamanhoCofo < 1){
            printf("Digite um valor maior que 0\n");
        }else{
            break;
        }
        system("pause");
        system("cls");
    }
    meuCofo = criarCofo(tamanhoCofo);
    
    /*Inserir elementos*/
    int item, i;
    printf("Insira os elementos: ");
    for(i = 0; i < tamanhoCofo; i++){
        scanf("%d", &item);
        inserirNoCofo(meuCofo, item);
    }

    /*Menu*/
    int opcao = -1;
    int verifica;
    while(1){
        system("cls");
        //system("color b");
        printf("1 - INSERIR\n");
        printf("2 - REMOVER\n");
        printf("3 - VERIFICAR\n");
        printf("4 - MOSTRE MEU COFO\n");
        printf("5 - APAGAR COFO\n:: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: 
                printf("Insira o elemento: ");
                scanf("%d", &item);
                verifica = inserirNoCofo(meuCofo, item);
                if(verifica){
                    printf("\nValor inserido no cofo.");
                }else{
                    printf("\nValor nao foi inserido no cofo.");
                }
                break;
            case 2: 
                printf("Insira o elemento: ");
                scanf("%d", &item);
                verifica = removerNoCofo(meuCofo, item);
                if(verifica){
                    printf("\nValor removido do cofo.");
                }else{
                    printf("\nValor nao foi removido do cofo.");
                }
                break;
            case 3: 
                printf("Insira o elemento: ");
                scanf("%d", &item);
                verifica = verificarNoCofo(meuCofo, item);
                if(verifica){
                    printf("\nValor esta no cofo.");
                }else{
                    printf("\nValor nao esta no cofo.");
                }
                break;
            case 4:
                mostraCofo(meuCofo);
                break;
            case 5: 
                deletaCOFO(meuCofo);
                printf("O Cofo foi excluido, Ate logo! ;(\n");
                system("pause");
                return 0;
                break;
            default:
                printf("Opção Invalida");
                break;
        }
        printf("\n");
        system("pause");
    }
}

