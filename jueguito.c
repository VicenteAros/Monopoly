#include "jueguito.h"

/****
* void mostrarTablero
* ****
* muestra por pantalla el tablero
* ****
* input:
* int* tablero: dirección base del tablero
* ****
* return:
*
****/
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

void aplicarCasilla(int *tablero, jugador player){
	int x,y;
	x = player.posicion[0];
	y = player.posicion[1];
	switch(*((tablero+y*8)+x)){
		case 0:
			player.dinero += 50;
			printf("ganas 50$\n");
			break;
		case 1:
			player.dinero -= 25;
			printf("pierdes 25$\n");
			break;
		case 2:
			player.dinero += 75;
			printf("ganas 75$\n");
			break;
		case 3:
			player.dinero -= 50;
			printf("pierdes 50$\n");
			break;
		case 4:
			printf("caes en la cárcel, pierdes un turno\n");
			break;
		case 5:
			player.dinero -= 75;
			printf("pierdes 75$\n");
			break;
		case 6:
			printf("caes en un espacio libre, no pasa nada\n");
			break;
		case 7:
			moverJugador(player, -2)
			printf("vuelve 2 espacios\n");
			break;
		case 8:
			moverJugador(player, -3)
			printf("vuelve 3 espacios\n");
			break;
		case 9:
			moverJugador(player, -4)
			printf("vuelve 4 espacios\n");
			break;
		case 10:
			moverJugador(player, 3)
			printf("avanza 3 espacios\n");
			break;
		case 11:
			moverJugador(player, 5)
			printf("avanza 5 espacios\n");
			break;
		case 12:
			printf("pasaste por el inicio, ganas 100$\n");
			break;
		default:
			printf("ocurrio un error al calcular posicion del jugador\n");
	}
}

void moverJugador(jugador player, int espacios){
	if(espacios >= 0){
		if(player.posicion[0]==0 && player.posicion[1]==0){
		}else if(player.posicion[0]==0 && player.posicion[1]==7){
		}else if(player.posicion[0]==7 && player.posicion[1]==7){
		}else if(player.posicion[0]==7 && player.posicion[1]==0){
		}
	}
	else{
		
	}
}

int rollD6(int randomNumber){
	int dado = randomNumber%5 + 1;
	return(dado);
}
