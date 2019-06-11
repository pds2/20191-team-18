#ifndef BOT_H
#define BOT_H

#include <iostream>
#include <vector>
#include "Jogador.hpp"

using std::cout;
using std::endl;
using std::string;

class Bot : public Jogador {

  public:
    /**
     * @brief Construtor da classe Bot
     * 
     * @param nome 
     * @param cartas 
     */
    Bot(string nome);
    /**
     * @brief Construtor da classe Bot que recebe as cartas em sua mão
     * 
     * @param nome 
     * @param cartas 
     */
    Bot(string nome, std::vector<Carta*> cartas);

    /**
     * @brief Retorna um inteiro correspondete a jogada selecionada pelo Bot
     * 
     * @param opcoesAdicionais 
     * @return int - Jogada selecionada pelo bot
     */
    virtual int jogar(std::vector<std::string> opcoesAdicionais) override;

    /**
     * @brief Permite ao bot escolher se aceita o desafio ou não
     * 
     * @param jogadorDesafiante - Jogador que propos o desafio
     * @param pontos - Quantidade de pontos disputados caso o desafio seja aceito
     * @return int   - Resposta ao desafio 0 - Correr; 1 - Aceitar; 2 - Aumentar;
     */
    virtual int aceitarDesafio(Jogador* jogadorDesafiante, int pontos) override;
};

#endif