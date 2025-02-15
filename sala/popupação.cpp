#include <stdio.h>

int main() {
	int T=0, id=0;
	int PA=0, PB=0;
	double G1=0.0, G2=0.0;
	scanf("%d", &T);
	while(T>=3000||T<0){
		scanf("%d", &T);
	}
	for(int i=0; i<T; i++){
		id=0;
		scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);
		while(PA<100 || PA>=1000000){
			scanf("%d", &PA);
		}
		while(PA>PB || PB>1000000){
			scanf("%d", &PB);
		}
		while(G1<G2){
		scanf("%lf %lf", &G1, &G2);
		}
		while(G1<0.1 || G1>10.0){
			scanf("%lf", &G1);
		}
		while(G2<0.0 || G2>10.0){
			scanf("%lf", &G2);
		}
		while(PA<=PB && id<=100){
			PA+=(PA*G1/100);
			PB+=(PB*G2/100);
			id++;
		}
		if (id > 100){
            printf("Mais de 1 seculo.\n");
            continue;
    	}else{
            printf("%d anos.\n", id);
    	}
   	}
   	return 0;
}

