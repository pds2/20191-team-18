#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include "exceptions/Exception.hpp"

using std::cout;
using std::endl;
using std::string;

class Partida {

  private:
    int rodada;
    int pontos;
    int mao;

  public:
    Partida(int rodada, int pontos, int mao);

    int getRodada();
    void setRodada(int rodada);

    int getPontos();
    void setPontos(int pontos);

    int getMao();
    void setMao(int mao);
};

#endif
