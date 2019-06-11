#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <list>
#include "exceptions/Exception.hpp"
#include "models/Jogador.hpp"
#include "controllers/Rodada.hpp"

using std::cout;
using std::endl;
using std::string;

class Partida {

  /**
   * @brief Número de pontos necessarios para ganhar a partida
   * 
   */
  const int PONTOS_VITORIA = 12;

  private:
    /**
     * @brief Pontos do time 1
     * 
     */
    int pontos_time1 = 0;

    /**
     * @brief Pontos do time 2
     * 
     */
    int pontos_time2 = 0;

    /**
     * @brief Lista com as Rodadas que compõem a partida
     * 
     */
    std::list<Rodada*> rodadas;
    /**
     * @brief Lista dos jogadores participantes da partida
     * 
     */
    std::list<Jogador*> jogadores;    

  public:
    /**
     * @brief Construtor da Partida
     * 
     * @param jogadores - Jogadores participantes da Partida 
     */
    Partida(std::list<Jogador*> jogadores);

    /**
     * @brief Controla a execução da Partida
     * 
     */
    void controlaPartida();
};

#endif
