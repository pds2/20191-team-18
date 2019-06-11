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
    /**
     * @brief Constutor da classe Rodada
     * 
     * @param numero 
     * @param pontos 
     * @param jogadores 
     * @param pontos_time1 
     * @param pontos_time2 
     */
    Rodada(int numero, int pontos, std::list<Jogador*> jogadores, int* pontos_time1, int* pontos_time2);

    /**
     * @brief Realiza o contorle da rodada
     * 
     */
    void controleRodada();
    
    /**
     * @brief Retorna a ordem dos jogadores a partir da ultima mão vencida
     * 
     * @return std::list<Jogador*> 
     */
    std::list<Jogador*> getOrdemJogadores();

    /**
     * @brief Altera o número de pontos da rodada
     * 
     * @param pontos 
     */
    void setPontos(int pontos);
    
  private:
    /**
     * @brief Numero da rodada
     * 
     */
    int numero;

    /**
     * @brief Valor de pontos da rodada
     * 
     */
    int pontos = 2;

    /**
     * @brief Número da mão no qual a rodada se encontra
     * 
     */
    int mao;

    /**
     * @brief Time que propos o ultimo desafio
     * 
     */
    int timeUltimoDesafiador = 0;

    /**
     * @brief Ponteiro para o número de pontos do time 1
     * 
     */
    int* pontos_time1 = nullptr;

    /**
     * @brief Ponteiro para o número de pontos do time 2
     * 
     */
    int* pontos_time2 = nullptr;
    
    /**
     * @brief Retorna o número de pontos disputador em um desafio
     * 
     * @return int 
     */
    int getValorDesafio();
    
    /**
     * @brief Número de mãos ganhas pelo time 1
     * 
     */
    int maos_ganhas_time1 = 0;

    /**
     * @brief Número de mãos ganhas pelo time 2
     * 
     */
    int maos_ganhas_time2 = 0;

    /**
     * @brief Número de mãos empatadas entre os dois times
     * 
     */
    int maos_empatadas = 0;
    
    /**
     * @brief Lista de cartas que formam o baralho
     * 
     */
    std::list<Carta*> baralho;
    
    /**
     * @brief Lista de jogadores que participam daquela rodada
     * 
     */
    std::list<Jogador*> jogadores;

    /**
     * @brief Ponteiro para o jogador que venceu a primeira mão da rodada
     * 
     */
    Jogador* primeiroVencedor;
    /**
     * @brief Indica qual jogador é o pé da mesa
     * 
     */
    Jogador* peMesa;
    
    /**
     * @brief Retorna uma lista de jogadores que são os adversários ao jogador recebido como parâmetro
     * 
     * @param jogador 
     * @return std::list<Jogador*> 
     */
    std::list<Jogador*> getAdversarios(Jogador* jogador);

    /**
     * @brief Propoem um desafio para elevar o número de pontos da rodada
     * 
     * @param jogador 
     * @param mesa 
     * @return true 
     * @return false 
     */
    bool desafiar(Jogador* jogador, Mesa* mesa);

    /**
     * @brief Joga uma carta da mão do jogador (jogada) para a Mesa
     * 
     * @param jogador 
     * @param mesa   
     * @param jogada - Posição da carta a ser jogada na mão do jogador
     */
    void jogarCarta(Jogador* jogador, Mesa* mesa, int jogada);

    /**
     * @brief Reoordena a lista de jogadores a partir do vencedor da ultima mão
     * 
     * @param jogadorInicial 
     */
    void reordenarListaJogadores(Jogador* jogadorInicial);

    /**
     * @brief Consolida a jogada de um jogador 
     * 
     * @param jogador 
     * @param mesa 
     * @param jogada 
     * @return true 
     * @return false 
     */
    bool consolidaJogada(Jogador* jogador, Mesa* mesa, int jogada);

    /**
     * @brief Retorna as opções adicionais para o estado atual de pontos de uma rodada
     * 
     * @param jogador 
     * @return std::vector<std::string> 
     */
    std::vector<std::string> getOpcoesAdicionais(Jogador* jogador);
    

    /**
     * @brief Computa qual time venceu a rodada e adiciona seus respectivos pontos
     * 
     * @param mesa 
     * @param desafioRecusado 
     */
    void computaVencedorRodada(Mesa* mesa, bool desafioRecusado);
};

#endif
