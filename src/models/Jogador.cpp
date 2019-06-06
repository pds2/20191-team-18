#include "models/Jogador.hpp"
#include "models/Carta.hpp"
#include <iostream>
#include <vector>

using std::string;
using std::toupper;

Jogador::Jogador(string nome) {
    this->nome = nome;
}

Jogador::Jogador(string nome, std::vector<Carta*> cartas) {
    this->nome = nome;
    this->mao  = cartas;
}

string Jogador::getNome() {
    return this->nome;
}

void Jogador::addCartaMao(Carta* carta) {
    this->mao.push_back(carta);
}

void Jogador::removeCartaMao(Carta* carta) {
    for(unsigned int i = 0; i < this->mao.size(); i++) {
        if(this->mao[i] == carta) {
            this->mao.erase(this->mao.begin() + i);
        }
    }
}

void Jogador::removeCartaMao(int posicao) {
    this->mao.erase(this->mao.begin() + posicao);  
}

Carta* Jogador::getCartaMao(int posicao) {
    return this->mao[posicao];
}

std::vector<Carta*> Jogador::getMao() {
    return this->mao;
}
