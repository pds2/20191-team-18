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

void MainScreen::initGame() {

    std::list<Jogador*> jogadores;
    string nomeBot[10] = {"Joao", "Germano", "Chaves", "Telles", "Pedro", "Arthur", "Matheus", "Gustavo", "Gabriel", "Hector"};

    string nomeJogador = "";  
    std::cout << "Digite o seu nome para iniciar a partida: ";
    std::cin >> nomeJogador;

    Humano* player = new Humano(nomeJogador);

    jogadores.push_back(player);
    
    srand((unsigned)time(NULL));
    
    int posicaoNome = rand() % 10;
    
    for(int i = 0; i < 3; i++) {
        string nome;
        do {
            posicaoNome += i;
            if(posicaoNome > 9) {
                posicaoNome = 0;
            }
            srand( (unsigned) time(NULL));
            cout << posicaoNome;
            nome = nomeBot[posicaoNome];
            if(nome == nomeJogador) {
                posicaoNome += 1;
            }
        } while(nome == nomeJogador);
        
        Bot* bot = new Bot(nome);
        jogadores.push_back(bot);
    }
        
    Partida p = Partida(jogadores);
    p.getPontosTime1();
    
    system("pause");
} 
