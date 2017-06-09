#ifndef _COZIM_H_
#define _COZIM_H_

#include <iostream>
//#include <ctime.h>
#include "fila.h"

#include "pedido.h"
#include "mont.h"
//class Fila;


using namespace std;

class Cozim
{
public:
    bool disponivel; //conferir se o forno esta disponivel / vazio
    int tAtual;
    int tRest; //tempo restante do cozimento   tempo total - (tempo atual - tempo chegada)
    int t; //tempo total de cozimento
    Pedido *Atual;

    bool getDisp();
    void setTempoAt(int aux);

    int getTRest(int tempo); //retorna tempo restante de cozimento
    void pedido(Pedido *P);

    Pedido* getPedido();

    Cozim();
    ~Cozim();
};
#endif
