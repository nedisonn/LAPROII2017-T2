#include "fila.h"


void Fila::adiciona(Pedido *aux) {
	NodoFila *temp;
	temp = new NodoFila;
	temp->setDados(aux);
	temp->setProx(NULL);
	if (inicio == NULL)
		{inicio = temp;}
	else
		{fim->setProx(temp);}
	fim = temp;
    tam++;
}



Pedido* Fila::retira() {

	NodoFila *temp;
	temp = new NodoFila;
	if (inicio == NULL) {
		cout << "Fila Vazia" << endl;
		return NULL;
		}
	else {
		temp = inicio;
		inicio = inicio->getProx();
		return temp->getDados();
	}
    tam--;

}
 int Fila::tamanho(){
     return tam;
 }

