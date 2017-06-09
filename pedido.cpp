#include "pedido.h"


Pedido::Pedido(){
    num = -1;
    qtdPizza = -1;
    qtdPasteis = -1;
    iTempo = -1;
}
Pedido::~Pedido(){


}

Pedido::Pedido(int tempo, int numP){

    qtdPasteis = rand() % 3 +1;
    qtdPizza = rand() % 5 +1;
    iTempo = tempo;
    num = numP;



}
int Pedido::getITempo(){

    return iTempo;
}