//#ifndef _PEDIDO_H_
//#define _PEDIDO_H_

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
////#include <ctime.h>
//#include "fila.h"
using namespace std;

class Pedido
{
  public:
    int num;        //numero do pedido
    int qtdPizza;   //uma certa quantidade de pizzas (sorteada entre 1 e 3),
    int qtdPasteis; //uma certa quantidade de pasteis (sorteada entre 1 e 5) e o
    int iTempo;     //instante de tempo que chegou
    int procTempo;

    int getNum(); //retorna numero de controle

    int getQtdPizza();         //retorna quantidade de pizzas
    void setQtdPizza(int aux); //adiciona pizzas
    int getProcTempo()
    {

        return procTempo;
    }
    void setProcTempo(int aux)
    {
        procTempo = aux;
    }
    int getQtdPasteis();         //retorna quantidade de pasteis
    void setQtdPasteis(int aux); //adiciona pasteis

    int getITempo();

    Pedido();
    ~Pedido();

    Pedido(float tempo, int numP);
};
//#endif

//#include "pedido.h"

Pedido::Pedido()
{
    //cout << "Pedido Construtor s/p" << endl;
    num = -1;
    qtdPizza = -1;
    qtdPasteis = -1;
    iTempo = -1;
}
Pedido::~Pedido()
{
}

Pedido::Pedido(float tempo, int numP)
{

    // cout << "Pedido Construtor c/p"  << endl;
    qtdPasteis = rand() % 3 + 1;
    qtdPizza = rand() % 5 + 1;
    iTempo = tempo;
    num = numP;
}
int Pedido::getITempo()
{

    return iTempo;
}

int Pedido::getNum()
{
    return num;
}

int Pedido::getQtdPizza()
{
    return qtdPizza;
}
void Pedido::setQtdPizza(int aux)
{
    qtdPizza = aux;
}

int Pedido::getQtdPasteis()
{
    return qtdPasteis;
}
void Pedido::setQtdPasteis(int aux)
{
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
    Pedido *getDados();

    void setProx(NodoFila *aux);
    NodoFila *getProx();
};

//#endif

//#include "nodoFila.h"

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

//#ifndef _FILA_H_
//#define _FILA_H_

//#include <iostream>

//#include "nodoFila.h"
//#include "pedido.h"
class Pedido;
class NodoFila;

using namespace std;

class Fila
{
  public:
    NodoFila *inicio, *fim;

    int tam;

    Fila();
    ~Fila();

    void adiciona(Pedido *aux);
    Pedido *retira();
    int tamanho();
    bool vazia();
};

//#endif

//#include "fila.h"

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

    int getTRest(float tempo); //retorna tempo restante de montagem

    void setTempoAt(int aux);

    bool getDisp();
    void setDisp(bool aux);

    bool getPronto();

    void pedido(Pedido *P, float tempo);
    Pedido *getPedido();
    Mont();
    ~Mont();
};
//#endif

//#include "mont.h"

