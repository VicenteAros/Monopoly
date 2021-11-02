#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  int dinero;
  int posicion[2]; // [0] = x, [1] = y
  int ID;
  int estado; // 0 -> puede jugar, 1 -> no puede jugar
}jugador;

void mostrarTablero(int *tablero);
void aplicarCasilla(int *tablero, jugador *player);
void moverJugador(int *tablero, jugador *player, int espacios);
int rollD6(int randomNumber);
