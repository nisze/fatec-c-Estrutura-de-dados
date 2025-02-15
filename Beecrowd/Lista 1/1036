#include <stdio.h>
#include <math.h>
 
int main() {
 	
 	double A, B, C, R1, R2, x;
 		scanf("%lf", &A);
 		scanf("%lf", &B);
 		scanf("%lf", &C);
 		if(A==0){
 			printf("Impossivel calcular\n");
 			return 0;
		}
		x=(B*B)-(4*A*C);
		if(x<=0){
			printf("Impossivel calcular\n");
			return 0;
		}
		
		R1=(-B + sqrt(x))/(2*A);
		R2=(-B - sqrt(x))/(2*A);
		printf("R1 = %.5lf\n", R1);
    	printf("R2 = %.5lf\n", R2);
 
    return 0;
}
