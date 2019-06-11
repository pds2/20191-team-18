#include "../../include/models/Partida.hpp"
#include "../../include/models/Rodada.hpp" 
#include "../../include/models/Jogador.hpp"
#include "../../include/models/Baralho.hpp"
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
        Rodada* rodada = new Rodada(nRodada, 2, jogadores, &this->pontos_time1, &this->pontos_time2);
        this->rodadas.push_back(rodada);
        nRodada++;
        this->jogadores = rodada->getOrdemJogadores();
        cout << "\n" << "Pontos do time 1: " << this->pontos_time1; 
        cout << "\n" << "Pontos do time 2: " << this->pontos_time2; 
    }

    if(this->pontos_time1 >= PONTOS_VITORIA) {
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




