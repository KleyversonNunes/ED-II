#include "./lista.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

// Implementação dos métodos da lista
void FZListaVazia(TipoLista *Lista)
{
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = nullptr;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void InserirItemLista(TipoLista *Lista,TipoItem Item)
{
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = Item;
    Lista->Ultimo->Prox = NULL;
}

void RetirarItemLista(TipoLista *Lista,TipoItem *Item,TipoApontador p)
{
    TipoApontador q;
    if(Vazia(*Lista) || p == NULL || p->Prox == NULL)
    {
        cout << "Erro: Lista vazia ou posicao nao existe" << endl;
        return ;
    }
    q = p->Prox;
    *Item = q->Item;
    p->Prox = q->Prox;
    if(p->Prox == NULL)
        Lista->Ultimo = p;
    free(q);
}

void ImprimirLista(TipoLista Lista)
{
    TipoApontador Aux;
    Aux = Lista.Primeiro->Prox; // Obtendo o primeiro elemento
    while(Aux != NULL)
    {
        cout << Aux->Item.Valor << endl;
        Aux = Aux->Prox;
    }
}