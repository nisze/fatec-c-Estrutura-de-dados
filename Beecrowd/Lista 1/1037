#include <stdio.h>

int main() {
    double valor;
    scanf("%lf", &valor);

    int intervalo = (valor >= 0 && valor <= 25) ? 0 :
                    (valor > 25 && valor <= 50) ? 1 :
                    (valor > 50 && valor <= 75) ? 2 :
                    (valor > 75 && valor <= 100) ? 3 : 4;
    char *mensagem;
    switch (intervalo) {
        case 0:
            mensagem = "Intervalo [0,25]";
            break;
        case 1:
            mensagem = "Intervalo (25,50]";
            break;
        case 2:
            mensagem = "Intervalo (50,75]";
            break;
        case 3:
            mensagem = "Intervalo (75,100]";
            break;
        default:
            mensagem = "Fora de intervalo";
            break;
    }
    printf("%s\n", mensagem);

    return 0;
}
