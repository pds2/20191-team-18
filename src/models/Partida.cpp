#include "models/Partida.hpp"
#include "models/Rodada.hpp" 
#include "models/Jogador.hpp"
#include "models/Baralho.hpp"
#include <list>
#include <iostream>

Partida::Partida(std::list<Jogador*> jogadores) {
    this->jogadores = jogadores;
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

    cout << "Partida Iniciada";

    while(this->pontos_time1 < PONTOS_VITORIA && this->pontos_time2 < PONTOS_VITORIA) {  
        cout << "\n" << "================================================";
        cout << "\n" << "Inicio da rodada "  << nRodada << "!";
        cout << "\n" << "Pontos do time 1: " << this->pontos_time1; 
        cout << "\n" << "Pontos do time 2: " << this->pontos_time2;           
        Rodada* rodada = new Rodada(nRodada, 2, jogadores, &pontos_time1, &pontos_time2);
        this->rodadas.push_back(rodada);
        this->jogadores = rodada->getOrdemJogadores();
        cout << "\n" << "Fim da rodada "  << nRodada << "!"; 
        cout << "\n" << "================================================";
        nRodada++;
    }

    if(this->pontos_time1 >= PONTOS_VITORIA) {
        cout << "\n" << "O Time 1 foi o vencedor !!!" << endl;
    }
    else {
        cout << "\n" << "O Time 2 foi o vencedor !!!" << endl;
    }
}




