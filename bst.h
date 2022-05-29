typedef struct noBst {
    int chave;
    struct noBst * esq;
    struct noBst * dir;
} BST;

typedef struct RegistroBST {
  int altura;
  int nos;
  double tempoConstrucao;
} RegBST;

void relatorioBST(int tamanho, RegBST registros[tamanho]);

double tempoMedioRegistrosBst(int tamanho, RegBST registros[tamanho]);

double alturaMediaRegistrosBst(int tamanho, RegBST registros[tamanho]);

BST *bstNovoNo(int chaveParaCriacao);

BST *bstInsert(BST * raiz, int chaveParaInsercao);

int bstCalculaAltura(BST * raiz);

void bstFree(BST * raiz);
