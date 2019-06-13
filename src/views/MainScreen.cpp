#include <list>
#include <iostream>
#include <time.h>  
#include "views/MainScreen.hpp"
#include "controllers/Partida.hpp"
#include "controllers/Humano.hpp"
#include "controllers/Bot.hpp"

MainScreen::~MainScreen() {

}

void MainScreen::initGame() {
    
    int nHumanos = 1;
/*    
    std::cout << "Informe o número de jogadores Humanos: ";
    std::cin >> nHumanos;*/
    
    std::list<Jogador*> jogadores = geraListaJogadores(nHumanos);
        
    Partida p = Partida(jogadores);
    
    system("pause");
} 


std::list<Jogador*> MainScreen::geraListaJogadores(int quantidadeHumanos) {
    
    std::list<Jogador*> jogadores;
    
    string nomeBot[10] = {"Joao", "Germano", "Chaves", "Telles", "Pedro", "Arthur", "Matheus", "Gustavo", "Gabriel", "Hector"};
    
    string nomeJogador = "";  
    
    for(int i = 0; i < quantidadeHumanos; i++) {
        std::cout << "Digite o seu nome: ";
        std::cin >> nomeJogador;
    
        jogadores.push_back(new Humano(nomeJogador));
    }
    
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