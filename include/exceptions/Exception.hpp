#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

using std::exception;

namespace Exception {
    class NipeInvalido  : public exception {};
    class ForcaInvalida : public exception {};
    class JogadorSemCartas : public exception {};
}

#endif