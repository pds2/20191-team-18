#define CATCH_CONFIG_MAIN
#include "../src/tests/catch.hpp"
#include "../src/models/Carta.cpp"

TEST_CASE( "Testando set e get" ) {
    Carta* c = new Carta("COPAS", 0, 13);
    REQUIRE( c->getNipe() == "COPAS" );
}

TEST_CASE( "Testando sdsaet e get" ) {
    Carta* c = new Carta("COPAS", 0, 13);
    REQUIRE( c->getNipe() == "COPAS" );
}

TEST_CASE( "Testando seewqewqt e get" ) {
    Carta* c = new Carta("COPAS", 0, 13);
    REQUIRE( c->getNipe() == "COPAS" );
}

TEST_CASE( "Testando sevcvbcbvt e get" ) {
    Carta* c = new Carta("COPAS", 0, 13);
    REQUIRE( c->getNipe() == "COPAS" );
}
