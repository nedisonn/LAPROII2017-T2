/*Nedison Velloso - T2 - LAPRO II - 2017/1*/
#ifndef _COZIM_H_
#define _COZIM_H_

#include <iostream>
#include "fila.h"
#include "pedido.h"
#include "mont.h"
using namespace std;

class Cozim
{
public:
    bool disponivel; //conferir se o forno esta disponivel / vazio
    bool pronto;
    int tAtual;
    int tRest; //tempo restante do cozimento   tempo total - (tempo atual - tempo chegada)
    int t; //tempo total de cozimento
    Pedido *Atual;

    bool getDisp();

    void setDisp(bool aux);
    
    void setTempoAt(int aux);

    int getTRest(float tempo); //retorna tempo restante de cozimento
    void pedido(Pedido *P, float tempo);

    Pedido* getPedido();

    bool getPronto();

    Cozim();
    ~Cozim();
};
#endif