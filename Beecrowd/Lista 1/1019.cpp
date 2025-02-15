#include <stdio.h>

int main() {
    int totalSegundos, horas, minutos, segundos;
    scanf("%d", &totalSegundos);

    horas = totalSegundos / 3600;
    minutos = (totalSegundos % 3600) / 60;
    segundos = totalSegundos % 60;
    
    printf("%d:%d:%d\n", horas, minutos, segundos);

    return 0;
}
