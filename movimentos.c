#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAPA_L 30
#define MAPA_C 120

void carrega_mapa(char mapa[MAPA_L][MAPA_C], int *linhas, int *colunas, char *porta, int *escada, int *caixa);
void movimento_vertical(char mapa[MAPA_L][MAPA_C], int linhas, int colunas, char *porta, int *escada, int *caixa, int direcao);
void movimento_horizontal(char mapa[MAPA_L][MAPA_C], int linhas, int colunas, char *porta, int *escada, int *caixa, int direcao);
void localiza_jogador(char mapa[MAPA_L][MAPA_C], int linhas, int colunas, int *x_jog, int *y_jog) ;
void busca_porta(char mapa[MAPA_L][MAPA_C], int linhas, int colunas, char porta, int *x_porta, int *y_porta);
void imprime_mapa(char mapa[MAPA_L][MAPA_C], int linhas, int colunas);

int main() {
    char mapa[MAPA_L][MAPA_C], mov, porta;
    int linhas, colunas, escada, caixa, x_jog, y_jog, x_porta, y_porta;

    carrega_mapa(mapa, &linhas, &colunas, &porta, &escada, &caixa);

    do {
        imprime_mapa(mapa, linhas, colunas);
        printf("Informe\n(c) para ir para cima,\n(b) para ir para baixo,\n(e) para ir para esquerda ou\n(d) para ir para direita\n");
        scanf(" %c", &mov);

        if (mov == 'c')
            movimento_vertical(mapa, linhas, colunas, &porta, &escada, &caixa, -1);

        if (mov == 'b')
            movimento_vertical(mapa, linhas, colunas, &porta, &escada, &caixa, 1);

        if (mov == 'e')
            movimento_horizontal(mapa, linhas, colunas, &porta, &escada, &caixa, -1);

        if (mov == 'd')
            movimento_horizontal(mapa, linhas, colunas, &porta, &escada, &caixa, 1);

    } while (mov != 's');

    return 0;
}

/*
 * Função que carrega o mapa do jogo
 * @param mapa matriz de caracteres que representa o mapa do jogo
 * @param *linhas ponteiro para inteiro que guardará o número de linhas ocupadas pelo mapa do jogo (parâmetro de saída)
 * @param *colunas ponteiro para inteiro que guardará o número de colunas ocupadas pelo mapa do jogo (parâmetro de saída)
 * @param *porta ponteiro para char que guardará um espaço em branco (' ') caso o jogador não esteja sobre uma porta, ou o identificador da porta, caso o jogador esteja parado sobre uma porta ('1', '2', etc)
 * @param *escada ponteiro para inteiros que indica se o jogador está parado sobre uma escada. Contém o valor 1 caso esteja e 0 caso não esteja
 */
void carrega_mapa(char mapa[MAPA_L][MAPA_C], int *linhas, int *colunas, char *porta, int *escada, int *caixa) {
    strcpy(mapa[0], "XXXXXXXXXX");
    strcpy(mapa[1], "X1 C  C2 X");
    strcpy(mapa[2], "XXHX  XX X");
    strcpy(mapa[3], "XCH    1 X");
    strcpy(mapa[4], "XXX HXHX X");
    strcpy(mapa[5], "X   H H  X");
    strcpy(mapa[6], "X   H HC2X");
    strcpy(mapa[7], "X HXX XXXX");
    strcpy(mapa[8], "XDH X   PX");
    strcpy(mapa[9], "XXXXXXXXXX");
    *linhas = 10;
    *colunas = 10;
    *porta = ' ';
    *escada = 0;
    *caixa = 0;
}

/*
 * Função responsável por fazer a movimentação para cima e para baixo do jogador
 * @param mapa Mapa do jogo
 * @param linhas número de linhas do mapa
 * @param colunas número de colunas do mapa
 * @param *porta ponteiro que indica se o jogador está sobre uma porta ou não
 * @param *escada ponteiro que indica se o jogador está sobre uma escada ou não
 * @param *caixa ponteiro que indica se o jogador está sobre uma caixa ou não
 * @param direcao indica a direção do movimento em escadas. O valor -1 indica movimento para cima, enquanto o valor 1 indica movimento para baixo
 */
