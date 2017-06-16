/*Nedison Velloso - T2 - LAPRO II - 2017/1*/
#include "fila.h"

Fila::Fila()
{
	tam = 0;
	inicio = NULL;
	fim = NULL;
}

Fila::~Fila()
{
}

void Fila::adiciona(Pedido *aux)
{
	//cout << "Fila Adiciona"  << endl;
	NodoFila *temp;
	temp = new NodoFila;
	temp->setDados(aux);
	temp->setProx(NULL);
	if (fim == NULL)
	{
		fim = temp;
		inicio = temp;
	}
	else
	{
		fim->setProx(temp);
		fim = temp;
	}
	tam++;
}

Pedido *Fila::retira()
{

	// cout << "Fila Retira"  << endl;

	NodoFila *temp;
	temp = new NodoFila;
	if (inicio == NULL)
	{
		//cout << "Fila Vazia" << endl;
		return NULL;
	}
	else
	{
		temp = inicio;
		inicio = inicio->getProx();
		if (inicio == NULL)
		{
			fim = NULL;
		}
		tam--;
		return temp->getDados();
	}
}
int Fila::tamanho()
{
	return tam;
}

bool Fila::vazia()
{
	if (inicio == NULL)
	{
		return true;
	}
	else
		return false;
}