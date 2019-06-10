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

    void pedirTruco();
    void exibirCartas();
    void exibirOpcoesAdicionais(std::vector<std::string> opcoesAdicionais, int nOpcao);

    virtual int jogar(std::vector<std::string> opcoesAdicionais) override;
    virtual int aceitarDesafio(Jogador* jogadorDesafiante, int pontos) override;

  private:

};

#endif