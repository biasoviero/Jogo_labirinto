#include "mapa.h"
#include <stdio.h>
#include <string.h>

void desenhaMapa(t_mapa fase, struct Jogador jogador){
    int i, j, x, y, larguraIcone;
    x = 10;
    y = TAM_FONTE + 20;
    larguraIcone = LARGURA / fase.linhas;


    Texture2D aux;
    Texture2D bau = LoadTexture("./assets/bau.png");
    Texture2D escada = LoadTexture("./assets/nuvem.png");
    Texture2D parede = LoadTexture("./assets/arco-iris.png");
    Texture2D porta = LoadTexture("./assets/porta.png");
    Texture2D personagem = LoadTexture("./assets/personagem.png");
    Texture2D quadrado = LoadTexture("./assets/arco-iris.png");
    Texture2D bandeira = LoadTexture("./assets/bandeira.png");


    for (i = 0; i < fase.linhas; i++){
        for (j = 0; j < fase.colunas; j++){
            if (i == fase.linhas - 1){
                DrawTexture(parede, x, y, WHITE);
                x += larguraIcone;
            } else if (i == 0 || j == 0 || j == fase.colunas - 1) {
                x += larguraIcone;

            } else{
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
                    case '!':
                    case '@':
                    case '#':
                    case '$':
                    case '%':
                    case 'C':
                    case 'B':
                    case 'K':
                        aux = bau;
                        break;
                    case ' ':
                        x += larguraIcone;
                        break;

                    //PROBLEMA AO ESCONDER A SAÍDA!
                    case 'P':
                        if (jogador.chave == 1)
                            aux = bandeira;
                        else
                            x += larguraIcone;
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

void desenhaBarra(struct Jogador jogador, int nivel, int mensagem){
    int i, posx, posy;
    int vetor_fase[2];
    char vetor_pontos[15];
    char texto[20];
    posx = 10;
    posy = 5;
    Image heart = LoadImage("./assets/heart.png");
    ImageResize(&heart, TAM_FONTE, TAM_FONTE);
    Texture2D coracao = LoadTextureFromImage(heart);
    UnloadImage(heart);

    DrawText("SCORE: ", posx, posy, TAM_FONTE, BLACK);
    posx +=  MeasureText("SCORE: ", TAM_FONTE) + 10;

    sprintf(vetor_pontos, "%4d PONTOS", jogador.pontuacao);
    DrawText(vetor_pontos, posx, posy, TAM_FONTE, BLACK);
    posx +=  MeasureText("9999 PONTOS", TAM_FONTE) + 10;

    DrawText("NIVEL: ", posx, posy, TAM_FONTE, BLACK);
    posx +=  MeasureText("NIVEL: ", TAM_FONTE) + 10;

    sprintf(vetor_fase, "%1d", nivel);
    DrawText(vetor_fase, posx, posy, TAM_FONTE, BLACK);
    posx +=  MeasureText("9", TAM_FONTE) + 10;


    DrawText("VIDAS:", posx, posy, TAM_FONTE, BLACK);
    posx +=  MeasureText("VIDAS:", TAM_FONTE) + 10;
    for (i = 0; i < jogador.vidas; i++){
        DrawTexture(coracao, posx, posy, WHITE);
        posx +=  TAM_FONTE;
    }

    posx += 10;
    posy += 5;

    switch (mensagem){
        case -1:
            strcpy(texto, " ");
            break;
        case 0:
            strcpy(texto, "Chave encontrada");
            break;
        case 1:
            strcpy(texto, "Bomba encontrada");
            break;
        case 2:
            strcpy(texto, "Ametista encontrada");
            break;
        case 3:
            strcpy(texto, "Safira encontrada");
            break;
        case 4:
            strcpy(texto, "Rubi encontrado");
            break;
        case 5:
            strcpy(texto, "Anel encontrado");
            break;
        case 6:
            strcpy(texto, "Coroa encontrada");
            break;
    }

    DrawText(texto, posx, posy, TAM_FONTE - 5, BLACK);

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
    fase->caixa = 0;

    return;
}

void sorteiaCaixa (t_mapa *fase){
    int i, j, c, a;
    c = 0; //conta baús
    char bens[5] = {'!', '@', '#', '$', '%'};

    //Loop que conta quantos Cs há no mapa
    for (i = 0; i < fase->linhas; i++){
        for (j = 0; j < fase->colunas; j++){
            c++;
        }
    }

    srand(time(NULL));
    char sorteio[c];
    //Faz um vetor com a quantidade de baús e sorteia os bens
    for (i = 0; i < c; i++){
        sorteio[i] = bens[0 + (rand() % (4 - 0 + 1))];
    }

    a = 0; //Contador
    //Posiciona os bens sorteados no mapa
    for (i = 0; i < fase->linhas; i++){
        for (j = 0; j < fase->colunas; j++){
            if (fase->mapa[i][j] == 'C'){
                fase->mapa[i][j] = sorteio[a];
                a++;
            }
        }
    }
}
