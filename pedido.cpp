#include "pedido.h"


Pedido::Pedido(){
    //cout << "Pedido Construtor s/p" << endl;
    num = -1;
    qtdPizza = -1;
    qtdPasteis = -1;
    iTempo = -1;
}
Pedido::~Pedido(){


}

Pedido::Pedido(int tempo, int numP){

   // cout << "Pedido Construtor c/p"  << endl;
    qtdPasteis = rand() % 3 +1;
    qtdPizza = rand() % 5 +1;
    iTempo = tempo;
    num = numP;



}
int Pedido::getITempo(){

    return iTempo;
}

int Pedido::getNum(){
    return num;
}

int Pedido::getQtdPizza(){
    return qtdPizza;
}
void Pedido::setQtdPizza(int aux){
    qtdPizza = aux;
}

int Pedido::getQtdPasteis(){
    return qtdPasteis;
}
void Pedido::setQtdPasteis(int aux){
    qtdPasteis = aux;
}