#include <stdio.h>

int main() {
    int total_cartas;

    while (1) {
        scanf("%d", &total_cartas);

        if (total_cartas == 0) {
            break;
        }

        int cartas[total_cartas];
        int descartadas[total_cartas];
        int topo_cartas = total_cartas - 1;
        int fim_descartadas = -1;

        for (int i = 0; i < total_cartas; i++) {
            cartas[i] = total_cartas - i;
        }

        while (topo_cartas >= 1) {
            descartadas[++fim_descartadas] = cartas[topo_cartas--];

            int carta_topo = cartas[topo_cartas--];
            for (int i = topo_cartas + 1; i > 0; i--) {
                cartas[i] = cartas[i - 1];
            }
            cartas[0] = carta_topo;
            topo_cartas++;
        }

        printf("Discarded cards: ");
        for (int i = 0; i <= fim_descartadas; i++) {
            if (i > 0) {
                printf(", ");
            }
            printf("%d", descartadas[i]);
        }

        printf("\nRemaining card: %d\n", cartas[topo_cartas]);
    }

    return 0;
}
