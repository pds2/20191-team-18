#include "models/Mesa.hpp" 
#include "models/CartaNaMesa.hpp" 

#include <list>
#include <iostream>

Mesa::Mesa() {
    
}

CartaNaMesa* Mesa::obterMaiorCarta(){
    std::list<CartaNaMesa*> cartasNaMesa = this->getCartasMesa();
    CartaNaMesa* maiorCarta;
    bool primeira = true;
    for (auto const& cartaNaMesa : cartasNaMesa) {
        Carta carta = *cartaNaMesa->getCarta();
        if( primeira == true || (maiorCarta->getCarta()->getForca() < carta.getForca())){
            maiorCarta = cartaNaMesa;
            primeira = false;
        }
    }

    return maiorCarta;
}

std::list<CartaNaMesa*> Mesa::getCartasMesa(){
    return this->cartasNaMesa;
}

void Mesa::addCartaNaMesa(CartaNaMesa* cartaNaMesa) {
    this->cartasNaMesa.push_back(cartaNaMesa);
}

void Mesa::limpaCartasNaMesa() {
    this->cartasNaMesa = {};
}