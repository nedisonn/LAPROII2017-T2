#ifndef _PEDIDO_H_
#define _PEDIDO_H_

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "fila.h"
using namespace std;

class Pedido{
    public:
int num; //numero do pedido
int qtdPizza; //uma certa quantidade de pizzas (sorteada entre 1 e 3),
int qtdPasteis; //uma certa quantidade de pasteis (sorteada entre 1 e 5) e o
int iTempo; //instante de tempo que chegou


int getNum(); //retorna numero de controle


int getQtdPizza(); //retorna quantidade de pizzas
void setQtdPizza(int aux); //adiciona pizzas

int getQtdPasteis();//retorna quantidade de pasteis
void setQtdPasteis(int aux); //adiciona pasteis

int getITempo();

Pedido();
~Pedido();

Pedido(int tempo, int numP);
};
#endif
