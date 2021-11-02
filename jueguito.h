#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  int dinero = 100;
  int posicion[2] = {0};
}jugador;

void mostrarTablero(int *tablero);
void aplicarCasilla(int *tablero, jugador player);
void moverJugador(jugador player, int espacios);
int rollD6(int randomNumber);
