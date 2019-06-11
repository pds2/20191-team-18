#ifndef MESA_H
#define MESA_H

#include <iostream>
#include <list>
#include "exceptions/Exception.hpp"
#include "models/CartaNaMesa.hpp"

using std::cout;
using std::endl;
using std::string;

class Mesa {
    private:
        /**
         * @brief Lista de cartas que já foram jogadas na Mesa
         * 
         */
        std::list<CartaNaMesa*> cartasNaMesa;

        /**
         * @brief Retorna a lista de cartas que foram jodadas na Mesa
         * 
         * @return std::list<CartaNaMesa*> - lista de cartas que foram jogadas na Mesa
         */
        std::list<CartaNaMesa*> getCartasMesa();
    
    public:
        /**
         * @brief Construtor da classe Mesa
         * 
         */
        Mesa();

        /**
         * @brief Retorna a maior ou as maiores cartas que foram jogadas na mesa
         * 
         * @return std::list<CartaNaMesa*> 
         */
        std::list<CartaNaMesa*> obterMaiorCarta();  

        /**
         * @brief Joga uma carta na mesa
         * 
         * @param cartaNaMesa - Carta a ser jogada na mesa
         */        
        void addCartaNaMesa(CartaNaMesa* cartaNaMesa);

        /**
         * @brief Limpa a lista de cartas jogadas na mesa
         * 
         */
        void limpaCartasNaMesa();
};

#endif
