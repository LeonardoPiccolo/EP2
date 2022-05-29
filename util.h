#include "avl.h"
#include "bst.h"

int MAX(int a, int b);

int *geraNumerosAleatorios(int N);

void relatorioGeral(int tamanho, RegAVL registrosAvl[tamanho], RegBST registrosBst[tamanho]);

//Calcula tempo de execução
double tempoMedioGeral(int tamanho, RegAVL registrosAvl[tamanho], RegBST registrosBst[tamanho]);

//Calcula média de altura
double alturaMediaGeral(int tamanho, RegAVL registrosAvl[tamanho], RegBST registrosBst[tamanho]);

void print(char *msg);
