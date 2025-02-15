#include <stdio.h>
typedef struct{
	char nome[50];
	char universidade[50];
	char email[100];
} SAP;
typedef struct{
	int inscritos=0;
	int presente=0;
	int cont=0;
}Cracha;
int main(){
	SAP registro;
	Cracha evento;
	scanf("%d", &evento.inscritos);
	for (int i=0; i<evento.inscritos; i++){
		scanf("%d", &evento.presente);
		if(evento.presente==1){
			evento.cont++;
		}
	}
	printf("%d\n", evento.cont );
	return 0;
}
