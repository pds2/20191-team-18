/**
 * @author: João Vitor de Carvalho
 * @project: PDS2_Truco
 * 
 * @description: Classe que gerencia toda a interação com o
 *  usuário. Imprime telas e elementos.
 */

#include "views/UIManager.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ncurses.h>
#include <locale.h>

using namespace std;

/**
 * Class constructor
 */
UIManager::UIManager(bool shouldInitScr){
    if(shouldInitScr){
        setlocale(LC_ALL, "");

        this->resizeScreen();

        initscr();
        noecho();
        cbreak();
        keypad(stdscr, TRUE);

        start_color();
        init_pair(0, COLOR_WHITE, COLOR_BLACK);
        init_pair(1, COLOR_BLACK, COLOR_WHITE);

        this->win = stdscr;
        this->_initializedScreen = false;
        this->_stopListener = false;
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
    
    (void)yPos; //Suppress g++ warning

    return xPos;
}

/**
 * Retorna posição do cursor no eixo X.
 */
int UIManager::getY_Position(){
    int xPos, yPos;
    getyx(this->win, yPos, xPos);
    
    (void)xPos; //Suppress g++ warning

    return yPos;
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

/**
 * Inicia listener de ações da tela. 
 * Espera por ações do teclado e executa funções
 * definidas a ela.
 */
void UIManager::initScreenActionListener(){
    int ch;
    while(!this->_stopListener){
        ch = wgetch(this->win);

        if(this->_screenMode==SCR_MODE_MENU){
            this->menuNavigate(ch);
        }
    }
}

/**
 * Define variavel que permite executação
 * do listener;
*/
void UIManager::startListener(){
    this->_stopListener = false;
}

/**
 * Define variavel que bloqueia executação
 * do listener;
*/
void UIManager::stopListener(){
    this->_stopListener = true;
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
    this->_menuStartDrawPos = startingAt;

    if(!startingAt){
        this->_menuEntryPos = 0;
    } else if(startingAt>((int)menu.size()-MENU_NUMBER_OF_ITEM)){
        // Implement exception
    } 
    
    if((MENU_NUMBER_OF_ITEM-(int)menu.size())<=0 || startingAt<=(MENU_NUMBER_OF_ITEM-(int)menu.size())){
        this->_screenMode = SCR_MODE_MENU;

        if(menu.size()<=MENU_NUMBER_OF_ITEM){
            menuEntriesToDraw = menu.size();
        } else {
            menuEntriesToDraw = MENU_NUMBER_OF_ITEM;
        }
        for(int i=0; i<menuEntriesToDraw; i++){
            mvwaddstr(this->win, yPos+i, xPos, menu[i+startingAt].c_str());
        }

        
        if(!startingAt){
            this->highlightMenuEntry(0);
            move(yPos, xPos);
        } else {
            wrefresh(this->win);
        }

        this->initScreenActionListener();
    }

}

void UIManager::drawMenu(vector<string> menu, int startingAt, bool forceStartListener){
    if(forceStartListener){
        this->startListener();
    }
    this->drawMenu(menu, startingAt);
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
 * Navega pelo menu desenhado na tela
 * de acordo com a tecla pressionada.
*/
void UIManager::menuNavigate(int pressedKey){
    switch(pressedKey){
        case KEY_UP:
            this->menuNavigateUp();
            break;
        case KEY_DOWN:
            this->menuNavigateDown();
            break;
        case '\n':
            this->stopListener();
            break;
    }
}

/**
 * Navega para o registro superior
 * ao selecionado atualmente no menu
*/
void UIManager::menuNavigateUp(){
    if(this->_menuEntryPos > MENU_BEGIN){
        this->_menuEntryPos--;
        int curX = this->getX_Position();
        int curY = this->getY_Position();
        
        if(this->_menuStartDrawPos!=0 && this->_menuEntryPos==this->_menuStartDrawPos-1){
            int startingDraw = this->_menuStartDrawPos-1;

            this->stopListener();
            this->drawMenu(this->curMenu, startingDraw);
            this->startListener();

        } else {
            curY--;
        }

        this->unhighlightMenuEntry(this->_menuEntryPos+1);
        this->highlightMenuEntry(this->_menuEntryPos);
        move(curY, curX);
    }   
}

/**
 * Navega para o registro inferior
 * ao selecionado atualmente no menu
*/
void UIManager::menuNavigateDown(){
    if(this->_menuEntryPos < (int)this->curMenu.size()-1){
        this->_menuEntryPos++;
        int curX = this->getX_Position();
        int curY = this->getY_Position();
        
        if(this->_menuEntryPos>MENU_NUMBER_OF_ITEM-1){

            int startingDraw = this->_menuEntryPos-MENU_NUMBER_OF_ITEM+1;

            this->stopListener();
            this->drawMenu(this->curMenu, startingDraw);
            this->startListener();

        } else {
            curY++;
        }
        
        this->unhighlightMenuEntry(this->_menuEntryPos-1);
        this->highlightMenuEntry(this->_menuEntryPos);
        move(curY, curX);
    }
}

/**
 * Destaca linha selecionada pelo 
 * usuario no menu,
*/
void UIManager::highlightMenuEntry(int entryNum){
    int xPos, yPos;
    this->getMenuDrawPosition(yPos, xPos);

    yPos = yPos+entryNum-this->_menuStartDrawPos;
    wattron(this->win, COLOR_PAIR(1));
    mvwaddstr(this->win, yPos, xPos, this->curMenu[entryNum].c_str());
    wattroff(this->win, COLOR_PAIR(1));
    wrefresh(this->win);
}

/**
 * Destaca linha selecionada pelo 
 * usuario no menu,
*/
void UIManager::unhighlightMenuEntry(int entryNum){
    int xPos, yPos;
    this->getMenuDrawPosition(yPos, xPos);

    yPos = yPos+entryNum-this->_menuStartDrawPos;
    wattron(this->win, COLOR_PAIR(0));
    mvwaddstr(this->win, yPos, xPos, this->curMenu[entryNum].c_str());
    wattroff(this->win, COLOR_PAIR(0));
    wrefresh(this->win);
}

/**
* Retorna entrada selecionada pelo usuário.
*/
int UIManager::getSelectedMenuItem(){
    return this->_menuEntryPos;
}

/**
* Desenha string na tela na posição indicada.
*/
void UIManager::printString(string str_to_print, int x, int y){
    this->drawBorders('@', '@');
    mvwaddstr(this->win, y, x, str_to_print.c_str());
    wrefresh(this->win);
}

/**
* Lê string do teclado e retorna
* a origem da função
*/
string UIManager::readString(){
    std::string input;

    nocbreak();
    echo();

    int ch = getch();
    while( ch != '\n' ){
        input.push_back(ch);
        ch = getch();
    }

    cbreak();
    noecho();

    return input;
}

/**
* Limpa tela e redesenha as bordas
*/
void UIManager::clearScreen(){
    wclear(this->win);
    this->drawBorders('@', '@');
    wrefresh(this->win);
}

void UIManager::resizeScreen(){
    system("resize -s 30 120");
}