void movimento_vertical(char mapa[MAPA_L][MAPA_C], int linhas, int colunas, char *porta, int *escada, int *caixa, int direcao) {
    int x_jog, y_jog, x_porta, y_porta;

    localiza_jogador(mapa, linhas, colunas, &x_jog, &y_jog);
    busca_porta(mapa, linhas, colunas, *porta, &x_porta, &y_porta);


    if (*porta != ' ' && direcao == -1) {
        printf("Para se teletransportar para o par dessa porta, informe (c)\n");
        if (*porta == '1') {
            mapa[x_porta][y_porta] = 'D';
            mapa[x_jog][y_jog] = '1';

        } else if (*porta == '2') {
            mapa[x_porta][y_porta] = 'D';
            mapa[x_jog][y_jog] = '2';
        }

    if (*caixa == 1 && direcao == 1) {
        printf("A caixa foi aberta!\n");
    }


    } else if (*escada == 1 || mapa[x_jog + 1][y_jog] == 'H') {
        if (direcao == -1) {
            if (mapa[x_jog + direcao][y_jog] != 'H' && *escada == 1) {
                mapa[x_jog + direcao][y_jog] = 'D';
                mapa[x_jog][y_jog] = 'H';
                *escada = 0;
            } else if (*escada == 1) {
                mapa[x_jog + direcao][y_jog] = 'D';
                mapa[x_jog][y_jog] = 'H';
            }

        } else if (direcao == 1) {
            if (mapa[x_jog + direcao][y_jog] != 'X') {
                mapa[x_jog][y_jog] = 'H';
                mapa[x_jog + direcao][y_jog] = 'D';
            }
        }

    }
}

/*
 * Função responsável por fazer a movimentação para cima e para baixo do jogador
 * @param mapa Mapa do jogo
 * @param linhas número de linhas do mapa
 * @param colunas número de colunas do mapa
 * @param *porta ponteiro que indica se o jogador está sobre uma porta ou não
 * @param *escada ponteiro que indica se o jogador está sobre uma escada ou não
 * @param *caixa ponteiro que indica se o jogador está sobre uma caixa ou não
 * @param direcao indica a direção do movimento para os lados. O valor -1 indica movimento para esquerda, enquanto o valor 1 indica movimento para direita
 */
