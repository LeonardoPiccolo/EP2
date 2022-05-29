#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int A, N, inicio, fim, opcao;

  do {
    print("1 - Nova simulação");
    print("2 - Sair");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1: {
        system("clear");
        printf("Digite a quantidade de amostras: ");
        scanf("%d", &A);
        printf("Digite a quantidade de elementos para cada amostra: ");
        scanf("%d", &N);
  
        RegBST registrosBst[A];
        RegAVL registrosAvl[A];
  
        for (int i = 0; i < A; i++) {
          int *numerosAleatorios = geraAleatorio(N);
  
          BST *rBst = malloc(sizeof(BST));
          AVL *rAvl = malloc(sizeof(AVL));
  
          rBst = NULL;
          rAvl = NULL;
  
          RegAVL regAvl;
          RegBST regBst;
  
          inicio = clock();
          for (int k = 0; k < N; k++) {
            rBst = bstInsert(rBst, numerosAleatorios[k]);
          }
          fim = clock();
          regBst.tempoConstrucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
  
          inicio = clock();
          for (int j = 0; j < N; j++) {
            rAvl = avlInsert(rAvl, numerosAleatorios[j]);
          }
          fim = clock();
          regAvl.tempoConstrucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

  
          regAvl.nos = N;
          regBst.nos = N;
          regAvl.altura = avlCalculaAltura(rAvl);
          regBst.altura = bstCalculaAltura(rBst);
  
          registrosBst[i] = regBst;
          registrosAvl[i] = regAvl;
  
          avlFree(rAvl);
          bstFree(rBst);
          free(numerosAleatorios);
        }
        
        print("--------------------------------");
        relatorioGeral(A, registrosAvl, registrosBst);
        print("--------------------------------");
        relatorioBST(A, registrosBst);
        print("--------------------------------");
        relatorioAvl(A, registrosAvl);
        print("--------------------------------");
        break;
      }
      case 2: {
        system("clear");
        print("Fim do progama!");
        break;
      }
    }
  } while (opcao != 2);
}
