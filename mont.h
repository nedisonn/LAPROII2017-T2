#ifndef _MONT_H_
#define _MONT_H_

#include <iostream>
#include "fila.h"
#include "pedido.h"



class Mont
{
public:
    bool disponivel; //conferir se a montagem esta disponivel
    bool pronto;
    int tRest; //tempo restante da montagem     tempo total - (tempo atual - tempo chegada)
    int tAtual;
    int t; //tempo total de montagem
    Pedido *Atual;

    int getTRest(int tempo); //retorna tempo restante de montagem

    void setTempoAt(int aux);

    bool getDisp();
    void setDisp(bool aux);

    bool getPronto();

    void pedido(Pedido *P);
    Pedido* getPedido();
    Mont();
    ~Mont();
};
#endif
