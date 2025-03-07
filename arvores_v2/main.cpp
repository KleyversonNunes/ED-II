#include "arvores.h"
//#include "arvores.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    TipoApontador raiz;
    //vector<int> lista = {10,15,13,8,9,6,5,11,12,18,3,16,20,23,17};
    vector<int> lista = {10,15,8,9,6,5,18,3,20,23};

    for(int i = 0;i < lista.size(); i++)
    {
        if(i == 0)
        {
            raiz = criarNo(lista[i]);
            inserirNo(raiz);
        }
        else
            inserirNo(criarNo(lista[i]),raiz);
    }

    // Imprimindo a arvore
    cout << "Inicio: ";
    pre_ordem(raiz);
    cout << endl;

    /*
    inserirNo(criarNo(22),raiz);
    cout << "Inserindo o 22: ";
    pre_ordem(raiz);
    cout << endl;

    removerNo(&raiz,9);
    cout << "Removendo o 9: ";
    pre_ordem(raiz);
    cout << endl;

    removerNo(&raiz,3);
    cout << "Removendo o 3: ";
    pre_ordem(raiz);
    cout << endl;

    removerNo(&raiz,6);
    cout << "Removendo o 6: ";
    pre_ordem(raiz);
    cout << endl;

    removerNo(&raiz,11);
    cout << "Removendo o 11: ";
    pre_ordem(raiz);
    cout << endl;

    removerNo(&raiz,23);
    cout << "Removendo o 23: ";
    pre_ordem(raiz);
    cout << endl;
    */

    removerNo(&raiz,10);
    cout << "Removendo a raiz: ";
    pre_ordem(raiz);
    cout << endl;

    /*
    removerNo(&raiz,18);
    cout << "Removendo o 18: ";
    pre_ordem(raiz);
    cout << endl;

    removerNo(&raiz,15);
    cout << "Removendo o 15: ";
    pre_ordem(raiz);
    cout << endl;
    */
    return 0;
}