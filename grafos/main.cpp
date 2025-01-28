#include <iostream>
#include "./grafo_lista_adjacencia.h"

int main()
{
    int vertices = 5;

    Grafo* grafo = CriarGrafo(vertices);

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
