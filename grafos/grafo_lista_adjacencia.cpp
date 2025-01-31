#include <iostream>
#include "./grafo_lista_adjacencia.h"\

TipoApontador CriarNo(int vert)
{
    TipoApontador novo = new no;
    novo->Vertice = vert;
    novo->Proximo = nullptr;
    return novo;
}

Grafo* CriarGrafo(int vert)
{
    Grafo* grafo = new Grafo;
    grafo->numVertices = vert;

    grafo->listaAdj = new TipoApontador[vert];

    for(int i = 0;i < vert;i++)
        grafo->listaAdj[i] = nullptr;
    
    return grafo;
}

void AdicionarAresta(Grafo *grafo,int origem, int destino)
{
    // Adiciona a aresta de origem para destino
    TipoApontador NovoNo = CriarNo(destino);
    NovoNo->Proximo = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = NovoNo;

    // Adiciona a aresta de destino para origem (se o grafo for não direcionado)
    /*NovoNo = CriarNo(origem);
    NovoNo->Proximo = grafo->listaAdj[destino];
    grafo->listaAdj[destino] = NovoNo;*/
}

void Imprime(Grafo *grafo)
{
    for(int i = 0;i < grafo->numVertices;i++)
    {
        TipoApontador Aux = grafo->listaAdj[i];
        std::cout << "\nLista de adjacencia do vertice " << i << std::endl;
        while(Aux)
        {
            std::cout << " -> " << Aux->Vertice;
            Aux = Aux->Proximo;
        }
        std::cout << std::endl;
    }
}