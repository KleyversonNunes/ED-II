#include "./arvore.h"
#include <iostream>

using namespace std;

TipoApontador criarNo(int Valor)
{
    TipoApontador novo = new TipoNo;
    novo->Valor = Valor;
    novo->arv_esd = nullptr;
    novo->arv_dir = nullptr;
    return novo;
}

int buscarNo(TipoApontador raiz, int no)
{
    /*
        1 -> Encontrou o nó
        0 -> Não encontrou o nó
    */
    if(raiz == nullptr)
        return 0;
    
    if(no == raiz->Valor)
    {   
        cout << "\n" << no << " foi encontrado!" << endl;
        return 1;
    }else if(no < raiz->Valor)
    {    
        return buscarNo(raiz->arv_esd,no);
    }else
    {
        return buscarNo(raiz->arv_dir,no);
    }
    return 0;
}

void inserirNo(TipoApontador raiz, TipoApontador novo)
{
    if(buscarNo(raiz,novo->Valor) == 1)
    {
        cout << "O " << novo->Valor << " no já está inserido na árvore" << endl;
        return;
    }
    else
    {
        cout << raiz->Valor << " ";
        if(novo->Valor < raiz->Valor)
        {
            if(raiz->arv_esd != nullptr)
                inserirNo(raiz->arv_esd,novo);
            else
            {
                raiz->arv_esd = novo;
                return;
            }
        }
        else
        {
            if(raiz->arv_dir != nullptr)
                inserirNo(raiz->arv_dir,novo);
            else
            {
                raiz->arv_dir = novo;
                return;
            }    
        }
    }
}