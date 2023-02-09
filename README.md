# Jogo do tipo labirinto em C

Esse projeto de autoria de [Beatriz Soviero](https://github.com/biasoviero) e [Laís Canabarro](https://github.com/laiscanabarro) foi o trabalho final da disciplina de Algoritmos e Programação que teve como objetivo a criação de um projeto grande utilizando a linguagem C e a biblioteca Raylib.

## Objetivo do jogo
O personagem se encontra no céu, rodeado por arco-íris, nuvens e portas que o teletransportam. O arco-íris serve como chão e as nuvens como escadas. O jogador se depara com diversos baús que contêm bens preciosos que aumentam a pontuação, bombas que diminuem a pontuação e uma vida, e chaves. O objetivo é encontrar o baú com a chave que mostrará a saída para a próxima fase.

## Prévia do jogo
![Prévia do jogo](https://github.com/biasoviero/Jogo/blob/main/previa_jogo.gif)

## Mecânica do jogo
As setas -> e <- representam os movimentos horizontais e as setas para cima e para baixo representam os movimentos verticais quando o jogador está em uma nuvem. Além disso, quando o jogador encontra um baú, se a tecla para baixo é pressionada o baú é aberto. E, quando o jogador quer se teletransportar pelas portas, basta pressionar o botão para cima quando estiver em uma.
O jogador morre quando perde as três vidas, o que pode acontecer quando são encontradas bombas os quando ele sofre uma queda com no mínimo três blocos de altura. O jogo acaba quando o jogador morre ou quando é achada a saída da terceira fase. Se a pontuação for suficiente, é pedido o nome do jogador para o registro no ranking.

