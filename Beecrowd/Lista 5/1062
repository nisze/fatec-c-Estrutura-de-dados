#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pilha[1000];
    int topo;
} Pilha;

void empilhar(Pilha *p, int valor) {
    p->pilha[++p->topo] = valor;
}

void desempilhar(Pilha *p) {
    p->topo--;
}

int main() {
    int vagao, numVagoes, i, erro, entrando, sair;
    Pilha pilha;
    
    while (scanf("%d", &numVagoes) && numVagoes) {
        while (1) {
            pilha.topo = -1;
            entrando = 1;
            erro = 0;
            sair = 0;

            for (i = 0; i < numVagoes && !erro && !sair; i++) {
                scanf("%d", &vagao);
                if (vagao == 0) {
                    sair = 1;
                    break;
                }

                while (1) {
                    if (vagao == entrando) {
                        entrando++;
                        break;
                    } else if (vagao > entrando) {
                        empilhar(&pilha, entrando);
                        entrando++;
                    } else {
                        if (pilha.pilha[pilha.topo] == vagao) {
                            desempilhar(&pilha);
                        } else {
                            erro = 1;
                            for (; i < numVagoes - 1; i++) {
                                scanf("%d", &vagao);
                            }
                        }
                        break;
                    }
                }
            }

            if (sair) break;

            if (erro) {
                printf("No\n");
            } else {
                printf("Yes\n");
            }
        }
        printf("\n");
    }

    return 0;
}
