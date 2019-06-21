#include <cstdlib>
#include "controllers/Humano.hpp"
#include "models/Carta.hpp"
#include "views/UIManager.hpp"

template<class T, std::size_t n>
constexpr std::size_t size(T (&)[n])
{ return n; }

Humano::Humano(string nome, UIManager* manager) : Jogador(nome) {
    this->uim = manager;
}
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
    
    getch();
    
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
    this->uim->printString("Opções: ", 3, 9+nOpcao);

    nOpcao++;

    for(int i = nOpcao, j = 0; j < sizeOpcoes; i++, j++) {
        this->uim->printString("[ _ ] -> ", 5, 9+i);
        this->uim->printString(std::to_string(i), 7, 9+i);
        this->uim->printString(opcoesAdicionais[j], 15, 9+i);
    }
}

void Humano::exibirCartas(bool opcao) {
    string prefix = (opcao) ? "Opcao" : "Carta"; 
    if(this->mao.size() == 0) {
        throw Exception::JogadorSemCartas();
    }

    this->uim->printString(this->getNome(), 3, 7);
    this->uim->printString("Cartas: ", 3, 8);
    

    for(int i = 0; i < (int) mao.size(); i++) {
        this->uim->printString("[ _ ] -> ", 5, 9+i);
        this->uim->printString(std::to_string(i), 7, 9+i);
        this->uim->printString(mao[i]->getValor(), 15, 9+i);
        this->uim->printString(mao[i]->getNipe(), 16, 9+i);
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