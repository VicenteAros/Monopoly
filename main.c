#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){

	//se simula un tablero de 8x8 como un array bidimensional, solo se mueve en las dimensiones cuando se encuentra en el inicio o final de la otra dimensiones, ej: tablero[x][y] solo se movera en x si y=0 o y=7
	int tablero[8][8];
	//las casillas del tablero son predeterminadas, se les asignara un char que representara su efecto con un switch
	tablero[0][1] = tablero[0][2] = tablero[0][5] = tablero[7][5] = tablero[7][3] = 0; //+50
	tablero[0][3] = tablero[0][6] = tablero[1][7] = tablero[2][0] = 1; //-25
	tablero[7][1] = tablero[7][4] = tablero[7][5] = tablero[6][0] = tablero[4][0] = 2; //+75
	tablero[7][2] = tablero[7][3] = tablero[2][7] = 3; //-50
	tablero[0][7] = tablero[7][0] = 4; //jail
	tablero[1][0] = 5; //+75
	tablero[7][7] = 6; //free space
	tablero[0][4] = 7; //back 2
	tablero[6][7] = 8; //back 3
	tablero[7][4] = tablero[3][0] = 9; //back 4
	tablero[7][6] = 10; //forward 3
	tablero[5][0] = 11; //forward 5
	tablero[0][0] = 12; //START
	
	for(int x=0; x<8; x++){
		for(int y=0; y<8; y++){
			
			switch(tablero[x][y]){
				case 0:
					printf("|    +50    ");
					break;
				case 1:
					printf("|    -25    ");
					break;
				case 2:
					printf("|    +75    ");
					break;
				case 3:
					printf("|    -50    ");
					break;
				case 4:
					printf("|    Jail   ");
					break;
				case 5:
					printf("|    +75    ");
					break;
				case 6:
					printf("|    Free   ");
					break;
				case 7:
					printf("|   back 2  ");
					break;
				case 8:
					printf("|   back 3  ");
					break;
				case 9:
					printf("|   back 4  ");
					break;
				case 10:
					printf("| forward 3 ");
					break;
				case 11:
					printf("| forward 5 ");
					break;
				case 12:
					printf("|   Start   ");
					break;
				default:
					printf("            ");
			}
			if(x == 7){
				printf("|\n");
			}
		}
	}
	
	return(0);
}
