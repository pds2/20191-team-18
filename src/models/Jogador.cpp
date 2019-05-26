#include "models/Jogador.hpp"
#include "models/Carta.hpp"
#include <iostream>
#include <vector>

using std::string;
using std::toupper;

Jogador::Jogador(string nome) {
    this->nome = nome;
}

Jogador::Jogador(string nome, std::vector<Carta> cartas) {
    this->nome = nome;
    //this->mao  = cartas;
}

string Jogador::getNome() {
    return this->nome;
}

void Jogador::addCartaMao(Carta* carta) {

}

void Jogador::removeCartaMao(Carta* carta) {

}

std::vector<Carta> Jogador::getMao() {
    return this->mao;
}