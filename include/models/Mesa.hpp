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
        std::list<CartaNaMesa*> cartasNaMesa;
        std::list<CartaNaMesa*> getCartasMesa();
    
    public:
        Mesa();
        CartaNaMesa* obterMaiorCarta();          
        void addCartaNaMesa(CartaNaMesa* cartaNaMesa);
};

#endif
