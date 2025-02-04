#include <iostream>
#include "./grafo_lista_adjacencia.h"

int main()
{
    int vertices = 7;

    Grafo* grafo = CriarGrafo(vertices);

    // Adicionando as arestas
    
    AdicionarAresta(grafo,0,1);
    AdicionarAresta(grafo,0,2);
    AdicionarAresta(grafo,0,4);

    AdicionarAresta(grafo,1,3);
    AdicionarAresta(grafo,1,4);
    AdicionarAresta(grafo,1,5);

    AdicionarAresta(grafo,2,2);
    AdicionarAresta(grafo,2,5);

    AdicionarAresta(grafo,3,0);
    AdicionarAresta(grafo,3,1);
    AdicionarAresta(grafo,3,3);
    AdicionarAresta(grafo,3,6);

    AdicionarAresta(grafo,4,1);
    AdicionarAresta(grafo,4,3);

    AdicionarAresta(grafo,5,1);
    AdicionarAresta(grafo,5,2);
    
    AdicionarAresta(grafo,6,3);
    AdicionarAresta(grafo,6,4);
    AdicionarAresta(grafo,6,5);
    AdicionarAresta(grafo,6,6);
    
    /*
    AdicionarAresta(grafo,0,1);
    AdicionarAresta(grafo,0,4);
    AdicionarAresta(grafo,1,2);
    AdicionarAresta(grafo,1,3);
    AdicionarAresta(grafo,1,4);
    AdicionarAresta(grafo,2,3);
    AdicionarAresta(grafo,3,4);
    */

    // Exibindo o grafo
    Imprime(grafo);

    std::cout << std::endl;
    std::cout << grafo->listaAdj[6]->Vertice;
    std::cout << grafo->listaAdj[6]->Proximo->Vertice;
    std::cout << grafo->listaAdj[6]->Proximo->Proximo->Vertice;
    std::cout << grafo->listaAdj[6]->Proximo->Proximo->Proximo->Vertice;
    std::cout << grafo->listaAdj[6]->Proximo->Proximo->Proximo->Proximo->Vertice;
    return 0;
}
