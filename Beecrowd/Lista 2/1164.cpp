#include <stdio.h>

int main() {
	int N, X, cont=0, soma=0;
	scanf("%d", &N);
	while(N>20||N<0){
		scanf("%d", &N);
	}
	for(int i=0; i<N; i++){
		soma=0;
		cont=0;
		scanf("%d", &X);
		while(X<1||X>100000000){
			scanf("%d", &X);
		}	
		for(int j=1;j<X;j++){
        	if(X%j == 0){
            	soma += j;
            }
        }
        if(soma==X){
        	printf("%d eh perfeito\n", X);
		}else{
			printf("%d nao eh perfeito\n", X);	
		}
	}
	return 0;
}
