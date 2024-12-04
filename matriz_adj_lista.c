/*
    Aluno: Kleyverson Nunes da Silva
    Matrícula: 202311140004
    Atividade: Implementar uma representação de matriz de adjacências utilizando como base listas encadeadas.
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura para o nó de uma lista encadeada
typedef struct Node {
    int vertex;           // Vértice adjacente
    struct Node* next;    // Próximo nó da lista
} Node;

// Estrutura para o grafo usando listas encadeadas
typedef struct Graph {
    int numVertices;      // Número de vértices
    Node** adjacencyList; // Array de ponteiros para listas encadeadas
} Graph;

// Função para criar um nó da lista encadeada
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo com um número fixo de vértices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Inicializa o array de listas encadeadas
    graph->adjacencyList = (Node**)malloc(numVertices * sizeof(Node*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(Graph* graph, int src, int dest) {
    // Adiciona o destino à lista de adjacência do vértice de origem
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Para grafos não direcionados, adiciona a origem à lista do destino
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Função para imprimir o grafo
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjacencyList[i];
        printf("Vértice %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Função principal
int main() {
    int numVertices = 5;

    // Cria um grafo com 5 vértices
    Graph* graph = createGraph(numVertices);

    // Adiciona algumas arestas ao grafo
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Imprime o grafo
    printGraph(graph);

    return 0;
}