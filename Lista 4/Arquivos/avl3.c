#include "avl3.h"
#include <string.h>
/*Função que devolve o maior entre dois números inteiros!*/
int maior (int esq, int dir) {
  return (esq > dir ? esq : dir);
}

/*----------------------*/
int altura (Arvore* a) {
  return (a == NULL ? -1 : a->altura);	
}

int atualizar_altura (Arvore *a) {
  return (maior(altura(a->esq), altura(a->dir)) + 1);	
}

/*----------------------*/
int balanceamento (Arvore *a) {
  return (altura(a->dir) - altura(a->esq));
}

/*----------------------*/
Arvore* rotacao_simples_esq (Arvore* a) {
  No* t = a->dir;
  a->dir = t->esq;
  t->esq = a;
  a->altura = atualizar_altura(a);
  t->altura = atualizar_altura(t);
  return t;
}

/*----------------------*/
Arvore* rotacao_simples_dir (Arvore* a) {
  No* t = a->esq;
  a->esq = t->dir;
  t->dir = a;
  a->altura = atualizar_altura(a);
  t->altura = atualizar_altura(t);
  return t;
}

/*----------------------*/
Arvore* rotacao_dupla_esq (Arvore* a) {
  a->dir = rotacao_simples_dir(a->dir);
  return rotacao_simples_esq(a);
}

/*----------------------*/
Arvore* rotacao_dupla_dir (Arvore* a) {
  a->esq = rotacao_simples_esq(a->esq);
  return rotacao_simples_dir(a);
}

/*----------------------*/
Arvore* atualizar_fb_dir (Arvore *a) {
  a->altura = atualizar_altura(a);
  if(balanceamento(a) == 2) {
    if(balanceamento(a->dir) >= 0) {
      a = rotacao_simples_esq(a);
    }
    else {
      a = rotacao_dupla_esq(a);
    }
  }
  return a;
}

/*----------------------*/
Arvore* atualizar_fb_esq (Arvore *a) {
  a->altura = atualizar_altura(a);
  if(balanceamento(a) == -2) {
    if(balanceamento(a->esq) <= 0) {
      a = rotacao_simples_dir(a);
    }
    else {
      a = rotacao_dupla_dir(a);
    }
  }
  return a;
}

/*----------------------*/
Arvore* inserir (Arvore *a, char* chave) {
  if(a == NULL) {
    a = (No*)malloc(sizeof(No));
    a->chave = strdup(chave);
    a->altura = 0;
    a->esq = a->dir = NULL;
  }
  else if(strcmp(chave, a->chave) < 0) {
    a->esq = inserir(a->esq, chave);
    a = atualizar_fb_esq(a);
  }
  else {
    a->dir = inserir(a->dir, chave);
    a = atualizar_fb_dir(a);
  }
  return a;
}

/*Função para remover um nó de uma árvore binária de busca balanceada!*/
Arvore* remover (Arvore *a, char* chave) {
    if (a == NULL) {
        return NULL;
    }
    else {
        int cmp = strcmp(chave, a->chave);
        if (cmp < 0) {
            a->esq = remover(a->esq, chave);
            a = atualizar_fb_dir(a);
        }
        else if (cmp > 0) {
            a->dir = remover(a->dir, chave);
            a = atualizar_fb_esq(a);
        }
        else {
            if ((a->esq == NULL) && (a->dir == NULL)) {
                free(a->chave); // Free the memory for the key
                free(a);
                a = NULL;
            }
            else if (a->esq == NULL) {
                No* tmp = a;
                a = a->dir;
                free(tmp->chave); // Free the memory for the key
                free(tmp);
            }
            else if (a->dir == NULL) {
                No* tmp = a;
                a = a->esq;
                free(tmp->chave); // Free the memory for the key
                free(tmp);
            }
            else {
                No* tmp = a->esq;
                while (tmp->dir != NULL) {
                    tmp = tmp->dir;
                }
                char* tmp_chave = a->chave;
                a->chave = tmp->chave;
                tmp->chave = tmp_chave;
                a->esq = remover(a->esq, chave);
                a = atualizar_fb_dir(a);
            }
        }
        return a;
    }
}

/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimir_in_order (Arvore* a, int nivel) {
  if (a != NULL) {
    int i;
    for (i = 0; i < nivel; i++) {
      printf("      ");
    }
    printf("Nome: %s (altura: %d, fb: %+d) no nivel: %d\n", a->chave, a->altura, balanceamento(a), nivel);
    imprimir_in_order (a->esq, nivel + 1);
    imprimir_in_order (a->dir, nivel + 1);
  }
}

