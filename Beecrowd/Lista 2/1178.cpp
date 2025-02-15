#include <stdio.h>

int main(){
	double vetor[100]={0};
	double t, x;
	scanf("%lf", &t);
	for(int i=0; i<100; i++){
		vetor[i]=t;
		x=t/2;
		t=x;
	}
	for(int i=0; i<100; i++){
		printf("N[%d] = %.4lf\n", i, vetor[i]);
	}
	return 0;
}
