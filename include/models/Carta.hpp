#ifndef CARTA_H
#define CARTA_H

#include <iostream>

#include "../exceptions/Exception.hpp"

using std::cout;
using std::endl;
using std::string;

class Carta {

  const int MAX_FORCA = 50;

  const int COPAS = 0;
  const int OUROS = 1;
  const int ESPADAS = 2;
  const int PAUS    = 3;

  public:
    
    Carta(string  valor,  string  nipe);
    Carta(string  valor,  int     nipe);
    Carta(string  valor,  string  nipe,   int forca);
    Carta(string  valor,  int     nipe,   int forca);

    string  getNipe();
    void setNipe(int nipe);
    void setNipe(string nipe);

    void setValor(string valor);
    string getValor();

    void setForca(int forca);
    int getForca();

  private:

    int nipe;
    string valor; 
    int forca = 0;

};

#endif