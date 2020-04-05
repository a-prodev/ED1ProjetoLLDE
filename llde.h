#ifndef JOSE_LLDE_H
#define JOSE_LLDE_H
#include <no.h>
#include <QString>

namespace jose {

class LLDE // Lista Linear Duplamente Encadeada
{
    No * pInicio;
    No * pFim;
    int quantidade;
public:
    LLDE();
    ~LLDE();
    int getQuantidade() const;
    bool estaVazia() const {return getQuantidade() == 0;}
    void inserirInicio(int valor);
    int retirarInicio();
    void inserirFim(int elemento);
    int retiarFim();
    int operator[](int pos);
};

} // namespace jose

#endif // JOSE_LLDE_H