void movimento_horizontal(char mapa[MAPA_L][MAPA_C], int linhas, int colunas, char *porta, int *escada, int *caixa, int direcao) {
    int x_jog, y_jog, x_porta, y_porta, i = 0;

    localiza_jogador(mapa, linhas, colunas, &x_jog, &y_jog);

    if (mapa[x_jog][y_jog + direcao] != 'X' && (mapa[x_jog + 1][y_jog + direcao] == 'X' || mapa[x_jog + 1][y_jog + direcao] == 'H')) {
        if (*escada == 1) {
            mapa[x_jog][y_jog + direcao] = 'D';
            mapa[x_jog][y_jog] = 'H';
            *escada = 0;
        } else if (mapa[x_jog][y_jog + direcao] == 'H') {
            mapa[x_jog][y_jog + direcao] = 'D';
            mapa[x_jog][y_jog] = ' ';
            *escada = 1;
        } else if (mapa[x_jog][y_jog + direcao] == '1') {
            mapa[x_jog][y_jog + direcao] = 'D';
            mapa[x_jog][y_jog] = ' ';
            *porta = '1';
        } else if (mapa[x_jog][y_jog + direcao] == '2') {
            mapa[x_jog][y_jog + direcao] = 'D';
            mapa[x_jog][y_jog] = ' ';
            *porta = '2';
        } else if (*porta == '1'){
            mapa[x_jog][y_jog + direcao] = 'D';
            mapa[x_jog][y_jog] = '1';
            *porta = ' ';
        } else if (*porta == '2'){
            mapa[x_jog][y_jog + direcao] = 'D';
            mapa[x_jog][y_jog] = '2';
            *porta = ' ';
        } else if (mapa[x_jog][y_jog + direcao] == 'C') {
            mapa[x_jog][y_jog + direcao] = 'D';
            mapa[x_jog][y_jog] = ' ';
            *caixa = 1;
        } else if (*caixa == 1) {
            mapa[x_jog][y_jog + direcao] = 'D';
            mapa[x_jog][y_jog] = 'C';
            *caixa = 0;
        } else {
            mapa[x_jog][y_jog + direcao] = 'D';
            mapa[x_jog][y_jog ] = ' ';
        }
    } else if (mapa[x_jog + 1][y_jog + direcao] == ' ' && *escada == 0) {
        while (mapa[x_jog + i][y_jog + direcao] == ' ') {
            i++;
        }
        if (mapa[x_jog + i][y_jog + direcao] == 'C'){
            mapa[x_jog + i][y_jog + direcao] = 'D';
            mapa[x_jog][y_jog] = ' ';
            *caixa = 1;
        } else if (mapa[x_jog + i][y_jog + direcao] == '1') {
            mapa[x_jog + i][y_jog + direcao] = 'D';
            mapa[x_jog][y_jog] = ' ';
            *porta = '1';
        } else if (mapa[x_jog + i][y_jog + direcao] == '2') {
            mapa[x_jog + i][y_jog + direcao] = 'D';
            mapa[x_jog][y_jog] = ' ';
            *porta = '2';
        } else {
            i--;
            mapa[x_jog + i][y_jog + direcao] = 'D';
            mapa[x_jog][y_jog] = ' ';
        }
    }

}


/*
 * Função que imprime o mapa do jogo na tela
 * @param mapa Mapa do jogo
 * @param linhas número de linhas do mapa
 * @param colunas número de colunas do mapa
 */
void imprime_mapa(char mapa[MAPA_L][MAPA_C], int linhas, int colunas) {
    int l, c;
    for (l = 0; l < linhas; l++) {
        for (c = 0; c < colunas; c++){
            printf(" %c", mapa[l][c]);
        }
        printf("\n");
    }
}

/*
 * Função que retorna a localização do jogador no mapa
 * @param mapa Mapa do jogo
 * @param linhas número de linhas do mapa
 * @param colunas número de colunas do mapa
 * @param *x_jog parâmetro de saída, indicando a posição da linha do jogador
 * @param *y_jog parâmetro de saída que indica a posição da coluna em que o jogador se encontra
 */
void localiza_jogador(char mapa[MAPA_L][MAPA_C], int linhas, int colunas, int *x_jog, int *y_jog) {
    int l, c;
    for (l = 0; l < linhas; l++) {
        for (c = 0; c < colunas; c++) {
            if (mapa[l][c] == 'D') {
                *x_jog = l;
                *y_jog = c;
            }
        }
    }
}

/*
 * Função para buscar a localização do par de uma porta no mapa
 * @param mapa Mapa do jogo
 * @param linhas número de linhas do mapa
 * @param colunas número de colunas do mapa
 * @param porta identificador (char) de uma porta
 * @param *x_porta parâmetro de saída, indicando a posição da linha da porta
 * @param *y_porta parâmetro de saída que indica a posição da coluna em que a porta se encontra
 */
void busca_porta(char mapa[MAPA_L][MAPA_C], int linhas, int colunas, char porta, int *x_porta, int *y_porta) {
    int l, c;
    for (l = 0; l < linhas; l++){
        for (c = 0; c < colunas; c++){
            if (mapa[l][c] == porta){
                *x_porta = l;
                *y_porta = c;
            }
        }
    }
}
