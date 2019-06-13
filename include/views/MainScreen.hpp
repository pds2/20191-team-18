#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <list>
#include <iostream>
#include "exceptions/Exception.hpp"
#include "models/Jogador.hpp"

using std::cout;
using std::endl;

class MainScreen {
  public:
    /**
     * @brief Inicializa o game
     * 
     */
    virtual void initGame();

    /**
     * @brief Destrutor da classe MainScreen
     * 
     */
    virtual ~MainScreen();
    
    /**
     * @brief Gera a lista de jogadores para o jogo
     *
     * @param quantidadeHumanos - Número de humanos participantes do jogo
     */
    std::list<Jogador*> geraListaJogadores(int quantidadeHumanos);
    
  protected:
    /**
     * @brief Limpa a tela
     * 
     */
    void clrscr();
};

#endif