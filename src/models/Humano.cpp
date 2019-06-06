#include "models/Humano.hpp"
#include "models/Carta.hpp"


Humano::Humano(string nome) : Jogador(nome) {}
Humano::Humano(string nome, std::vector<Carta*> cartas) : Jogador(nome, cartas) {};

Carta* Humano::jogar () {
    
    if(this->mao.size() == 0) {
        throw Exception::JogadorSemCartas();
    }

    for(int i = 0; i < (int) mao.size(); i++) {
        cout << "\n" << "Carta [" << i << "]: " << mao[i]->getValor() << " Nipe: " << mao[i]->getNipe() <<  " Forca: " << mao[i]->getForca();
    }

    int choice = this->mao.size() + 1;
    
    do {
        cout << "\n" << "Digite qual carta deseja jogar: " << endl;
        std::cin >> choice;

        if(choice > (int) this->mao.size()) {
            cout << "\n" << "Opcao invalida! " << endl;
        }

    } while(choice > (int) this->mao.size());

    Carta* c = this->mao[choice];
    removeCartaMao(c);

    return c;

}