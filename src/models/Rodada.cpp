#include "../../include/models/Rodada.hpp" 
#include "../../include/models/Jogador.hpp"
#include "../../include/models/Baralho.hpp"
#include "../../include/models/Mesa.hpp"
#include "../../include/models/CartaNaMesa.hpp"
#include <list>
#include <iostream>
#include <exception>

Rodada::Rodada(int numero, int pontos, std::list<Jogador*> jogadores, int* pontos_time1, int* pontos_time2) {    
    Baralho baralhoPartida;
    baralhoPartida.embaralhar();
    this->baralho = baralhoPartida.getCartas();
    this->numero = numero;
    this->pontos = pontos;
    this->jogadores = jogadores;            
    this->mao    = 1;    
    this->pontos_time1 = pontos_time1;
    this->pontos_time2 = pontos_time2;
    controleRodada();
}

void Rodada::controleRodada() {
    for (auto const& jogador : this->jogadores) {
        jogador->limparCartasMao();
        auto carta1 = std::next(baralho.begin(), 0);
        auto carta2 = std::next(baralho.begin(), 1);
        auto carta3 = std::next(baralho.begin(), 2);
        jogador->addCartaMao(*carta1);
        jogador->addCartaMao(*carta2);
        jogador->addCartaMao(*carta3);
        baralho.erase(carta1);
        baralho.erase(carta2);
        baralho.erase(carta3);
    }

    Mesa* mesa = new Mesa();
    bool alguemCorreu = false;

    while(this->maos_ganhas_time1 < 2 && this->maos_ganhas_time2 < 2) {
        cout << "\n";
        mesa->limpaCartasNaMesa();
        
        for (auto const& jogador : this->jogadores) {
            std::vector<std::string> opcoesAdicionais;        
            opcoesAdicionais.push_back("Pedir Truco");
            
            int jogada = jogador->jogar(opcoesAdicionais);
            alguemCorreu = consolidaJogada(jogador, mesa, jogada);
            
            if(alguemCorreu) {
                break;
            }
        }
        cout << "\n" << "Mãos ganhas time 1: " << this->maos_ganhas_time1 << "Maos ganhas time 2: " << this->maos_ganhas_time2;
        this->computaVencedorRodada(mesa, alguemCorreu);
        
    }

    if(this->maos_ganhas_time1 >= 2) {
        cout << "\n" << "O Time 1 venceu a rodada e somou " << this->pontos << " pontos !!!" << endl;
    }
    else {
        cout << "\n" << "O Time 2 venceu a rodada e somou " << this->pontos << " pontos !!!" << endl;
    }

}

bool Rodada::consolidaJogada(Jogador* jogador, Mesa* mesa, int jogada) {
    if(jogada < jogador->getNumeroCartas()) {
        jogarCarta(jogador, mesa, jogada);
        return false;
    } else {
        bool alguemCorreu = desafiar(jogador, mesa);
        return alguemCorreu;
    }
}

void Rodada::reordenarListaJogadores() {
    
    Jogador* jogadorInicial = this->ultimoVencedor;

    std::list<Jogador*> novaOrdemJogadores;

    bool achouJogador = false;

    for (auto const jogador : this->jogadores) {
        if(jogador == jogadorInicial) {
            novaOrdemJogadores.push_back(jogador);   
            achouJogador = true;
        }
        else if(achouJogador == true) {
            novaOrdemJogadores.push_back(jogador); 
        }
    }

    for (auto const jogador : this->jogadores) {
        if(jogador == jogadorInicial) {
            break;
        }
        novaOrdemJogadores.push_back(jogador);
    }
    this->jogadores = novaOrdemJogadores;
}

std::list<Jogador*> Rodada::getOrdemJogadores() {
    
    return this->jogadores;
}

void Rodada::setPontos(int pontos) {
    this->pontos = pontos;
}

void Rodada::jogarCarta(Jogador* jogador, Mesa* mesa, int jogada) {
    Carta* c = jogador->getCartaMao(jogada);
    CartaNaMesa* cm = new CartaNaMesa(c, jogador);
    mesa->addCartaNaMesa(cm);
    jogador->removeCartaMao(jogada);
    cout << "\n" << jogador->getNome() << " jogou a Carta: " << c->getValor() << " " << c->getNipe();
}

