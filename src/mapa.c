#include "mapa.h"
#include <stdio.h>
#include <string.h>

void desenhaMapa(t_mapa fase){
    int i, j, x, y, larguraIcone;
    x = 10;
    y = TAM_FONTE + 20;
    larguraIcone = LARGURA / fase.linhas;


    Texture2D aux;
    Texture2D bau = LoadTexture("./assets/bau.png");
    Texture2D escada = LoadTexture("./assets/escada.png");
    Texture2D parede = LoadTexture("./assets/chao2.png");
    Texture2D porta = LoadTexture("./assets/porta.png");
    Texture2D personagem = LoadTexture("./assets/alienPink.png");
    Texture2D quadrado = LoadTexture("./assets/chao.png");
    Texture2D bandeira = LoadTexture("./assets/bandeira.png");


    for (i = 0; i < fase.linhas; i++){
        for (j = 0; j < fase.colunas; j++){
            if (i == 0 || i == fase.linhas - 1 || j == 0 || j == fase.colunas - 1){
                DrawTexture(parede, x, y, WHITE);
                x += larguraIcone;
            }

            else{
                switch(fase.mapa[i][j]){
                    case 'H':
                        aux = escada;
                        break;
                    case 'D':
                        aux = personagem;
                        break;
                    case 'X':
                        aux = quadrado;
                        break;
                    case 'C':
                        aux = bau;
                        break;
                    case ' ':
                        x += larguraIcone;
                        break;
                    case 'P':
                        aux = bandeira;
                        break;
                    default:
                        aux = porta;
                    }
                if (fase.mapa[i][j] != ' '){
                    DrawTexture(aux, x, y, WHITE);
                    x += larguraIcone;
                }
            }
        }
        x = 10;
        y += larguraIcone;
    }
    return;
}

void desenhaBarra(int pontos, int nivelAtual, int vida){
    int i, posx, posy;
    int vetor_fase[2];
    char vetor_pontos[15];
    posx = 10;
    posy = 5;
    Image heart = LoadImage("./assets/heart.png");
    ImageResize(&heart, TAM_FONTE, TAM_FONTE);
    Texture2D coracao = LoadTextureFromImage(heart);
    UnloadImage(heart);

    DrawText("SCORE: ", posx, posy, TAM_FONTE, BLACK);
    posx +=  MeasureText("SCORE: ", TAM_FONTE) + 15;

    sprintf(vetor_pontos, "%4d PONTOS", pontos);
    DrawText(vetor_pontos, posx, posy, TAM_FONTE, BLACK);
    posx +=  MeasureText("9999 PONTOS", TAM_FONTE) + 15;

    DrawText("NIVEL: ", posx, posy, TAM_FONTE, BLACK);
    posx +=  MeasureText("NIVEL: ", TAM_FONTE) + 15;

    sprintf(vetor_fase, "%1d", nivelAtual);
    DrawText(vetor_fase, posx, posy, TAM_FONTE, BLACK);
    posx +=  MeasureText("99", TAM_FONTE) + 15;


    DrawText("VIDAS: ", posx, posy, TAM_FONTE, BLACK);
    posx +=  MeasureText("VIDAS: ", TAM_FONTE) + 15;
    for (i = 0; i < 3; i++){
        DrawTexture(coracao, posx, posy, WHITE);
        posx +=  TAM_FONTE;
    }
    return;
}

void carregaMapa(t_mapa *fase){
    char linha[MAPA_C], i;
    int c;

    FILE *nivel = fopen("./fases/fase_1.txt", "r"); //parâmetro 'r' para ler o arquivo

    if(nivel == NULL){
        printf("Nao foi possivel iniciar a fase");
    }

    fase->linhas = 0;

    while (fgets(linha, sizeof(linha), nivel)){ //lê cada linha e armazena na variável
        strcpy(fase->mapa[fase->linhas], linha);
        fase->linhas++;
    }

    i = fase->mapa[0][0];
    fase->colunas = 0;
    c = 0;

    while (i != '\0'){ //conta a quantidade de colunas
        c++;
        i = fase->mapa[0][c];
        fase->colunas++;
    }
    fase->colunas--;
    fase->porta = ' ';
    fase->escada = 1;

    return;
}
