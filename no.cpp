#include "no.h"

namespace jose {

void No::setAnterior(No * valor){
    anterior = valor;
}

void No::setDado(int valor) {
    dado = valor;
}

void No::setProximo(No * valor)
{
    proximo = valor;
}

No::No():
    anterior(nullptr),
    dado(0),
    proximo(nullptr)
{
}

No::No(int dado):
    anterior(nullptr),
    dado(dado),
    proximo(nullptr)
{

}

} // namespace jose
