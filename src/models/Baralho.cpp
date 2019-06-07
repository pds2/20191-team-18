#include "models/Baralho.hpp"
#include <queue>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <random>
#include <functional>
#include <string>
#include <time.h> 

Baralho::Baralho() {

    for(int i = 0; i < (int) (sizeof(this->figuras) / sizeof(string)) ; i++) {

        for(int j = 0; j < (int) (sizeof(this->nipes) / sizeof(int)) ; j++) {

            string figura = this->figuras[i];
            int nipe = this->nipes[j];
            int forca = 0;

            if(figura == "4" && nipe == PAUS) {
                forca = FORCA_ZAPE;
            }
            else if(figura == "7") {
                if(nipe == COPAS) {
                    forca = FORCA_SETECOPAS;
                }
                else if(nipe == OUROS) {
                    forca = FORCA_SETEOUROS;
                }
                else {
                    forca = 4;
                }
            }
            else if(figura == "A" && nipe == ESPADAS) {
                forca = FORCA_ESPADILHA;
            } 
            else {
                forca = i + 1;
            }
            Carta* c = new Carta(figura, nipe, forca);
            cout << "\n" << "Figura: " << figura << " Nipe: " << nipe << " Forca:  " << forca; 
            cartas.push_back( c );
        }
    }

}

std::list<Carta*> Baralho::getCartas() {
    return cartas;
}



void Baralho::embaralhar() {
    cout << "\n" << "Embaralhando -----------------------------------";
    std::list<Carta* >::iterator begin;
    begin = this->cartas.begin();

    srand(time(0));

    std::list<Carta* >::iterator end;
    end = this->cartas.end();
    // copy it into a vector and shuffle it
    std::vector<Carta*> temp(begin, end);
    std::random_shuffle(temp.begin(), temp.end());

    // copy the (shuffled) vector back into the list
    std::copy(temp.begin(), temp.end(), begin);
}

Baralho::~Baralho() {
    for (auto const& i : this->cartas) {
        cout << "TESTE";
        delete i;
    } 
}