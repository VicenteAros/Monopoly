#include "jueguito.h"

void mostrarTablero(int* tablero){
  for(int y=7; y>=0; y--){
		printf("--------------------------------------------------------------------------------------------------------\n");
		for(int x=0; x<8; x++){
			
			switch(*((tablero+y*8)+x)){
				case 0:
					printf("|    +50    |");
					break;
				case 1:
					printf("|    -25    |");
					break;
				case 2:
					printf("|    +75    |");
					break;
				case 3:
					printf("|    -50    |");
					break;
				case 4:
					printf("|   Jail    |");
					break;
				case 5:
					printf("|    -75    |");
					break;
				case 6:
					printf("|   Free    |");
					break;
				case 7:
					printf("|   back 2  |");
					break;
				case 8:
					printf("|   back 3  |");
					break;
				case 9:
					printf("|   back 4  |");
					break;
				case 10:
					printf("| forward 3 |");
					break;
				case 11:
					printf("| forward 5 |");
					break;
				case 12:
					printf("|   Start   |");
					break;
				default:
					printf("             ");
			}
			if(x == 7){
				printf("\n");
			}
		}
	}
	printf("--------------------------------------------------------------------------------------------------------\n");
}
