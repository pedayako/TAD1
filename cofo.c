/* Universidade Federal do Maranhão
  Disciplina: Estrutura de Dados 1
  Professor: Anselmo Paiva
  Alunos: Pedro Alexandre Ferreira França e  Valter Abreu Silva Junior
                            Trabalho de Implementação 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "cofo.h"

#define FALSE 0;
#define TRUE 1; 

struct _cofo_{
    int numItens;
    int maxItens;
    int *vetorItens;
};

COFO *criarCofo(int maxItens){
    COFO *novo_cofo = malloc(sizeof(COFO));
    
    novo_cofo->numItens = 0;
    novo_cofo->maxItens = maxItens;
    novo_cofo->vetorItens = malloc(sizeof(int)*(maxItens+1));

    /*preenche vetor com valor -1 == vazio */
    int i;
    for (i = 0; i < novo_cofo->maxItens; i++){
        novo_cofo->vetorItens[i] = -1;
    }
    
    return novo_cofo;
}
int inserirNoCofo(COFO *cofo, int item){
    if(cofo->numItens < cofo->maxItens){
        cofo->vetorItens[cofo->numItens] = item;
        cofo->numItens += 1;
        return TRUE;
    }
    return FALSE;
}
int removerNoCofo(COFO *cofo, int item){
    int i;
    for (i = 0; i <= cofo->numItens; i++){
        if( cofo->vetorItens[i] == item){
            cofo->numItens -= 1;
            for (int j=i+1; j<cofo->maxItens; j++) {
                cofo->vetorItens[j-1] = cofo->vetorItens[j];
            }
            cofo->vetorItens[cofo->maxItens-1] = -1;
            return TRUE;
        }
    }
    return FALSE; 
}
int verificarNoCofo(COFO *cofo, int item){
    int i;
    for (i = 0; i <= cofo->numItens; i++){
        if( cofo->vetorItens[i] == item){
            return TRUE;
        }
    }
    return FALSE; 
}
int deletaCOFO(COFO *cofo){
    free(cofo->vetorItens);
    free(cofo);
    return TRUE;
}
void mostraCofo(COFO *cofo){
    printf("[");
    for(int i=0; i < cofo->maxItens; i++){
        printf("%d ", cofo->vetorItens[i]);
    }
    printf("]");
}
