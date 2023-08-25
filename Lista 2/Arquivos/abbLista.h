#ifndef ABBLISTA_H
#define ABBLISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
  int info;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;

int minimo(Arvore* a);
int maximo(Arvore* a);
void imprime_decrescente(Arvore* a);
int maior_ramo(Arvore* a, int res);

Arvore* cria_arvore_vazia(void);
void arvore_libera(Arvore* a);
Arvore* inserir(Arvore* a, int v);
Arvore* remover(Arvore* a, int v);
int buscar(Arvore* a, int v);
void pre_order(Arvore* a); 


#endif