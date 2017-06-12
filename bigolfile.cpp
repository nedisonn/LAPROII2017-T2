//#ifndef _PEDIDO_H_
//#define _PEDIDO_H_

#include <iostream>
////#include <ctime.h>
//#include "fila.h"
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
//#endif

//#include "pedido.h"


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
//#ifndef _NODOFILA_H_
//#define _NODOFILA_H_

//#include <iostream>
//#include "pedido.h"
using namespace std;
class Pedido;

class NodoFila
{
public:
    Pedido *Dados;
    NodoFila *prox;

    void setDados(Pedido *aux);
    Pedido* getDados();

    void setProx(NodoFila *aux);
    NodoFila* getProx();

};

//#endif

//#include "nodoFila.h"

void NodoFila::setDados(Pedido *aux)
{
    Dados = aux;
}
Pedido* NodoFila::getDados()
{
    return Dados;
}


void NodoFila::setProx(NodoFila *aux)
{
    prox = aux;
}
NodoFila* NodoFila::getProx()
{
    return prox;
}

//#ifndef _FILA_H_
//#define _FILA_H_


//#include <iostream>

//#include "nodoFila.h"
//#include "pedido.h"
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

//#endif

//#include "fila.h"

Fila::Fila(){
    tam = 0;
    inicio = NULL;
    fim = NULL;
}

Fila::~Fila(){

}

