#include "../../include/models/Carta.hpp"

using std::string;
using std::toupper;

Carta::Carta(string valor, int nipe) {
    setNipe(nipe);
    setValor(valor);
}

Carta::Carta(string valor, string  nipe) {
    setNipe(nipe);
    setValor(valor);
}

Carta::Carta(string  valor, int nipe,       int forca) {
    setNipe(nipe);
    setValor(valor);
    setForca(forca);
}

Carta::Carta(string  valor,  string  nipe,   int forca) {
    setNipe(nipe);
    setValor(valor);
    setForca(forca);
}

std::string Carta::getNipe() {
    if(nipe == COPAS) {
        return "\u2665\ufe0f";
    }
    else if(nipe == OUROS) {
        return "\u2666\ufe0f";
    }
    else if(nipe == ESPADAS) {
        return "\u2660\ufe0f";
    }
    else if(nipe == PAUS) {
        return "\u2663\ufe0f";
    }
    else {
        throw Exception::NipeInvalido();
    }
}

void Carta::setNipe(int nipe) {
    switch(nipe) {
        case 0: 
            this->nipe = COPAS;
            break;
        case 1: 
            this->nipe = OUROS;
            break;
        case 2:
            this->nipe = ESPADAS;
            break;
        case 3: 
            this->nipe = PAUS;
            break;
        default: 
            throw Exception::NipeInvalido();
            break;
    }
}

void Carta::setNipe(string nipe) {

    for (std::string::size_type i=0; i < nipe.length(); ++i) {
        nipe[i] = std::toupper(nipe[i]);
    } 

    if(nipe == "COPAS") {
        this->nipe = COPAS;
    }
    else if(nipe == "OUROS") {
        this->nipe = OUROS;
    }
    else if(nipe == "ESPADAS"){
        this->nipe = ESPADAS;
    }
    else if(nipe == "PAUS") {
        this->nipe = PAUS;
    }
    else {
        throw Exception::NipeInvalido();
    }
}

string Carta::getValor() {
    return this->valor;
}

void Carta::setValor(string valor) {
    this->valor = valor;
}

int Carta::getForca() {
    if(forca < MAX_FORCA) {
        return this->forca;
    }
    else {
        throw Exception::ForcaInvalida();
    }
}

void Carta::setForca(int forca) {
    this->forca = forca;
}


