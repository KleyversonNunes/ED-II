#include "arvores.h"
#include <iostream>
#include <algorithm>

using namespace std;

TipoApontador criarNo(int no)
{
    TipoApontador novo = new TipoNo;
    novo->Valor = no;
    novo->altura = 0;
    novo->FB = 0;
    novo->subArvEsq = nullptr;
    novo->subArvDir = nullptr;
    novo->noPai = nullptr;
    return novo;
}

int altura(TipoApontador no)
{
    return (no == nullptr) ? -1 : no->altura;
}

void atualizarAltura(TipoApontador no)
{
    if(no != nullptr)
        no->altura = 1 + max(altura(no->subArvEsq),altura(no->subArvDir));
}

void fatorBalanceamento(TipoApontador no)
{
    if(no == nullptr) no->FB = 0;
    no->FB = altura(no->subArvEsq)-altura(no->subArvDir);
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
    if(!buscarNo(*raiz,no)){
        cout << "O no nao existe!" << endl;
        return;
    }
    else
    {
        TipoApontador no_rm = buscarNo(*raiz,no);
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
            return;
        }
        // Caso 2 - Nó com somente um filho
        else if(!no_rm->subArvEsq || !no_rm->subArvDir)
        {
            TipoApontador noFilho = (no_rm->subArvEsq) ? no_rm->subArvEsq : no_rm->subArvDir;
            // Quando no_rm for a raiz
            if(no_rm == *raiz)
            {
                *raiz = noFilho;
                (*raiz)->noPai = nullptr;
            }
            else
            {
                if(no_rm->Valor < no_rm->noPai->Valor)
                    no_rm->noPai->subArvEsq = noFilho;
                else
                    no_rm->noPai->subArvDir = noFilho;
                noFilho->noPai = no_rm->noPai;
            }
            delete no_rm;
            return;
        }
        // Caso 3 - Nó com dois filhos
        else
        {
            TipoApontador no_esc = no_rm->subArvDir;
            // Encontrar o nó mais a esquerda
            while(no_esc->subArvEsq)
                no_esc = no_esc->subArvEsq;
            
            no_rm->subArvEsq->noPai = no_esc;
            no_esc->subArvEsq = no_rm->subArvEsq;
            if(no_esc != no_rm->subArvDir)
            {
                if(no_esc->subArvDir)
                    no_esc->subArvDir->noPai = no_esc->noPai;
                no_esc->noPai->subArvEsq = no_esc->subArvDir;
                no_rm->subArvDir->noPai = no_esc;
                no_esc->subArvDir = no_rm->subArvDir;
            }
            no_esc->noPai = no_rm->noPai;
            
            // Quando no_rm for a raiz
            if(no_rm == *raiz)
                *raiz = no_esc;
            else
                if(no_rm->Valor < no_rm->noPai->Valor)
                    no_rm->noPai->subArvEsq = no_esc;
                else
                    no_rm->noPai->subArvDir = no_esc;
            delete no_rm;
            return;
        }
    }
}

// Implementação dos percursos
void pre_ordem(TipoApontador raiz)
{
    if(raiz != nullptr)
    {
        cout << raiz->Valor << " (" << "Alt = " << raiz->altura << " FB = " << raiz->FB << ")" << endl;
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