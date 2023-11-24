#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criar_grafo_adj(int tamanho) {
  int v;
  GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
  G->E = 0;
  G->V = tamanho;
  G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
  for (v = 0; v < G->V; v++) {
    G->Adj[v] = NULL;
  }
  return G;
}

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho) {
  int v;
  GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
  G->E = 0;
  G->V = tamanho;
  G->Mat = (int **)malloc(tamanho * sizeof(int *));
  for (v = 0; v < G->V; v++) {
    G->Mat[v] = (int *)calloc(tamanho, sizeof(int));
  }
  return G;
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj(GrafoA *G) {
  int v;
  for (v = 0; v < G->V; v++) {
    if (G->Adj[v] != NULL) {
      free(G->Adj[v]);
    }
  }
  free(G->Adj);
  free(G);
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_mat(GrafoM *G) {
  int v;
  for (v = 0; v < G->V; v++) {
    if (G->Mat[v] != NULL) {
      free(G->Mat[v]);
    }
  }
  free(G->Mat);
  free(G);
}