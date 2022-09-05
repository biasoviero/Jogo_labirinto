#ifndef JOGADOR_H_INCLUDED
#define JOGADOR_H_INCLUDED
#define TAM 20


struct Jogador{
    char nome[TAM];
    int pontuacao;
    int vidas;
    int linha;
    int coluna;
    int chave; //0 indica que o jogador não tem chave
};

struct Jogador jog_inicializa(int x, int y);
int jog_diminui_vida(struct Jogador *jogador);
void jog_aumenta_pontuacao(struct Jogador *jogador, int pontos);

#endif // JOGADOR_H_INCLUDED
