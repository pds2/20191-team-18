#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/tests/doctest.h"
#include "../include/models/Carta.hpp"
#include "../include/models/Mesa.hpp"
#include "../include/models/CartaNaMesa.hpp"
#include "../include/controllers/Bot.hpp"
#include "../include/models/Jogador.hpp"
#include "../include/models/Baralho.hpp"
#include <list>

bool checkCartas(Carta* cartaPraValidar, std::list<Carta*> baralho){
    for (auto const& carta : baralho) {
        if(carta->getForca() == cartaPraValidar->getForca() && carta->getValor() == carta->getValor()){
            return true;
        }
    }

    return false;
}

TEST_CASE("1: Construtor do Aquecedor") {
    CHECK_NOTHROW(Carta("7", 0, 13));
}

TEST_CASE( "Testa se as manilhas estão no baralho" ) {
    Baralho b;
    std::list<Carta*> baralho = b.getCartas();  
    Carta* zap = new Carta("4", 3, 14);
    Carta* seteCopas = new Carta("7", 0, 13);
    Carta* espadilha = new Carta("A", 2, 12);
    Carta* seteOuro = new Carta("7", 1, 11);      
    REQUIRE(checkCartas(zap, baralho) == true);
    REQUIRE(checkCartas(seteCopas, baralho) == true);
    REQUIRE(checkCartas(espadilha, baralho) == true);
    REQUIRE(checkCartas(seteOuro, baralho) == true);
}

TEST_CASE("Testa o tamanho do baralho"){
    Baralho b;
    std::list<Carta*> baralho = b.getCartas();
    REQUIRE(baralho.size() == 40);
}

TEST_CASE("Testa se a mesa retorna a maior carta"){
    Mesa* mesa = new Mesa();
    mesa->limpaCartasNaMesa();
    Bot* player = new Bot("Gabriel");
    Bot* player2 = new Bot("Pedro");
    std::list<Jogador*> jogadores;
    jogadores.push_back(player);
    jogadores.push_back(player2);
    Carta* zap = new Carta("4", 3, 14);
    Carta* seteCopas = new Carta("7", 0, 13);
    CartaNaMesa* cm = new CartaNaMesa(zap, player);
    CartaNaMesa* cm2 = new CartaNaMesa(seteCopas, player2);
    mesa->addCartaNaMesa(cm);
    mesa->addCartaNaMesa(cm2);
    std::list<CartaNaMesa*> c = mesa->obterMaiorCarta();
    Carta* maiorCarta = c.front()->getCarta();
    Jogador* jogador = c.front()->getJogador();    
    CHECK(maiorCarta->getForca() == 14);
    CHECK(maiorCarta->getValor() == "4");
    CHECK(jogador->getNome() == "Gabriel");
}