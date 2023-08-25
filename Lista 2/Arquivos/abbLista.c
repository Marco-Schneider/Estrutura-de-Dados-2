#include "abbLista.h"
#include <stdlib.h>

Arvore* cria_arvore_vazia(void) {
  return NULL;
}

void arvore_libera(Arvore* a) {
  if (a != NULL) {
    arvore_libera (a->esq);
    arvore_libera (a->dir);
    free(a);
  }
}

//========= Q1 - inserir
Arvore* inserir(Arvore *a, int v) {
  if(a == NULL) {
    a = (Arvore*)malloc(sizeof(Arvore));
    a->info = v;
    a->esq = NULL;
    a->dir = NULL;
  }
  else if(v < a->info) {
    a->esq = inserir(a->esq, v);
  }
  else {
    a->dir = inserir(a->dir, v);
  }
  return a;
}

//========= Q1 - remover
Arvore* remover(Arvore *a, int v) {
  if(a == NULL) {
    return NULL;
  }
  else {
    if(a->info > v) {
      a->esq = remover(a->esq, v);
    }
    else if(a->info < v) {
      a->dir = remover(a->dir, v);
    }
    else {
      if((a->esq == NULL) && (a->dir == NULL)) {
        free(a);
        a = NULL;
      }
      else if(a->dir == NULL) {
        Arvore* temp = a;
        a = a->esq;
        free(temp);
      }
      else if(a->esq == NULL) {
        Arvore* temp = a;
        a = a->dir;
        free(temp);
      }
      else {
        Arvore* temp = a->esq;
        while(temp->dir != NULL) {
          temp = temp->dir;
        }
        a->info = temp->info;
        temp->info = v;
        a->esq = remover(a->esq, v);
      }
    }
  }
  return a;
}


//========= Q1 - busca
int buscar(Arvore *a, int v) {
  if(a == NULL) {
    return 0;
  }
  else if(v < a->info) {
    return buscar(a->esq, v);
  }
  else if(v > a->info) {
    return buscar(a->dir, v);
  }
  else {
    return 1;
  }    
}

//========= Q2 - min =====
int minimo(Arvore* a) {
  if(a == NULL) {
    return -INT_MAX;
  }
  else {
    while(a->esq != NULL) {
      a = a->esq;
    }
    return a->info;
  }
}

//========= Q2 - max =====
int maximo(Arvore* a) {
  if(a == NULL) {
    return -INT_MAX;
  }
  else {
    while(a->dir != NULL) {
      a = a->dir;
    }
    return a->info;
  }
}

//========= Q3 - imprime_decrescente =====
void imprime_decrescente(Arvore* a) {
  if(a == NULL) {
    return;
  }
  imprime_decrescente(a->dir);
  printf("%d ", a->info);
  imprime_decrescente(a->esq);
}

//========= Q4 - maior ramo =====
int maior_ramo(Arvore* a, int res) {
    if (a == NULL)
      return 0;
 
    int l = maior_ramo(a->esq, res);
    int r = maior_ramo(a->dir, res);
 
    int max_single = max(max(l, r) + a->info, a->info);
 
    int max_top = max(max_single, l + r + a->info);
 
    res = max(res, max_top);
 
    return max_single;
}

void pre_order (Arvore* a) {
  if (a != NULL) {
    printf("%d ", a->info);
    pre_order (a->esq);
    pre_order (a->dir);
  } 
}

// int main () {

//    int i;

//    Arvore *a = cria_arvore_vazia ();

//    //inserir
//    //....

//    printf("\n");
//    pre_order (a);	
//    printf("\n");


//    // ====== Q5 ====

//    return 0;
// }

