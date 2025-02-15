#include <stdio.h>

int main() {
    int valorA, valorB, valorC, valorD;
    scanf("%d", &valorA);
    scanf("%d", &valorB);
    scanf("%d", &valorC);
    scanf("%d", &valorD);

    if (valorB > valorC && valorD > valorA && (valorC + valorD) > (valorA + valorB) && valorC > 0 &&
        valorD > 0 && valorA % 2 == 0) {
        printf("Valores aceitos\n");
    } else {
        printf("Valores nao aceitos\n");
    }

    return 0;
}
