#include "./lista.h"
//#include <stdlib.h>
#include <iostream>
//#include <string>

void FLVazia(TipoLista *Lista)
{
    //Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Primeiro = new TipoCelula;
    Lista->Ultimo = Lista->Primeiro;
    //Lista->Primeiro->Prox = NULL;
    Lista->Primeiro->Prox = nullptr;
}

int Vazia(TipoLista Lista)
{
    return Lista.Primeiro == Lista.Ultimo;
}

void Insere(TipoItem x, TipoLista *Lista)
{
    //Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo->Prox = new TipoCelula;

    if(Lista->Ultimo->Prox == nullptr)
    {
        std::cout << "Erro ao alocar memória para a célula!" << std::endl;
        return;
    }

    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    //Lista->Ultimo->Prox = NULL;
    Lista->Ultimo->Prox = nullptr;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{
    TipoApontador q;
    //if(Vazia(*Lista) || p == NULL || p->Prox == NULL)
    if(Vazia(*Lista) || p == nullptr || p->Prox == nullptr)
    {
        std::cout << "Erro: Lista vazia ou posicao nao existe\n";
        return;
    }
    q = p->Prox;
    *Item = q->Item;
    p->Prox = q->Prox;
    //if(p->Prox == NULL)
    if(p->Prox == nullptr)
        Lista->Ultimo = p;
    //free(q);
    delete q;
}

void Imprime(TipoLista Lista)
{
    TipoApontador Aux;
    Aux = Lista.Primeiro->Prox;
    while(Aux != NULL)
    {
        std::cout << Aux->Item.Valor << std::endl;
        Aux = Aux->Prox;
    }
}