Mont::Mont()
{
    disponivel = true;
    tRest = -1;
    tAtual = -1;
    Atual = NULL;
    t = -1;
    pronto = false;
}
Mont::~Mont()
{
}
int Mont::getTRest(float tempo)
{
    tRest = Atual->getProcTempo() - tempo + t;
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

void Mont::pedido(Pedido *P, float tempo)
{
    //cout << "Mont pedido" << endl;
    Atual = P;
    t = Atual->getQtdPasteis() * 1 + Atual->getQtdPizza() * 3;
    disponivel = false;
    Atual->setProcTempo(tempo);
}

Pedido *Mont::getPedido()
{
    return Atual;
}

bool Mont::getPronto()
{

    if (getTRest(tAtual) <= 0)
    {

        return pronto = true;
    }
    else
        return pronto = false;
}

void Mont::setDisp(bool aux)
{
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
    int t;     //tempo total de cozimento
    Pedido *Atual;

    bool getDisp();

    void setDisp(bool aux);

    void setTempoAt(int aux);

    int getTRest(float tempo); //retorna tempo restante de cozimento
    void pedido(Pedido *P, float tempo);

    Pedido *getPedido();

    bool getPronto();

    Cozim();
    ~Cozim();
};
//#endif

//#include "cozim.h"

Cozim::Cozim()
{
    disponivel = true;
    tRest = -1;
    tAtual = -1;
    Atual = NULL;
    t = -1;
    pronto = false;
}
Cozim::~Cozim()
{
}
int Cozim::getTRest(float tempo)
{
    tRest = Atual->getProcTempo() - tempo + t;
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

void Cozim::pedido(Pedido *P, float tempo)
{
    //cout << "Cozim pedido" << endl;
    Atual = P;
    t = Atual->getQtdPasteis() * 2 + Atual->getQtdPizza() * 4;
    disponivel = false;
    Atual->setProcTempo(tempo);
}
Pedido *Cozim::getPedido()
{

    return Atual;
}

bool Cozim::getPronto()
{
    if (getTRest(tAtual) <= 0)
    {

        return pronto = true;
    }
    else
        return pronto = false;
}

void Cozim::setDisp(bool aux)
{
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

    int getTRest(float tempo); //retorna tempo restante de empacotamento

    void setTempoAt(int aux);
    bool getDisp();
    void setDisp(bool aux);

    Pedido *getPedido();
    void pedido(Pedido *P, float tempo);
    Empac();
    ~Empac();
    bool getPronto();
};
//#endif

//#include "empac.h"

Empac::Empac()
{
    disponivel = true;
    tRest = -1;
    tAtual = -1;
    Atual = NULL;
    t = -1;
    pronto = false;
}
Empac::~Empac()
{
}
int Empac::getTRest(float tempo)
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

void Empac::pedido(Pedido *P, float tempo)
{
    // cout << "Cozim pedido" << endl;
    Atual = P;
    t = Atual->getQtdPasteis() * 1 + Atual->getQtdPizza() * 1;
    disponivel = false;
    Atual->setProcTempo(tempo);
}
Pedido *Empac::getPedido()
{

    return Atual;
}

bool Empac::getPronto()
{
    if (getTRest(tAtual) <= 0)
    {

        return pronto = true;
    }
    else
        return pronto = false;
}

void Empac::setDisp(bool aux)
{
    disponivel = aux;
}
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <cstdlib>
//#include <stdlib.h>
//#include "fila.h"
//#include "pedido.h"
//#include "cozim.h"
//#include "mont.h"
//#include "empac.h"

using namespace std;

int main()
{
    Fila M; //Fila de pedidos antes de entrar no montador
    Fila F; // Fila de pedidos antes de entrar no forno
    Fila E; //Fila de pedidos antes de entrar no empacotador
    Pedido *P, *aux;
    Mont M1, M2, M3;  // 3 montadores
    Cozim F1, F2, F3; //3 fornos
    Empac E1, E2, E3; //3 empacotadores
    int control, numP;
    float tempo, entregues, tempoMedio, aux1;
    tempoMedio = 0;
    numP = 0; //numero do pedido
    tempo = 0;
    aux1 = 0; //auxiliar para o calculo da media de tempo
    entregues = 0;
    control = 0;
    while (cin.get() != 'q')
    {
        control = rand() % 100 + 1;
        if (control > 80)
        {
            numP++;
            P = new Pedido(tempo, numP); //novo pedido
            M.adiciona(P);               // adiciona o pedido a fila
        }

        M1.setTempoAt(tempo); //adiciona o tempo atual a cada processo
        M2.setTempoAt(tempo);
        M3.setTempoAt(tempo);
        F1.setTempoAt(tempo);
        F2.setTempoAt(tempo);
        F3.setTempoAt(tempo);
        E1.setTempoAt(tempo);
        E2.setTempoAt(tempo);
        E3.setTempoAt(tempo);

        if (M1.getDisp() == true) // verifica se cada processo esta disponivel para consultar se a fila tem itens,
        {
            if (M.vazia() != true)
            {

                aux = M.retira(); //se houver, retira o primeiro elemento
                if (aux != NULL)
                {
                    M1.pedido(aux, tempo);
                }
            }
        }
        if (M2.getDisp() == true)
        {
            if (M.vazia() != true)
            {

                aux = M.retira();
                if (aux != NULL)
                {
                    M2.pedido(aux, tempo);
                }
            }
        }
        if (M3.getDisp() == true)
        {
            if (M.vazia() != true)
            {

                aux = M.retira();
                if (aux != NULL)
                {
                    M3.pedido(aux, tempo);
                }
            }
        }
        //montador pronto

        if (M1.getDisp() == false)
        {                               // verifica se nao esta disponivel, ou seja, em processo
            if (M1.getPronto() == true) // verifica se esta pronto, se o processo esta pronto
            {

                aux = M1.getPedido();
                if (aux != NULL)
                {
                    F.adiciona(aux); // passa para a proxima fila
                    M1.setDisp(true);
                } // libera o processo
            }
        }
        if (M2.getDisp() == false)
        {
            if (M2.getPronto() == true)
            {

                aux = M2.getPedido();
                if (aux != NULL)
                {
                    F.adiciona(aux);

                    M2.setDisp(true);
                }
            }
        }
        if (M3.getDisp() == false)
        {
            if (M3.getPronto() == true)
            {
                aux = M3.getPedido();
                if (aux != NULL)
                {
                    F.adiciona(aux);
                    M3.setDisp(true);
                }
            }
        }
        //
        if (F1.getDisp() == true)
        {
            if (F.vazia() != true)
            {

                aux = F.retira();
                if (aux != NULL)
                {
                    F1.pedido(aux, tempo);
                }
            }
        }
        if (F2.getDisp() == true)
        {
            if (F.vazia() != true)
            {

                aux = F.retira();
                if (aux != NULL)
                {
                    F2.pedido(aux, tempo);
                }
            }
        }
        if (F3.getDisp() == true)
        {
            if (F.vazia() != true)
            {

                aux = F.retira();
                if (aux != NULL)
                {
                    F3.pedido(aux, tempo);
                }
            }
        }
        //forno pronto
        if (F1.getDisp() == false)
        {
            if (F1.getPronto() == true)
            {

                aux = F1.getPedido();
                if (aux != NULL)
                {
                    E.adiciona(aux);
                    F1.setDisp(true);
                }
            }
        }
        if (F2.getDisp() == false)
        {
            if (F2.getPronto() == true)
            {
                aux = F2.getPedido();
                if (aux != NULL)
                {
                    E.adiciona(aux);
                    F2.setDisp(true);
                }
            }
        }
        if (F3.getDisp() == false)
        {
            if (F3.getPronto() == true)
            {
                aux = F3.getPedido();
                if (aux != NULL)
                {
                    E.adiciona(aux);
                    F3.setDisp(true);
                }
            }
        }
        //
        if (E1.getDisp() == true)
        {
            if (E.vazia() != true)
            {
                aux = E.retira();
                if (aux != NULL)
                {
                    E1.pedido(aux, tempo);
                }
            }
        }
        if (E2.getDisp() == true)
        {
            if (E.vazia() != true)
            {
                aux = E.retira();
                if (aux != NULL)
                {
                    E2.pedido(aux, tempo);
                }
            }
        }
        if (E3.getDisp() == true)
        {
            if (E.vazia() != true)
            {
                aux = E.retira();
                if (aux != NULL)
                {
                    E3.pedido(aux, tempo);
                }
            }
        }

        system("clear");
        cout << "Status das listas" << endl;
        cout << "Quantidades de pedidos na fila de Montagem: " << M.tamanho() << endl;
        if (M1.getDisp() == false)
            cout << "Montador 1 falta " << M1.getTRest(tempo) << " instantes para finalizar o pedido " << M1.getPedido()->num << endl;
        else
            cout << "Montador 1 vazio" << endl;
        if (M2.getDisp() == false)
            cout << "Montador 2 falta " << M2.getTRest(tempo) << " instantes para finalizar o pedido " << M2.getPedido()->num << endl;
        else
            cout << "Montador 2 vazio" << endl;
        if (M3.getDisp() == false)
            cout << "Montador 3 falta " << M3.getTRest(tempo) << " instantes para finalizar o pedido " << M3.getPedido()->num << endl;
        else
            cout << "Montador 3 vazio" << endl;
        cout << "Quantidades de pedidos na fila de Cozimento: " << F.tamanho() << endl;
        if (F1.getDisp() == false)
            cout << "Forno 1 falta " << F1.getTRest(tempo) << " instantes para finalizar o pedido " << F1.getPedido()->num << endl;
        else
            cout << "Forno 1 vazio" << endl;
        if (F2.getDisp() == false)
            cout << "Forno 2 falta " << F2.getTRest(tempo) << " instantes para finalizar o pedido " << F2.getPedido()->num << endl;
        else
            cout << "Forno 2 vazio" << endl;

        if (F3.getDisp() == false)
            cout << "Forno 3 falta " << F3.getTRest(tempo) << " instantes para finalizar o pedido " << F3.getPedido()->num << endl;
        else
            cout << "Forno 3 vazio" << endl;
        cout << "Quantidades de pedidos na fila de Empacotamento: " << E.tamanho() << endl;
        if (E1.getDisp() == false)
            cout << "Empacotador 1 falta " << E1.getTRest(tempo) << " instantes para finalizar o pedido " << E1.getPedido()->num << endl;
        else
            cout << "Empacotador 1 vazio" << endl;
        if (E2.getDisp() == false)
            cout << "Empacotador 2 falta " << E2.getTRest(tempo) << " instantes para finalizar o pedido " << E2.getPedido()->num << endl;
        else
            cout << "Empacotador 2 vazio" << endl;
        if (E3.getDisp() == false)
            cout << "Empacotador 3 falta " << E3.getTRest(tempo) << " instantes para finalizar o pedido " << E3.getPedido()->num << endl;
        else
            cout << "Empacotador 3 vazio" << endl;
        if (entregues > 0)
        {
            cout << entregues << " pedidos entregues em " << tempo << " instantes." << endl;
            tempoMedio = aux1 / entregues;
            cout << "Tempo medio de atendimento: " << tempoMedio << endl;
        }
        //empacotamento pronto
        if (E1.getDisp() == false)
        {
            if (E1.getPronto() == true)
            {
                aux = E1.getPedido();
                if (aux != NULL)
                {
                    cout << "Pedido de numero " << aux->getNum() << ", com " << aux->getQtdPasteis() << " pasteis e " << aux->getQtdPizza() << " pizzas, foi entregue." << endl;
                    E1.setDisp(true);
                    entregues++;
                    aux1 = aux1 + (tempo - aux->getITempo());
                    delete aux;
                }
            }
        }
        if (E2.getDisp() == false)
        {
            if (E2.getPronto() == true)
            {
                aux = E2.getPedido();
                if (aux != NULL)
                {
                    cout << "Pedido de numero " << aux->getNum() << ", com " << aux->getQtdPasteis() << " pasteis e " << aux->getQtdPizza() << " pizzas, foi entregue." << endl;
                    E2.setDisp(true);
                    entregues++;
                    aux1 = aux1 + (tempo - aux->getITempo());
                    delete aux;
                }
            }
        }
        if (E3.getDisp() == false)
        {
            if (E3.getPronto() == true)
            {
                aux = E3.getPedido();
                if (aux != NULL)
                {
                    cout << "Pedido de numero " << aux->getNum() << ", com " << aux->getQtdPasteis() << " pasteis e " << aux->getQtdPizza() << " pizzas, foi entregue." << endl;

                    E3.setDisp(true);
                    entregues++;
                    aux1 = aux1 + (tempo - aux->getITempo());
                    delete aux;
                }
            }
        }
        tempo++;
    }
    return 0;
}
