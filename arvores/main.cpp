#include "./arvore.h"
#include <iostream>
using namespace std;

int main()
{
    /*
    TipoApontador raiz = criarNo(10);

    // Montando a árvore
    TipoApontador no8 = criarNo(8);
    raiz->arv_esd = no8;

    TipoApontador no15 = criarNo(15);
    raiz->arv_dir = no15;

    TipoApontador no6 = criarNo(6);
    TipoApontador no9 = criarNo(9);
    no8->arv_esd = no6;
    no8->arv_dir = no9;

    TipoApontador no3 = criarNo(3);
    no6->arv_esd = no3;

    TipoApontador no12 = criarNo(12);
    TipoApontador no17 = criarNo(17);
    no15->arv_esd = no12;
    no15->arv_dir = no17;

    TipoApontador no11 = criarNo(11);
    no12->arv_esd = no11;

    // Buscando um nó
    cout << buscarNo(raiz,10) << endl;
    cout << buscarNo(raiz,12) << endl;
    cout << buscarNo(raiz,4) << endl;

    // Inserindo um no
    inserirNo(raiz,criarNo(5));
    cout << buscarNo(raiz,5) << endl;

    cout << raiz->arv_esd->arv_esd->arv_esd->arv_dir->Valor << endl;

    inserirNo(raiz,criarNo(2));
    cout << buscarNo(raiz,2) << endl;
    cout << raiz->arv_esd->arv_esd->arv_esd->arv_esd->Valor << endl;

    inserirNo(raiz,criarNo(11));
    inserirNo(raiz,criarNo(17));
    inserirNo(raiz,criarNo(22));
    */

    int nos[14] = {10,15,12,8,9,6,5,11,18,3,16,20,23,17};
    TipoApontador raiz = new TipoNo;;

    for(int i = 0;i < 14;i++)
    {
        if(i == 0)
        {
            raiz = criarNo(nos[i]);
            inserirNo(nullptr,raiz);
        }
        else
            inserirNo(raiz,criarNo(nos[i]));
    }

    // Percurso em pre-ordem
    cout << "Pre-ordem -> ";
    pre_ordem(raiz);
    cout << endl;

    // Percurso em intra-ordem ou em ordem
    cout << "Intra-ordem -> ";
    intra_ordem(raiz);
    cout << endl;

    // Percurso em pos-ordem
    cout << "Pos-ordem -> ";
    pos_ordem(raiz);
    cout << endl;

    //retirarNo(raiz,3);
    //retirarNo(raiz,4);
    //retirarNo(raiz,12);
    retirarNo(&raiz,8);
    retirarNo(&raiz,10);
    retirarNo(&raiz,18);
    //retirarNo(raiz,17);

    // Percurso em pre-ordem
    cout << "Pre-ordem -> ";
    pre_ordem(raiz);
    cout << endl;

    return 0;
}