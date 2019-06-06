#include "models/Bot.hpp"
#include "models/Carta.hpp"
#include <time.h>       /* time */


Bot::Bot(string nome) : Jogador(nome) {}
Bot::Bot(string nome, std::vector<Carta*> cartas) : Jogador(nome, cartas) {};

/*
* Retorna uma carta da mão do bot realizando a jogada.
**/
Carta* Bot::jogar () {

    if(this->mao.size() == 0) {
        throw Exception::JogadorSemCartas();
    }

    srand (time(NULL));
    int posicaoCarta = rand() % (this->mao.size() - 1);

    Carta* c = this->mao[posicaoCarta];
    removeCartaMao(c);

    return c;
}