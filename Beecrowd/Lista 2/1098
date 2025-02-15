#include <stdio.h>

int main() {
	
    float I = 0.0;
    while (I <= 2.0+0.001) {
    	float J=1;
    	if((int) (I*10)%10==0 ){
    		printf("I=%.0f J=%.0f\n", I, J + I);
            printf("I=%.0f J=%.0f\n", I, J + 1 + I);
            printf("I=%.0f J=%.0f\n", I, J + 2 + I);
    	}else{
        	printf("I=%.1f J=%.1f\n", I, J+I);
        	printf("I=%.1f J=%.1f\n", I, J+1+I);
        	printf("I=%.1f J=%.1f\n", I, J+2+I);
    	}
    	I += 0.2;
    }

    return 0;
}
