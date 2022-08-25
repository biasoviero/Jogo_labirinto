#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"
#include "mapa.h"

#define ALTURA 660
#define LARGURA 640
#define MAPA_L 10
#define MAPA_C 10
#define OPCOES 4
#define TAM 20
#define POSY 100

void desenhaMenu(int selecionada);

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
