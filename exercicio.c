#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Estrutura para o EP2 - Nas Alturas
 * 
 * O objetivo do EP é utilizar as árvores binárias de busca comum
 * e também as auto-balanceada (AVL).
 * 
 * O programa deve receber dois inputs do usuário:
 *  Amostra (A)
 *  Numero de nós (N)
 * 
 * O programa deve, para cada amostra, gerar duas árvores com N nós:
 *  >>> uma AVL
 *  >>> uma BST comum
 * Depois de gerar cada uma delas, o programa vai anotar suas alturas para
 * poder calcular a média de alturas geral e a média para bst comum e AVL.
 * 
 * Usando esse template, vc precisa:
 * >>> Implementar as funções:
        bstCalculaAltura
        avlCalculaAltura
        avlRotR
        geraNumerosAleatorios
   >>> Pensar em como resolver o TODO no final da função main().
       Como fazer o EP funcionar? Vc deve pensar em uma forma de 
       armazenar as alturas e depois calcular as médias (geral e para cada tipo de árvore)
 * 
 * --------------------------------------------------------------------------------
 * Pra quem gosta mesmo:
 * Para calcularmos o tempo gasto numa operação, fazemos:
 
    clock_t t_inicio, t_final;
    double t_total;

    t_inicio = clock();
    fazTudoQueTemQueFazer(); // aqui podemos ter várias linhas, é onde vai o que queremos medir o tempo
    t_final = clock();

    t_total = (double) (t_final - t_inicio) / CLOCKS_PER_SEC;
    printf("Tempo total gasto pela CPU: %f\n", t_total);
 * 
 */

/**
 * @brief Retorna o maior valor entre a e b.
 * 
 * @param a 
 * @param b 
 * @return int o maior valor
 */
int MAX(int a, int b) {
    return a > b ? a : b;
}

typedef struct noBst {
    int chave;
    struct noBst * esq;
    struct noBst * dir;
} BST;

/**
 * Responsável pela criação de um espaço na memória
 * que "caiba" o equivalente a uma struct noBst.
 * @return o ponteiro para o nó criado
 * */
