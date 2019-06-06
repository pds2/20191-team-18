#ifndef HUMANO_H
#define HUMANO_H

#include <iostream>
#include <vector>
#include "Jogador.hpp"

using std::cout;
using std::endl;
using std::string;

class Humano : public Jogador {

  public:

    Humano(string nome);
    Humano(string nome, std::vector<Carta*> cartas);

    virtual Carta* jogar() override;

  private:

};

#endif