#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../src/models/Carta.cpp"
#include "../src/models/Mesa.cpp"
#include "../src/models/CartaNaMesa.cpp"
#include "../src/controllers/Bot.cpp"
#include "../src/models/Jogador.cpp"
#include "../src/models/Baralho.cpp"
#include "../src/tests/catch.hpp"
#include <list>


bool checkCartas(Carta* cartaPraValidar, std::list<Carta*> baralho){
    for (auto const& carta : baralho) {
        if(carta->getForca() == cartaPraValidar->getForca() && carta->getValor() == carta->getValor()){
            return true;
        }
    }

    return false;
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
    REQUIRE(maiorCarta->getForca() == 14);
    REQUIRE(maiorCarta->getValor() == "4");
    REQUIRE(jogador->getNome() == "Gabriel");
}