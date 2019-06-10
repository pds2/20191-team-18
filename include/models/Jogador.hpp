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
    Jogador(string nome, std::vector<Carta*> cartas);

    string  getNome();

    void addCartaMao(Carta* carta);
    void removeCartaMao(Carta* carta);
    void removeCartaMao(int posicao); 
    void setMao(std::vector<Carta> cartas);
    Carta* getCartaMao(int posicao); 
    std::vector<Carta*> getMao();

    int getNumeroCartas();

    void setTimeJogador(int timeJogador);
    int getTimeJogador();

    void limparCartasMao();
    
    virtual int jogar(std::vector<std::string> opcoesAdicionais) = 0;
    virtual int aceitarDesafio(Jogador* jogadorDesafiante, int pontos) = 0;

  protected:

    std::vector<Carta*> mao;
    int timeJogador;

  private:
    string nome; 

};

#endif