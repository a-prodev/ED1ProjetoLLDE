#ifndef JOSE_NO_H
#define JOSE_NO_H


namespace jose {

class No
{
    No * anterior;
    int dado;
    No * proximo;
public:
    No();
    No(int dado);
    No *getAnterior() const {return anterior;}
    void setAnterior(No *);
    int getDado() const {return dado;}
    void setDado(int dado);
    No *getProximo() const {return proximo;}
    void setProximo(No *);    
};

} // namespace jose

#endif // JOSE_NO_H
