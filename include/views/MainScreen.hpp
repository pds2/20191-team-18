#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <iostream>
#include "exceptions/Exception.hpp"
#include "UIManager.hpp"

using std::cout;
using std::endl;

class MainScreen {
  public:
    virtual void initGame();
    MainScreen();
    virtual ~MainScreen();
  protected:
    void clrscr();
    int getInput();
  private:
  	UIManager* uim;
};

#endif