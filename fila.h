#ifndef _FILA_H_
#define _FILA_H_


#include <iostream>

#include "nodoFila.h"
#include "pedido.h"
class Pedido;
class NodoFila;

using namespace std;

class Fila{
    public:
		NodoFila *inicio, *fim;

        int tam;

        Fila();
        ~Fila();

		void adiciona(Pedido *aux);
		Pedido* retira();
        int tamanho();
        bool vazia(); 


};

#endif
