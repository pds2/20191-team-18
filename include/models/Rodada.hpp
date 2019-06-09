#ifndef RODADA_H
#define RODADA_H

#include <iostream>
#include <list>
#include "exceptions/Exception.hpp"
#include "models/Jogador.hpp"

using std::cout;
using std::endl;
using std::string;

class Rodada {

  public:

    Rodada(int numero, int pontos, std::list<Jogador*> jogadores, int* pontos_time1, int* pontos_time2);
    void controleRodada();
    std::list<Jogador*> getOrdemJogadores();
    
  private:
  
    int numero;
    int pontos = 2;
    int mao;
    int* pontos_time1 = nullptr;
    int* pontos_time2 = nullptr;
    int maos_ganhas_time1 = 0;
    int maos_ganhas_time2 = 0;
    std::list<Jogador*> jogadores;
    std::list<Carta*> baralho;
    void reordenarListaJogadores();
    Jogador* ultimoVencedor;

};

#endif
