#ifndef CARTANAMESA_H
#define CARTANAMESA_H

#include <iostream>
#include <vector>
#include "Carta.hpp"
#include "Jogador.hpp"

using std::cout;
using std::endl;
using std::string;

class CartaNaMesa : public Carta {
  public:
    CartaNaMesa(Carta* carta, Jogador* jogador);

    string GetJogador();
    
  private:
    string nomeJogador;
    
};

#endif