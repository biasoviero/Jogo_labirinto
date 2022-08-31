#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#include "raylib.h"

#define LARGURA 640
#define TAM_FONTE 20
#define MAPA_L 30
#define MAPA_C 120

typedef struct {
    char mapa[MAPA_L][MAPA_C];
    int linhas;
    int colunas;
    int escada;
    char porta;
    int caixa;
    int saida;
} t_mapa;

//Função que lê o arquivo texto da fase e carrega o mapa
void carregaMapa(t_mapa *fase);

//Função que, dado um mapa, desenha cada caractere com a sua imagem correspondente
void desenhaMapa(t_mapa fase);

//Função que, dadas a pontuação, a fase e a quantidade de vidas, desenha uma barra informando essas informações
void desenhaBarra(int pontos, int nivel, int vida);


#endif // MAPA_H_INCLUDED