bool Rodada::desafiar(Jogador* jogador, Mesa* mesa) {
    cout << "\nJogador " << jogador->getNome() << " está trucando: "; 
    cout << "TRUCO SEU RATO! "; 
    std::list<Jogador*> adversarios = getAdversarios(jogador);
    this->timeUltimoDesafiador = jogador->getTimeJogador();
    
    int escolhaDupla  = 0;
    bool alguemCorreu = false;
    
    do {
        escolhaDupla = 0;
        
        int valorDesafio = getValorDesafio();
        
        for (auto const& adversario : adversarios) {
            int result = adversario->aceitarDesafio(jogador, valorDesafio);
            if(result == 0) {
                alguemCorreu = true;
            }
            escolhaDupla += result;
        }
        
        std::list<Jogador*>::iterator itJogadorAdversario = adversarios.begin();
        Jogador* jogadorAdversario = *itJogadorAdversario;
        
        if(!alguemCorreu) {
            this->setPontos(valorDesafio);
            
            if(escolhaDupla > 2) {
                this->timeUltimoDesafiador = jogadorAdversario->getTimeJogador();
                adversarios = getAdversarios(jogadorAdversario);
            }
            else {
                cout << "\n" << "O Time " << jogadorAdversario->getTimeJogador() << " aceitou !!!"; 
            }
        }
        else {
            cout << "\n" << "O Time " << jogadorAdversario->getTimeJogador() << " correu !!!"; 
        }
        
    } while(escolhaDupla > 2 && alguemCorreu == false);
    
    if(alguemCorreu == false) {
        std::vector<std::string> opcoesAdicionais;
    
        if(jogador->getTimeJogador() != this->timeUltimoDesafiador) {
    
            if(this->pontos == 4) {
                opcoesAdicionais.push_back("Pedir Seis!");     
            } else if(this->pontos == 8) {
                opcoesAdicionais.push_back("Pedir Nove!"); 
            } else if(this->pontos == 10) {
                opcoesAdicionais.push_back("Pedir Doze!"); 
            }
        }
        
        int jogada = jogador->jogar(opcoesAdicionais);
        consolidaJogada(jogador, mesa, jogada);
    }   
    return alguemCorreu;
}

int Rodada::getValorDesafio() {
    if(this->pontos != 4) {
        return this->pontos + 2;
    } else {
        return this->pontos * 2;
    }
}

std::list<Jogador*> Rodada::getAdversarios(Jogador* jogador) {
    std::list<Jogador*> adversarios;
    
    for (auto const& jogadorIt : this->jogadores) {
        if(jogadorIt->getTimeJogador() != jogador->getTimeJogador()) {
            adversarios.push_back(jogadorIt);
        }   
    }
    
    return adversarios;
}

void Rodada::computaVencedorRodada(Mesa* mesa, bool desafioRecusado) {
    if(!desafioRecusado) {
        CartaNaMesa* maiorCartaNaMesa = mesa->obterMaiorCarta();
        Jogador* jogadorMaiorCarta = maiorCartaNaMesa->getJogador();
        
        Carta* maiorCarta = maiorCartaNaMesa->getCarta();
    
        cout << "\n\n" << jogadorMaiorCarta->getNome() << " jogou a carta " << maiorCarta->getValor()  << " " << maiorCarta->getNipe() << " e venceu a rodada !!!";
    
        if(jogadorMaiorCarta->getTimeJogador() == 1) {
            this->maos_ganhas_time1 += 1;
        }
        else {
            this->maos_ganhas_time2 += 1;
        }
        
        this->ultimoVencedor = jogadorMaiorCarta;
 
        reordenarListaJogadores();
        
    }
    else {
        if(this->timeUltimoDesafiador == 1) {
            this->maos_ganhas_time1 = 2;
            this->maos_ganhas_time2 = 0;
            *this->pontos_time1 += this->pontos;
        }
        else {
            this->maos_ganhas_time1 = 0;
            this->maos_ganhas_time2 = 2;
            *this->pontos_time2 += this->pontos;
        }
    }
    
}