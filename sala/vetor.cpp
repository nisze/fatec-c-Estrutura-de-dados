#include <stdio.h>
#include <locale.h>
int soma(int vet[]){
	int soma=0;
	for(int i=0; i<10; i++){
		soma+=vet[i];
	}
	return soma;
}
int main(){
	int vet[10];
	for(int i=0 ; i<10; i++){
		printf("\nDigite o %d elemento do vetor: ", i+1);
		scanf("%d", &vet[i]);
	}
	int jose=soma(vet);
	printf("\nsoma e %d", jose);
	printf("\nvetor criado\n");
	for(int i=0; i<10; i++){
		printf("%d ", vet[i]);
	}
	return 0;
}