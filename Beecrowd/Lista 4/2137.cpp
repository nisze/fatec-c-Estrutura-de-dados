#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenarPorSelecao(char (*matriz)[5], int tamanho);

int main() {
    int quantidade, contador;

    while (scanf("%d", &quantidade) != EOF) {        
        char matrizStrings[quantidade][5];
        for (contador = 0; contador < quantidade; contador++) {
            scanf("%s", matrizStrings[contador]);            
        }
        
        ordenarPorSelecao(matrizStrings, quantidade);

        for (contador = 0; contador < quantidade; contador++) {
            printf("%s\n", matrizStrings[contador]);
        }
    }

    return 0;
}

void ordenarPorSelecao(char (*matriz)[5], int tamanho) {
    int atual, comparador, posicaoMinima;
    char temporario[5];

    for (atual = 0; atual < tamanho; atual++) {
        posicaoMinima = atual;
        for (comparador = atual + 1; comparador < tamanho; comparador++) {
            if (strcmp(matriz[comparador], matriz[posicaoMinima]) < 0) {
                posicaoMinima = comparador;
            }
        }
        
        strcpy(temporario, matriz[atual]);
        strcpy(matriz[atual], matriz[posicaoMinima]);
        strcpy(matriz[posicaoMinima], temporario);
    }
}
