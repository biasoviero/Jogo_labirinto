#ifndef MOVIMENTOS_H_INCLUDED
#define MOVIMENTOS_H_INCLUDED
#include "mapa.h"
#include "jogador.h"
#include <stdio.h>

//Fun��o que move o jogador para a direita e para a esquerda
void movimento_vertical(t_mapa *fase, int direcao);

//Fun��o que move o jogador para cima e para baixo
void movimento_horizontal(t_mapa *fase, int direcao);

//Fun��o que localiza a linha e a coluna em que o jogador est�
void localiza_jogador(t_mapa fase, int *x_jog, int *y_jog);

//Fun��o que localiza a linha e a coluna do outro par de uma porta
void busca_porta(t_mapa fase, int *x_porta, int *y_porta);

//Fun��o que abre a caixa e recebe seu conte�do
void abreCaixa(t_mapa fase, struct Jogador *jogador, int *mensagem);

#endif // MOVIMENTOS_H_INCLUDED
