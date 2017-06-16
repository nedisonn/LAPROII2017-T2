/*Nedison Velloso - T2 - LAPRO II - 2017/1*/
#ifndef _NODOFILA_H_
#define _NODOFILA_H_

#include <iostream>
#include "pedido.h"
using namespace std;
class Pedido;

class NodoFila
{
  public:
    Pedido *Dados;
    NodoFila *prox;

    void setDados(Pedido *aux);
    Pedido *getDados();

    void setProx(NodoFila *aux);
    NodoFila *getProx();
};

#endif