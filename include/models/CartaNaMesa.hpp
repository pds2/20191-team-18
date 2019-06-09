#ifndef CARTANAMESA_H
#define CARTANAMESA_H

#include <iostream>
#include <vector>
#include "Carta.hpp"
#include "Jogador.hpp"

using std::cout;
using std::endl;
using std::string;

class CartaNaMesa {
  public:
    CartaNaMesa(Carta* carta, Jogador* jogador);

    Jogador* getJogador();
    Carta* getCarta();
    
  private:
    Jogador* jogador;
    Carta* carta;
    
};

#endif