#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FIL 10
#define COL 10
#define TIROS 20
#include "funciones.h"

int main(int argc, char *argv[])
{
	int mapa[FIL][COL], tiros = TIROS;	
	char resp;
	
	srand(time(NULL));
	
	do {
		system("CLS");
		
		vaciar_mapa(mapa);
		cargar_barcos(mapa);
		imprimir_mapa(mapa);
		disparos(mapa,tiros);
		
		printf("\n\t\tDesea jugar otra partdia? s/n: ");
		fflush(stdin);
		scanf("%c", &resp);
	} while(resp == 's');
	
	printf("\n\t\tFIN DEL JUEGO");
	return 0;
}

