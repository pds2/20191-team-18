#include "views/MainScreen.hpp"

int main() {
    MainScreen *mainScreen = new MainScreen();

    mainScreen->initGame();

    delete mainScreen;
    return 0;
} 