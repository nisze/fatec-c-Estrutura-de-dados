#include <stdio.h>

int main() {
	int X,cont=0, soma=0;
	while(true){
		scanf("%d", &X);
		if(X==0){
			break;
		}
		soma=0;
		cont=0;
		while(cont<5){
			if(X%2==0){
				soma+=X;
				cont++;
				X++;
			}else{
				X++;
			}
		}
		printf("%d\n", soma);
	}
}
