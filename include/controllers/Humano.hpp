#ifndef HUMANO_H
#define HUMANO_H

#include <iostream>
#include <vector>
#include "../models/Jogador.hpp"
#include "../views/UIManager.hpp"

using std::cout;
using std::endl;
using std::string;

class Humano : public Jogador {
  private:
    UIManager* uim;
  public:
    /**
     * @brief Construtor da classe Humano
     * 
     * @param nome 
     */
    Humano(string nome, UIManager*);

    /**
     * @brief Construtor da classe Humano que recebe as cartas em sua mão
     * 
     * @param nome 
     * @param cartas 
     */
    Humano(string nome, std::vector<Carta*> cartas);

    /**
     * @brief Exibe as cartas que o humano possui em sua mão
     * 
     * @param opcao - Indica qual o prefixo deve ser exibido ao mostrar as cartas
     */
    void exibirCartas(bool opcao);

    /**
     * @brief Exibe as opções adicionais que o jogador têm para aquela jogada. 
     * Como, por exemplo, pedir truco, pedir seis, entre outros.
     * 
     * @param opcoesAdicionais - Vetor com as opções a serem exibidas
     * @param nOpcao - Numero de opções exibidos anteriormente
     */
    void exibirOpcoesAdicionais(std::vector<std::string> opcoesAdicionais, int nOpcao);

    /**
     * @brief Controla a exibição das cartas e de opções adicionais para o jogador 
     * 
     * @param opcoesAdicionais - Vetor com as opções adicionais de jogada além das cartas que o jogador possui
     * @return int 
     */
    virtual int jogar(std::vector<std::string> opcoesAdicionais) override;

    /**
     * @brief Permite ao jogador humano escolher se aceita o desafio ou não
     * 
     * @param jogadorDesafiante - Jogador que propos o desafio
     * @param pontos - Quantidade de pontos disputados caso o desafio seja aceito
     * @return int   - Resposta ao desafio 0 - Correr; 1 - Aceitar; 2 - Aumentar;
     */
    virtual int aceitarDesafio(Jogador* jogadorDesafiante, int pontos) override;
};

#endif