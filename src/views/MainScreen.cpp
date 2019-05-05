#include "views/MainScreen.hpp"
#include "../models/Carta.cpp"

MainScreen::~MainScreen() {

}

void MainScreen::clrscr() {
    system("cls");
}

int MainScreen::getInput() {
    int choice;    
    std::cin >> choice;
    return choice;
} 

void MainScreen::showMenu() {

    int choice = 0;

     do {
        this->clrscr();
        cout << "Menu Principal" << endl;
        cout << "Escolha uma opção" << endl;
        cout << "1 - Iniciar Jogo - Melhor de 1" << endl;
        cout << "2 - Iniciar Jogo - Melhor de 3" << endl;
        cout << "6 - Sair" << endl;
        cout << "Escolha: ";
        
        choice = this->getInput();

        switch(choice) {
            case 1:
                cout << "Iniciando Jogo - Melhor de 1!" << endl;
                break;
            case 2:
                cout << "Iniciando Jogo - Melhor de 3!" << endl;
                break;
            case 6:
                cout << "Saindo..." << endl;
                break;
            default:
                break;
        } 

    } while(choice!=6); 

    
    Carta carta;
    carta.setForca(10);
    cout << carta.getForca();
    carta.setNipe(0);
    cout << carta.getNipe();
    carta.setNipe("espadas");
    cout << carta.getNipe();
    carta.setForca(100);

} 

