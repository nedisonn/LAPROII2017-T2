#ifndef _EMPAC_H_
#define _EMPAC_H_

#include <iostream>
//#include <ctime.h>
#include "fila.h"

#include "pedido.h"
#include "mont.h"
#include "cozim.h"
using namespace std;
class Empac
{
public:
    bool disponivel; //conferir se o empacotamento esta disponivel
    int tRest; //tempo restante do empacotamento   tempo total - (tempo atual - tempo chegada)
    int tAtual;
    int t; //tempo total de empacotamento
    Pedido *Atual;

    int getTRest(int tempo); //retorna tempo restante de empacotamento

    void setTempoAt(int aux);
    bool getDisp();

    Pedido* getPedido();
    void pedido(Pedido *P);
    Empac();
    ~Empac();
};
#endif
