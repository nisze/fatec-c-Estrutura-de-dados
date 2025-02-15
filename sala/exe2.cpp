#include <stdio.h>

int main(){
	float vetor[10]={0};
	for(int i=0; i<10; i++){
		scanf("%f", &vetor[i]);
	}
	
	for(int i=0; i<10; i++){
		if(vetor[i]<=0)
		printf("A[%d] = %.1f\n", i, vetor[i]);
	}
	return 0;
}