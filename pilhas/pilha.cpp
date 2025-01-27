#include "./pilha.h"
//#include <stdlib.h>
#include <iostream>
//#include <string>

void FPVazia(TipoPilha *Pilha)
{
    //Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Pilha->Primeiro = new TipoCelula;
    Pilha->Ultimo = Pilha->Primeiro;
    //Lista->Primeiro->Prox = NULL;
    Pilha->Primeiro->Prox = nullptr;
}

int Vazia(TipoPilha Pilha)
{
    return Pilha.Primeiro == Pilha.Ultimo;
}

void Empilha(TipoItem x, TipoPilha *Pilha)
{
    TipoApontador novo = new TipoCelula;
    if(Vazia(*Pilha))
    {
        Pilha->Ultimo = novo;
        novo->Prox = nullptr;
    }
    novo->Prox = Pilha->Primeiro->Prox;
    novo->Item = x;
    Pilha->Primeiro->Prox = novo;
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{
    if(Vazia(*Pilha))
    {
        std::cout << "Erro: Pilha vazia\n";
        return;
    }
    TipoApontador Aux = Pilha->Primeiro->Prox;
    Pilha->Primeiro->Prox = Aux->Prox;
    if(Aux->Prox == nullptr)
        Pilha->Ultimo = Pilha->Primeiro;
    *Item = Aux->Item;
    delete Aux;
}

void Imprime(TipoPilha Pilha)
{
    TipoApontador Aux;
    Aux = Pilha.Primeiro->Prox;
    while(Aux != NULL)
    {
        std::cout << Aux->Item.Valor << std::endl;
        Aux = Aux->Prox;
    }
}