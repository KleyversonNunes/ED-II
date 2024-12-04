#include <stdio.h>
#define SIZE 10

// Função para inicializar a matriz de adjacência com zeros
void inicializarGrafo(int grafo[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grafo[i][j] = 0;
        }
    }
}

// Função para adicionar uma aresta no grafo
void adicionarAresta(int grafo[SIZE][SIZE], int vertice1, int vertice2) {
    if (vertice1 >= 0 && vertice1 < SIZE && vertice2 >= 0 && vertice2 < SIZE) {
        grafo[vertice1][vertice2] = 1;
        grafo[vertice2][vertice1] = 1; // Para grafos não direcionados
    } else {
        printf("Vértices inválidos!\n");
    }
}

// Função para exibir o grafo
void exibirGrafo(int grafo[SIZE][SIZE]) {
    printf("Matriz de Adjacência:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }
}

// Função para calcular o grau de um vértice
int calcularGrau(int grafo[SIZE][SIZE], int vertice) {
    if (vertice < 0 || vertice >= SIZE) {
        printf("Vértice inválido!\n");
        return -1;
    }

    int grau = 0;
    for (int i = 0; i < SIZE; i++) {
        grau += grafo[vertice][i];
    }
    return grau;
}

int main() {
    int grafo[SIZE][SIZE];
    inicializarGrafo(grafo);

    // Adicionando algumas arestas
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 1, 3);

    // Exibindo o grafo
    exibirGrafo(grafo);

    // Calculando o grau de um vértice
    int vertice = 1;
    int grau = calcularGrau(grafo, vertice);
    if (grau != -1) {
        printf("O grau do vértice %d é: %d\n", vertice, grau);
    }

    return 0;
}
