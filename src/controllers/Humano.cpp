#include <cstdlib>
#include "controllers/Humano.hpp"
#include "models/Carta.hpp"

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

    exibirCartas(true);
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

void Humano::exibirOpcoesAdicionais(std::vector<std::string> opcoesAdicionais, int nOpcao) {
    int sizeOpcoes = opcoesAdicionais.size();
    for(int i = nOpcao, j = 0; j < sizeOpcoes; i++, j++) {
        cout << "\n" << "Opcao [" << i << "]: "  << opcoesAdicionais[j];
    }
}

void Humano::exibirCartas(bool opcao) {
    string prefix = (opcao) ? "Opcao" : "Carta"; 
    if(this->mao.size() == 0) {
        throw Exception::JogadorSemCartas();
    }

    cout << "\n\n" << this->getNome() << ", voce possui as seguintes cartas:" << endl;

    for(int i = 0; i < (int) mao.size(); i++) {
        cout << "\n" <<  prefix <<" [" << i << "]: " << mao[i]->getValor() << " " << mao[i]->getNipe();
    }
}

int Humano::aceitarDesafio(Jogador* jogadorDesafiante, int pontos) {
    int choice;
    exibirCartas(false);
    do {
        cout << "\n\nO que deseja fazer?" << endl;
        
        cout << "\nOpcao [0]: Correr!";
        cout << "\nOpcao [1]: Aceitar!";
        
        switch(pontos) {
            case 4:
                cout << "\nOpcao [2]: Pedir seis!";
                break;
            case 8:
                cout << "\nOpcao [2]: Pedir nove!";
                break;
            case 10:
                cout << "\nOpcao [2]:  Pedir doze!";
                break;
        }
        
        cout << "\n" << "Digite a opcao selecionada: ";
        
        std::cin >> choice;    
    } while(choice < 0 || choice > 2);
    
    return choice;
}