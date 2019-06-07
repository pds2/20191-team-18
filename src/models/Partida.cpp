#include "../../include/models/Partida.hpp"

using std::string;
using std::toupper;

Partida::Partida(int rodada, int pontos, int mao) {
    setRodada(rodada);
    setPontos(pontos);
    setMao(mao);
}

int Partida::getRodada() {
    return this->rodada;
}

int Partida::getPontos() {
    return this->pontos;
}

int Partida::getMao() {
    return this->mao;
}

void Partida::setRodada(int rodada) {
    this->rodada = rodada;
}

void Partida::setPontos(int pontos) {
    this->pontos = pontos;
}

void Partida::setMao(int mao) {
    this->mao = mao;
}



