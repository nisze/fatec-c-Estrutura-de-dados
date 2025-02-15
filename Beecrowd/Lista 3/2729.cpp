#include <stdio.h>
#include <string.h>

typedef struct{

	char item[21];

} Lista;

void ordenar(Lista *listaCompras, int tam)
{
	int i = 1, j;
	Lista item_atual;
	while (i < tam)
	{
		j = i - 1;
		item_atual = listaCompras[i];
		while (j >= 0 && strcmp(listaCompras[j].item, item_atual.item) > 0)
		{

			listaCompras[j + 1] = listaCompras[j];
			j--;
		}
		listaCompras[j + 1] = item_atual;
		i++;
	}
}

int main ()
{
	int n, i, j;
	Lista listaCompras[1010];
	char itens[20001], *cadaItem;
	scanf("%d", &n);

	while (n--)
	{
		scanf(" %[^\n]", itens);
		i = 0;
		cadaItem = strtok(itens, " ");
		strcpy(listaCompras[i++].item, cadaItem);
		do
		{
			cadaItem = strtok(NULL, " ");
			if (cadaItem == NULL)
				break;
			strcpy(listaCompras[i].item, cadaItem);
			i++;
		} while (cadaItem);
		ordenar(listaCompras, i);
		for (j = 0; j < i; j++)
		{
			if (strcmp(listaCompras[j].item, listaCompras[j - 1].item) != 0)
			{
				if (j != 0 && j != i)
					printf(" ");
				printf("%s", listaCompras[j].item);
			}
		}
		printf("\n");
	}
return 0;
}
