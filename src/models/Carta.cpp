#include "models/Carta.hpp"

using std::string;
using std::toupper;

int  Carta::getNipe() {
    return this->nipe;
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


