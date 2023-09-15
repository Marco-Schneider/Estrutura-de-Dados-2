#include "Arquivos/avl3.h"

int main() {
  Arvore* avl = NULL;
  char* nomes[] = {
      "Pedro", "Joaquim", "Sandra", "Daniele", "Jhony",
      "Bruna", "Roberto", "Ricardo", "Rafael", "Hayana",
      "Lorena", "Mariana", "Marina", "Roberta", "Chayene",
      "Edmundo"
  };
  int num_nomes = sizeof(nomes) / sizeof(nomes[0]);

  // Insert the names into the AVL tree
  for (int i = 0; i < num_nomes; i++) {
    avl = inserir(avl, nomes[i]);
  }

  // Print the AVL tree in alphabetical order
  printf("AVL Tree in alphabetical order:\n");
  imprimir_in_order(avl, 0);

  // Free the memory occupied by the AVL tree nodes
  for (int i = 0; i < num_nomes; i++) {
    avl = remover(avl, nomes[i]);
  }

  return 0;
}