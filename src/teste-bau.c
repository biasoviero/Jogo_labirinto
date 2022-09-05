#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
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

void carregaMapa(struct Mapa *fase);
void sorteiaCaixa (struct Mapa *fase);

int main(){
    int i, j;
    struct Mapa fase_atual;
    carregaMapa(&fase_atual);
    sorteiaCaixa(&fase_atual);
    for (i = 0; i < fase_atual.linhas; i++){
        for (j = 0; j < fase_atual.colunas; j++){
            printf("%c", fase_atual.mapa[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void sorteiaCaixa (struct Mapa *fase){
    int i, j, c, chave, bombas;
    c = 0; //conta baús
    int baus[fase->linhas][fase->colunas]; //inicializa com 0, se tiver 1, há um baú nessa posição
    char bens[5] = {'!', '@', '#', '$', '%'};

    for (i = 0; i < fase->linhas; i++){
        for (j = 0; j < fase->colunas; j++){
            if (fase->mapa[i][j] == 'C'){
                baus[i][j] = 1;
                c++;
            }
            else{
                baus[i][j] = 0;
            }
        }
    }
    srand(time(NULL));
    char sorteio[c];
    for (i = 0; i < c; i++){
        sorteio[i] = bens[0 + (rand() % (4 - 0 + 1))];
    }


    for (i = 0; i < fase->linhas; i ++){
        for (j = 0; j < fase->colunas; j++){
            if (baus[i][j] == 1){
                fase->mapa[i][j] = sorteio[c - 1];
                c--;
            }
        }
    }
}

void carregaMapa(struct Mapa *fase){
    char linha[MAPA_C], i;
    int c;

    strcpy(fase->mapa[0], "XXXXXXXXXX");
    strcpy(fase->mapa[1], "X1 C  C2 X");
    strcpy(fase->mapa[2], "XXHX  XX X");
    strcpy(fase->mapa[3], "XKH    1 X");
    strcpy(fase->mapa[4], "XXX HXHX X");
    strcpy(fase->mapa[5], "X   H H  X");
    strcpy(fase->mapa[6], "X   D HB2X");
    strcpy(fase->mapa[7], "X HXX XXXX");
    strcpy(fase->mapa[8], "X H X   PX");
    strcpy(fase->mapa[9], "XXXXXXXXXX");

    fase->linhas = 10;
    fase->colunas = 10;
    fase->porta = ' ';
    fase->escada = 1;
    return;
}
