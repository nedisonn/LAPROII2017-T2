#include "cozim.h"

Cozim::Cozim(){
    disponivel = true;
    tRest = -1;
    tAtual = -1;
    if (Atual != NULL){
    t = Atual->qtdPasteis*1 + Atual->qtdPizza*3;}
    else t = -1;
}
Cozim::~Cozim(){

}
int Cozim::getTRest(int tempo)
{
    tRest = Atual->getITempo() - tempo + t;
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

void Cozim::pedido(Pedido *P) {}
Pedido* Cozim::getPedido()
{

    return Atual;
}

