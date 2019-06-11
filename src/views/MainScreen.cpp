#include "views/MainScreen.hpp"
#include "controllers/Partida.hpp"
#include "controllers/Humano.hpp"
#include "controllers/Bot.hpp"
#include <time.h>  

MainScreen::~MainScreen() {

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

            nome = nomeBot[posicaoNome];
            if(nome == nomeJogador) {
                posicaoNome += 1;
            }

        } while(nome == nomeJogador);
        
        Bot* bot = new Bot(nome);
        jogadores.push_back(bot);
    }
        
    Partida p = Partida(jogadores);
    
    system("pause");
} 
