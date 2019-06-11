#ifndef RODADA_H
#define RODADA_H

#include <iostream>
#include <list>
#include "exceptions/Exception.hpp"
#include "models/Jogador.hpp"
#include "models/Mesa.hpp"

using std::cout;
using std::endl;
using std::string;

class Rodada {

  public:

    Rodada(int numero, int pontos, std::list<Jogador*> jogadores, int* pontos_time1, int* pontos_time2);
    void controleRodada();
    std::list<Jogador*> getOrdemJogadores();
    void setPontos(int pontos);
    
  private:
  
    int numero;
    int pontos = 2;
    int mao;
    int timeUltimoDesafiador = 0;
    int* pontos_time1 = nullptr;
    int* pontos_time2 = nullptr;
    
    int getValorDesafio();
    
    int maos_ganhas_time1 = 0;
    int maos_ganhas_time2 = 0;
    int maos_empatadas = 0;
    
    std::list<Carta*> baralho;
    
    std::list<Jogador*> jogadores;
    Jogador* primeiroVencedor;
    Jogador* peMesa;
    
    std::list<Jogador*> getAdversarios(Jogador* jogador);
    bool desafiar(Jogador* jogador, Mesa* mesa);
    void jogarCarta(Jogador* jogador, Mesa* mesa, int jogada);
    void reordenarListaJogadores(Jogador* jogadorInicial);
    bool consolidaJogada(Jogador* jogador, Mesa* mesa, int jogada);
    std::vector<std::string> getOpcoesAdicionais(Jogador* jogador);
    
    void computaVencedorRodada(Mesa* mesa, bool desafioRecusado);
};

#endif
