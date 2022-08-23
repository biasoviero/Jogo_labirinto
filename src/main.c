#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"

#define ALTURA 660
#define LARGURA 640
#define TAM_FONTE 20
#define MAPA_L 10
#define MAPA_C 11
#define LARGURA_ICONE 30
#define TAM_STRING 10
#define OPCOES 4
#define TAM 20
#define POSY 100

void desenhaMenu(int selecionada);
void desenhaMapa(char mapa[MAPA_L][MAPA_C]);
void desenhaBarra(int pontos, int nivel, int vida);

int main() {

    char mapa[MAPA_L][MAPA_C];
    int opcao = 0; // Inicializa a opção como 0
    int pontuacao, vidas;
    pontuacao = 0;
    vidas = 3;
    //int e, l, c; //escada, linhas, colunas

    strcpy(mapa[0], "XXXXXXXXXX");
    strcpy(mapa[1], "X1 C  C2 X");
    strcpy(mapa[2], "XXHX  XX X");
    strcpy(mapa[3], "XCH    1 X");
    strcpy(mapa[4], "XXX HXHX X");
    strcpy(mapa[5], "X   H H  X");
    strcpy(mapa[6], "X   D HC2X");
    strcpy(mapa[7], "X HXX XXXX");
    strcpy(mapa[8], "X H X   PX");
    strcpy(mapa[9], "XXXXXXXXXX");


    InitWindow(LARGURA, ALTURA, "Labirinto");

    SetTargetFPS(60);

    while (!WindowShouldClose() && !IsKeyPressed(KEY_ENTER)){

        if (IsKeyPressed(KEY_DOWN)){ //Se a tecla "para baixo" for pressionada
            opcao++; //É adicionado 1 à solução
            if (opcao == 4){ //Caso a opção ultrapasse número de soluções - 1, é reinicializada para 0
                opcao = opcao - 4;
            }

        }

        else if(IsKeyPressed(KEY_UP)){ //Se a tecla "para cima" for pressionada
            opcao--;//É diminuído 1 da opção
            if (opcao == -1){//Se a opção for menor que 0
                opcao += 4;//É reinicializada para o fim
            }
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);
        desenhaMenu(opcao);
        EndDrawing();
    }

    if (IsKeyPressed(KEY_ENTER)){
        switch (opcao){ //Apenas imprime a opcao selecionada
            case 0: //Se for 0, imprime jogo inicia
                printf("Inicia jogo\n");
                break;
            case 1: //Se for 1, imprime carrega jogo
                printf("Carrega jogo\n");
                break;
            case 2: //Se for 2, imprime mostrando ranking dos pontos
                printf("Mostrando ranking dos pontos\n");
                break;
            case 3: //Se for 3, a janela é fechada
                CloseWindow();
        }

        while (!WindowShouldClose()){
            switch (opcao) { //Entra na opcao do menu selecionada
            case 0: //Se for 0, um jogo inicia
                BeginDrawing();
                ClearBackground(RAYWHITE);
                desenhaBarra(pontuacao, 1, vidas);
                desenhaMapa(mapa);
                EndDrawing();

                break;
            case 1: //Se for 1 o jogo é carregado

            case 2: //Se for 2 é mostrado o ranking de pontos

            case 3: //Se for 3 a janela é fechada
                CloseWindow();
            }
        }
    }
    return 0;
}

void desenhaMapa(char mapa[MAPA_L][MAPA_C]){
    int i, j, x, y;
    x = TAM_FONTE;

    Texture2D aux;
    Texture2D bau = LoadTexture("./assets/bau.png");
    Texture2D escada = LoadTexture("./assets/escada.png");
    Texture2D parede = LoadTexture("./assets/parede.png");
    Texture2D porta = LoadTexture("./assets/porta.png");
    Texture2D personagem = LoadTexture("./assets/emoji.png");
    Texture2D quadrado = LoadTexture("./assets/quadrado.png");


    for (i = 0; i < MAPA_L; i++){
        y = 10;
        for (j = 0; j< MAPA_C; j++){
/*
            if (i == 0 || i == MAPA_L || j == 0 || j == MAPA_C){
                if (i == MAPA_L)
                    y = i * LARGURA_ICONE; //PROBLEMA AQUI

            }*/

            //else{

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
                        y += LARGURA_ICONE;
                        break;
                    default:
                        aux = porta;
                    }
                printf("%c ", mapa[i][j]);
                if (mapa[i][j] != ' '){
                    DrawTexture(aux, x, y, WHITE);
                    y += LARGURA_ICONE;
                }

            //}
        }
        x += LARGURA_ICONE;
        y = 10;
        printf("\n");
    }

    //DrawTexture(parede, x, y, BLACK);
}


void desenhaMenu(int selecionada){
    char texto[OPCOES][TAM] = {"Novo Jogo", "Carregar Jogo", "[Ranking Pontos]", "Sair"}; //Declaração do texto do menu
    int i; // Contador
    int c = 1; //Contador para a posição y

    for(i = 0; i < OPCOES; i++){
        if(i == selecionada){ //Se o contador for a opção selecionada
            DrawText(texto[i], (LARGURA / 2) - (MeasureText(texto[i], TAM_FONTE) / 2), c * POSY, TAM_FONTE, RED); //Deseenha o texto em vermelho
        }
        else { //Senão
            DrawText(texto[i], (LARGURA / 2) - (MeasureText(texto[i], TAM_FONTE) / 2), c * POSY, TAM_FONTE, GREEN); //Desenha o texto em verde
        }
        c++; //Aumenta uma posição em y
    }
}

void desenhaBarra(int pontos, int nivel, int vida){
    //char pontuacao[TAM_STRING], fase[TAM_STRING], vida[TAM_STRING];
    int i, x, y;
    int vetor_fase[1];
    char vetor_pontos[15];
    x = 10;
    y = 5;
    Image heart = LoadImage("./assets/heart.png");
    ImageResize(&heart, TAM_FONTE, TAM_FONTE);
    Texture2D coracao = LoadTextureFromImage(heart);
    UnloadImage(heart);

    DrawText("SCORE: ", x, y, TAM_FONTE, BLACK);
    x +=  MeasureText("SCORE: ", TAM_FONTE) + 15;

    sprintf(vetor_pontos, "%4d PONTOS", pontos);
    DrawText(vetor_pontos, x, y, TAM_FONTE, BLACK);
    x +=  MeasureText("9999 PONTOS", TAM_FONTE) + 15;

    DrawText("NIVEL: ", x, y, TAM_FONTE, BLACK);
    x +=  MeasureText("NIVEL: ", TAM_FONTE) + 15;

    sprintf(vetor_fase, "%2d", nivel);
    DrawText(vetor_fase, x, y, TAM_FONTE, BLACK);
    x +=  MeasureText(" 99", TAM_FONTE) + 15;


    DrawText("VIDAS: ", x, y, TAM_FONTE, BLACK);
    x +=  MeasureText("VIDAS: ", TAM_FONTE) + 15;
    for (i = 0; i < vida; i++){
        DrawTexture(coracao, x, y, WHITE);
        x +=  TAM_FONTE;
    }

    //DrawText(vida, x, y, TAM_FONTE, BLACK);
}
