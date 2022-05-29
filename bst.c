#include "util.h"
#include <stdio.h>
#include <stdlib.h>

double tempoMedioBst(int tamanho, RegBST registros[tamanho]) {
  double media = 0;

  for(int i = 0; i < tamanho; i++) {
    media += registros[i].tempoConstrucao;
  }
  media /= tamanho;

  return media;
}

double alturaMediaBst(int tamanho, RegBST registros[tamanho]) {
  double media = 0;

  for(int i = 0; i < tamanho; i++) {
    media += registros[i].altura;
  }
  media = media / tamanho;

  return media;
}

BST * bstNovoNo(int chaveParaCriacao) {
  BST *no = malloc(sizeof(struct noBst));
  no->chave = chaveParaCriacao;
  no->esq = NULL;
  no->dir = NULL;
  return no;
}

BST * bstInsert(BST *raiz, int chaveParaInsercao) {
  if (raiz == NULL) {
    return bstNovoNo(chaveParaInsercao);
  }

  if (chaveParaInsercao > raiz->chave) {
    raiz->dir = bstInsert(raiz->dir, chaveParaInsercao);
  } else {
    raiz->esq = bstInsert(raiz->esq, chaveParaInsercao);
  }

  return raiz;
}

int bstCalculaAltura(BST *raiz) {
  if (raiz == NULL)
    return 0;

  int alturaEsq = bstCalculaAltura(raiz->esq);
  int alturaDir = bstCalculaAltura(raiz->dir);
  return MAX(alturaEsq, alturaDir) + 1;
}

void bstFree(BST *raiz) {
  if (raiz == NULL)
    return;

  if (raiz->esq != NULL)
    bstFree(raiz->esq);
  if (raiz->dir != NULL)
    bstFree(raiz->dir);

  free(raiz);
}

void relatorioBST(int tamanho, RegBST registros[tamanho]) {
  printf("BST\n\n");
  printf("Experimento com A = %d e N = %d\n\n", tamanho, registros[0].nos);
  printf("Tempo médio de construção: %fs\n\n", tempoMedioBst(tamanho, registros));
  printf("Altura média: %.2f\n", alturaMediaBst(tamanho, registros));
}
