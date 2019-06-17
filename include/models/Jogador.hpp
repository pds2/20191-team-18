#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include "../exceptions/Exception.hpp"
#include "Carta.hpp"
#include <vector>

using std::cout;
using std::endl;
using std::string;

class Jogador {

  public:
    /**
     * @brief Construtor da classe Jogador
     * 
     */
    Jogador(string nome);
    
    /**
     * @brief Construtor da classe Jogador
     * 
     */
    Jogador(string nome, std::vector<Carta*> cartas);

  
    /**
     * @brief Retorna o Nome do Jogador
     * 
     * @return string - Nome do Jogador
     */
    string  getNome();

    /**
     * @brief Adiciona uma carta a mão do Jogador
     * 
     */
    void addCartaMao(Carta* carta);
    
    /**
     * @brief Remove uma carta a mão do Jogador
     * 
     * @param carta - Carta a ser removida
     */
    void removeCartaMao(Carta* carta);
    
    /**
     * @brief Remove uma carta a mão do Jogador
     * 
     * @param posicao - Posição da carta a ser removida
     */
    void removeCartaMao(int posicao);
    
    /**
     * @brief Define quais são as cartas que o Jogador possui na mão
     * 
     * @param cartas - Cartas a serem definidas como mão do jogador
     */
    void setMao(std::vector<Carta> cartas);
    
    /**
     * @brief Retorna uma das cartas na mão do Jogador
     * 
     * @param posicao - Posicao da carta a ser retornada
     * @return Carta*
     */
    Carta* getCartaMao(int posicao); 
    
    /**
     * @brief Retorna uma das cartas na mão do jogador
     * 
     * @return std::vector<Carta*> - Retorna a mão do Jogador
     */
    std::vector<Carta*> getMao();

    /**
     * @brief Retorna o número de cartas que o jogador possui em sua mão
     * 
     * @return int - Número de cartas que o jogador possui em sua mão
     */
    int getNumeroCartas();
    
    /**
     * @brief Define qual é o time do jogador
     * 
     */
    void setTimeJogador(int timeJogador);
    
    /**
     * @brief Retorna qual é o time do Jogador
     * 
     * @return int - Time do Jogador
     */
    int getTimeJogador();

    /**
     * @brief Deixa o jogador sem nenhuma carta na mão
     *
     */
    void limparCartasMao();
    
    
    /**
     * @brief Metódo a ser implementado para que o Jogador realize sua jogada
     *
     * @param opcoesAdicionais - Opções adicionais de jogada além das cartas que o jogador possui na mão
     * @return int - Jogada
     */
    virtual int jogar(std::vector<std::string> opcoesAdicionais) = 0;
    
    /**
     * @brief Metódo a ser implementado para que o Jogador aceite ou não os desafios propostos
     * pelo adversário
     *
     * @param jogadorDesafiante - Jogador que propos o desafio
     * @param pontos - Número de pontos do desafio
     * @return int - Resposta do desafio
     */
    virtual int aceitarDesafio(Jogador* jogadorDesafiante, int pontos) = 0;

  protected:
    /**
     * @brief Cartas que o Jogador possui em sua mão
     *
     */
    std::vector<Carta*> mao;
    
    /**
     * @brief Time do Jogador
     *
     */
    int timeJogador;

  private:
    /**
     * @brief Nome do Jogador
     *
     */
    string nome; 

};

#endif