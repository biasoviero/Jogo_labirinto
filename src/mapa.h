#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#include "raylib.h"
#include "jogador.h"
#include <time.h>
#include <stdlib.h>

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

//Fun��o que l� o arquivo texto da fase e carrega o mapa
void carregaMapa(t_mapa *fase);

//Fun��o que, dado um mapa, desenha cada caractere com a sua imagem correspondente
void desenhaMapa(t_mapa fase, struct Jogador jogador);

//Fun��o que, dadas a pontua��o, a fase e a quantidade de vidas, desenha uma barra informando essas informa��es
void desenhaBarra(struct Jogador jogador, int nivel, int mensagem);

//Fun��o que sorteia os bens que cada ba� conter�
void sorteiaCaixa (t_mapa *fase);

#endif // MAPA_H_INCLUDED
