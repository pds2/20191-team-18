#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <list>
#include <iostream>
#include "exceptions/Exception.hpp"
#include "UIManager.hpp"
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
     * @brief Construtor da classe MainScreen
     * 
     */
    MainScreen();

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
    int getInput();

    /**
     * @brief Desenha menu principal
     *
     * @return Seleção do menu
     */
    int mainMenu();
  private:

    /**
     * @brief Gerenciador de interface
     */
  	UIManager* uim;

};

#endif