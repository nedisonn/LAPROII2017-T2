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
    control = 0;
    while(cin.get() != 'q')
    {

        control = rand()%100 +1;
           if (control > 80)
        {
            numP++;
            P = new Pedido(tempo, numP); //novo pedido
            M.adiciona(P); // adiciona o pedido a fila
        } 
       


        M1.setTempoAt(tempo);
        M2.setTempoAt(tempo);
        M3.setTempoAt(tempo);
        F1.setTempoAt(tempo);
        F2.setTempoAt(tempo);
        F3.setTempoAt(tempo);
        E1.setTempoAt(tempo);
        E2.setTempoAt(tempo);
        E3.setTempoAt(tempo);

     

        if (M1.getDisp() == true)
            {
                if (M.vazia() != true){
                
                aux = M.retira();
               if (aux != NULL){
                M1.pedido(aux, tempo);}}
            }
            if (M2.getDisp() == true)
            {
                if (M.vazia() != true){
                    
                aux = M.retira();
               if (aux != NULL){ 
                M2.pedido(aux, tempo);}}
            }
            if (M3.getDisp() == true)
            {
                if (M.vazia() != true) {
                
                aux = M.retira();
                if (aux != NULL){
                M3.pedido(aux, tempo);}}
            }
//montador pronto
        
                if (M1.getDisp() == false){
                    if (M1.getPronto() == true)
                    {
                   
                        aux = M1.getPedido();
                        if (aux != NULL){
                            F.adiciona(aux);
                            M1.setDisp(true);}
                    }}
                if (M2.getDisp() == false){
                    if (M2.getPronto() == true)
                    {
                    
                         aux = M2.getPedido();
                        if (aux != NULL){
                            F.adiciona(aux);

                            M2.setDisp(true);}
                    }}
                if (M3.getDisp() == false){
                    if (M3.getPronto() == true)
                    {
                 
                        aux = M3.getPedido();

                        if (aux != NULL){
                            F.adiciona(aux);

                             M3.setDisp(true);}
                    }}

        


//
        
            if (F1.getDisp() == true)
            {
                if (F.vazia() != true){
                  
                aux = F.retira();
                if (aux != NULL){
                F1.pedido(aux, tempo);}}
            }
            if (F2.getDisp() == true)
            {
                if (F.vazia() != true){
                    
              aux = F.retira();
                if (aux != NULL){
                F2.pedido(aux, tempo);}}
            }
            if (F3.getDisp() == true)
            {
              if (F.vazia() != true){
                 
            aux = F.retira();
               if (aux != NULL){ 
              F3.pedido(aux, tempo);}}
            }
        

//forno pronto
        
             if (F1.getDisp() == false){
                if (F1.getPronto() == true)
                {
                    
                    aux = F1.getPedido();
                     if (aux != NULL){
                         E.adiciona(aux);
                     F1.setDisp(true);}
                }}

                 if (F2.getDisp() == false){
                if (F2.getPronto() == true)
                {
                   
                    aux = F2.getPedido();
                     if (aux != NULL){
                         E.adiciona(aux);
                     F2.setDisp(true);}
                }}

                 if (F3.getDisp() == false){
                if (F3.getPronto() == true)
                {
                   
                    aux = F3.getPedido();
                 if (aux != NULL){
                     E.adiciona(aux);
                 F3.setDisp(true);}
                }}



        

//
        
            if (E1.getDisp() == true)
            {
                if (E.vazia() != true)
                 {
                    aux = E.retira();
                      if (aux != NULL){
                       E1.pedido(aux, tempo);}}
            }

            if (E2.getDisp() == true)
            {
               if (E.vazia() != true)
        {
                aux = E.retira();
                if (aux != NULL){
        E2.pedido(aux, tempo);}}
            }

            if (E3.getDisp() == true)
            {
                if (E.vazia() != true)
        {
                aux = E.retira();
                if (aux != NULL){
        E3.pedido(aux, tempo);}}
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


    
if (entregues > 0) {
    cout << entregues << " pedidos entregues em " << tempo << " instantes."<< endl;
   tempoMedio = aux1/entregues;
cout << "Tempo medio de atendimento: " << tempoMedio << endl;}


//aparecer na tela por mais tempo...
            if (E1.getDisp() == false ){
                if (E1.getPronto() == true)
                {
                    
                    aux = E1.getPedido();
                    if (aux != NULL){
                        cout <<"Pedido de numero "<<  aux->getNum() << ", com " << aux->getQtdPasteis() << " pasteis e " << aux->getQtdPizza() << " pizzas, foi entregue."<< endl;
                    E1.setDisp(true);
                    entregues++;
                    aux1 = aux1 + aux->getITempo();
                    delete aux;}
                }}

                if(E2.getDisp() == false){
                if (E2.getPronto() == true)
                {
                    
                    aux = E2.getPedido();
                    if (aux != NULL){cout <<"Pedido de numero "<<  aux->getNum() <<", com " << aux->getQtdPasteis() << " pasteis e " << aux->getQtdPizza() << " pizzas, foi entregue."<< endl;
                    E2.setDisp(true);
                    entregues++;
                    aux1 = aux1 + aux->getITempo();
                    delete aux;}
                }}

                if(E3.getDisp() == false){
                if (E3.getPronto() == true)
                {
                    
                    aux = E3.getPedido();
                    if (aux != NULL){cout <<"Pedido de numero "<<  aux->getNum() <<", com " << aux->getQtdPasteis() << " pasteis e " << aux->getQtdPizza() << " pizzas, foi entregue."<< endl;

                    E3.setDisp(true);
                    entregues++;
                    aux1 = aux1 + aux->getITempo();
                    delete aux;
                    }
                }}






        tempo++;
        //cout << tempo << endl;
        cout << control << endl;

    }


    return 0;
}
