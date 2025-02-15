#include <stdio.h>
#include <math.h>

typedef struct {
    int casas; 
    double resultado;    
} CasoTeste;

int main() {
    int casos_teste, i;
    CasoTeste *casos; 

    scanf("%d", &casos_teste);

    casos = (CasoTeste *)malloc(casos_teste * sizeof(CasoTeste));
    
    for (i = 0; i < casos_teste; i++) {
        scanf("%d", &casos[i].casas);  

        casos[i].resultado = pow(2, casos[i].casas);
    }

    for (i = 0; i < casos_teste; i++) {
        printf("%.lf kg\n", floor(casos[i].resultado / 12000));
    }

    free(casos);

    return 0;
}
