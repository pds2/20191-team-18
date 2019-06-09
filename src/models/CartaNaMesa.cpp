#include "models/Carta.hpp"
#include "models/Jogador.hpp"
#include "models/CartaNaMesa.hpp"

using std::string;

CartaNaMesa::CartaNaMesa(Carta* carta, Jogador* jogador) : Carta(carta->getValor(), carta->getNipe(), carta->getForca()) {
    this->setForca(carta->getForca());
    this->setValor(carta->getValor());
    this->setNipe(carta->getNipe());
    this->nomeJogador = jogador->getNome();
}

string CartaNaMesa::GetJogador(){
    return this->nomeJogador;
}