typedef struct noAvl {
    int chave;
    int altura;
    struct noAvl * esq;
    struct noAvl * dir;
} AVL;

typedef struct RegistroAVL {
  int altura;
  int nos;
  double tempoConstrucao;
} RegAVL;

void relatorioAvl(int tamanho, RegAVL registros[tamanho]);

double tempoMedioRegistrosAvl(int tamanho, RegAVL registros[tamanho]);

double alturaMediaRegistrosAvl(int tamanho, RegAVL registros[tamanho]);

AVL *avlNovoNo(int chaveParaCriacao);

int avlGetAltura(AVL *raiz);

int avlCalculaAltura(AVL *raiz);

int avlCalculaFb(AVL *no);

AVL *avlRotL(AVL *raiz);

AVL *avlRotR(AVL *raiz);

AVL *avlInsert(AVL *raiz, int chave);

void avlFree(AVL *raiz);
