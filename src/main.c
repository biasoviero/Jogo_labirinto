#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"
#include "mapa.h"
#include "movimentos.h"

#define ALTURA 660
#define LARGURA 640
#define MAPA_L 30
#define MAPA_C 120
#define OPCOES 4
#define TAM 20
#define POSY 100

void desenhaMenu(int selecionada);

int main() {

    int opcao = 0; // Inicializa a op��o como 0
    int pontuacao, vidas;
    t_mapa fase_atual;
    pontuacao = 0;
    vidas = 3;

    carregaMapa(&fase_atual);

    InitWindow(LARGURA, ALTURA, "Labirinto");

    SetTargetFPS(60);

    while (!WindowShouldClose() && !IsKeyPressed(KEY_ENTER)){

        if (IsKeyPressed(KEY_DOWN)){ //Se a tecla "para baixo" for pressionada
            opcao++; //� adicionado 1 � solu��o
            if (opcao == 4){ //Caso a op��o ultrapasse n�mero de solu��es - 1, � reinicializada para 0
                opcao = opcao - 4;
            }

        }

        else if(IsKeyPressed(KEY_UP)){ //Se a tecla "para cima" for pressionada
            opcao--;//� diminu�do 1 da op��o
            if (opcao == -1){//Se a op��o for menor que 0
                opcao += 4;//� reinicializada para o fim
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
            case 3: //Se for 3, a janela � fechada
                CloseWindow();
        }

        while (!WindowShouldClose()){
            switch (opcao) { //Entra na opcao do menu selecionada
            case 0: //Se for 0, um jogo inicia
                BeginDrawing();
                ClearBackground(SKYBLUE);
                desenhaBarra(pontuacao, 1, vidas);
                desenhaMapa(fase_atual);
                if (IsKeyPressed(KEY_RIGHT)){
                    movimento_horizontal(&fase_atual, 1);
                }
                else if (IsKeyPressed(KEY_LEFT)){
                    movimento_horizontal(&fase_atual, -1);
                }
                else if (IsKeyPressed(KEY_UP)){
                    movimento_vertical(&fase_atual, -1);
                }
                else if (IsKeyPressed(KEY_DOWN)){
                    movimento_vertical(&fase_atual, 1);
                }
                EndDrawing();

                break;
            case 1: //Se for 1 o jogo � carregado

            case 2: //Se for 2 � mostrado o ranking de pontos

            case 3: //Se for 3 a janela � fechada
                CloseWindow();
            }
        }
    }
    return 0;
}


void desenhaMenu(int selecionada){
    char texto[OPCOES][TAM] = {"Novo Jogo", "Carregar Jogo", "[Ranking Pontos]", "Sair"}; //Declara��o do texto do menu
    int i; // Contador
    int c = 1; //Contador para a posi��o y

    for(i = 0; i < OPCOES; i++){
        if(i == selecionada){ //Se o contador for a op��o selecionada
            DrawText(texto[i], (LARGURA / 2) - (MeasureText(texto[i], TAM_FONTE) / 2), c * POSY, TAM_FONTE, RED); //Deseenha o texto em vermelho
        }
        else { //Sen�o
            DrawText(texto[i], (LARGURA / 2) - (MeasureText(texto[i], TAM_FONTE) / 2), c * POSY, TAM_FONTE, GREEN); //Desenha o texto em verde
        }
        c++; //Aumenta uma posi��o em y
    }
}
