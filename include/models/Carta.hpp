#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include "exceptions/Exception.hpp"

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
    
    int  getNipe();
    void setNipe(int nipe);
    void setNipe(string nipe);

    void setValor(string valor);
    string getValor();

    void setForca(int forca);
    int getForca();

  private:

    int nipe;
    string valor; 
    int forca;

};

#endif