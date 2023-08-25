#include "Arquivos/abbLista.h"

int main(int argc, char* argv[ ]) {
  
  int elementoProcurado = atoi(argv[1]);

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

  if(buscar(a, elementoProcurado) == 1) {
    printf("O elemento %d foi encontrado!\n", elementoProcurado);
  }
  else {
    printf("O elemento %d nao foi encontrado\n", elementoProcurado);
  }

  arvore_libera(a);

  return 0;
}