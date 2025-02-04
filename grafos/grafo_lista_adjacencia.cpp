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
    Grafo* grafo = new Grafo;
    grafo->numVertices = vert;

    grafo->listaAdj = new TipoApontador;

    for(int i = 0;i < vert;i++)
        grafo->listaAdj[i] = NULL;
    
    return Grafo;
}

int VerificaAresta(TipoGrafo *Grafo,int origem,int destino)
{
    // Adiciona a aresta de origem para destino
    TipoApontador NovoNo = CriarNo(destino);
    NovoNo->Proximo = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = NovoNo;

    // Adiciona a aresta de destino para origem (se o grafo for não direcionado)
    NovoNo = CriarNo(origem);
    NovoNo->Proximo = grafo->listaAdj[destino];
    grafo->listaAdj[destino] = NovoNo;
}

void RetiraAresta(TipoGrafo *Grafo,int origem,int destino)
{
    for(int i = 0;i < grafo->numVertices;i++)
    {
        TipoApontador Aux = grafo->listaAdj[i];
        std::cout << "\nLista de adjacencia do vertice " << i << std::endl;
        while(Aux)
        {
            cout << " -> " << Aux->Vertice;
            Aux = Aux->Proximo;
        }
        cout << endl;
    }
    return;
}