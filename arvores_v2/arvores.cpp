#include "arvores.h"
#include <iostream>

using namespace std;

TipoApontador criarNo(int no)
{
    TipoApontador novo = new TipoNo;
    novo->Valor = no;
    novo->subArvEsq = nullptr;
    novo->subArvDir = nullptr;
    novo->noPai = nullptr;
    return novo;
}

TipoApontador buscarNo(TipoApontador raiz, int no)
{
    if(raiz == nullptr)
        return raiz;
    
    if(no == raiz->Valor)
        return raiz;
    else if(no < raiz->Valor)
        return buscarNo(raiz->subArvEsq,no);
    else
        return  buscarNo(raiz->subArvDir,no);
    
    return nullptr;
}

void inserirNo(TipoApontador novo,TipoApontador raiz)
{
    if(raiz == nullptr)
    {
        raiz = novo;
        return;
    }
    if(buscarNo(raiz,novo->Valor))
    {   
        cout << "No ja inserido!" << endl;
        return;
    }
    if(novo->Valor < raiz->Valor)
        if(raiz->subArvEsq != nullptr)
            inserirNo(novo,raiz->subArvEsq);
        else
        {
            raiz->subArvEsq = novo;
            novo->noPai = raiz;
        }
    else
        if(raiz->subArvDir != nullptr)
            inserirNo(novo,raiz->subArvDir);
        else
        {
            raiz->subArvDir = novo;
            novo->noPai = raiz;
        }
}

void removerNo(TipoApontador *raiz,int no)
{
    TipoApontador no_rm = buscarNo(*raiz,no);
    if(!no_rm)
        cout << "O no nao existi!" << endl;
    else
    {
        // Caso 1 - Nó sem filhos
        if(!no_rm->subArvEsq && !no_rm->subArvDir)
        {
            // Quando no_rm for a raiz
            if(no_rm == *raiz)
                *raiz = nullptr;
            else 
                if(no_rm->Valor < no_rm->noPai->Valor)
                    no_rm->noPai->subArvEsq = nullptr;
                else
                    no_rm->noPai->subArvDir = nullptr;
            delete no_rm;
        }
        // Caso 2.A - Nó com somente um filho, a esquerda
        else if(no_rm->subArvEsq && !no_rm->subArvDir)
        {
            // Quando no_rm for a raiz
            if(no_rm == *raiz)
            {
                *raiz = no_rm->subArvEsq;
                (*raiz)->noPai = nullptr;
            }
            else
            {
                if(no_rm->Valor < no_rm->noPai->Valor)
                    no_rm->noPai->subArvEsq = no_rm->subArvEsq;
                else
                    no_rm->noPai->subArvDir = no_rm->subArvEsq;
                no_rm->subArvEsq->noPai = no_rm->noPai;
            }
            delete no_rm;   
        }
        // Caso 2.B - Nó com somente um filho, a direita
        else if(!no_rm->subArvEsq && no_rm->subArvDir)
        {
            if(no_rm == *raiz)
            {
                *raiz = no_rm->subArvDir;
                (*raiz)->noPai = nullptr;
            }
            else
            {
                if(no_rm->Valor < no_rm->noPai->Valor)
                    no_rm->noPai->subArvEsq = no_rm->subArvDir;
                else
                    no_rm->noPai->subArvDir = no_rm->subArvDir;
                no_rm->subArvDir->noPai = no_rm->noPai;
            }
            delete no_rm;
        }
        // Caso 3 - Nó com dois filhos
        else
        {
            TipoApontador no_esc = no_rm->subArvDir;
            // Encontrar o nó mais a esquerda
            while(no_esc->subArvEsq)
                no_esc = no_esc->subArvEsq;
            //cout << "No mais a esq: " << no_esc->Valor << endl;
            // Quando no_rm for a raiz
            if(no_rm == *raiz)
            {
                no_rm->subArvEsq->noPai = no_esc;
                no_esc->subArvEsq = no_rm->subArvEsq;
                if(no_esc != no_rm->subArvDir)
                {
                    if(no_esc->subArvDir)
                        no_esc->subArvDir->noPai = no_esc->noPai;
                    no_esc->noPai->subArvEsq = no_esc->subArvDir;
                    no_esc->subArvDir = no_rm->subArvDir;
                    no_rm->subArvDir->noPai = no_esc;
                }
                no_esc->noPai = no_rm->noPai;
                *raiz = no_esc;
                delete no_rm;
            }   
            else
            {
                if(no_rm->Valor < no_rm->noPai->Valor)
                    no_rm->noPai->subArvEsq = no_esc;
                else
                    no_rm->noPai->subArvDir = no_esc;
                no_rm->subArvEsq->noPai = no_esc;
                no_esc->subArvEsq = no_rm->subArvEsq;

                // Quando o nó mais a esquerda não é filho de no_rm
                if(no_esc != no_rm->subArvDir)
                {
                    if(no_esc->subArvDir)
                        no_esc->subArvDir->noPai = no_esc->noPai;
                    no_esc->noPai->subArvEsq = no_esc->subArvDir;
                    no_rm->subArvDir->noPai = no_esc;
                    no_esc->subArvDir = no_rm->subArvDir;
                }
                no_esc->noPai = no_rm->noPai;
                delete no_rm;
            }
        }
    }
}

// Implementação dos percursos
void pre_ordem(TipoApontador raiz)
{
    if(raiz != nullptr)
    {
        cout << raiz->Valor << " ";
        pre_ordem(raiz->subArvEsq);
        pre_ordem(raiz->subArvDir);
    }
}

void intra_ordem(TipoApontador raiz)
{
    if(raiz != nullptr)
    {
        intra_ordem(raiz->subArvEsq);
        cout << raiz->Valor << " ";
        intra_ordem(raiz->subArvDir);
    }
}

void pos_ordem(TipoApontador raiz)
{
    if(raiz != nullptr)
    {
        pos_ordem(raiz->subArvEsq);
        pos_ordem(raiz->subArvDir);
        cout << raiz->Valor << " ";
    }
}