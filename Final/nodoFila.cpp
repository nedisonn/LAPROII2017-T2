/*Nedison Velloso - T2 - LAPRO II - 2017/1*/
#include "nodoFila.h"

void NodoFila::setDados(Pedido *aux)
{
    Dados = aux;
}
Pedido *NodoFila::getDados()
{
    return Dados;
}

void NodoFila::setProx(NodoFila *aux)
{
    prox = aux;
}
NodoFila *NodoFila::getProx()
{
    return prox;
}