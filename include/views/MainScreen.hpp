#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <iostream>
#include "exceptions/Exception.hpp"

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
  protected:
    /**
     * @brief Limpa a tela
     * 
     */
    void clrscr();
};

#endif