#include <stdio.h>

int main() {
    double nota1, nota2, mediaPonderada;
    scanf("%lf", &nota1);
    scanf("%lf", &nota2);
    double peso1 = 3.5, peso2 = 7.5;
    mediaPonderada = (nota1 * peso1 + nota2 * peso2) / (peso1 + peso2);
    printf("MEDIA = %.5lf\n", mediaPonderada);

    return 0;
}
