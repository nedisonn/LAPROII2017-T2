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

		void adiciona(Pedido *aux);
		Pedido* retira();
		//bool vazio();
        int tamanho();



};

#endif
