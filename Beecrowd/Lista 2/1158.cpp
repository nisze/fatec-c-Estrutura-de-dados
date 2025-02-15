#include <stdio.h>

int main() {
	int N, X, Y, cont=0, soma=0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		soma=0;
		cont=0;
		scanf("%d %d", &X, &Y);
		while(cont<Y){
			if(X%2==0){
			X++;
			}else{
				soma+=X;
				cont++;
				X++;
			}
		}
	printf("%d\n", soma);	
	}
	return 0;
}
