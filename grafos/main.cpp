#include "./grafo_lista_adjacencia.h"
#include <iostream>

int main()
{
    // Criando um grafo com sete vértices
    TipoGrafo *Grafo = CriarGrafo(4);

    // Inserindo as arestas
    AdicionarAresta(Grafo,0,1);
    AdicionarAresta(Grafo,0,2);
    AdicionarAresta(Grafo,0,3);

    AdicionarAresta(Grafo,1,0);
    AdicionarAresta(Grafo,1,3);

    AdicionarAresta(Grafo,2,0);
    AdicionarAresta(Grafo,3,0);
    AdicionarAresta(Grafo,3,1);

    /*
    AdicionarAresta(Grafo,3,0);
    AdicionarAresta(Grafo,3,1);
    AdicionarAresta(Grafo,3,3);
    AdicionarAresta(Grafo,3,6);

    AdicionarAresta(Grafo,4,1);
    AdicionarAresta(Grafo,4,3);

    AdicionarAresta(Grafo,5,1);
    AdicionarAresta(Grafo,5,2);

    AdicionarAresta(Grafo,6,3);
    AdicionarAresta(Grafo,6,4);
    AdicionarAresta(Grafo,6,5);
    AdicionarAresta(Grafo,6,6);
    */
    

    // Imprimindo o grafo
    Imprime(Grafo);

    std::cout << std::endl;
    RetiraAresta(Grafo,0,2);
    RetiraAresta(Grafo,1,0);
    RetiraAresta(Grafo,3,2);
    Imprime(Grafo);

    //int res = VerificaVertice(Grafo,1,4);
    //std::cout << Grafo->ListaAdj[0]->Proximo->Vertice << std::endl;
    //std::cout << VerificaVertice(Grafo,1,2) << std::endl;

    return 0;
}