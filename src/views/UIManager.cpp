/**
 * @author: João Vitor de Carvalho
 * @project: PDS2_Truco
 * 
 * @description: Classe que gerencia toda a interação com o
 *  usuário. Imprime telas e elementos.
 */

#include "../../include/views/UIManager.hpp"
#include <iostream>
#include <ncurses.h>
#include <vector>
#include <string>

using namespace std;

/**
 * Class constructor
 */
UIManager::UIManager(bool shouldInitScr){
    if(shouldInitScr){
        initscr();

        this->win = stdscr;
        this->_initializedScreen = false;
        getmaxyx(this->win, this->_screenSizeY, this->_screenSizeX);

    } else {
        cout << "Not initialized" << endl;
    }
}

/**
 * Class destructor
 */
UIManager::~UIManager(){
    cout << "Endend Screen..." << endl;
    endwin();
}

/**
 * Inicia tela padrão usada em todo o sistema.
 * imprime bordas padrões.
 */
void UIManager::initScreen(){
    if(!this->_initializedScreen){
        this->drawBorders('@', '@');
    } else {
        cout << "Screen already initialized" << endl;
    }
}

/**
 * Retorna tamanho no eixo X da tela
 * desenhada
 */
int UIManager::getX_Size(){
    return this->_screenSizeX;
}

/**
 * Retorna tamanho no eixo Y da tela
 * desenhada
 */
int UIManager::getY_Size(){
    return this->_screenSizeY;
}

/**
 * Retorna posição do cursor no eixo X.
 */
int UIManager::getX_Position(){
    int xPos, yPos;
    getyx(this->win, yPos, xPos);
    return xPos;
}

/**
 * Retorna posição do cursor no eixo X.
 */
int UIManager::getY_Position(){
    int xPos, yPos;
    getyx(this->win, yPos, xPos);
    return yPos;
}

/**
 * Desenha menu padrão de acordo com string
 * recebido utilizando o meio da tela como referência. 
 */
void UIManager::drawMenu(vector<string> menu, int startingAt=0){
    int xPos, yPos;
    int menuEntriesToDraw = 0;
    this->getMenuDrawPosition(yPos, xPos);

    this->curMenu = menu;
    if(!startingAt){
        this->_menuEntryPos = 0;
    } else if(startingAt>(menu.size()-MENU_NUMBER_OF_ITEM)){
        // Implement exception
    } 
    
    if(startingAt<=(menu.size()-MENU_NUMBER_OF_ITEM)){

        if(menu.size()<=MENU_NUMBER_OF_ITEM){
            menuEntriesToDraw = menu.size();
        } else {
            menuEntriesToDraw = MENU_NUMBER_OF_ITEM;
        }
        for(int i=0; i<menuEntriesToDraw; i++){
            mvwaddstr(this->win, yPos+i, xPos, menu[i+startingAt].c_str());
        }


        move(yPos, xPos);
        wrefresh(this->win);
    }

}

/**
 * Define nos endereços das variaveis
 * passadas por parametro as coord.
 * para desenhar o menu de acordo
 * com parametros pre estabelecidos.
 */
void UIManager::getMenuDrawPosition(int &y, int &x){
    int xSize = this->_screenSizeX;
    int ySize = this->_screenSizeY;

    x = (xSize - MENU_STRING_ITEM_LENGTH)/2;
    y = (ySize - MENU_NUMBER_OF_ITEM)/2;
}

/**
 * Desenha bordas de acordo com os parametros.
 * 
 * @param char vChar caractere a ser usado para
 * linhas verticais.
 * @param char hChar caractere a ser usado para
 * linhas horizontais.
 */
void UIManager::drawBorders(char vChar, char hChar){
    box(this->win, vChar, hChar);
    wrefresh(this->win);
}