#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

using std::exception;

namespace Exception {
    /**
     * @brief Exceção para quando o nipe da carta é inválido
     * 
     */
    class NipeInvalido  : public exception {};

    /**
     * @brief Exceção para quando a força da carta é inválida
     * 
     */
    class ForcaInvalida : public exception {};

    /**
     * @brief Exceção para quando ocorre uma tentativa de retirada de carta
     * da mão de um jogador que não possui cartas
     * 
     */
    class JogadorSemCartas : public exception {};
}

#endif