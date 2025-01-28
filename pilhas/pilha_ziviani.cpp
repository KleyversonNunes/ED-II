#include "./pilha_ziviani.h"
#include <iostream>

void FPVazia(TipoPilha *Pilha)
{
    Pilha->Topo = new TipoCelula;
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = nullptr;
    Pilha->Tamanho = 0;
}

int Vazia(TipoPilha Pilha)
{
    return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TipoItem x, TipoPilha *Pilha)
{
    TipoApontador Aux;
    Aux = new TipoCelula;
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{
    TipoApontador q;
    if(Vazia(*Pilha))
    {
        std::cout << "Erro: A pilha esta vazia" << std::endl;
        return;
    }
    q = Pilha->Topo;
    Pilha->Topo = q->Prox;
    *Item = q->Prox->Item;
    delete q;
    Pilha->Tamanho--;
}

int Tamanho(TipoPilha Pilha)
{
    return Pilha.Tamanho;
}

void Imprime(TipoPilha Pilha)
{
    TipoApontador Aux = Pilha.Topo->Prox; // Pega o elemento do topo
    while(Aux != nullptr)
    {
        std::cout << Aux->Item.Valor << std::endl;
        Aux = Aux->Prox;
    }
}