#include "Arquivos/abbLista.h"

int main(int argc, char* argv[ ]) {
  
  Arvore *a = NULL;

  a = inserir (a, 50);
  a = inserir (a, 30);
  a = inserir (a, 90);
  a = inserir (a, 20);
  a = inserir (a, 40);
  a = inserir (a, 95);
  a = inserir (a, 10);
  a = inserir (a, 35);
  a = inserir (a, 45);

  printf("O menor valor encontrado foi %d\n", minimo(a));
  printf("O maior valor encontrado foi %d\n", maximo(a));

  arvore_libera(a);

  return 0;
}