#include "views/MainScreen.hpp"

int main() {
    MainScreen *mainScreen = new MainScreen();

    mainScreen->showMenu();

    delete mainScreen;
    return 0;
}