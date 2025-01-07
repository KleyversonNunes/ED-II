#include <stdio.h>
#include <stdlib.h>

int grafo[8][8];
int fila[8]; // Recebe os vértices assim que são descobertos
int inicio_fila = 0; // Indica de qual vértice a busca está partindo
int fim_fila = 0;
int tam = 8;

char estados[8];
int distancias[8];
int vertice_antecessor[8];
    
void bfs()
{
    int ver_inicial = 7;
    int ver_atual;
    // Os estados são iniciam todos em branco
    /*
        Os estados podem ser:
            Branco (B) - Inicial
            Cinza (C) - Descoberta
            Preto (P) - Finalizado
    */
    for(int i=0;i<tam;i++)
    {
        estados[i] = 'B';
        distancias[i] = -1;
        vertice_antecessor[i] = -1; // Indica inicialmente que todos os valores são NULL
    }
    fila[fim_fila++] = ver_inicial;
    estados[ver_inicial] = 'C';
    distancias[ver_inicial] = 0;

    while(inicio_fila < fim_fila)
    {
        ver_atual = fila[inicio_fila++];
        for(int i=0;i<tam;i++)
        {
            if(grafo[ver_atual][i] == 1 && estados[i] == 'B')
            {
                estados[i] = 'C';
                distancias[i] = distancias[ver_atual]+1;
                vertice_antecessor[i] = ver_atual;
                fila[fim_fila++] = i;
            }
        }
        estados[ver_atual] = 'P';
    }
}

int main()
{
    int a = 0; // Controle 

    // Setando a matriz com zeros
    for(int a = 0;a < tam;a++)
        for(int b = 0;b < tam;b++)
            grafo[a][b] = 0;

    // Arestas
    grafo[0][1] = 1;
    grafo[0][5] = 1;
    grafo[0][6] = 1;
    grafo[0][7] = 1;

    grafo[1][0] = 1;
    grafo[1][7] = 1;

    grafo[2][3] = 1;
    grafo[2][5] = 1;

    grafo[3][2] = 1;
    grafo[3][4] = 1;

    grafo[4][3] = 1;

    grafo[5][0] = 1;
    grafo[5][2] = 1;
    grafo[5][6] = 1;

    grafo[6][0] = 1;
    grafo[6][5] = 1;
    grafo[6][7] = 1;

    grafo[7][0] = 1;
    grafo[7][1] = 1;
    grafo[7][6] = 1;

    printf("   1 2 3 4 5 6 7 8\n\n");
    // Imprimindo o grafo
    for(int a = 0;a < tam;a++)
    {
        printf("%d  ",a+1);
        for(int b = 0;b < tam;b++)
            printf("%d ",grafo[a][b]);
        printf("\n");
    }

    bfs();

    // Exibindo a fila
    printf("\n\nFila: \n");
    for(a = 7;a >=0;a--)
        printf("%d ",fila[a]);
    
    // Exibindo a distâncias
    printf("\n\nDistancias: \n");
    for(a = 0;a < tam;a++)
        printf("%d ",distancias[a]);

    printf("\n\nAntecessores: \n");
    for(a = 0;a < tam;a++)
        printf("%d ",vertice_antecessor[a]);
    printf("\n");

    return 0;
}