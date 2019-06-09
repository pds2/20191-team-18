#include "models/Rodada.hpp" 
#include "models/Jogador.hpp"
#include <list>
#include <iostream>

Rodada::Rodada(int numero, int pontos, std::list<Jogador*> jogadores, int* pontos_time1, int* pontos_time2) {
    this->numero = numero;
    this->pontos = pontos;
    this->jogadores = jogadores;            
    this->mao    = 1;
    *pontos_time1 = 12;
}