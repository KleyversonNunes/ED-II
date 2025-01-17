#include "./lista.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x,TipoLista *Lista)
{
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void Retira(TipoApontador p,TipoLista *Lista,TipoItem *Item)
{
    TipoApontador q;
    if(Vazia(*Lista) || p == NULL || p->Prox == NULL)
    {
        cout << "Erro: Lista vazia ou posicao nao existe\n";
        return;
    }
    q = p->Prox;
    p->Prox = q->Prox;
    if(p->Prox == NULL)
        Lista->Ultimo = p;
    free(q);
}

void Imprime(TipoLista Lista)
{
    TipoApontador Aux;
    Aux = Lista.Primeiro->Prox;
    while(Aux != NULL)
    {
        cout << Aux->Item.Valor << endl;
        Aux = Aux->Prox;
    }
}