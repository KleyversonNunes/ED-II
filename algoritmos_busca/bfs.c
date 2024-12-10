#include <stdio.h>
#include <stdlib.h>

void bfs()
{
    //
}

int main()
{
    int grafo[7][7];
    int fila[7];
    int i = 0; // Controle da fila

    char estados[7];
    int distancias[7];
    int tempo_descoberta[7];
    int tempo_finalizacao[7];

    // Os estados são iniciam todos em branco
    /*
        Os estados podem ser:
            Branco (B) - Inicial
            Cinza (C) - Descoberta
            Preto (P) - Finalizado
    */
    for(i;i<7;i++)
        estados[i] = 'B';

    // Setando a matriz com zeros
    for(int a = 0;a < 7;a++)
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

    printf("   1 2 3 4 5 6 7\n\n");
    // Imprimindo o grafo
    for(int a = 0;a < 7;a++)
    {
        printf("%d  ",a+1);
        for(int b = 0;b < 7;b++)
            printf("%d ",grafo[a][b]);
        printf("\n");
    }


    return 0;
}