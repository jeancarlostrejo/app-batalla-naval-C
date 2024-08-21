void vaciar_mapa(int mapa[FIL][COL])
{
	int i, j;
	
	for ( i = 0; i < FIL; i++) {
		for (j = 0; j < COL; j++) {		
			mapa[i][j] = 0; // el mar sera representado por un 0	
		}
	}
}
		
void imprimir_mapa(int mapa[FIL][COL])
{	
	int i, j;
	
	for (i = 0; i < FIL; i++) {
		printf("\n");
		
		for (j = 0; j < COL; j++) {
			//imprimimos mar
			if (mapa[i][j] == 0) {
				printf("*");
			}
			
			 //imprimimos barcos	
			if (mapa[i][j] == 5) {
				printf("*");
			}
			
			//imprimimos disparos que le dieron al barco
			if (mapa[i][j] == 2) {
				printf("0");
			}
			
			//imprimimos disparo fallido
			if (mapa[i][j] == 3) {
				printf("X");	
			}			
		}
	}	
}


void cargar_barcos(int mapa[FIL][COL])
{
	int x, y;
		
	x = rand()%FIL;
	y = rand()%COL;	
		
	 //barco de 1 posicion
	mapa[x][y] = 5;
	
	do {
		x = rand()%(FIL-1);
		y = rand()%(COL);
	} while( mapa[x][y] == 5 || mapa[x+1][y] == 5);
	
	//barco de 2 posiciones	
	mapa[x][y] = 5;
	mapa[x+1][y] = 5;
	
	do {
		x = rand()%(FIL);
		y = rand()%(COL-2);
	} while (mapa[x][y] == 5 || mapa[x][y+1] == 5 || mapa[x][y+2] == 5) ;
	
	//barco de 3 posiciones
	mapa[x][y] = 5;
	mapa[x][y+1] = 5 ;
	mapa[x][y+2] = 5;	
}

void disparos(int mapa[FIL][COL], int tiros)
{
	int x, y, band=0, gano=0;		
		
	do {

	  printf("\n\n---INSTRUCCIONES---", tiros);
		printf("\nLos tiros Fallidos se representan con una X", tiros); 
		printf("\nLos tiros Acertados se representan con una 0", tiros);
		printf("\nHay tres barcos, uno de una posicion, otro de dos posiciones y el ultimo de tres posiciones", tiros);
		printf("\n\nTIROS RESTANTES: %d\n\n", tiros);

		//pido las coordenadas (x,y) del disparo
		printf("\n\t\tIngrese las coordenadas del tiro(x): "); 
		fflush(stdin);
		scanf("%d", &y);
	
		printf("\n\t\tIngrese las coordenadas del tiro(y): ");
		fflush(stdin);
		scanf("%d", &x);
			
		//condicion para ver si le dispare a un barco
		if (mapa[x][y] == 5) {
			mapa[x][y] = 2; // el 2 significa disparo
		}
	
	 	// condicion para ver si no le di a ningun barco
		if (mapa[x][y] == 0)	{
		    mapa[x][y] = 3; //disparo fallido
		}

		system("CLS");
		
		if (barcos_hundidos(mapa) == 0) {
			gano = 1; 
			break;
		}
		
		tiros--;
		imprimir_mapa(mapa);
	} while (tiros != 0);
	
	if (gano == 1) {
		printf("\n\n\t\tFELICITACIONES, HAS DESTRUIDO TODOS LOS BARCOS\t\t");
	}
	
	if(gano == 0){
		printf("\n\n\t\tHAS PERDIDO, NO HAS PODIDO DESTRUIR TODOS LOS BARCOS\t\t");
	}
}

int barcos_hundidos(int mapa[FIL][COL])
{		
	int i, j, bandera=0;
	
	for (i = 0; i < FIL; i++) {
		for(j = 0; j < COL; j++) {
			if(mapa[i][j] == 5) {
				bandera = 1 ;			//significa que no encontro ningun barco
			}
		}
	}
	
	return bandera;
}
		

