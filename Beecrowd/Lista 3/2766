#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char nome[30];
	int indice_1;
	int indice_2;
	int indice_3;
}Lista;
int main() {
	
	Lista *ponteiro;
	ponteiro = (Lista*) malloc(10 * sizeof(Lista));

	for (int i=0; i<10; i++){
		scanf("%s", ponteiro[i].nome);
		if(i==2){
			ponteiro[i].indice_1=i;
		}
		if(i==6){
			ponteiro[i].indice_2=i;
		}
		if(i==8){
			ponteiro[i].indice_3=i;
		}
	}
	printf("%s\n",ponteiro[2].nome);
	printf("%s\n",ponteiro[6].nome);
	printf("%s\n",ponteiro[8].nome);
	
    return 0;
}
