#include "models/Partida.hpp"
#include "models/Rodada.hpp" 
#include "models/Jogador.hpp"
#include "models/Baralho.hpp"
#include <list>
#include <iostream>

Partida::Partida(std::list<Jogador*> jogadores) {
    
    this->jogadores = jogadores;
    Baralho baralhoPartida;
    int count = 1, nRodada = 1;

    for (auto const& jogador : jogadores) {
        if(count % 2 == 1) {
            jogador->setTimeJogador(1);
        }
        else {
            jogador->setTimeJogador(2);
        }
        count++;
    }

    cout << "Partida Iniciada";

    while(pontos_time1 < PONTOS_VITORIA && pontos_time2 < PONTOS_VITORIA) {
        baralhoPartida.embaralhar();
        this->baralho = baralhoPartida.getCartas();
        for (auto const& jogador : jogadores) {
            auto carta1 = std::next(baralho.begin(), 0);
            auto carta2 = std::next(baralho.begin(), 1);
            auto carta3 = std::next(baralho.begin(), 2);
            jogador->addCartaMao(*carta1);
            jogador->addCartaMao(*carta2);
            jogador->addCartaMao(*carta3);
            baralho.erase(carta1);
            baralho.erase(carta2);
            baralho.erase(carta3);
        }
            
        Rodada* rodada = new Rodada(nRodada, 2, jogadores, &pontos_time1, &pontos_time2);
        this->rodadas.push_back(rodada);
        nRodada++;
    }

    if(pontos_time1 == PONTOS_VITORIA) {
        cout << "\n" << "O Time 1 foi o vencedor";
    }
    else {
        cout << "\n" << "O Time 2 foi o vencedor";
    }
}

int Partida::getPontosTime1() {
    return this->pontos_time1;
}

int Partida::getPontosTime2() {
    return this->pontos_time2;
}




