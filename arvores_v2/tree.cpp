#include "tree.h"
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
    if (no != nullptr)
    {
        no->altura = 1 + max(altura(no->subArvEsq), altura(no->subArvDir));
        no->FB = altura(no->subArvEsq) - altura(no->subArvDir);
    }
}

void rotacaoSimplesDir(TipoApontador *raiz, TipoApontador no)
{
    if (!no || !no->subArvEsq) return;
    TipoApontador filho = no->subArvEsq;
    TipoApontador pai = no->noPai;
    
    no->subArvEsq = filho->subArvDir;
    if (filho->subArvDir) filho->subArvDir->noPai = no;
    
    filho->subArvDir = no;
    filho->noPai = pai;
    no->noPai = filho;
    
    if (pai)
        (pai->subArvEsq == no ? pai->subArvEsq : pai->subArvDir) = filho;
    else
        *raiz = filho;
    
    atualizarAltura(no);
    atualizarAltura(filho);
}

void rotacaoSimplesEsq(TipoApontador *raiz, TipoApontador no)
{
    if (!no || !no->subArvDir) return;
    TipoApontador filho = no->subArvDir;
    TipoApontador pai = no->noPai;
    
    no->subArvDir = filho->subArvEsq;
    if (filho->subArvEsq) filho->subArvEsq->noPai = no;
    
    filho->subArvEsq = no;
    filho->noPai = pai;
    no->noPai = filho;
    
    if (pai)
        (pai->subArvDir == no ? pai->subArvDir : pai->subArvEsq) = filho;
    else
        *raiz = filho;
    
    atualizarAltura(no);
    atualizarAltura(filho);
}

void balancear(TipoApontador *raiz, TipoApontador no)
{
    while (no)
    {
        atualizarAltura(no);
        if (no->FB > 1)
        {
            if (no->subArvEsq->FB < 0)
                rotacaoSimplesEsq(raiz, no->subArvEsq);
            rotacaoSimplesDir(raiz, no);
        }
        else if (no->FB < -1)
        {
            if (no->subArvDir->FB > 0)
                rotacaoSimplesDir(raiz, no->subArvDir);
            rotacaoSimplesEsq(raiz, no);
        }
        no = no->noPai;
    }
}

void inserirNo(TipoApontador *raiz, TipoApontador novo)
{
    if (*raiz == nullptr)
    {
        *raiz = novo;
        return;
    }
    TipoApontador atual = *raiz, pai = nullptr;
    while (atual)
    {
        pai = atual;
        if (novo->Valor < atual->Valor)
            atual = atual->subArvEsq;
        else
            atual = atual->subArvDir;
    }
    novo->noPai = pai;
    if (novo->Valor < pai->Valor)
        pai->subArvEsq = novo;
    else
        pai->subArvDir = novo;
    
    balancear(raiz, pai);
}

void removerNo(TipoApontador *raiz, int no)
{
    TipoApontador alvo = buscarNo(*raiz, no);
    if (!alvo) return;
    
    TipoApontador pai = alvo->noPai;
    TipoApontador substituto = nullptr;
    
    if (!alvo->subArvEsq || !alvo->subArvDir)
        substituto = alvo->subArvEsq ? alvo->subArvEsq : alvo->subArvDir;
    else
    {
        substituto = alvo->subArvDir;
        while (substituto->subArvEsq)
            substituto = substituto->subArvEsq;
        
        if (substituto->noPai != alvo)
        {
            substituto->noPai->subArvEsq = substituto->subArvDir;
            if (substituto->subArvDir)
                substituto->subArvDir->noPai = substituto->noPai;
            substituto->subArvDir = alvo->subArvDir;
            alvo->subArvDir->noPai = substituto;
        }
        substituto->subArvEsq = alvo->subArvEsq;
        alvo->subArvEsq->noPai = substituto;
    }
    
    if (!pai)
        *raiz = substituto;
    else if (alvo == pai->subArvEsq)
        pai->subArvEsq = substituto;
    else
        pai->subArvDir = substituto;
    
    if (substituto)
        substituto->noPai = pai;
    delete alvo;
    
    balancear(raiz, pai);
}

void pre_ordem(TipoApontador raiz)
{
    if (raiz)
    {
        cout << raiz->Valor << " ";
        pre_ordem(raiz->subArvEsq);
        pre_ordem(raiz->subArvDir);
    }
}