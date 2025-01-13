#include "./lista.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

// Implementação dos métodos da lista
void FZListaVazia(TipoLista *Lista)
{
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

// Insere em qualquer posição da lista
void InserirItemLista(TipoLista *Lista,TipoItem Item,int posicao = 1)
{
    TipoApontador q = Lista->Primeiro;
    TipoApontador novo = (TipoApontador)malloc(sizeof(TipoCelula));
    novo->Item = Item;
    novo->Prox = NULL;

    if(posicao == 1)
    {
        novo->Prox = Lista->Primeiro;
        Lista->Primeiro = novo;
        if(Lista->Ultimo == Lista->Primeiro)
            Lista->Ultimo = novo;
    }
    else
    {
        TipoApontador q = Lista->Primeiro;
        for(int i = 1;i < posicao-1;i++)
            q = q->Prox;
        novo->Prox = q->Prox;
        q->Prox = novo;
        if(novo->Prox == NULL)
            Lista->Ultimo = novo;
    }
    
}

// Insere apenas no final da lista
/*
void InserirItemLista(TipoLista *Lista,TipoItem Item)
{
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = Item;
    Lista->Ultimo->Prox = NULL;
}
*/

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