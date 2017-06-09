#include "mont.h"

Mont::Mont(){
    disponivel = true;
    tRest = -1;
    tAtual = -1;
    if (Atual != NULL){
    t = Atual->qtdPasteis*1 + Atual->qtdPizza*3;}
    else t = -1;
}
Mont::~Mont(){

}



int Mont::getTRest(int tempo)
{
    tRest = Atual->getITempo() - tempo + t;
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

void Mont::pedido(Pedido *P) {}
Pedido* Mont::getPedido()
{
    return Atual;
}
