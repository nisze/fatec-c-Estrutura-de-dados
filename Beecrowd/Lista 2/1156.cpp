#include <stdio.h>

int main() {
    double S = 0.0, n=1.0;
	int i = 1;

    while (i <= 39) {
        S+=i/n;
        i=i+2;
        n=n*2.0;
    }
	printf("%.2f\n", S);
    return 0;
}
