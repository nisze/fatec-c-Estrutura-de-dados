#include <stdio.h>
int main() {
	double matriz[12][12];
	double soma=0, media=0;
	int cont=0;
	char c;
	scanf(" %c", &c);
	for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &matriz[i][j]);
		}
	}
	for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
			if(i<j && i<12-j-1){
        		soma+=matriz[i][j];
        		cont++;
			}
		}
	}
	if(c=='S'){
		printf("%.1f\n", soma);
	}
	else if(c=='M'){
		if(cont>0){
			media=soma/cont;
			printf("%.1f\n", media);
		}
	}
	return 0;
}
