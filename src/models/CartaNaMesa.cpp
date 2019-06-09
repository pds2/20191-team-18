#include "models/Carta.hpp"
#include "models/Jogador.hpp"
#include "models/CartaNaMesa.hpp"

using std::string;

CartaNaMesa::CartaNaMesa(Carta* carta, Jogador* jogador)  {
    this->jogador = jogador;
    this->carta = carta;
}

Jogador* CartaNaMesa::getJogador(){
    return this->jogador;
}

Carta* CartaNaMesa::getCarta() {
    return this->carta;
}