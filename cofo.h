/* Universidade Federal do Maranhão
  Disciplina: Estrutura de Dados 1
  Professor: Anselmo Paiva
  Alunos: Pedro Alexandre Ferreira França e  Valter Abreu Silva Junior
                            Trabalho de Implementação 
*/

/*Variáveis*/
typedef struct _cofo_ COFO;

/*Funçoes*/
COFO *criarCofo(int maxItens);
int inserirNoCofo(COFO *cofo, int item);
int removerNoCofo(COFO *cofo, int item);
int verificarNoCofo(COFO *cofo, int item);
int deletaCOFO(COFO *cofo);
void mostraCofo(COFO * cofo);