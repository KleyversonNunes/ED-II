#include "./arvore.h"
#include <iostream>
using namespace std;

int main()
{
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

    return 0;
}