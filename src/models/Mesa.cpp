#include "models/Mesa.hpp" 
#include "models/CartaNaMesa.hpp" 

#include <list>
#include <iostream>

Mesa::Mesa(std::list<CartaNaMesa*> cartasNaMesa) {
    this->cartasNaMesa = cartasNaMesa;
}

CartaNaMesa* Mesa::ObterMaiorCarta(){
    std::list<CartaNaMesa*> cartasNaMesa = this->getCartasMesa();
    CartaNaMesa* maiorCarta;
    maiorCarta->setForca(0);
    for (auto const& carta : cartasNaMesa) {
        if(maiorCarta->getForca() < carta->getForca()){
            maiorCarta = carta;
        }
    }

    return maiorCarta;
}

std::list<CartaNaMesa*> Mesa::getCartasMesa(){
    return this->cartasNaMesa;
}