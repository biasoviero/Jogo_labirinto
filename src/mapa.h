#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#include "raylib.h"

#define LARGURA 640
#define TAM_FONTE 20
#define MAPA_L 10
#define MAPA_C 10
#define LARGURA_ICONE LARGURA/MAPA_L


//Função que, dado um mapa, desenha cada caractere com a sua imagem correspondente
void desenhaMapa(char mapa[MAPA_L][MAPA_C]);

//Função que, dadas a pontuação, a fase e a quantidade de vidas, desenha uma barra informando essas informações
void desenhaBarra(int pontos, int nivel, int vida);

void carregaMapa(char mapa[MAPA_L][MAPA_C]);

#endif // MAPA_H_INCLUDED
