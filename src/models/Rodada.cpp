#include "models/Rodada.hpp" 
#include "models/Jogador.hpp"
#include "models/Baralho.hpp"
#include <list>
#include <iostream>

Rodada::Rodada(int numero, int pontos, std::list<Jogador*> jogadores, int* pontos_time1, int* pontos_time2) {
    Baralho baralhoPartida;
    baralhoPartida.embaralhar();
    this->numero = numero;
    this->pontos = pontos;
    this->jogadores = jogadores;            
    this->mao    = 1;
    this->baralho = baralhoPartida.getCartas();
    *pontos_time1 = 12;

    for (auto const& jogador : jogadores) {
        auto carta1 = std::next(baralho.begin(), 0);
        auto carta2 = std::next(baralho.begin(), 1);
        auto carta3 = std::next(baralho.begin(), 2);
        jogador->addCartaMao(*carta1);
        jogador->addCartaMao(*carta2);
        jogador->addCartaMao(*carta3);
        baralho.erase(carta1);
        baralho.erase(carta2);
        baralho.erase(carta3);
    }
}

//Rodada::vencedorRodada(){
 //   for (auto const& jogador : jogadores) {
        //jogador->getCartaMao();
        //jogador->addCartaMao(*carta2);
        //jogador->addCartaMao(*carta3);
        //baralho.erase(carta1);
        //baralho.erase(carta2);
        //baralho.erase(carta3);
    //}
//}