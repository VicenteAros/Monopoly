#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  int dinero = 100;
  int posicion[2] = {0};
}jugador;

void mostrarTablero(int *tablero);
int rollD6(int randomNumber);
void moverJugador(jugador player, int espacios);
void aplicarCasilla(int *tablero, jugador player);
