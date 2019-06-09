#ifndef RODADA_H
#define RODADA_H

#include <iostream>
#include <list>
#include "exceptions/Exception.hpp"
#include "models/Jogador.hpp"

using std::cout;
using std::endl;
using std::string;

class Rodada {

  public:

    Rodada(int numero, int pontos, std::list<Jogador*> jogadores, int* pontos_time1, int* pontos_time2);
    string vencedorRodada();

  private:
  
    int numero;
    int pontos;
    int mao;
    std::list<Jogador*> jogadores;
    std::list<Carta*> baralho;

};

#endif
