#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "jueguito.h"

int main(int argc, char* argv[]){

	//se simula un tablero de 8x8 como un array bidimensional, solo se mueve en las dimensiones cuando se encuentra en el inicio o final de la otra dimensiones, ej: tablero[x][y] solo se movera en x si y=0 o y=7
	int tablero[8][8] = { [ 0 ... 7 ][ 0 ... 7 ] = -1 };
	//las casillas del tablero son predeterminadas, se les asignara un char que representara su efecto con un switch
	tablero[0][1] = tablero[0][2] = tablero[0][5] = tablero[7][5] = tablero[7][3] = 0; //+50
	tablero[0][3] = tablero[0][6] = tablero[7][1] = tablero[2][0] = 1; //-25
	tablero[1][7] = tablero[4][7] = tablero[5][7] = tablero[6][0] = tablero[4][0] = 2; //+75
	tablero[2][7] = tablero[3][7] = tablero[7][2] = 3; //-50
	tablero[0][7] = tablero[7][0] = 4; //jail
	tablero[1][0] = 5; //-75
	tablero[7][7] = 6; //free space
	tablero[0][4] = 7; //back 2
	tablero[6][7] = 8; //back 3
	tablero[7][4] = tablero[3][0] = 9; //back 4
	tablero[7][6] = 10; //forward 3
	tablero[5][0] = 11; //forward 5
	tablero[0][0] = 12; //START
	
	mostrarTablero(tablero);
	
	pid_t pid;
	int fd12[2], fd21[2], fd23[2], fd32[2], fd31[2], fd13[2]; //pipes
	
	pid = fork();
	if(pid==0){
		 pid = fork();
	}

	jugador player = { 100, {0}, pid, 0};
	
	while(player.dinero <500){
		wait(NULL);
		if(player.ID == 0){
			int entrada;
			printf("Turno del Jugador %d\n", player.ID);
			printf("Dinero: %d", player.dinero);
			printf("Seleccione una acción\n");
			printf("\t1. Tirar dado\n");
			printf("\t2. Salir del juego\n");
			scanf("%d", &entrada);
			if(entrada == 1){
				int roll;
				roll = rollD6(srandom(getpid()));
				printf("Jugador %d rollea un $d\n", player.ID, roll);
				moverJugador(tablero, &player, roll);
				mostrarTablero(tablero);
			}

		}
	}
	
	return(0);
}
