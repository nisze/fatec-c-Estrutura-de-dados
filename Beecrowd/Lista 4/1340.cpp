#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned short ushort;

typedef struct NoFila {
    int valor;
    struct NoFila *proximo;
} NoFila;

typedef struct Fila {
    NoFila *inicio;
    NoFila *fim;
} Fila;

typedef struct NoPilha {
    int valor;
    struct NoPilha *proximo;
} NoPilha;

typedef struct Pilha {
    NoPilha *topo;
} Pilha;

typedef struct ElementoPrioridade {
    int valor;
    int prioridade;
} ElementoPrioridade;

typedef struct FilaPrioridade {
    int quantidade;
    ElementoPrioridade elementos[1000];
} FilaPrioridade;

void inicializaFila(Fila *fila);
void adicionaFila(Fila *fila, int valor);
int frenteFila(Fila *fila);
void removeFila(Fila *fila);

void inicializaPilha(Pilha *pilha);
void adicionaPilha(Pilha *pilha, int valor);
void removePilha(Pilha *pilha);
int topoPilha(Pilha *pilha);

FilaPrioridade* criaFilaPrioridade();
void adicionaFilaPrioridade(FilaPrioridade *filaP, int prioridade, int valor);
void removeFilaPrioridade(FilaPrioridade *filaP);
int topoFilaPrioridade(FilaPrioridade *filaP);
void ajustaRemocao(FilaPrioridade *filaP, int pai);
void ajustaInsercao(FilaPrioridade *filaP, int filho);

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int valor, comando, i;
        _Bool ehFila, ehPilha, ehPrioridade;
        FilaPrioridade *filaPrio = criaFilaPrioridade();
        Fila filaSimples;
        Pilha pilhaSimples;

        inicializaFila(&filaSimples);
        inicializaPilha(&pilhaSimples);

        ehFila = ehPilha = ehPrioridade = 1;
        for (i = 0; i < n; ++i) {
            scanf("%d %d", &comando, &valor);

            if (comando == 1) {
                adicionaFilaPrioridade(filaPrio, valor, valor);
                adicionaPilha(&pilhaSimples, valor);
                adicionaFila(&filaSimples, valor);
            } else {
                if (topoPilha(&pilhaSimples) != valor)
                    ehPilha = 0;
                else
                    removePilha(&pilhaSimples);

                if (frenteFila(&filaSimples) != valor)
                    ehFila = 0;
                else
                    removeFila(&filaSimples);

                if (topoFilaPrioridade(filaPrio) != valor)
                    ehPrioridade = 0;
                else
                    removeFilaPrioridade(filaPrio);
            }
        }

        if (!ehPilha && !ehFila && !ehPrioridade)
            printf("impossible\n");
        else if ((ehPilha && ehFila) || (ehPilha && ehPrioridade) || (ehFila && ehPrioridade))
            printf("not sure\n");
        else if (ehPilha)
            printf("stack\n");
        else if (ehFila)
            printf("queue\n");
        else if (ehPrioridade)
            printf("priority queue\n");
    }

    return 0;
}

void inicializaFila(Fila *fila) {
    fila->inicio = fila->fim = NULL;
}

void adicionaFila(Fila *fila, int valor) {
    NoFila *novoNo = (NoFila *) malloc(sizeof(NoFila));
    if (!novoNo) exit(1);

    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if (fila->fim)
        fila->fim->proximo = novoNo;
    else
        fila->inicio = novoNo;

    fila->fim = novoNo;
}

void removeFila(Fila *fila) {
    if (!fila->inicio) return;

    NoFila *remover = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if (!fila->inicio)
        fila->fim = NULL;

    free(remover);
}

int frenteFila(Fila *fila) {
    return fila->inicio ? fila->inicio->valor : -1;
}

void inicializaPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

void adicionaPilha(Pilha *pilha, int valor) {
    NoPilha *novoNo = (NoPilha *) malloc(sizeof(NoPilha));
    if (!novoNo) exit(1);

    novoNo->valor = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

void removePilha(Pilha *pilha) {
    if (!pilha->topo) return;

    NoPilha *remover = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(remover);
}

int topoPilha(Pilha *pilha) {
    return pilha->topo ? pilha->topo->valor : -1;
}

FilaPrioridade* criaFilaPrioridade() {
    FilaPrioridade *filaP = (FilaPrioridade *) malloc(sizeof(FilaPrioridade));
    if (filaP) filaP->quantidade = 0;
    return filaP;
}

void adicionaFilaPrioridade(FilaPrioridade *filaP, int prioridade, int valor) {
    if (!filaP || filaP->quantidade >= 1000) exit(1);

    filaP->elementos[filaP->quantidade].valor = valor;
    filaP->elementos[filaP->quantidade].prioridade = prioridade;
    ajustaInsercao(filaP, filaP->quantidade++);
}

void ajustaInsercao(FilaPrioridade *filaP, int filho) {
    int pai = (filho - 1) / 2;
    ElementoPrioridade temp;

    while (filho > 0 && filaP->elementos[pai].prioridade <= filaP->elementos[filho].prioridade) {
        temp = filaP->elementos[filho];
        filaP->elementos[filho] = filaP->elementos[pai];
        filaP->elementos[pai] = temp;

        filho = pai;
        pai = (pai - 1) / 2;
    }
}

int topoFilaPrioridade(FilaPrioridade *filaP) {
    return (filaP && filaP->quantidade > 0) ? filaP->elementos[0].valor : -1;
}

void removeFilaPrioridade(FilaPrioridade *filaP) {
    if (!filaP || filaP->quantidade == 0) exit(1);

    filaP->elementos[0] = filaP->elementos[--filaP->quantidade];
    ajustaRemocao(filaP, 0);
}

void ajustaRemocao(FilaPrioridade *filaP, int pai) {
    int filho = 2 * pai + 1;
    ElementoPrioridade temp;

    while (filho < filaP->quantidade) {
        if (filho + 1 < filaP->quantidade && filaP->elementos[filho].prioridade < filaP->elementos[filho + 1].prioridade)
            filho++;

        if (filaP->elementos[pai].prioridade >= filaP->elementos[filho].prioridade)
            break;

        temp = filaP->elementos[pai];
        filaP->elementos[pai] = filaP->elementos[filho];
        filaP->elementos[filho] = temp;

        pai = filho;
        filho = 2 * pai + 1;
    }
}
