/*Nedison Velloso - T2 - LAPRO II - 2017/1*/
#include "cozim.h"

Cozim::Cozim()
{
    disponivel = true;
    tRest = -1;
    tAtual = -1;
    Atual = NULL;
    t = -1;
    pronto = false;
}
Cozim::~Cozim()
{
}
int Cozim::getTRest(float tempo)
{
    tRest = Atual->getProcTempo() - tempo + t;
    return tRest;
} //retorna tempo restante de montagem

void Cozim::setTempoAt(int aux)
{
    tAtual = aux;
}

bool Cozim::getDisp()
{

    return disponivel;
}

void Cozim::pedido(Pedido *P, float tempo)
{
    //cout << "Cozim pedido" << endl;
    Atual = P;
    t = Atual->getQtdPasteis() * 2 + Atual->getQtdPizza() * 4;
    disponivel = false;
    Atual->setProcTempo(tempo);
}

Pedido *Cozim::getPedido()
{

    return Atual;
}

bool Cozim::getPronto()
{
    if (getTRest(tAtual) <= 0)
    {

        return pronto = true;
    }
    else
        return pronto = false;
}

void Cozim::setDisp(bool aux)
{
    disponivel = aux;
}