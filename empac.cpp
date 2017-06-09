#include "empac.h"
Empac::Empac(){
    disponivel = true;
    tRest = -1;
    tAtual = -1;
    if (Atual != NULL){
    t = Atual->qtdPasteis*1 + Atual->qtdPizza*3;}
    else t = -1;
}
Empac::~Empac(){

}
int Empac::getTRest(int tempo)
{
    tRest = Atual->getITempo() - tempo + t;
    return tRest;
} //retorna tempo restante de montagem

void Empac::setTempoAt(int aux)
{
    tAtual = aux;

}

bool Empac::getDisp()
{
    return disponivel;
}

void Empac::pedido(Pedido *P) {}
Pedido* Empac::getPedido()
{
    return Atual;
}
