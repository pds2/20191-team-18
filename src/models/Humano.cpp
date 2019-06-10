#include "models/Humano.hpp"
#include <models/Carta.hpp>
#include <cstdlib>

template<class T, std::size_t n>
constexpr std::size_t size(T (&)[n])
{ return n; }

Humano::Humano(string nome) : Jogador(nome) {}
Humano::Humano(string nome, std::vector<Carta*> cartas) : Jogador(nome, cartas) {};

/* 
    Retorna a opção selecionada dentro das jogadas possiveis
    As jogadas possiveis para o jogador são as cartas de sua mão 
    e o vetor de opções adicionais 
*/ 
int Humano::jogar(std::vector<std::string> opcoesAdicionais) {

    int choice = -1;
    int nCartas = this->mao.size();

    exibirCartas();
    exibirOpcoesAdicionais(opcoesAdicionais, nCartas);
    
    do {
        cout << "\n" << "Digite a opcao selecionada: " << endl;
        std::cin >> choice;

        if(choice > (int) this->mao.size()) {
            cout << "\n" << "Opcao invalida! " << endl;
        }

    } while(choice > ((int) this->mao.size()) + 1);

    return choice;
}

/*
    Exibe as opções adicionais do jogador que pode ser pedir truco, pedir seis,
    pedir nove e pedir doze
 */
void Humano::exibirOpcoesAdicionais(std::vector<std::string> opcoesAdicionais, int nOpcao) {
    int sizeOpcoes = opcoesAdicionais.size();
    for(int i = nOpcao, j = 0; j < sizeOpcoes; i++, j++) {
        cout << "\n" << "Opcao [" << i << "]: "  << opcoesAdicionais[j];
    }
}

void Humano::exibirCartas() {

    if(this->mao.size() == 0) {
        throw Exception::JogadorSemCartas();
    }

    cout << "\n\n" << this->getNome() << ", voce possui as seguintes cartas:" << endl;

    for(int i = 0; i < (int) mao.size(); i++) {
        cout << "\n" << "Opcao [" << i << "]: " << mao[i]->getValor() << " " << mao[i]->getNipe();
    }
}

void Humano::pedirTruco() {
    cout << "TRUCO NA MENTE";
}

int Humano::aceitarDesafio(Jogador* jogadorDesafiante, int pontos) {
    int choice;
    do {
        switch(pontos) {
            case 4:
                cout << jogadorDesafiante->getNome() << " está pedindo truco!" << endl;
                break;
            case 8:
                cout << jogadorDesafiante->getNome() << " está pedindo seis!" << endl;
                break;
            case 10:
                cout << jogadorDesafiante->getNome() << " está pedindo nove!" << endl;
                break;
            case 12:
                cout << jogadorDesafiante->getNome() << " está pedindo doze!" << endl;
                break;
        }
        
        cout << "\n O que deseja fazer?" << endl;
        cout << "\n 1 - Aceitar" << endl;
        
        switch(pontos) {
            case 4:
                cout << "2 - Pedir seis!" << endl;
                break;
            case 8:
                cout << "2 - Pedir nove!" << endl;
                break;
            case 10:
                cout << "2 - Pedir doze!" << endl;
                break;
        }
        
        cout << "\n 3 - Correr!" << endl;
        cout << "\n" << "Digite a opcao selecionada: " << endl;
        
        std::cin >> choice;    
    } while(choice < 1 || choice > 3);
    
    return choice;
}