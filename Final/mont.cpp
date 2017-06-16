/*Nedison Velloso - T2 - LAPRO II - 2017/1*/
#include "mont.h"

Mont::Mont()
{
    disponivel = true;
    tRest = -1;
    tAtual = -1;
    Atual = NULL;
    t = -1;
    pronto = false;
}
Mont::~Mont()
{
}
int Mont::getTRest(float tempo)
{
    tRest = Atual->getProcTempo() - tempo + t;
    return tRest;
} //retorna tempo restante de montagem

void Mont::setTempoAt(int aux)
{
    tAtual = aux;
}

bool Mont::getDisp()
{
    return disponivel;
}

void Mont::pedido(Pedido *P, float tempo)
{
    //cout << "Mont pedido" << endl;
    Atual = P;
    t = Atual->getQtdPasteis() * 1 + Atual->getQtdPizza() * 3;
    disponivel = false;
    Atual->setProcTempo(tempo);
}

Pedido *Mont::getPedido()
{
    return Atual;
}

bool Mont::getPronto()
{

    if (getTRest(tAtual) <= 0)
    {

        return pronto = true;
    }
    else
        return pronto = false;
}

void Mont::setDisp(bool aux)
{
    disponivel = aux;
}