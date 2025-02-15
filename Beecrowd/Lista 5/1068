#include <stdio.h>
#include <string.h>

typedef struct Pilha {
    int topo;
    char valores[1001];  
} Pilha;

void empilhar(Pilha* p, char valor) {
    if (p->topo < 1000) { 
        p->topo++;
        p->valores[p->topo] = valor;
    }
}

void desempilhar(Pilha* p) {
    if (p->topo >= 0) {  
        p->topo--;
    }
}

int pilhaVazia(Pilha* p) {
    return p->topo == -1;  
}

char topo(Pilha* p) {
    if (!pilhaVazia(p)) {
        return p->valores[p->topo];  
    }
    return '\0';  
}

void inicializarPilha(Pilha* p) {
    p->topo = -1;  
}

int main() {
    char expressao[1001];
    Pilha pilha;

    while (scanf("%1000s", expressao) == 1) {  
        inicializarPilha(&pilha);
        int i, tam = strlen(expressao);
        int correta = 1;

        for (i = 0; i < tam; i++) {
            if (expressao[i] == '(') {
                empilhar(&pilha, '(');
            } else if (expressao[i] == ')') {
                if (pilhaVazia(&pilha)) {
                    correta = 0;
                    break;
                } else {
                    desempilhar(&pilha);
                }
            }
        }

        if (correta && pilhaVazia(&pilha)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
