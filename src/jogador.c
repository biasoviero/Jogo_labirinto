#include "jogador.h"

struct Jogador jog_inicializa(int x, int y){
    struct Jogador jogador;
    jogador.vidas = 3;
    jogador.pontuacao = 0;
    jogador.linha = x;
    jogador.coluna = y;
    jogador.chave = 0;
    return jogador;
}

int jog_diminui_vida(struct Jogador *jogador){
    if (jogador->vidas >= 1){
        jogador->vidas--;
        return 1;
    }
    else{
        return 0;
    }
}

void jog_aumenta_pontuacao(struct Jogador *jogador, int pontos){
    jogador->pontuacao += pontos;
    return;
}