BST * bstNovoNo(int chaveParaCriacao) {
    BST * no = malloc(sizeof(struct noBst));
    no->chave = chaveParaCriacao;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

/**
 * @brief Insere um novo nó em uma BST comum, mantendo as propriedades da BST
 * 
 * @param raiz nó que será usado como início do algoritmo de busca para inserção
 * @param chaveParaInsercao chave do novo nó inserido
 * @return BST* raíz da árvore (na BST comum nunca muda)
 */
BST * bstInsert(BST * raiz, int chaveParaInsercao) {
    if (raiz == NULL) {
        return bstNovoNo(chaveParaInsercao);
    }

    if (chaveParaInsercao > raiz->chave) {
        raiz->dir = bstInsert(raiz->dir, chaveParaInsercao);
    }
    else {
        raiz->esq = bstInsert(raiz->esq, chaveParaInsercao);
    }

    return raiz;
}

/**
 * @brief Calcula a altura de um nó recebido por parâmetro como raíz
 * 
 * @param raiz nó a se calcular a altura
 * @return int a altura calculada do nó
 */
int bstCalculaAltura(BST * raiz) {
  // TODO: Essa função precisa retornar um inteiro que represente a altura do 
  //       nó BST recebido
  return 0; // retornando zero só para não dar erro até vc implementar certo
}

void bstFree(BST * raiz) {
  if (raiz == NULL) return;

  if (raiz->esq != NULL)
    bstFree(raiz->esq);
  if (raiz->dir != NULL)
    bstFree(raiz->dir);
  
  free(raiz);
}

// _____________________________________________________________________________________________

typedef struct noAvl {
    int chave;
    int altura; // Para árvores AVL, precisamos ter a altura dos nós
    struct noAvl * esq;
    struct noAvl * dir;
} AVL;

/**
 * Responsável pela criação de um espaço na memória
 * que "caiba" o equivalente a uma struct noAvl.
 * @return o ponteiro para o nó criado
 * */
AVL * avlNovoNo(int chaveParaCriacao) {
    AVL * no = malloc(sizeof(struct noAvl));
    no->chave = chaveParaCriacao;
    no->altura = 1; // Qual é a altura de uma folha?
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

/**
 * @brief Acessa o campo altura do nó AVL
 * 
 * @param raiz 
 * @return int 
 */
int avlGetAltura(AVL * raiz) {
  if (raiz == NULL) return 0;
  return raiz->altura;
}

/**
 * @brief Calcula a altura de um nó recebido por parâmetro como raíz
 * 
 * @param raiz nó a se calcular a altura
 * @return int a altura calculada do nó
 */
int avlCalculaAltura(AVL * raiz) {
  // TODO: Essa função precisa retornar um inteiro que represente a altura do 
  //       nó AVL recebido
  return 0; // retornando zero só para não dar erro até vc implementar certo
}

/**
 * @brief Calcula o fator de balanceamento de um nó
 * 
 * @param no um nó AVL 
 * @return int o fator de balanceamento do nó
 */
int avlCalculaFb(AVL * no) {
  return avlGetAltura(no->esq) - avlGetAltura(no->dir);
}

/**
 * @brief Recebe um nó AVL e realiza uma rotação à esquerda
 *        com esse nó como pivô. Ao realizar a rotação,
 *        calcula e atualiza a altura do nó recebido e da nova
 *        raíz gerada após a rotação
 * 
 * @param raiz 
 * @return AVL* nova raíz após a rotação
 */
AVL * avlRotL(AVL * raiz) {
  if (raiz == NULL) return raiz;
  
  AVL * novaRaiz = raiz->dir;
  raiz->dir = novaRaiz->esq;
  novaRaiz->esq = raiz;

  raiz->altura = avlCalculaAltura(raiz);
  novaRaiz->altura = avlCalculaAltura(novaRaiz);

  return novaRaiz;
}

/**
 * @brief Recebe um nó AVL e realiza uma rotação à direita
 *        com esse nó como pivô. Ao realizar a rotação,
 *        calcula e atualiza a altura do nó recebido e da nova
 *        raíz gerada após a rotação
 * 
 * @param raiz 
 * @return AVL* nova raíz após a rotação
 */
AVL * avlRotR(AVL * raiz) {
  if (raiz == NULL) return raiz;
  
  AVL * novaRaiz = raiz->esq;
  raiz->esq = novaRaiz->dir;
  novaRaiz->dir = raiz;

  raiz->altura = avlCalculaAltura(raiz);
  novaRaiz->altura = avlCalculaAltura(novaRaiz);

  return novaRaiz;
}

/**
 * @brief Insere um novo nó em uma árvore AVL, que tem raíz recebida por param.
 *        A árvore se auto balanceará e mudará a raíz, se necessário.
 * 
 * @param raiz nó que será usado como início do algoritmo de busca para inserção
 * @param chaveParaInsercao chave do novo nó inserido
 * @return AVL* raíz da árvore (pode alterar)
 */
AVL * avlInsert(AVL * raiz, int chave) {
  if (raiz == NULL)
    return avlNovoNo(chave);
  
  if (chave > raiz->chave)
    raiz->dir = avlInsert(raiz->dir, chave);
  else
    raiz->esq = avlInsert(raiz->esq, chave);

  raiz->altura = avlCalculaAltura(raiz);
  int fb = avlCalculaFb(raiz);
  // Temos um nó desbalanceado... vamos arrumar!
  if (fb == +2) { // não precisaria do +2, mas só pra ficar didático
    if (avlCalculaFb(raiz->esq) < 0) {
      raiz->esq = avlRotL(raiz->esq); // Essa rotação só executa SE o nó debaixo está desbalanceado pro outro lado...
    }
    raiz = avlRotR(raiz); // Perceba que essa rotação SEMPRE vai executar.
  }
  else if (fb == -2) {
    if (avlCalculaFb(raiz->dir) > 0) {
      raiz->dir = avlRotR(raiz->dir);
    }
    raiz = avlRotL(raiz);
  }
  
  return raiz;
}

void avlFree(AVL * raiz) {
  if (raiz == NULL) return;

  if (raiz->esq != NULL)
    avlFree(raiz->esq);
  if (raiz->dir != NULL)
    avlFree(raiz->dir);
  
  free(raiz);
}

// _____________________________________________________________________________________________

/**
 * @brief Gera N números aleatórios que serão as chaves das árvores
 * 
 * @param N número de nós, inputado do usuário
 * @return int* array de números gerados
 */
int* geraNumerosAleatorios(int N) {
    int* numerosAleatorios = malloc(sizeof(int) * N); // array de numeros aleatorios inteiros, de tamanho N

    // TODO: gerar N números aleatórios e inserir no array numerosAleatorios
    // Perguntas que você deve fazer:
    //  -> Qual é o intervalo que esses números terão? Se temos N nós, podemos
    //     pensar nesse sentido. Se N = 1milhão, qual intervalo satisfaria nosso
    //     problema?
    //  -> Como garantimos que os números aleatórios são distintos? Aqui podemos
    //     pensar em meios de garantir isso de maneira eficiente. Imagine que
    //     nosso N é um valor bem grande, como 2 milhões. Como garantir que tenhamos
    //     2 milhões de nós com números distintos e aleatórios?

    
    return numerosAleatorios;
}

void print(char * msg) {
    printf("%s", msg);
    printf("\n");
}

int main() {
    srand(time(NULL)); // colocando a semente no ínicio do programa pra algo o mais aleatório possível

    int A, N;
    print("EP2 - Nas alturas - Template");
    print("--------------------------------");
    printf("Digite o número de amostras: ");
    scanf("%d", &A);
    printf("Digite o número de nós: ");
    scanf("%d", &N);

    for (int i = 0; i < A; i++) {
        int * numerosAleatorios = geraNumerosAleatorios(N); // para cada amostra, vamos gerar N numeros aleatorios, que serão as chaves dos nós a inserir
        BST * rBst;
        AVL * rAvl;
        for (int k = 0; k < N; k++) { // nós a serem inseridos na árvore (no máx N)
            rBst = bstInsert(rBst, numerosAleatorios[k]);
            rAvl = avlInsert(rAvl, numerosAleatorios[k]);
        }
        int alturaBst = bstCalculaAltura(rBst);
        int alturaAvl = avlCalculaAltura(rAvl);

        avlFree(rAvl);
        bstFree(rBst);
        free(numerosAleatorios);

        // TODO: pensar em um jeito de guardar essas alturas para depois poder calcular a média geral
    }

  // TODO: Imprimir o que foi pedido no EP2
}
