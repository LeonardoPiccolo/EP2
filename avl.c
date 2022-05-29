#include "util.h"
#include <stdio.h>
#include <stdlib.h>

double tempoMedioAvl(int tamanho, RegAVL registros[tamanho]) {
  double media = 0;

  for(int i = 0; i < tamanho; i++) {
    media += registros[i].tempoConstrucao;
  }
  media = media / tamanho;

  return media;
}

double alturaMediaAvl(int tamanho, RegAVL registros[tamanho]) {
  double media = 0;

  for(int i = 0; i < tamanho; i++) {
    media += registros[i].altura;
  }
  media = media / tamanho;

  return media;
}

AVL * avlNovoNo(int chaveParaCriacao) {
  AVL * no = malloc(sizeof(struct noAvl));
  no->chave = chaveParaCriacao;
  no->altura = 1;
  no->esq = NULL;
  no->dir = NULL;
  return no;
}

int avlGetAltura(AVL *raiz) {
  if (raiz == NULL)
    return 0;
  return raiz->altura;
}

int avlCalculaAltura(AVL *raiz) {
  if (raiz == NULL)
    return 0;

  int alturaEsq = avlCalculaAltura(raiz->esq);
  int alturaDir = avlCalculaAltura(raiz->dir);
  return MAX(alturaEsq, alturaDir) + 1;
}


int avlCalculaFb(AVL *no) {
  return avlGetAltura(no->esq) - avlGetAltura(no->dir);
}

AVL *avlRotL(AVL *raiz) {
  if (raiz == NULL)
    return raiz;

  AVL *novaRaiz = raiz->dir;
  raiz->dir = novaRaiz->esq;
  novaRaiz->esq = raiz;

  raiz->altura = avlCalculaAltura(raiz);
  novaRaiz->altura = avlCalculaAltura(novaRaiz);

  return novaRaiz;
}

AVL *avlRotR(AVL *raiz) {
  if (raiz == NULL)
    return raiz;

  AVL *novaRaiz = raiz->esq;
  raiz->esq = novaRaiz->dir;
  novaRaiz->dir = raiz;

  raiz->altura = avlCalculaAltura(raiz);
  novaRaiz->altura = avlCalculaAltura(novaRaiz);

  return novaRaiz;
}

AVL *avlInsert(AVL *raiz, int chave) {
  if (raiz == NULL)
    return avlNovoNo(chave);

  if (chave > raiz->chave)
    raiz->dir = avlInsert(raiz->dir, chave);
  else
    raiz->esq = avlInsert(raiz->esq, chave);

  raiz->altura = avlCalculaAltura(raiz);
  int fb = avlCalculaFb(raiz);
  
  if (fb == 2) { 
    if (avlCalculaFb(raiz->esq) < 0) {
      raiz->esq = avlRotL(raiz->esq); 
    }
    raiz = avlRotR(raiz); 
    
  } else if (fb == -2) {
    if (avlCalculaFb(raiz->dir) > 0) {
      raiz->dir = avlRotR(raiz->dir);
    }
    raiz = avlRotL(raiz);
  }

  return raiz;
}

void avlFree(AVL *raiz) {
  if (raiz == NULL)
    return;

  if (raiz->esq != NULL)
    avlFree(raiz->esq);
  if (raiz->dir != NULL)
    avlFree(raiz->dir);

  free(raiz);
}

void relatorioAvl(int tamanho, RegAVL registros[tamanho]) {
  printf("AVL\n\n");
  printf("Experimento com A = %d e N = %d\n\n", tamanho, registros[0].nos);
  printf("Tempo médio de construção: %fs\n\n", tempoMedioAvl(tamanho, registros));
  printf("Altura média: %.2f\n", alturaMediaAvl(tamanho, registros));
}
