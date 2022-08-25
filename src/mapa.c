#include "mapa.h"

void desenhaMapa(char mapa[MAPA_L][MAPA_C]){
    int i, j, x, y;
    x = 10;
    y = TAM_FONTE + 20;


    Texture2D aux;
    Texture2D bau = LoadTexture("./assets/bau.png");
    Texture2D escada = LoadTexture("./assets/escada.png");
    Texture2D parede = LoadTexture("./assets/parede.png");
    Texture2D porta = LoadTexture("./assets/porta.png");
    Texture2D personagem = LoadTexture("./assets/personagem.png");
    Texture2D quadrado = LoadTexture("./assets/quadrado.png");


    for (i = 0; i < MAPA_L; i++){

        for (j = 0; j< MAPA_C; j++){

            if (i == 0 || i == MAPA_L - 1 || j == 0 || j == MAPA_C - 1){
                DrawTexture(parede, x, y, WHITE);
                x += LARGURA_ICONE;
            }

            else{

                switch(mapa[i][j]){
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
                        x += LARGURA_ICONE;
                        break;
                    default:
                        aux = porta;
                    }
                printf("%c ", mapa[i][j]);
                if (mapa[i][j] != ' '){
                    DrawTexture(aux, x, y, WHITE);
                    x += LARGURA_ICONE;
                }

            }
        }
        x = 10;
        y += LARGURA_ICONE;
        printf("\n");
    }
    return;
}

void desenhaBarra(int pontos, int nivel, int vida){
    int i, posx, posy;
    int vetor_fase[1];
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

    sprintf(vetor_fase, "%1d", nivel);
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
