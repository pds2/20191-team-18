#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include "../exceptions/Exception.hpp"

using std::cout;
using std::endl;
using std::string;

class Carta {

  const int MAX_FORCA = 50;

  const int COPAS = 0;
  const int OUROS = 1;
  const int ESPADAS = 2;
  const int PAUS    = 3;

  public:
    
    /**
     * @brief Construtor da classe carta 
     * 
     * @param valor 
     * @param nipe 
     */
    Carta(string  valor,  string  nipe);
    
    /**
     * @brief Construtor da classe carta 
     * 
     * @param valor 
     * @param nipe 
     */
    Carta(string  valor,  int     nipe);

    /**
     * @brief Construtor da classe carta
     * 
     * @param valor 
     * @param nipe 
     * @param forca 
     */
    Carta(string  valor,  string  nipe,   int forca);

    /**
     * @brief Construtor da classe carta
     * 
     * @param valor 
     * @param nipe 
     * @param forca 
     */
    Carta(string  valor,  int     nipe,   int forca);

    /**
     * @brief Retorna o nipe da carta
     * 
     * @return string 
     */
    string  getNipe();

    /**
     * @brief Define o nipe da carta
     * 
     * @param nipe - inteiro representando o valor do nipe
     */
    void setNipe(int nipe);

    /**
     * @brief Define o nipe da carta
     * 
     * @param nipe - string com o nome do nipe
     */
    void setNipe(string nipe);

    /**
     * @brief Define o valor da Carta 
     * 
     * @param valor 
     */
    void setValor(string valor);

    /**
     * @brief Retorna o valor da Carta
     * 
     * @return string 
     */
    string getValor();
    
    /**
     * @brief Define qual a força da Carta
     * 
     * @param forca
     */
    void setForca(int forca);
    
    /**
     * @brief Retorna a força da Carta
     * 
     * @return int
     */
    int getForca();

  private:
    /**
     * @brief Valor da figura da carta
     * 
     */
    string valor; 

    /**
     * @brief Nipe da carta
     * 
     */
    int nipe;

    /**
     * @brief Força da carta
     * 
     */
    int forca = 0;

};

#endif