#include <iostream>
#include <sstream>
#include <string>

#include "fila.h"
#include "pedido.h"
#include "cozim.h"
#include "mont.h"
#include "empac.h"


int main ()
{
    Fila M, F, E;
    Pedido *P, *aux;
    Mont M1, M2, M3; // 3 montadores
    Cozim F1, F2, F3; //3 fornos
    Empac E1, E2, E3; //3 empacotadores
//string click;
    int control, tempo, numP;
    numP = 0;
    tempo = 0;
    control = rand() % 100;
//cin >> click;
    while(cin.get() != 'q')
    {

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
            P = new Pedido(tempo, numP);
            M.adiciona(P);
            if (M1.getDisp() == true)
            {
                M1.pedido(P);
            }
            else if (M2.getDisp() == true)
            {
                M2.pedido(P);
            }
            else if (M3.getDisp() == true)
            {
                M3.pedido(P);
            }
            if (M1.getDisp() == true|| M2.getDisp() == true || M3.getDisp() == true)
            {
                if (F1.getDisp() == true)
                {
                    aux = M1.getPedido();
                    F1.pedido(aux);
                }
                else if (F2.getDisp() == true)
                {
                    aux = M1.getPedido();
                    F2.pedido(aux);
                }
                else if (F3.getDisp() == true)
                {
                    aux = M1.getPedido();
                    F3.pedido(aux);
                }
                 else
				 F.adiciona(P);
            }
            if (M1.getDisp() == true || M2.getDisp() == true || M3.getDisp() == true)
            {
                if (E1.getDisp() == true)
                {
                    aux = E1.getPedido();
                    E1.pedido(aux);
                }
                else if (E2.getDisp() == true)
                {
                    aux = E1.getPedido();
                    E2.pedido(P);
                }
                else if (E3.getDisp() == true)
                {
                    aux = E1.getPedido();
                    E3.pedido(P);
                }
                else
					E.adiciona(P);
            }

        }




        tempo++;
        cout << tempo << endl;
//cin >> click;
        system("clear");
        cout << "Status das listas"<< endl;

        cout << "Quantidades de pedidos na fila de Montagem: " << M.tamanho() << endl;

        cout << "Montador 1: " << endl;
        cout << "Montador 2: " << endl;
        cout << "Montador 3: " <<  endl;

        cout << "Quantidades de pedidos na fila de Cozimento: " << F.tamanho() << endl;

        cout << "Forno 1: " <<  endl;
        cout << "Forno 2: " <<  endl;
        cout << "Forno 3: " <<  endl;

        cout << "Quantidades de pedidos na fila de Empacotamento: " << E.tamanho() << endl;

        cout << "Empacotador 1: " << endl;
        cout << "Empacotador 2: " << endl;
        cout << "Empacotador 3: " << endl;

        cout << "Tempo medio de atendimento: " << endl;






    }









    return 0;
}
