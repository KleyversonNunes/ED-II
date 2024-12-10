#include <stdio.h>
#include <stdlib.h>

int grafo[7][7];
char estados[7];

int tempo;
int tempo_descoberta[7];
int tempo_finalizacao[7];
int vertice_antecessor[7];

void dfs_visit(int vertice)
{
    tempo = tempo+1;
    tempo_descoberta[vertice] = tempo;
    estados[vertice] = 'C';
    for(int j = 0;j < 7;j++)
    {
        if(grafo[vertice][j] == 1 && estados[j] == 'B')
        {
            vertice_antecessor[j] = vertice;
            //dfs_visit(grafo[vertice][j]);
            dfs_visit(j);
        }
    }
    estados[vertice] = 'P';
    tempo++;
    tempo_finalizacao[vertice] = tempo;
}

void dfs()
{
    /*
        Os estados podem ser:
            Branco (B) - Inicial
            Cinza (C) - Descoberta
            Preto (P) - Finalizado
    */
    // Os estados são iniciam todos em branco
    for(int i = 0;i < 7;i++)
    {
        estados[i] = 'B';
        vertice_antecessor[i] = -1; // NULL será representado por -1
    }
    tempo = 0;
    for(int i = 3;i < 7;i++) 
        if(estados[i] == 'B')
            dfs_visit(i);
}

int main()
{
    int fila[7];
    int a = 0; // Controle da fila
    
    int distancias[7];

    // Setando a matriz com zeros
    for(int a;a < 7;a++)
        for(int b = 0;b < 7;b++)
            grafo[a][b] = 0;

    // Arestas
    grafo[0][1] = 1;
    grafo[0][2] = 1;
    grafo[0][3] = 1;

    grafo[1][0] = 1;
    grafo[1][3] = 1;
    grafo[1][5] = 1;

    grafo[2][0] = 1;
    grafo[2][3] = 1;

    grafo[3][0] = 1;
    grafo[3][1] = 1;
    grafo[3][2] = 1;
    grafo[3][6] = 1;

    grafo[4][5] = 1;
    grafo[4][6] = 1;

    grafo[5][1] = 1;
    grafo[5][4] = 1;
    grafo[5][6] = 1;

    grafo[6][3] = 1;
    grafo[6][4] = 1;
    grafo[6][5] = 1;

    // Chamando a função dfs
    dfs();

    printf("   1 2 3 4 5 6 7\n\n");
    // Imprimindo o grafo
    for(a = 0;a < 7;a++)
    {
        printf("%d  ",a+1);
        for(int b = 0;b < 7;b++)
            printf("%d ",grafo[a][b]);
        printf("\n");
    }

    // Exibindo os tempos de descobertas
    printf("\nTempos de descoberta:\n");
    printf("1 2 3 4 5 6 7\n");
    for(a = 0;a < 7;a++)
        printf("%d ",tempo_descoberta[a]);
    
    // Exibindo os tempos de finalização
    printf("\n\nTempos de finalizacao:\n");
    printf("1 2 3 4 5 6 7\n");
    for(a = 0;a < 7;a++)
        printf("%d ",tempo_finalizacao[a]);

    // Exibindo os antecessores de cada vértice
    printf("\n\nVertice antecessor:\n");
    printf("1 2 3 4 5 6 7\n");
    for(a = 0;a < 7;a++)
        printf("%d ",vertice_antecessor[a]+1);

    printf("\n");

    return 0;
}