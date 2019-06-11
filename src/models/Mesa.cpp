#include "models/Mesa.hpp" 
#include "models/CartaNaMesa.hpp" 

#include <list>
#include <iostream>

Mesa::Mesa() {
    
}

std::list<CartaNaMesa*> Mesa::obterMaiorCarta(){
    std::list<CartaNaMesa*> cartasNaMesa = this->getCartasMesa();
    std::list<CartaNaMesa*> maioresCartas;
    bool primeira = true;
    for (auto const& cartaNaMesa : cartasNaMesa) {
        Carta carta = *cartaNaMesa->getCarta();
        std::list<CartaNaMesa*>::iterator itMaiorCarta = maioresCartas.begin();
        CartaNaMesa* maiorCarta = *itMaiorCarta;
        
        if( primeira == true || (maiorCarta->getCarta()->getForca() < carta.getForca())){
            maioresCartas.clear();
            maioresCartas.push_back(cartaNaMesa);
            primeira = false;
        } else if(maiorCarta->getCarta()->getForca() == carta.getForca()) {
            maioresCartas.push_back(cartaNaMesa);
        }
    }

    return maioresCartas;
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