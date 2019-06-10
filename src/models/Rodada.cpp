#include "models/Rodada.hpp" 
#include "models/Jogador.hpp"
#include "models/Baralho.hpp"
#include "models/Mesa.hpp"
#include "models/CartaNaMesa.hpp"
#include <list>
#include <iostream>
#include <exception>

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
    controleRodada();
}

void Rodada::controleRodada() {
    for (auto const& jogador : this->jogadores) {
        jogador->limparCartasMao();
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
        cout << "\n";
        mesa.limpaCartasNaMesa();
        
        for (auto const& jogador : this->jogadores) {
            std::vector<std::string> opcoesAdicionais;        
            opcoesAdicionais.push_back("Pedir Truco");
            cout << "\n" << "Dei pau aqui";
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

        cout << "\n\n" << jogadorMaiorCarta->getNome() << " jogou a carta " << maiorCarta->getValor()  << " de " << maiorCarta->getNipe() << " e venceu a rodada !!!";
        cout << "\n\n" << "Time do Jogador" << jogadorMaiorCarta->getTimeJogador();
        if(jogadorMaiorCarta->getTimeJogador() == 1) {
            this->maos_ganhas_time1 += 1;
        }
        else {
            this->maos_ganhas_time2 += 1;
        }
        this->ultimoVencedor = jogadorMaiorCarta;
        if(this->maos_ganhas_time1 < 2 && this->maos_ganhas_time2 < 2) {
            reordenarListaJogadores();
        }
        
    }

    if(this->maos_ganhas_time1 >= 2) {
        cout << "\n" << "O Time 1 venceu a rodada e somou " << this->pontos << " pontos !!!" << endl;
    }
    else {
        cout << "\n" << "O Time 2 venceu a rodada e somou " << this->pontos << " pontos !!!" << endl;
    }

    *this->pontos_time1 += 6;
}

void Rodada::reordenarListaJogadores() {
    
    Jogador* jogadorInicial = this->ultimoVencedor;

    std::list<Jogador*> novaOrdemJogadores;

    bool achouJogador = false;

    for (auto const jogador : this->jogadores) {
        if(jogador == jogadorInicial) {
            novaOrdemJogadores.push_back(jogador);   
            achouJogador = true;
        }
        else if(achouJogador == true) {
            novaOrdemJogadores.push_back(jogador); 
        }
    }

    for (auto const jogador : this->jogadores) {
        if(jogador == jogadorInicial) {
            break;
        }
        novaOrdemJogadores.push_back(jogador);
    }
    this->jogadores = novaOrdemJogadores;
}

std::list<Jogador*> Rodada::getOrdemJogadores() {
    
    return this->jogadores;
}