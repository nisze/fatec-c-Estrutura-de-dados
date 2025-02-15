#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vagoes;   
    int tamanho;  
} Trem_struct;

int ordena(int *vet, int tamanho)
{
    int i, j, cont = 0, aux;

    while (tamanho--)
    {
        for (i = 0, j = 1; i < tamanho; i++, j++)
            if (vet[i] > vet[j])
            {   
                cont++;
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
    }
    return cont;
}
int main ()
{
    int n, i;

    scanf("%d", &n);

    while (n--)
    {
        Trem_struct trem;
        scanf("%d", &trem.tamanho);
        trem.vagoes = (int*)malloc(trem.tamanho * sizeof(int));

        for (i = 0; i < trem.tamanho; i++)
            scanf("%d", &trem.vagoes[i]);    
        printf("Optimal train swapping takes %d swaps.\n", ordena(trem.vagoes, trem.tamanho));
        free(trem.vagoes);
    }
    return 0;
}
