#ifndef MOVIMENTOS_H_INCLUDED
#define MOVIMENTOS_H_INCLUDED
#include "mapa.h"
#include <stdio.h>

void movimento_vertical(t_mapa *fase, int direcao);
void movimento_horizontal(t_mapa *fase, int direcao);
void localiza_jogador(t_mapa fase, int *x_jog, int *y_jog);
void busca_porta(t_mapa fase, int *x_porta, int *y_porta);

#endif // MOVIMENTOS_H_INCLUDED
