#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char elementos[30];
    int topo;
} Pilha;

int main() {
    int quantidade;
    while (scanf("%d", &quantidade) && quantidade) {
        char *chegada = (char *)malloc(sizeof(char) * quantidade);
        char *saida = (char *)malloc(sizeof(char) * quantidade);
        Pilha *pilhaTemp = (Pilha *)malloc(sizeof(Pilha));
        
        pilhaTemp->topo = -1;

        for (int i = 0; i < quantidade; ++i)
            scanf(" %c", &chegada[i]);
        for (int i = 0; i < quantidade; ++i)
            scanf(" %c", &saida[i]);

        int indiceChegada = 0;

        for (int i = 0; i < quantidade; ++i) {
            if (pilhaTemp->topo >= 0 && pilhaTemp->elementos[pilhaTemp->topo] == saida[i]) {
                pilhaTemp->topo--;
                printf("R");
            } else {
                while (indiceChegada < quantidade && saida[i] != chegada[indiceChegada]) {
                    pilhaTemp->elementos[++(pilhaTemp->topo)] = chegada[indiceChegada++];
                    printf("I");
                }
                if (indiceChegada < quantidade && chegada[indiceChegada] == saida[i]) {
                    printf("IR");
                    indiceChegada++;
                } else {
                    break;
                }
            }
        }
        if (pilhaTemp->topo >= 0)
            printf(" Impossible");
        printf("\n");

        free(chegada);
        free(saida);
        free(pilhaTemp);
    }
    return 0;
}
