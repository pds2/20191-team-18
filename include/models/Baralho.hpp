#ifndef BARALHO_H
#define BARALHO_H

#include <iostream>
#include <vector>
#include <list>
#include "Carta.hpp"
#include <queue>

using std::cout;
using std::endl;
using std::string;

class Baralho  {

    const static int NUM_CARTAS = 40;

    const int COPAS = 0;
    const int OUROS = 1;
    const int ESPADAS = 2;
    const int PAUS    = 3;

    const int FORCA_SETEOUROS = 11;
    const int FORCA_ESPADILHA = 12;
    const int FORCA_SETECOPAS = 13;
    const int FORCA_ZAPE = 14;

  public:
    /**
     * @brief Construtor da classe Baralho
     * 
     */
    Baralho();

    /**
     * @brief Destrutor da classe Baralho
     * 
     */
    ~Baralho();
    /**
     * @brief Retorna a lista de cartas do baralho em seu estado atual
     * 
     * @return std::list<Carta*> 
     */
    std::list<Carta*> getCartas();

    /**
     * @brief Troca a posição da lista de cartas do baralho de forma randomica
     * 
     */
    void embaralhar();

  private:
    /**
     * @brief Lista de cartas que compoe o baralho
     * 
     */
    std::list<Carta*> cartas;

    /**
     * @brief Figuras possiveis para as cartas do baralho
     * 
     */
    string figuras [10] = { "4", "5", "6", "7", "Q", "J", "K", "A", "2", "3"}; 

    /**
     * @brief Nipes possiveis para as cartas do baralho
     * 
     */
    int nipes[4] =  { COPAS, OUROS, ESPADAS, PAUS };

};

#endif