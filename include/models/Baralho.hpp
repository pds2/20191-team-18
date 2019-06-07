#ifndef BARALHO_H
#define BARALHO_H

#include <iostream>
#include <vector>
#include <list>
#include "Carta.hpp"
#include <queue>

using std::cout;
using std::endl;
using std::string;

class Baralho  {

    const static int NUM_CARTAS = 40;

    const int COPAS = 0;
    const int OUROS = 1;
    const int ESPADAS = 2;
    const int PAUS    = 3;

    const int FORCA_SETEOUROS = 11;
    const int FORCA_ESPADILHA = 12;
    const int FORCA_SETECOPAS = 13;
    const int FORCA_ZAPE = 14;

  public:

    Baralho();
    ~Baralho();

    std::list<Carta*> getCartas();
    void embaralhar();

  private:
    std::list<Carta*> cartas;
    string figuras [10] = { "4", "5", "6", "7", "Q", "J", "K", "A", "2", "3"}; 
    int nipes[4] =  { COPAS, OUROS, ESPADAS, PAUS };

};

#endif