#include "./grafo_lista_adjacencia.h"
#include <iostream>

using namespace std;

TipoApontador CriarVertice(int Vertice)
{
    TipoApontador novo = new TipoVertice;
    novo->Vertice = Vertice;
    novo->Proximo = nullptr;
    return novo;
}

TipoGrafo *CriarGrafo(int numVert)
{
    TipoGrafo *Grafo = new TipoGrafo;
    Grafo->numVertices = numVert;
    Grafo->ListaAdj = new TipoApontador[numVert];

    for(int i = 0;i < numVert;i++)
        Grafo->ListaAdj[i] = nullptr;
    
    return Grafo;
}

int VerificaAresta(TipoGrafo *Grafo,int origem,int destino)
{
    TipoApontador Aux = Grafo->ListaAdj[origem];
    while(Aux != nullptr)
    {
        if(Aux->Vertice == destino)
            return 1;
        Aux = Aux->Proximo;
    }
    return 0;
}

void AdicionarAresta(TipoGrafo *Grafo,int origem,int destino)
{
    if(VerificaAresta(Grafo,origem,destino) == 0)
    {
        TipoApontador novo = CriarVertice(destino);
        novo->Proximo = Grafo->ListaAdj[origem];
        Grafo->ListaAdj[origem] = novo;
    }
    
    if(VerificaAresta(Grafo,destino,origem) == 0)
    {
        TipoApontador novo2 = CriarVertice(origem);
        novo2->Proximo = Grafo->ListaAdj[destino];
        Grafo->ListaAdj[destino] = novo2;
    }
}

void RetiraAresta(TipoGrafo *Grafo,int origem,int destino)
{
    if(VerificaAresta(Grafo,origem,destino) == 1)
    {
        TipoApontador Aux = Grafo->ListaAdj[origem];
        while(Aux->Proximo->Vertice != destino)
            Aux->Proximo;
        TipoApontador q = Aux->Proximo;
        Aux->Proximo = q->Proximo;
        delete q;
    }
    else
        cout << "Aresta nao existe!\n\n";

    return;
}

void Imprime(TipoGrafo *Grafo)
{
    TipoApontador Aux;
    for(int i = 0;i < Grafo->numVertices;i++)
    {
        Aux = Grafo->ListaAdj[i];
        cout << "Vertice " << i << ":" << endl;
        while(Aux != nullptr)
        {
            cout << " -> " << Aux->Vertice;
            Aux = Aux->Proximo;
        }
        cout << endl;
    }
}