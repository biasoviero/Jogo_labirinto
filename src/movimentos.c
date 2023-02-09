#include "movimentos.h"

void movimento_vertical(t_mapa *fase, int direcao) {
    int x_jog, y_jog, x_porta, y_porta;

    localiza_jogador(*fase, &x_jog, &y_jog);
    busca_porta(*fase, &x_porta, &y_porta);

    if (fase->porta != ' ' && direcao == -1) {
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


    } else if (direcao == -1 && fase->escada == 1 ) {
        if (fase->mapa[x_jog + direcao][y_jog] != 'H') {
            fase->escada = 0;
        }
        fase->mapa[x_jog + direcao][y_jog] = 'D';
        fase->mapa[x_jog][y_jog] = 'H';

    } else if (direcao == 1 && fase->mapa[x_jog + direcao][y_jog] != 'X') {
        if (fase->escada == 1) {
            fase->mapa[x_jog][y_jog] = 'H';
            fase->mapa[x_jog + direcao][y_jog] = 'D';
        } else if (fase->mapa[x_jog - 1][y_jog] != 'H') {
            fase->mapa[x_jog + 1][y_jog] = 'D';
            fase->mapa[x_jog][y_jog] = ' ';
        }
        fase->escada = 1;

    }
}

void movimento_horizontal(t_mapa *fase, int direcao) {
    int x_jog, y_jog, x_porta, y_porta, i = 0;
    localiza_jogador(*fase, &x_jog, &y_jog);

    //se o jogador for para uma posição que nao tiver chao
        if (fase->mapa[x_jog + 1][y_jog + direcao] == ' ') {
            while (fase->mapa[x_jog + i][y_jog + direcao] == ' ') {
                i++;
            }

            //possíveis casos da posição atual do jogador
            if (fase->escada == 1) {
                fase->escada = 0;
                fase->mapa[x_jog][y_jog] = 'H';
            } else if (fase->porta == '1') {
                fase->porta = ' ';
                fase->mapa[x_jog][y_jog] = '1';
            } else if (fase->porta == '2') {
                fase->porta = ' ';
                fase->mapa[x_jog][y_jog] = '2';
            } else if (fase->caixa == 1) {
                fase->caixa = 0;
                fase->mapa[x_jog][y_jog] = 'C';
            } else if (fase->saida == 1) {
                fase->saida = 0;
                fase->mapa[x_jog][y_jog] = 'P';
            } else {
                fase->mapa[x_jog][y_jog] = ' ';
            }

            //possíveis casos do próximo movimento horizontal
            switch (fase->mapa[x_jog + i][y_jog + direcao]) {
                case 'H':
                    fase->escada = 1;
                    break;
                case '1':
                    fase->porta = '1';
                    break;
                case '2':
                    fase->porta = '2';
                    break;
                case 'C':
                    fase->caixa = 1;
                    break;
                case 'P':
                    fase->saida = 1;
                    break;
                default:
                    i--;
            }
            fase->mapa[x_jog + i][y_jog + direcao] = 'D';

    //se o próximo passo for diferente de 'X'
    } else if (fase->mapa[x_jog][y_jog + direcao] != 'X') {
        //se o jogador estiver em uma escada
        if (fase->escada == 1) {
            fase->escada = 0;

            //possíveis casos do próximo movimento horizontal
            switch (fase->mapa[x_jog][y_jog + direcao]) {
                case '1':
                    fase->porta = '1';
                    break;
                case '2':
                    fase->porta = '2';
                    break;
                case 'C':
                    fase->caixa = 1;
                    break;
                case 'P':
                    fase->saida = 1;
                    break;
            }
            fase->mapa[x_jog][y_jog] = 'H';
            fase->mapa[x_jog][y_jog + direcao] = 'D';
        //se o jogador for para uma posição que tem chão 'X' ou 'H'
        } else if (fase->mapa[x_jog + 1][y_jog + direcao] == 'X' || fase->mapa[x_jog + 1][y_jog + direcao] == 'H') {

            //possíveis casos da posição atual do jogador
            if (fase->escada == 1) {
                fase->escada = 0;
                fase->mapa[x_jog][y_jog] = 'H';
            } else if (fase->porta == '1') {
                fase->porta = ' ';
                fase->mapa[x_jog][y_jog] = '1';
            } else if (fase->porta == '2') {
                fase->porta = ' ';
                fase->mapa[x_jog][y_jog] = '2';
            } else if (fase->caixa == 1) {
                fase->caixa = 0;
                fase->mapa[x_jog][y_jog] = 'C';
            } else if (fase->saida == 1) {
                fase->saida = 0;
                fase->mapa[x_jog][y_jog] = 'P';
            } else {
                fase->mapa[x_jog][y_jog] = ' ';
            }

            //possíveis casos do próximo movimento horizontal
            switch (fase->mapa[x_jog][y_jog + direcao]) {
                case 'H':
                    fase->escada = 1;
                    break;
                case '1':
                    fase->porta = '1';
                    break;
                case '2':
                    fase->porta = '2';
                    break;
                case 'C':
                    fase->caixa = 1;
                    break;
                case 'P':
                    fase->saida = 1;
                    break;
            }
            fase->mapa[x_jog][y_jog + direcao] = 'D';
        }
    }
}

