#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <iostream>
#include "exceptions/Exception.hpp"

using std::cout;
using std::endl;

class MainScreen {
  public:
    virtual void initGame();
    virtual ~MainScreen();
  protected:
    void clrscr();
    int getInput();
};

#endif