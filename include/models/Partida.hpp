#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <list>
#include "exceptions/Exception.hpp"
#include "models/Jogador.hpp"
#include "models/Rodada.hpp"

using std::cout;
using std::endl;
using std::string;

class Partida {

  const int PONTOS_VITORIA = 12;


  private:
    
    int pontos_time1;
    int pontos_time2;

    std::list<Rodada*> rodadas;
    std::list<Jogador*> jogadores;

  public:

    Partida(std::list<Jogador*> jogadores);

    int getPontosTime1();
    int getPontosTime2();

    int getMao();
    void setMao(int mao);
};

#endif
