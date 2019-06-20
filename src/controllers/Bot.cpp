#include "controllers/Bot.hpp"
#include "models/Carta.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


Bot::Bot(string nome) : Jogador(nome) {}
Bot::Bot(string nome, std::vector<Carta*> cartas) : Jogador(nome, cartas) {};

/*
* Retorna uma carta da mão do bot realizando a jogada.
**/
int Bot::jogar(std::vector<std::string> opcoesAdicionais) {
    int posicaoCarta = 0;
    if(this->mao.size() == 0) {
        throw Exception::JogadorSemCartas();
    }

    srand ( time(NULL) );
    if(this->mao.size() != 1) {
        posicaoCarta = rand() % (this->mao.size() - 1);
    }
    
    return posicaoCarta;
}

int Bot::aceitarDesafio(Jogador* jogadorDesafiante, int pontos) {
    if(pontos != 12) {
        return 2;
    }
    else return 1;
}