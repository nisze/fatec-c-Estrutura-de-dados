#include <stdio.h>

int fatorial(int n) {
    if (n == 0)  // Caso base
    printf("n", n);
        return 1;
    else
        return n * fatorial(n - 1);  // Chamada recursiva
        printf("n", n);
}

int main() {
    int num = 5;
    printf("Fatorial de %d é %d\n", num, fatorial(num));
    return 0;
}