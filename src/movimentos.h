#ifndef MOVIMENTOS_H_INCLUDED
#define MOVIMENTOS_H_INCLUDED
#include "mapa.h"
#include "jogador.h"
#include <stdio.h>

//Função que move o jogador para a direita e para a esquerda
void movimento_vertical(t_mapa *fase, int direcao);

//Função que move o jogador para cima e para baixo
void movimento_horizontal(t_mapa *fase, int direcao);

//Função que localiza a linha e a coluna em que o jogador está
void localiza_jogador(t_mapa fase, int *x_jog, int *y_jog);

//Função que localiza a linha e a coluna do outro par de uma porta
void busca_porta(t_mapa fase, int *x_porta, int *y_porta);

//Função que abre a caixa e recebe seu conteúdo
void abreCaixa(t_mapa fase, struct Jogador *jogador, int *mensagem);

#endif // MOVIMENTOS_H_INCLUDED
