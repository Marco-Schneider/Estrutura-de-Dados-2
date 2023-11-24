#include "Arquivos/grafo.h"
#include <stdio.h>
#include <stdlib.h>

#define Va 6
#define Vm 6

void adiciona_aresta(GrafoA* G, int comeco, int fim) {
  NoA* novoNo = (NoA*)malloc(sizeof(NoA));
  novoNo->id = fim;
  novoNo->next = G->Adj[comeco];
  G->Adj[comeco] = novoNo;
  G->E++;
}

int main() {

  /* Usando a lista de adjacencia*/

  GrafoA* Ga = criar_grafo_adj (Va);

  /*
    {0, 1}, {0, 5},
    {1, 2}, {1, 3}, 
    {2, 0}, {2, 4}, 
    {3, 2}, 
    {4, 3}, 
    {5, 4} 
  */

  int listAdj[][2] = {
    {0, 1}, {0, 5},
    {1, 2}, {1, 3}, 
    {2, 0}, {2, 4}, 
    {3, 2}, 
    {4, 3}, 
    {5, 4} 
  };

  printf("Grafo (lista de adjacencia)\n");
  
  for(int i=0; i<Va; i++) {
    for (int j = 0; j < sizeof(listAdj) / sizeof(listAdj[0]); j++) {
      if (listAdj[j][0] == i) 
        adiciona_aresta(Ga, i, listAdj[j][1]);
    }
  }

  for(int i=0; i<Va; i++) {
    printf("%d -> ", i);
    NoA *temp = Ga->Adj[i];
    while(temp != NULL) {
      printf("%d ", temp->id);
      temp = temp->next;
    }
    printf("\n");
  }
  liberar_grafo_adj(Ga);

  /* Usando a matriz adjacencia */

  GrafoM* Gm = criar_grafo_mat (Vm);

  int matrizAdj[Vm][Vm] = {
    {0, 1, 0, 0, 0, 1},
    {0, 0, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 1, 0}
  };

  for(int i=0; i<Vm; i++) {
    for(int j=0; j<Vm; j++) {
      Gm->Mat[i][j] = matrizAdj[i][j];
    }
  }

  printf("\nGrafo (matriz adjacencia):\n");
  for(int i=0; i<Vm; i++) {
    for(int j=0; j<Vm; j++) {
      printf("%d ", Gm->Mat[i][j]);
    }
    printf("\n");
  }
  liberar_grafo_mat(Gm);

  return 0;
}