#include "llde.h"

namespace jose {

int LLDE::getQuantidade() const
{
    return quantidade;
}

void LLDE::inserirInicio(int valor)
{
    try {
        No* pAux = new No(valor);
        if (estaVazia()){
            pInicio = pFim = pAux;
            quantidade ++;
        }
        else{
            pAux->setProximo(pInicio);
            pInicio->setAnterior(pAux);
            pInicio = pAux;
            quantidade ++;
        }
    } catch (std::bad_alloc&) {
        throw QString("Erro: Elemento não inserido por falta de memória.");
    }
}

int LLDE::retirarInicio()
{
    if (estaVazia())
        throw QString("Erro: Elemento não retirado por a lista estar vazia.");
    if (quantidade == 1){
        int valor = pInicio->getDado();
        delete pInicio;
        pInicio = pFim = nullptr;
        quantidade = 0;
        return valor;
    }
    No* pAux = pInicio;
    pInicio = pInicio->getProximo();
    pInicio->setAnterior(nullptr);
    quantidade --;
    int valor = pAux->getDado();
    delete pAux;
    return valor;
}

void LLDE::inserirFim(int elemento)
{
    try {
        No* pAux = new No(elemento);
        if (estaVazia()){
            pInicio = pFim = pAux;
            quantidade ++;
        }
        else{
            pFim->setProximo(pAux);
            pAux->setAnterior(pFim);
            pFim = pAux;
            quantidade ++;
        }
    } catch (std::bad_alloc&) {
        throw QString("Erro: Elemento não inserido por falta de memória.");
    }

}

int LLDE::retirarFim()
{
    if (estaVazia())
        throw QString("Erro: Elemento não retirado por a lista estar vazia.");
    No* pAux = pFim;
    if(quantidade == 1){
        pInicio = pFim = nullptr;
    }else{
        pFim = pAux->getAnterior();
        pFim->setProximo(nullptr);
    }
    quantidade --;
    int aux = pAux->getDado();
    delete pAux;
    return aux;
}

int LLDE::operator[](int pos)
{
    if (pos < 1 || pos > quantidade)
        throw QString("Erro: Posição inserida inválida.");
    if (pos == 1)
        return pInicio->getDado();
    if (pos == getQuantidade())
        return pFim->getDado();
    No* pAux = pInicio;
    for (int cont = 1; cont < pos; cont++) {
        pAux = pAux->getProximo();
    }
    return pAux->getDado();
}

LLDE::LLDE():
    pInicio(nullptr),
    pFim(nullptr),
    quantidade(0)
{

}

LLDE::~LLDE()
{
    while (!estaVazia()) {
        this->retirarFim();
    }
}

} // namespace jose
