#include <stdio.h>

int main(){
	int vetor[1000]={0};
	int t, x;
	scanf("%d", &t);
	while(t<=2 || t>=50){
		scanf("%d", &t);
	}
	x=0;
	for(int i=0; i<1000; i++){
		vetor[i]=x;
		x++;
		if(x==t){
			x=0;
		}
	}
	for(int i=0; i<1000; i++){
		printf("N[%d] = %d\n", i, vetor[i]);
	}
	return 0;
}
