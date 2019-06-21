#include <list>
#include <iostream>
#include <vector>
#include <time.h>  
#include "views/MainScreen.hpp"
#include "views/UIManager.hpp"
#include "models/Carta.hpp"
#include "controllers/Partida.hpp"
#include "controllers/Humano.hpp"
#include "controllers/Bot.hpp"

MainScreen::MainScreen() {
    this->uim = new UIManager(true);
}

MainScreen::~MainScreen() {
    delete this->uim;
}

void MainScreen::initGame() {
    
    int nHumanos = 1;
/*    
    std::cout << "Informe o número de jogadores Humanos: ";
    std::cin >> nHumanos;*/
    
    int menuChoice = this->mainMenu();

    if(!menuChoice){
        std::list<Jogador*> jogadores = geraListaJogadores(nHumanos);
        
        Partida p = Partida(jogadores, this->uim);
    } 
    
    this->uim->clearScreen();
    this->uim->printString("Pressione qualquer tecla para sair...", 3, 3);
    getch();
} 


std::list<Jogador*> MainScreen::geraListaJogadores(int quantidadeHumanos) {
    
    std::list<Jogador*> jogadores;
    
    string nomeBot[10] = {"Joao", "Germano", "Chaves", "Telles", "Pedro", "Arthur", "Matheus", "Gustavo", "Gabriel", "Hector"};
    
    string nomeJogador = "";  

    this->uim->clearScreen();
    this->uim->printString("Digite o seu nome para iniciar a partida: ", 3, 3);
    this->uim->printString(">", 3, 4);

    nomeJogador = this->uim->readString();
    this->uim->clearScreen();

    Humano* player = new Humano(nomeJogador);

    jogadores.push_back(player);
    
    srand((unsigned)time(NULL));
    
    int posicaoNome = rand() % 10;
    
    for(int i = 0; i < 4 - quantidadeHumanos; i++) {
        string nome;
        do {

            posicaoNome += i;
            if(posicaoNome > 9) {
                posicaoNome = 0;
            }
            srand( (unsigned) time(NULL));

            nome = nomeBot[posicaoNome];
            if(nome == nomeJogador) {
                posicaoNome += 1;
            }

        } while(nome == nomeJogador);
        
        Bot* bot = new Bot(nome);
        jogadores.push_back(bot);
    }
    
    return jogadores;
}

int MainScreen::mainMenu(){
    this->uim->drawBorders('@', '@');
    std::vector<string> menu = {"Iniciar Jogo", "Sair"};
    this->uim->drawMenu(menu, MENU_BEGIN, true);
    return this->uim->getSelectedMenuItem();
}