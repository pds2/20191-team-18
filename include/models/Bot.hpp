#ifndef BOT_H
#define BOT_H

#include <iostream>
#include <vector>
#include "Jogador.hpp"

using std::cout;
using std::endl;
using std::string;

class Bot : public Jogador {

  public:

    Bot(string nome);
    Bot(string nome, std::vector<Carta*> cartas);

    virtual int jogar(std::vector<std::string> opcoesAdicionais) override;
    virtual int aceitarDesafio(Jogador* jogadorDesafiante, int pontos) override;

  private:

};

#endif