#include <stdio.h>
int main() {
	double matriz[12][12];
	double soma=0, media=0;
	int n;
	char c;
	
	scanf("%d", &n);
	while(n<0 || n>11){
		scanf("%d", &n);
	}
	scanf(" %c", &c);
	
	for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &matriz[i][j]);
		}
	}
	for (int j = 0; j < 12; j++) {
        soma+=matriz[n][j];
	}
	if(c=='S'){
		printf("%.1f\n", soma);
	}
	else if(c=='M'){
		media=soma/12;
		printf("%.1f\n", media);
	}
	return 0;
}
