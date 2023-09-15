#include "Arquivos/avl2.h"

int main () {

  Arvore *AVL = NULL;
  int chaves[] = {
    14, 
    5, 28, 
    2, 8, 18, 33, 
    1, 3, 6, 11, 15, 20, 30, 38,
    4, 7, 10, 12, 16, 19, 21, 29, 31, 35, 39,
    13, 22, 32, 34, 36, 40, 37
  };

  for(int i=0; i<sizeof(chaves)/sizeof(chaves[0]); i++) {
    AVL = inserir(AVL, chaves[i]);
  }

  printf("Arvore completa!\n");
  imprimir_in_order(AVL, 0);

  AVL = remover(AVL, 1);
  
  printf("Arvore depois de remover 1\n");
  imprimir_in_order(AVL, 0);

  for(int i=0; i<sizeof(chaves)/sizeof(chaves[0]); i++) {
    AVL = remover(AVL, chaves[i]);
  }

  return 0;
}