void localiza_jogador(t_mapa fase, int *x_jog, int *y_jog) {
    int l, c;
    for (l = 0; l < fase.linhas; l++) {
        for (c = 0; c < fase.colunas; c++) {
            if (fase.mapa[l][c] == 'D') {
                *x_jog = l;
                *y_jog = c;
            }
        }
    }
}

void busca_porta(t_mapa fase, int *x_porta, int *y_porta){
    int l, c;
    for (l = 0; l < fase.linhas; l++){
        for (c = 0; c < fase.colunas; c++){
            if (fase.mapa[l][c] == fase.porta){
                *x_porta = l;
                *y_porta = c;
            }
        }
    }
}

void abreCaixa(t_mapa fase, struct Jogador *jogador, int *mensagem){
    if(fase.mapa[jogador->linha][jogador->coluna + 1] == 'K'|| fase.mapa[jogador->linha][jogador->coluna - 1] == 'K'){
        jogador->chave = 1;
        *mensagem = 0; //"Chave encontrada"
        jog_aumenta_pontuacao(&jogador, 1000);
    }
    else if(fase.mapa[jogador->linha][jogador->coluna + 1] == 'B'|| fase.mapa[jogador->linha][jogador->coluna - 1] == 'B'){
        *mensagem = 1; //"Bomba encontrada"
        jog_aumenta_pontuacao(&jogador, -500);
        jogador->vidas = 0; //jogador morre
    }
    else if(fase.mapa[jogador->linha][jogador->coluna + 1] == '!'|| fase.mapa[jogador->linha][jogador->coluna - 1] == '!'){
        *mensagem = 2; //"Ametista encontrada"
        jog_aumenta_pontuacao(&jogador, 50);
    }
    else if(fase.mapa[jogador->linha][jogador->coluna + 1] == '@'|| fase.mapa[jogador->linha][jogador->coluna - 1] == '@'){
        *mensagem = 3; //"Safira encontrada"
        jog_aumenta_pontuacao(&jogador, 100);
    }
    else if(fase.mapa[jogador->linha][jogador->coluna + 1] == '#'|| fase.mapa[jogador->linha][jogador->coluna - 1] == '#'){
        *mensagem = 4; //"Rubi ncontrado"
        jog_aumenta_pontuacao(&jogador, 150);
    }
    else if(fase.mapa[jogador->linha][jogador->coluna + 1] == '$'|| fase.mapa[jogador->linha][jogador->coluna - 1] == '$'){
        *mensagem = 5; //"Anel encontrado"
        jog_aumenta_pontuacao(&jogador, 200);
    }
    else if(fase.mapa[jogador->linha][jogador->coluna + 1] == '%'|| fase.mapa[jogador->linha][jogador->coluna - 1] == '%'){
        *mensagem = 6; //"Coroa encontrada"
        jog_aumenta_pontuacao(&jogador, 300);
    }
}
