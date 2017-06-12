#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include "fila.h"
#include "pedido.h"
#include "cozim.h"
#include "mont.h"
#include "empac.h"

using namespace std;

int main ()
{
    Fila M; //Fila de pedidos antes de entrar no montador
    Fila F; // Fila de pedidos antes de entrar no forno
    Fila E; //Fila de pedidos antes de entrar no empacotador
    Pedido *P, *aux;
    Mont M1, M2, M3; // 3 montadores
    Cozim F1, F2, F3; //3 fornos
    Empac E1, E2, E3; //3 empacotadores
    int control, numP;
    float tempo, entregues,tempoMedio, aux1;
    tempoMedio = 0;
    numP = 0;
    tempo = 0;
    aux1 = 0;
    entregues = 0;
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
                if (M.vazia() != true) aux = M.retira();
                M1.pedido(aux);
            }
            else if (M2.getDisp() == true)
            {
                if (M.vazia() != true) aux = M.retira();
                M2.pedido(aux);
            }
            else if (M3.getDisp() == true)
            {
                if (M.vazia() != true) aux = M.retira();
                M3.pedido(aux);
            }
        }

//montador pronto
        if (M1.getDisp() == false || M2.getDisp() == false || M3.getDisp() == false)
        {
                if (M1.getDisp() == false){
                if (M1.getPronto() == true)
                {
                    aux = M1.getPedido();
                F.adiciona(aux);

                    M1.setDisp(true);
                }}
                 if (M2.getDisp() == false){
                if (M2.getPronto() == true)
                {
                    aux = M2.getPedido();
                F.adiciona(aux);

                    M2.setDisp(true);
                }}
                if (M3.getDisp() == false){
                if (M3.getPronto() == true)
                {
                    aux = M3.getPedido();

                F.adiciona(aux);

                    M3.setDisp(true);
                }}

        }


//
        if(F.vazia() != true)
        {
            if (F1.getDisp() == true)
            {
                if (F.vazia() != true) aux = F.retira();
                F1.pedido(aux);
            }
            else if (F2.getDisp() == true)
            {
              if (F.vazia() != true)  aux = F.retira();
                F2.pedido(aux);
            }
            else if (F3.getDisp() == true)
            {
              if (F.vazia() != true)  aux = F.retira();
                F3.pedido(aux);
            }
        }

//forno pronto
        if (F1.getDisp() == false || F2.getDisp() == false || F3.getDisp() == false)
        {
             if (F1.getDisp() == false){
                if (F1.getPronto() == true)
                {
                    aux = F1.getPedido();
                     E.adiciona(aux);
                    F3.setDisp(true);
                }}
                 if (F2.getDisp() == false){
                if (F2.getPronto() == true)
                {
                    aux = F2.getPedido();
                     E.adiciona(aux);
                    F2.setDisp(true);
                }}

                 if (F3.getDisp() == false){
                if (F3.getPronto() == true)
                {
                    aux = F3.getPedido();
                 E.adiciona(aux);
                    F3.setDisp(true);
                }}



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

if(aux->getNum() == 1) {
    aux1 = aux->getITempo();
}

   tempoMedio = entregues/(tempo-aux1);
    cout << "Tempo medio de atendimento: " << tempoMedio << endl;

    cout << entregues << " pedidos entregues." << endl;


//aparecer na tela por mais tempo...
            if (E1.getDisp() == false ){
                if (E1.getPronto() == true)
                {
                    aux = E1.getPedido();
                    cout <<"Pedido de numero "<<  aux->getNum() << " ,foi entregue"<< endl;
                    E1.setDisp(true);
                    entregues++;
                }}

                if(E2.getDisp() == false){
                if (E2.getPronto() == true)
                {
                    aux = E2.getPedido();
                    cout <<"Pedido de numero "<<  aux->getNum() << " ,foi entregue"<< endl;
                    E2.setDisp(true);
                    entregues++;
                }}

                if(E3.getDisp() == false){
                if (E3.getPronto() == true)
                {
                    aux = E3.getPedido();
                    cout <<"Pedido de numero "<<  aux->getNum() << " ,foi entregue"<< endl;

                    E3.setDisp(true);
                    entregues++;
                }}





        tempo++;
        //cout << tempo << endl;

    }


    return 0;
}
