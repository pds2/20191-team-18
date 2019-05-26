#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include "exceptions/Exception.hpp"
#include "Carta.hpp"
#include <vector>

using std::cout;
using std::endl;
using std::string;

class Jogador {

  public:

    Jogador(string nome);
    Jogador(string nome, std::vector<Carta> cartas);

    string  getNome();
    void addCartaMao(Carta* carta);
    void removeCartaMao(Carta* carta);
    void setMao(std::vector<Carta> cartas);
    std::vector<Carta> getMao();

  private:

    std::vector<Carta> mao;
    string nome; 

};

#endif