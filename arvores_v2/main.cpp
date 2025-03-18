#include "arvores.h"
//#include "arvores.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    TipoApontador raiz, Aux;
    //vector<int> lista = {10,15,13,8,9,6,5,11,12,18,3,16,20,23,17};
    vector<int> lista = {10,15,13,14,11};//,12,8,9,6,5,18,16,17,3,20,23};
    //vector<int> lista = {10,15,12,14,11,13,8,9,6,5,18,16,17,3,20,23};
    //vector<int> lista = {10,7,4,8,15,12,18};

    for(int i = 0;i < lista.size(); i++)
    {
        if(i == 0)
        {
            raiz = criarNo(lista[i]);
            inserirNo(raiz,nullptr);
        }
        else
        {
            inserirNo(criarNo(lista[i]),raiz);
            Aux = buscarNo(raiz,lista[i])->noPai;
            while(Aux != nullptr)
            {
                atualizarAltura(Aux);
                fatorBalanceamento(Aux);
                if(Aux->FB > 1 && Aux->subArvEsq->FB >= 0)
                    rotacaoSimplesDir(&raiz,Aux);
                else if(Aux->FB < -1 && Aux->subArvDir->FB <= 0)
                    rotacaoSimplesEsq(&raiz,Aux);
                else if(Aux->FB > 1 && Aux->subArvEsq->FB < 0)
                    rotacaoDuplaDir(&raiz,Aux);
                else if(Aux->FB < -1 && Aux->subArvDir->FB > 0)
                    rotacaoDuplaEsq(&raiz,Aux);
                Aux = Aux->noPai;
            }
        }
    }

    cout << endl;
    // Imprimindo a arvore
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

    //removerNo(&raiz,8);
    //cout << "Removendo a raiz: ";
    //cout << "Removendo o 8: ";
    //pre_ordem(raiz);
    //cout << endl;

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