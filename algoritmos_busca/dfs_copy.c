#include <stdio.h>
#include <stdlib.h>

int grafo[8][8];
char estados[8];

int tempo;
int tempo_descoberta[8];
int tempo_finalizacao[8];
int vertice_antecessor[8];

void dfs_visit(int vertice)
{
    tempo = tempo+1;
    tempo_descoberta[vertice] = tempo;
    estados[vertice] = 'C';
    for(int j = 0;j < 8;j++)
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
    for(int i = 0;i < 8;i++)
    {
        estados[i] = 'B';
        vertice_antecessor[i] = -1; // NULL será representado por -1
    }
    tempo = 0;
    for(int i = 0;i < 8;i++) 
        if(estados[i] == 'B')
            dfs_visit(0); // Vértice de partida
}

int main()
{
    int a = 0;

    // Setando a matriz com zeros
    for(int a;a < 8;a++)
        for(int b = 0;b < 8;b++)
            grafo[a][b] = 0;

    // Arestas
    grafo[0][2] = 1;
    grafo[0][3] = 1;
    grafo[0][5] = 1;
    grafo[1][5] = 1;
    grafo[1][6] = 1;
    grafo[2][7] = 1;
    grafo[3][4] = 1;
    grafo[4][0] = 1;
    grafo[4][2] = 1;
    grafo[5][7] = 1;
    grafo[5][1] = 1;
    grafo[6][6] = 1;
    grafo[7][6] = 1;
    grafo[7][2] = 1;

    /*
    grafo[0][1] = 1;
    grafo[1][2] = 1;
    grafo[3][2] = 1;
    grafo[3][4] = 1;
    grafo[3][5] = 1;
    grafo[4][0] = 1;
    grafo[4][1] = 1;
    grafo[4][5] = 1;
    grafo[5][2] = 1;
    
    grafo[0][2] = 1;
    grafo[0][3] = 1;

    grafo[1][2] = 1;
    grafo[1][7] = 1;

    grafo[2][4] = 1;

    grafo[3][4] = 1;

    grafo[5][7] = 1;

    grafo[8][1] = 1;
    grafo[8][7] = 1;
    grafo[6][5] = 1;
    */
    // Chamando a função dfs
    dfs();

    // Imprimindo o grafo
    printf("Representacao do grafo por matriz de adjacencia\n");
    printf("   1 2 3 4 5 6 7 8\n\n");

    for(a = 0;a < 8;a++)
    {
        printf("%d  ",a+1);
        for(int b = 0;b < 8;b++)
            printf("%d ",grafo[a][b]);
        printf("\n");
    }

    // Exibindo os tempos de descobertas
    printf("\n    ");
    for(a = 0;a < 8;a++)
        printf("%2d ",a+1);
    printf("\n--------------------------------");
    
    printf("\nTD: ");
    for(a = 0;a < 8;a++)
        printf("%2d ",tempo_descoberta[a]);
    
    // Exibindo os tempos de finalização
    printf("\nTF: ");
    for(a = 0;a < 8;a++)
        printf("%2d ",tempo_finalizacao[a]);

    // Exibindo os antecessores de cada vértice
    printf("\nVA: ");
    for(a = 0;a < 8;a++)
        printf("%2d ",vertice_antecessor[a]+1);

    printf("\n\n");

    // Setando a matriz com zeros
    for(int a;a < 8;a++)
        for(int b = 0;b < 8;b++)
            grafo[a][b] = 0;

    // Arestas
    grafo[2][0] = 1;
    grafo[3][0] = 1;
    grafo[5][0] = 1;
    grafo[5][1] = 1;
    grafo[6][1] = 1;
    grafo[7][2] = 1;
    grafo[4][3] = 1;
    grafo[0][4] = 1;
    grafo[2][4] = 1;
    grafo[7][5] = 1;
    grafo[1][5] = 1;
    grafo[6][6] = 1;
    grafo[6][7] = 1;
    grafo[2][7] = 1;

    dfs();

    // Exibindo os tempos de descobertas
    printf("\n    ");
    for(a = 0;a < 8;a++)
        printf("%2d ",a+1);
    printf("\n--------------------------------");
    
    printf("\nTD: ");
    for(a = 0;a < 8;a++)
        printf("%2d ",tempo_descoberta[a]);
    
    // Exibindo os tempos de finalização
    printf("\nTF: ");
    for(a = 0;a < 8;a++)
        printf("%2d ",tempo_finalizacao[a]);

    // Exibindo os antecessores de cada vértice
    printf("\nVA: ");
    for(a = 0;a < 8;a++)
        printf("%2d ",vertice_antecessor[a]+1);

    printf("\n\n");
    return 0;
}