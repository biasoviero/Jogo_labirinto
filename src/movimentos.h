#ifndef MOVIMENTOS_H_INCLUDED
#define MOVIMENTOS_H_INCLUDED
#include "mapa.h"
#include <stdio.h>

void movimento_vertical(struct Mapa *fase, int direcao);
void movimento_horizontal(struct Mapa *fase, int direcao);
void localiza_jogador(struct Mapa *fase, int *x_jog, int *y_jog);
void busca_porta(struct Mapa *fase, int *x_porta, int *y_porta);

#endif // MOVIMENTOS_H_INCLUDED
