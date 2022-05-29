#include <stdlib.h>
#include <stdio.h>
#include "util.h"

int MAX(int a, int b) { return a > b ? a : b; }

//função para gerar números aleátorios 
int *geraAleatorio(int N) {
  int *numerosAleatorios = malloc(sizeof(int) * N);

  for (int i = 0; i < N; i++) {
    numerosAleatorios[i] = (rand() % (N * 1000)) + 1;
  }

  return numerosAleatorios;
}

void print(char *msg) {
  printf("%s", msg);
  printf("\n");
}

//função para cálculo do tempo de execução
double tempoMedioGeral(int tamanho, RegAVL registrosAvl[tamanho], RegBST registrosBst[tamanho]) {

  double media = 0;
  for(int i = 0; i < tamanho; i++) {
    media += registrosAvl[i].tempoConstrucao;
    media += registrosBst[i].tempoConstrucao;
    
  }
  media /= (tamanho * 2);
  return media;
}

//função para cálculo de altura
double alturaMediaGeral(int tamanho, RegAVL registrosAvl[tamanho], RegBST registrosBst[tamanho]) {
  double media = 0;

  for(int i = 0; i < tamanho; i++) {
    media += registrosAvl[i].altura;
    media += registrosBst[i].altura;
    
  }
  media /= (tamanho * 2);
  return media;
}

void relatorioGeral(int tamanho, RegAVL registrosAvl[tamanho], RegBST registrosBst[tamanho]) {
  printf("Geral\n\n");
  printf("Experimento com A = %d e N = %d\n\n", tamanho, registrosAvl[0].nos);
  printf("Tempo médio de construção: %fs\n\n", tempoMedioGeral(tamanho, registrosAvl, registrosBst));
  printf("Altura média: %.2f\n", alturaMediaGeral(tamanho, registrosAvl, registrosBst));
}
