#include "./arvore.h"
#include <iostream>

using namespace std;

TipoApontador criarNo(int Valor)
{
    TipoApontador novo = new TipoNo;
    novo->Valor = Valor;
    novo->arv_esq = nullptr;
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
        return buscarNo(raiz->arv_esq,no);
    }else
    {
        return buscarNo(raiz->arv_dir,no);
    }
    return 0;
}

void inserirNo(TipoApontador raiz, TipoApontador novo)
{
    if(raiz == nullptr)
    {
        raiz = novo;
        return;
    }    

    if(buscarNo(raiz,novo->Valor) == 1)
    {
        cout << "O no " << novo->Valor << " já está inserido na árvore" << endl;
        return;
    }
    
    //cout << raiz->Valor << " ";
    if(novo->Valor < raiz->Valor)
    {
        if(raiz->arv_esq != nullptr)
            inserirNo(raiz->arv_esq,novo);
        else
            raiz->arv_esq = novo;
    }
    else
    {
        if(raiz->arv_dir != nullptr)
            inserirNo(raiz->arv_dir,novo);
        else
            raiz->arv_dir = novo;
    }
}

// Iplementação algoritmos de percurso
void pre_ordem(TipoApontador no)
{
    if(no != nullptr)
    {
        cout << no->Valor << " ";
        pre_ordem(no->arv_esq);
        pre_ordem(no->arv_dir);
    }
}

void intra_ordem(TipoApontador no)
{
    if(no != nullptr)
    {
        intra_ordem(no->arv_esq);
        cout << no->Valor << " ";
        intra_ordem(no->arv_dir);
    }
}

void pos_ordem(TipoApontador no)
{
    if(no != nullptr)
    {
        pos_ordem(no->arv_esq);
        pos_ordem(no->arv_dir);
        cout << no->Valor << " ";
    }
}