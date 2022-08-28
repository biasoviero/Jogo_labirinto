#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#include "raylib.h"

#define LARGURA 640
#define TAM_FONTE 20
#define MAPA_L 30
#define MAPA_C 120

struct Mapa{
    char mapa[MAPA_L][MAPA_C];
    int linhas;
    int colunas;
    int escada;
    char porta;
    int caixa;
};

//Fun��o que l� o arquivo texto da fase e carrega o mapa
void carregaMapa(struct Mapa *fase);

//Fun��o que, dado um mapa, desenha cada caractere com a sua imagem correspondente
void desenhaMapa(struct Mapa fase);

//Fun��o que, dadas a pontua��o, a fase e a quantidade de vidas, desenha uma barra informando essas informa��es
void desenhaBarra(int pontos, int nivel, int vida);


#endif // MAPA_H_INCLUDED
