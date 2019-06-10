#include "views/MainScreen.hpp"
#include "models/Partida.hpp"
#include "models/Carta.hpp"
#include "models/Humano.hpp"
#include "models/Bot.hpp"
#include <time.h>  

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

    //  int choice = 0;

    //  do {
    //     this->clrscr();
    //     cout << "Menu Principal" << endl;
    //     cout << "Escolha uma opção" << endl;
    //     cout << "1 - Iniciar Jogo - Melhor de 1" << endl;
    //     cout << "2 - Iniciar Jogo - Melhor de 3" << endl;
    //     cout << "6 - Sair" << endl;
    //     cout << "Escolha: ";
        
    //     choice = this->getInput();

    //     switch(choice) {
    //         case 1:
    //             cout << "Iniciando Jogo - Melhor de 1!" << endl;
    //             break;
    //         case 2:
    //             cout << "Iniciando Jogo - Melhor de 3!" << endl;
    //             break;
    //         case 6:
    //             cout << "Saindo..." << endl;
    //             break;
    //         default:
    //             break;
    //     }  

    // } while(choice!=6);

    std::list<Jogador*> jogadores;
    string nomeBot[10] = {"Joao", "Germano", "Chaves", "Telles", "Pedro", "Arthur", "Matheus", "Gustavo", "Gabriel", "Hector"};

    string nomeJogador = "";  
    std::cout << "Digite o seu nome para iniciar a partida: ";
    std::cin >> nomeJogador;

    Humano* player = new Humano(nomeJogador);

    jogadores.push_back(player);

    for(int i = 0; i < 3; i++) {
        srand((unsigned)time(NULL));
        int posicaoNome = rand() % 10;
        string nome = nomeBot[posicaoNome];
        nome += i;
        Bot* bot = new Bot(nome);
        jogadores.push_back(bot);
    }
        
    Partida p = Partida(jogadores);
    p.getPontosTime1();
    
    system("pause");
} 
