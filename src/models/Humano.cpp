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

    cout << "\n" << this->getNome() << ", voce possui as seguintes cartas:" << endl;

    for(int i = 0; i < (int) mao.size(); i++) {
        cout << "\n" << "Opcao [" << i << "]: " << mao[i]->getValor() << " de " << mao[i]->getNipe();
    }
}

void Humano::pedirTruco() {
    cout << "TRUCO NA MENTE";
}