void Fila::adiciona(Pedido *aux) {
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


Pedido* Fila::retira() {
    
   // cout << "Fila Retira"  << endl;

	NodoFila *temp;
	temp = new NodoFila;
	if (inicio == NULL) {
		//cout << "Fila Vazia" << endl;
		return NULL;
		}
	else {
		temp = inicio;
		inicio = inicio->getProx();
        if(inicio == NULL){fim = NULL;}
        tam--;
		return temp->getDados();
	}
}
 int Fila::tamanho(){
     return tam;
 }


bool Fila::vazia(){
    if (inicio ==NULL){
    return  true;}
    else return false;
}
//#ifndef _MONT_H_
//#define _MONT_H_

//#include <iostream>
//#include "fila.h"
//#include "pedido.h"



class Mont
{
public:
    bool disponivel; //conferir se a montagem esta disponivel
    bool pronto;
    int tRest; //tempo restante da montagem     tempo total - (tempo atual - tempo chegada)
    int tAtual;
    int t; //tempo total de montagem
    Pedido *Atual;

    int getTRest(int tempo); //retorna tempo restante de montagem

    void setTempoAt(int aux);

    bool getDisp();
    void setDisp(bool aux);

    bool getPronto();

    void pedido(Pedido *P);
    Pedido* getPedido();
    Mont();
    ~Mont();
};
//#endif

//#include "mont.h"

Mont::Mont(){
    disponivel = true;
    tRest = -1;
    tAtual = -1;
    if (Atual != NULL){
    t = Atual->getQtdPasteis()*1 + Atual->getQtdPizza()*3;}
    else t = -1;
}
Mont::~Mont(){
}
int Mont::getTRest(int tempo)
{
    tRest = Atual->getITempo() - tempo + t;
    return tRest;
} //retorna tempo restante de montagem

void Mont::setTempoAt(int aux)
{
    tAtual = aux;

}

bool Mont::getDisp()
{
    return disponivel;
}

void Mont::pedido(Pedido *P) {
    //cout << "Mont pedido" << endl;
    Atual = P;
    t = Atual->getQtdPasteis()*1 + Atual->getQtdPizza()*3;
    disponivel = false;
}

Pedido* Mont::getPedido()
{
    return Atual;
}


bool Mont::getPronto(){

    if (getTRest(tAtual) <= 0){
   

    return pronto = true ;}
    else return pronto = false;
}


void Mont::setDisp(bool aux){
    disponivel = aux;
}
//#ifndef _COZIM_H_
//#define _COZIM_H_

//#include <iostream>
//#include "fila.h"
//#include "pedido.h"
//#include "mont.h"
using namespace std;

class Cozim
{
public:
    bool disponivel; //conferir se o forno esta disponivel / vazio
    bool pronto;
    int tAtual;
    int tRest; //tempo restante do cozimento   tempo total - (tempo atual - tempo chegada)
    int t; //tempo total de cozimento
    Pedido *Atual;

    bool getDisp();

    void setDisp(bool aux);
    
    void setTempoAt(int aux);

    int getTRest(int tempo); //retorna tempo restante de cozimento
    void pedido(Pedido *P);

    Pedido* getPedido();

    bool getPronto();

    Cozim();
    ~Cozim();
};
//#endif

//#include "cozim.h"

Cozim::Cozim(){
    disponivel = true;
    tRest = -1;
    tAtual = -1;
    if (Atual != NULL){
    t = Atual->getQtdPasteis()*2 + Atual->getQtdPizza()*4;}
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

void Cozim::pedido(Pedido *P) {
    //cout << "Cozim pedido" << endl;
    Atual = P;
    t = Atual->getQtdPasteis()*2 + Atual->getQtdPizza()*4;
    disponivel = false;
    }
Pedido* Cozim::getPedido()
{

    return Atual;
}

bool Cozim::getPronto(){
  if (getTRest(tAtual) <= 0){
   

    return pronto = true ;}
    else return pronto = false;
}


void Cozim::setDisp(bool aux){
    disponivel = aux;
}
//#ifndef _EMPAC_H_
//#define _EMPAC_H_

//#include <iostream>
//#include "fila.h"
//#include "pedido.h"
//#include "mont.h"
//#include "cozim.h"
using namespace std;
class Empac
{
public:
    bool disponivel; //conferir se o empacotamento esta disponivel
    bool pronto;
    int tRest; //tempo restante do empacotamento   tempo total - (tempo atual - tempo chegada)
    int tAtual;
    int t; //tempo total de empacotamento
    Pedido *Atual;

    int getTRest(int tempo); //retorna tempo restante de empacotamento

    void setTempoAt(int aux);
    bool getDisp();
    void setDisp(bool aux);

    Pedido* getPedido();
    void pedido(Pedido *P);
    Empac();
    ~Empac();
    bool getPronto();
};
//#endif

//#include "empac.h"

Empac::Empac(){
    disponivel = true;
    tRest = -1;
    tAtual = -1;
    if (Atual != NULL){
    t = Atual->getQtdPasteis()*1 + Atual->getQtdPizza()*1;}
    else t = -1;
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
//#include <iostream>
//#include <sstream>
//#include <string>

//#include "fila.h"
//#include "pedido.h"
//#include "cozim.h"
//#include "mont.h"
//#include "empac.h"


int main ()
{
    Fila M; //Fila de pedidos antes de entrar no montador
    Fila F; // Fila de pedidos antes de entrar no forno
    Fila E; //Fila de pedidos antes de entrar no empacotador
    Pedido *P, *aux;
    Mont M1, M2, M3; // 3 montadores
    Cozim F1, F2, F3; //3 fornos
    Empac E1, E2, E3; //3 empacotadores
    int control, tempo, numP;
    numP = 0;
    tempo = 0;
    while(cin.get() != 'q')
    {

        control = rand() % 100;
        M1.setTempoAt(tempo);
        M2.setTempoAt(tempo);
        M3.setTempoAt(tempo);
        F1.setTempoAt(tempo);
        F2.setTempoAt(tempo);
        F3.setTempoAt(tempo);
        E1.setTempoAt(tempo);
        E2.setTempoAt(tempo);
        E3.setTempoAt(tempo);

        if (control > 80)
        {
            numP++;
            P = new Pedido(tempo, numP); //novo pedido
            M.adiciona(P); // adiciona o pedido a fila
            if (M1.getDisp() == true)
            {
                aux = M.retira();
                M1.pedido(aux);
            }
            else if (M2.getDisp() == true)
            {
                aux = M.retira();
                M2.pedido(aux);
            }
            else if (M3.getDisp() == true)
            {
                aux = M.retira();
                M3.pedido(aux);
            }
        }

//montador pronto
        if (M1.getDisp() == false && M2.getDisp() == false && M3.getDisp() == false)
        {
            if (M1.getPronto() == true || M2.getPronto() == true || M3.getPronto() == true )
            {
                if (M1.getPronto() == true)
                {
                    aux = M1.getPedido();
                    M1.setDisp(true);
                }
                if (M2.getPronto() == true)
                {
                    aux = M2.getPedido();
                    M2.setDisp(true);
                }
                if (M3.getPronto() == true)
                {
                    aux = M3.getPedido();

                    M3.setDisp(true);
                }

                F.adiciona(aux);
            }
        }


//
        if(F.vazia() != true)
        {
            if (F1.getDisp() == true)
            {
                aux = F.retira();
                F1.pedido(aux);
            }
            else if (F2.getDisp() == true)
            {
                aux = F.retira();
                F2.pedido(aux);
            }
            else if (F3.getDisp() == true)
            {
                aux = F.retira();
                F3.pedido(aux);
            }
        }

//forno pronto
        if (F1.getDisp() == false && F2.getDisp() == false && F3.getDisp() == false)
        {
            if (F1.getPronto() == true || F2.getPronto() == true || F3.getPronto() == true )
            {
                if (F1.getPronto() == true)
                {
                    aux = F1.getPedido();
                    F3.setDisp(true);
                }
                if (F2.getPronto() == true)
                {
                    aux = F2.getPedido();
                    F2.setDisp(true);
                }
                if (F3.getPronto() == true)
                {
                    aux = F3.getPedido();

                    F3.setDisp(true);
                }

                E.adiciona(aux);
            }
        }

//
        if (E.vazia() != true)
        {
            if (E1.getDisp() == true)
            {
                aux = E.retira();
                E1.pedido(aux);
            }
            else if (E2.getDisp() == true)
            {
                aux = E.retira();
                E2.pedido(aux);
            }
            else if (E3.getDisp() == true)
            {
                aux = E.retira();
                E3.pedido(aux);
            }
        }
        system("clear");
        cout << "Status das listas"<< endl;



        cout << "Quantidades de pedidos na fila de Montagem: " << M.tamanho() << endl;
        if (M1.getDisp() == false )
            cout << "Montador 1 falta " << M1.getTRest(tempo) << " instantes para finalizar o pedido "<< M1.getPedido()->num << endl;
        else
            cout << "Montador 1 vazio" << endl;
        if(M2.getDisp() == false)
            cout << "Montador 2 falta " <<  M2.getTRest(tempo) << " instantes para finalizar o pedido "<< M2.getPedido()->num << endl;
        else
            cout << "Montador 2 vazio" << endl;
        if(M3.getDisp() == false)
            cout << "Montador 3 falta " <<  M3.getTRest(tempo) << " instantes para finalizar o pedido "<< M3.getPedido()->num <<  endl;
        else
            cout << "Montador 3 vazio" << endl;

        cout << "Quantidades de pedidos na fila de Cozimento: " << F.tamanho() << endl;
        if (F1.getDisp() == false)
            cout << "Forno 1 falta " <<  F1.getTRest(tempo) << " instantes para finalizar o pedido "<< F1.getPedido()->num<<endl;
        else
            cout << "Forno 1 vazio" << endl;
        if(F2.getDisp() == false)
            cout << "Forno 2 falta " <<  F2.getTRest(tempo) << " instantes para finalizar o pedido "<< F2.getPedido()->num<<  endl;
        else
            cout << "Forno 2 vazio" << endl;
        if(F3.getDisp() == false)
            cout << "Forno 3 falta " <<  F3.getTRest(tempo) << " instantes para finalizar o pedido "<< F3.getPedido()->num<<  endl;
        else
            cout << "Forno 3 vazio" << endl;

        cout << "Quantidades de pedidos na fila de Empacotamento: " << E.tamanho() << endl;
        if (E1.getDisp() == false)
            cout << "Empacotador 1 falta " <<  E1.getTRest(tempo) << " instantes para finalizar o pedido "<< E1.getPedido()->num<< endl;
        else
            cout << "Empacotador 1 vazio" << endl;
        if(E2.getDisp() == false)
            cout << "Empacotador 2 falta " <<  E2.getTRest(tempo) << " instantes para finalizar o pedido "<< E2.getPedido()->num<< endl;
        else
            cout << "Empacotador 2 vazio" << endl;
        if(E3.getDisp() == false)
            cout << "Empacotador 3 falta " <<  E3.getTRest(tempo) << " instantes para finalizar o pedido "<< E3.getPedido()->num<< endl;
        else
            cout << "Empacotador 3 vazio" << endl;


        
    cout << "Tempo medio de atendimento: " << endl;



//aparecer na tela por mais tempo...
            if (E1.getDisp() == false ){
                if (E1.getPronto() == true)
                {
                    aux = E1.getPedido();
                    cout <<"Pedido de numero "<<  aux->getNum() << " ,foi entregue"<< endl;
                    E1.setDisp(true);
                }}

                if(E2.getDisp() == false){
                if (E2.getPronto() == true)
                {
                    aux = E2.getPedido();
                    cout <<"Pedido de numero "<<  aux->getNum() << " ,foi entregue"<< endl;
                    E2.setDisp(true);
                }}

                if(E3.getDisp() == false){
                if (E3.getPronto() == true)
                {
                    aux = E3.getPedido();
                    cout <<"Pedido de numero "<<  aux->getNum() << " ,foi entregue"<< endl;

                    E3.setDisp(true);
                }}
            
        
    


        tempo++;
        //cout << tempo << endl;

    }


    return 0;
}
