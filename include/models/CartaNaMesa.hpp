#ifndef CARTANAMESA_H
#define CARTANAMESA_H

#include <iostream>
#include <vector>
#include "Carta.hpp"
#include "Jogador.hpp"

using std::cout;
using std::endl;
using std::string;

class CartaNaMesa {

  public:
    /**
     * @brief Construtor para a classe CartaNaMesa. 
     * 
     * @param carta - Carta jogada na mesa
     * @param jogador - Jogador que jogou a carta na mesa
     */
    CartaNaMesa(Carta* carta, Jogador* jogador);

    /**
     * @brief Retorna o jogador que jogou aquela carta na mesa
     * 
     * @return Jogador* 
     */
    Jogador* getJogador();

    /**
     * @brief Retorna a carta jogada na mesa
     * 
     * @return Carta* 
     */
    Carta* getCarta();
    
  private:
    /**
     * @brief Jogador que jogou a carta na mesa 
     * 
     */
    Jogador* jogador;
    
    /**
     * @brief Carta jogada na mesa
     * 
     */
    Carta* carta;
    
};

#endif