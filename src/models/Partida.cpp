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

    while(pontos_time1 != PONTOS_VITORIA && pontos_time2 != PONTOS_VITORIA) {            
        Rodada* rodada = new Rodada(nRodada, 2, jogadores, &pontos_time1, &pontos_time2);
        this->rodadas.push_back(rodada);
        nRodada++;
    }

    if(pontos_time1 >= PONTOS_VITORIA) {
        cout << "\n" << "O Time 1 foi o vencedor !!!" << endl;
    }
    else {
        cout << "\n" << "O Time 2 foi o vencedor !!!" << endl;
    }
}

int Partida::getPontosTime1() {
    return this->pontos_time1;
}

int Partida::getPontosTime2() {
    return this->pontos_time2;
}




