#include "models/Rodada.hpp" 
#include "models/Jogador.hpp"
#include "models/Baralho.hpp"
#include "models/Mesa.hpp"
#include "models/CartaNaMesa.hpp"
#include <list>
#include <iostream>

Rodada::Rodada(int numero, int pontos, std::list<Jogador*> jogadores, int* pontos_time1, int* pontos_time2) {    
    Baralho baralhoPartida;
    baralhoPartida.embaralhar();
    this->baralho = baralhoPartida.getCartas();
    this->numero = numero;
    this->pontos = pontos;
    this->jogadores = jogadores;            
    this->mao    = 1;    
    this->pontos_time1 = pontos_time1;
    this->pontos_time2 = pontos_time2;
    this->maos_ganhas_time1 = 0;
    this->maos_ganhas_time2 = 0;
    controleRodada();
}

void Rodada::controleRodada() {
    for (auto const& jogador : this->jogadores) {
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

    Mesa mesa = Mesa();

    while(this->maos_ganhas_time1 < 2 && this->maos_ganhas_time2 < 2) {

        mesa.limpaCartasNaMesa();

        for (auto const& jogador : jogadores) {
            std::vector<std::string> opcoesAdicionais;        
            opcoesAdicionais.push_back("Pedir Truco");
            int jogada = jogador->jogar(opcoesAdicionais);
            if(jogada < jogador->getNumeroCartas()) {
                Carta* c = jogador->getCartaMao(jogada);
                CartaNaMesa* cm = new CartaNaMesa(c, jogador);
                mesa.addCartaNaMesa(cm);
                jogador->removeCartaMao(jogada);
                cout << "\n" << jogador->getNome() << " jogou a Carta: " << c->getValor() << " " << c->getNipe();
            }
        }

        CartaNaMesa* maiorCartaNaMesa = mesa.obterMaiorCarta();
        Jogador* jogadorMaiorCarta = maiorCartaNaMesa->getJogador();
        
        Carta* maiorCarta = maiorCartaNaMesa->getCarta();

        cout << "\n\n" << jogadorMaiorCarta->getNome() << " jogou a carta " << maiorCarta->getValor()  << " de " << maiorCarta->getNipe() << " e venceu a rodada";

        if(jogadorMaiorCarta->getTimeJogador() == 1) {
            this->maos_ganhas_time1 ++;
        }
        else {
            this->maos_ganhas_time2 ++;
        }
    }

    if(maos_ganhas_time1 >= 2) {
        cout << "\n" << "O Time 1 venceu a rodada e somou " << this->pontos << " pontos." << endl;
    }
    else {
        cout << "\n" << "O Time 1 venceu a rodada e somou " << this->pontos << " pontos." << endl;
    }

    *this->pontos_time1 = 12;
}