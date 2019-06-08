#include "models/Bot.hpp"
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

    if(this->mao.size() == 0) {
        throw Exception::JogadorSemCartas();
    }

    srand ( time(NULL) );
    int posicaoCarta = rand() % (this->mao.size() - 1);
    return posicaoCarta;
}