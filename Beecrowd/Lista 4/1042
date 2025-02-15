#include <stdio.h>
#include <stdlib.h>

int comparar(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int a, b, c;
    int numeros[3];

    scanf("%d %d %d", &a, &b, &c);
    numeros[0] = a;
    numeros[1] = b;
    numeros[2] = c;

    qsort(numeros, 3, sizeof(int), comparar);

    for (int i = 0; i < 3; i++) {
        printf("%d\n", numeros[i]);
    }

    printf("\n");
    printf("%d\n%d\n%d\n", a, b, c);

    return 0;
}
