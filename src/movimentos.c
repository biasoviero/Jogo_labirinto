#include "movimentos.h"

void movimento_vertical(struct Mapa *fase, int direcao) {
    int x_jog, y_jog, x_porta, y_porta;

    localiza_jogador(&fase, &x_jog, &y_jog);
    busca_porta(&fase, &x_porta, &y_porta);


    if (fase->porta != ' ' && direcao == -1) {
        printf("Para se teletransportar para o par dessa porta, informe (c)\n");
        if (fase->porta == '1') {
            fase->mapa[x_porta][y_porta] = 'D';
            fase->mapa[x_jog][y_jog] = '1';

        } else if (fase->porta == '2') {
            fase->mapa[x_porta][y_porta] = 'D';
            fase->mapa[x_jog][y_jog] = '2';
        }

    if (fase->caixa == 1 && direcao == 1) {
        printf("A caixa foi aberta!\n");
    }


    } else if (fase->escada == 1 || fase->mapa[x_jog + 1][y_jog] == 'H') {
        if (direcao == -1) {
            if (fase->mapa[x_jog + direcao][y_jog] != 'H' && fase->escada == 1) {
                fase->mapa[x_jog + direcao][y_jog] = 'D';
                fase->mapa[x_jog][y_jog] = 'H';
                fase->escada = 0;
            } else if (fase->escada == 1) {
                fase->mapa[x_jog + direcao][y_jog] = 'D';
                fase->mapa[x_jog][y_jog] = 'H';
            }

        } else if (direcao == 1) {
            if (fase->mapa[x_jog + direcao][y_jog] != 'X') {
                fase->mapa[x_jog][y_jog] = 'H';
                fase->mapa[x_jog + direcao][y_jog] = 'D';
            }
        }

    }
}

void movimento_horizontal(struct Mapa *fase, int direcao) {
    int x_jog, y_jog, x_porta, y_porta, i = 0;

    localiza_jogador(&fase, &x_jog, &y_jog);

    if (fase->mapa[x_jog][y_jog + direcao] != 'X' && (fase->mapa[x_jog + 1][y_jog + direcao] == 'X' || fase->mapa[x_jog + 1][y_jog + direcao] == 'H')) {
        if (fase->escada == 1) {
            fase->mapa[x_jog][y_jog + direcao] = 'D';
            fase->mapa[x_jog][y_jog] = 'H';
            fase->escada = 0;
        } else if (fase->mapa[x_jog][y_jog + direcao] == 'H') {
            fase->mapa[x_jog][y_jog + direcao] = 'D';
            fase->mapa[x_jog][y_jog] = ' ';
            fase->escada = 1;
        } else if (fase->mapa[x_jog][y_jog + direcao] == '1') {
            fase->mapa[x_jog][y_jog + direcao] = 'D';
            fase->mapa[x_jog][y_jog] = ' ';
            fase->porta = '1';
        } else if (fase->mapa[x_jog][y_jog + direcao] == '2') {
            fase->mapa[x_jog][y_jog + direcao] = 'D';
            fase->mapa[x_jog][y_jog] = ' ';
            fase->porta = '2';
        } else if (fase->porta == '1'){
            fase->mapa[x_jog][y_jog + direcao] = 'D';
            fase->mapa[x_jog][y_jog] = '1';
            fase->porta = ' ';
        } else if (fase->porta == '2'){
            fase->mapa[x_jog][y_jog + direcao] = 'D';
            fase->mapa[x_jog][y_jog] = '2';
            fase->porta = ' ';
        } else if (fase->mapa[x_jog][y_jog + direcao] == 'C') {
            fase->mapa[x_jog][y_jog + direcao] = 'D';
            fase->mapa[x_jog][y_jog] = ' ';
            fase->caixa = 1;
        } else if (fase->caixa == 1) {
            fase->mapa[x_jog][y_jog + direcao] = 'D';
            fase->mapa[x_jog][y_jog] = 'C';
            fase->caixa = 0;
        } else {
            fase->mapa[x_jog][y_jog + direcao] = 'D';
            fase->mapa[x_jog][y_jog ] = ' ';
        }
    } else if (fase->mapa[x_jog + 1][y_jog + direcao] == ' ' && fase->escada == 0) {
        while (fase->mapa[x_jog + i][y_jog + direcao] == ' ') {
            i++;
        }
        if (fase->mapa[x_jog + i][y_jog + direcao] == 'C'){
            fase->mapa[x_jog + i][y_jog + direcao] = 'D';
            fase->mapa[x_jog][y_jog] = ' ';
            fase->caixa = 1;
        } else if (fase->mapa[x_jog + i][y_jog + direcao] == '1') {
            fase->mapa[x_jog + i][y_jog + direcao] = 'D';
            fase->mapa[x_jog][y_jog] = ' ';
            fase->porta = '1';
        } else if (fase->mapa[x_jog + i][y_jog + direcao] == '2') {
            fase->mapa[x_jog + i][y_jog + direcao] = 'D';
            fase->mapa[x_jog][y_jog] = ' ';
            fase->porta = '2';
        } else {
            i--;
            fase->mapa[x_jog + i][y_jog + direcao] = 'D';
            fase->mapa[x_jog][y_jog] = ' ';
        }
    }
}

void localiza_jogador(struct Mapa *fase, int *x_jog, int *y_jog) {
    int l, c;
    for (l = 0; l < fase->linhas; l++) {
        for (c = 0; c < fase->colunas; c++) {
            if (fase->mapa[l][c] == 'D') {
                *x_jog = l;
                *y_jog = c;
            }
        }
    }
}

void busca_porta(struct Mapa *fase, int *x_porta, int *y_porta){
    int l, c;
    for (l = 0; l < fase->linhas; l++){
        for (c = 0; c < fase->colunas; c++){
            if (fase->mapa[l][c] == fase->porta){
                *x_porta = l;
                *y_porta = c;
            }
        }
    }
}
