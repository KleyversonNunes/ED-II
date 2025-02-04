#include "./grafo_lista_adjacencia.h"
#include <iostream>

int main()
{
    int vertices = 5;

    // Inserindo as arestas
    AdicionarAresta(Grafo,0,1);
    AdicionarAresta(Grafo,0,2);
    AdicionarAresta(Grafo,0,3);

    AdicionarAresta(Grafo,1,0);
    AdicionarAresta(Grafo,1,3);

    AdicionarAresta(Grafo,2,0);
    AdicionarAresta(Grafo,3,0);
    AdicionarAresta(Grafo,3,1);

    // Adicionando as arestas
    AdicionarAresta(grafo,0,1);
    AdicionarAresta(grafo,0,4);
    AdicionarAresta(grafo,1,2);
    AdicionarAresta(grafo,1,3);
    AdicionarAresta(grafo,1,4);
    AdicionarAresta(grafo,2,3);
    AdicionarAresta(grafo,3,4);

    // Exibindo o grafo
    Imprime(grafo);
    
    return 0;
}