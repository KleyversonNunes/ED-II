#include <iostream>

typedef struct no *TipoApontador;

typedef struct no
{
    int Vertice;
    TipoApontador Proximo;
}no;

typedef struct Grafo
{
    int numVertices;
    TipoApontador *listaAdj;
}Grafo;

// Métodos
TipoApontador CriarNo(int);
Grafo* CriarGrafo(int);
void AdicionarAresta(Grafo *,int,int);
void Imprime(Grafo *);