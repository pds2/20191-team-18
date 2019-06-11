#define CATCH_CONFIG_MAIN
#include "./models/Carta.cpp"
#include "./models/Mesa.cpp"
#include "./models/CartaNaMesa.cpp"
#include "./models/Jogador.cpp"
#include "./models/Baralho.cpp"
#include "./models/Rodada.cpp"
#include "./models/Bot.cpp"
#include "./tests/catch.hpp"

//variaveis compartilhadas entre os testes
//cartas
Carta* zap = new Carta("4", 3, 14);
Carta* seteCopas = new Carta("7", 0, 13);
Carta* espadilha = new Carta("A", 2, 12);
Carta* seteOuro = new Carta("7", 1, 11);  
//jogadores
Bot* player = new Bot("Gabriel");
Bot* player2 = new Bot("Pedro");
Bot* player3 = new Bot("Joao");
Bot* player4 = new Bot("Germano");
//fim variaveis compartilhadas

bool checkCartas(Carta* cartaPraValidar, std::list<Carta*> baralho){
    for (auto const& carta : baralho) {
        if(carta->getForca() == cartaPraValidar->getForca() && carta->getValor() == carta->getValor()){
            return true;
        }
    }

    return false;
}

TEST_CASE("Testa se a mesa retorna a maior carta"){
    Bot* player = new Bot("Gabriel");
    Bot* player2 = new Bot("Pedro");
    Mesa* mesa = new Mesa();
    mesa->limpaCartasNaMesa();
    CartaNaMesa* cm = new CartaNaMesa(zap, player);
    CartaNaMesa* cm2 = new CartaNaMesa(seteCopas, player2);
    mesa->addCartaNaMesa(cm);
    mesa->addCartaNaMesa(cm2);
    CartaNaMesa* c = mesa->obterMaiorCarta();
    Carta* maiorCarta = c->getCarta();
    Jogador* jogador = c->getJogador();    
    SECTION("seção para validar se a maior carta foi retornada certa"){
        REQUIRE(maiorCarta->getForca() == 14);
        REQUIRE(maiorCarta->getValor() == "4");
    }

    SECTION("Seçãp para validar se o jogador da maior carta foi retornado corretamente"){
        REQUIRE(jogador->getNome() == "Gabriel");
    }    
}

TEST_CASE( "Testa se as manilhas estão no baralho" ) {
    Baralho b;
    std::list<Carta*> baralho = b.getCartas();    
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

TEST_CASE("Testa o inicio da rodada (distribuição de cartas)"){
    std::list<Jogador*> jogadores;
    jogadores.push_back(player);
    jogadores.push_back(player2);
    jogadores.push_back(player3);
    jogadores.push_back(player4);
    Rodada* rodada = new Rodada(0, 2, jogadores, 0, 0);
    rodada->controleRodada();

    for (auto const& jogador : jogadores) {
        REQUIRE(jogador->getNumeroCartas() == 3);
    }
}

SCENARIO( "Mudança na ordem de quem joga a primeira carta" ) {
    GIVEN( "Dado uma lista de jogadores" ) {
        std::list<Jogador*> jogadores;
        jogadores.push_back(player);
        jogadores.push_back(player2);
        jogadores.push_back(player3);
        jogadores.push_back(player4);

        WHEN( "Quando a rodada começa" ) {
            Rodada* rodadaTeste = new Rodada(0, 2, jogadores, 0, 0);
            rodadaTeste->controleRodada();
            THEN( "Então a rodada termina e a ordem dos jogadores muda" ) {
                std::list<Jogador*> jogadoresComecoRodada = rodadaTeste->getOrdemJogadores();
                CHECK(jogadoresComecoRodada.front()->getNome() != jogadores.front()->getNome());
            }
        }
    }
}




