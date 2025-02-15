#include <stdio.h>

int main() {
    int n, valor;
    scanf("%d", &n);
    printf("%d\n", n);
    
    valor = n/100;
    printf("%d nota(s) de R$ 100,00\n", valor);
    n%=100;
    
    valor=n/50;
	printf("%d nota(s) de R$ 50,00\n", valor);
	n%=50;
	
    valor=n/20;
	printf("%d nota(s) de R$ 20,00\n", valor);
	n%=20;
	
    valor=n/10;
	printf("%d nota(s) de R$ 10,00\n", valor);
	n%=10;
	
    valor=n/5;
	printf("%d nota(s) de R$ 5,00\n", valor);
	n%=5;
	
    valor=n/2;
	printf("%d nota(s) de R$ 2,00\n", valor);
	n%=2;
	
	valor=n;
	printf("%d nota(s) de R$ 1,00\n", valor);
    return 0;
}
