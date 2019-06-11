#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <iostream>
#include "exceptions/Exception.hpp"
#include "UIManager.hpp"

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
     * @brief Construtor da classe MainScreen
     * 
     */
    MainScreen();

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
    int getInput();
  private:
  	UIManager* uim;
};

#endif