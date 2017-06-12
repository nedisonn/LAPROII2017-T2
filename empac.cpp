#include "empac.h"

Empac::Empac(){
    disponivel = true;
    tRest = -1;
    tAtual = -1;
     Atual = NULL;
    t = -1;
    pronto = false;
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

void Empac::pedido(Pedido *P) {
   // cout << "Cozim pedido" << endl;
    Atual = P;
    t = Atual->getQtdPasteis()*1 + Atual->getQtdPizza()*1;
    disponivel = false;
    }
Pedido* Empac::getPedido()
{

    return Atual;
}

bool Empac::getPronto(){
  if (getTRest(tAtual) <= 0){


    return pronto = true ;}
    else return pronto = false;
}


void Empac::setDisp(bool aux){
    disponivel = aux;
}
