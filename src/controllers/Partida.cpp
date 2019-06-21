#include "controllers/Partida.hpp"
#include "controllers/Rodada.hpp" 
#include "models/Jogador.hpp"
#include "models/Baralho.hpp"
#include "views/UIManager.hpp"
#include <list>
#include <iostream>

Partida::Partida(std::list<Jogador*> jogadores, UIManager* manager) {
    this->jogadores = jogadores;
    this->uim = manager;
    controlaPartida();
}

void Partida::controlaPartida() {
    
    int count = 1, nRodada = 1;

    for (auto const& jogador : this->jogadores) {
        if(count % 2 == 1) {
            jogador->setTimeJogador(1);
        }
        else {
            jogador->setTimeJogador(2);
        }
        count++;
    }

    this->uim->clearScreen();
    this->uim->printString("Partida Iniciada", 50, 3);

    while(this->pontos_time1 < PONTOS_VITORIA && this->pontos_time2 < PONTOS_VITORIA) {  
        this->uim->printString("Rodada: ", 3, 27);
        this->uim->printString(std::to_string(nRodada), 11, 27);

        this->uim->printString("Rodada: ", 50, 4);
        this->uim->printString(std::to_string(nRodada), 58, 4);

        this->uim->printString("Time 1: ", 15, 27);
        this->uim->printString(std::to_string(this->pontos_time1), 23, 27); 
        this->uim->printString("pts", 25, 27);

        this->uim->printString("Time 2: ", 33, 27);
        this->uim->printString(std::to_string(this->pontos_time2), 41, 27); 
        this->uim->printString("pts", 43, 27);

        Rodada* rodada = new Rodada(nRodada, 2, jogadores, &pontos_time1, &pontos_time2, this->uim);
        this->rodadas.push_back(rodada);
        this->jogadores = rodada->getOrdemJogadores();

        this->uim->printString("Fim da rodada   !", 50, 3);
        this->uim->printString(std::to_string(nRodada), 65, 3);


        nRodada++;
    }

    this->uim->clearScreen();
    if(this->pontos_time1 >= PONTOS_VITORIA) {
        this->uim->printString("O Time 1 foi o vencedor !!!", 3, 3);
    }
    else {
        this->uim->printString("O Time 2 foi o vencedor !!!", 3, 3);
    }
    
    getch();
}




