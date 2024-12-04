/*
    Aluno: Kleyverson Nunes da Silva
    Matrícula: 202311140004
    Atividade: Implementar uma representação de matriz de adjacências utilizando como base listas encadeadas.
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura para o nó de uma lista encadeada
typedef struct TipoItem {
    int vertice;           // Vértice adjacente
    struct TipoItem* proximo;    // Próximo nó da lista
}TipoItem;

// Estrutura para o grafo usando listas encadeadas
typedef struct Grafo {
    int numVertices;      // Número de vértices
    TipoItem** listaAdj; // Array de ponteiros para listas encadeadas
} Grafo;

// Função para criar um nó da lista encadeada
TipoItem* criarItem(int vertice) {
    TipoItem* novoItem = (TipoItem*)malloc(sizeof(TipoItem));
    novoItem->vertice = vertice;
    novoItem->proximo = NULL;
    return novoItem;
}

// Função para criar um grafo com um número fixo de vértices
Grafo* criarGrafo(int numVertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;

    // Inicializa o array de listas encadeadas
    grafo->listaAdj = (TipoItem**)malloc(numVertices * sizeof(TipoItem*));
    for (int i = 0; i < numVertices; i++) {
        grafo->listaAdj[i] = NULL;
    }

    return grafo;
}

// Função para adicionar uma aresta ao grafo
void adicionarAresta(Grafo* grafo, int V1, int V2) {
    // Adiciona o destino à lista de adjacência do vértice de origem
    TipoItem* novoItem = criarItem(V2);
    novoItem->proximo = grafo->listaAdj[V1];
    grafo->listaAdj[V1] = novoItem;

    // Para grafos não direcionados, adiciona a origem à lista do destino
    novoItem = criarItem(V1);
    novoItem->proximo = grafo->listaAdj[V2];
    grafo->listaAdj[V2] = novoItem;
}

// Função para imprimir o grafo
void imprimeGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        TipoItem* temp = grafo->listaAdj[i];
        printf("Vértice %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertice);
            temp = temp->proximo;
        }
        printf("NULL\n");
    }
}

// Função principal
int main() {
    int numVertices = 5;

    // Cria um grafo com 5 vértices
    Grafo* grafo = criarGrafo(numVertices);

    // Adiciona algumas arestas ao grafo
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 4);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 3, 4);

    // Imprime o grafo
    imprimeGrafo(grafo);

    return 0;
}