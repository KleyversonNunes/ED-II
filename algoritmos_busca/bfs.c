#include <stdio.h>
#include <stdlib.h>

int grafo[8][8];
int fila[8]; // Recebe os vértices assim que são descobertos
int controle_fila; // Indica de qual vértice a busca está partindo
int tam = 8;

char estados[8];
int distancias[8];
int vertice_antecessor[8];
    
void bfs()
{
    int i = 0;
    int ver_inicial = 7;
    int ver_atual;
    // Os estados são iniciam todos em branco
    /*
        Os estados podem ser:
            Branco (B) - Inicial
            Cinza (C) - Descoberta
            Preto (P) - Finalizado
    */
    for(i;i<8;i++)
    {
        estados[i] = 'B';
        distancias[i] = -1;
        vertice_antecessor[i] = -1;
    }
    estados[ver_inicial] = 'C';
    distancias[ver_inicial] = 0;
    vertice_antecessor[ver_inicial] = -1; //Indica que o vértice não tem antecessor
    fila[0] = ver_inicial;
    controle_fila = 0;

    while(controle_fila < tam)
    {
        ver_atual = fila[controle_fila];
        for(i=0;i<tam;i++)
        {
            if(grafo[fila[controle_fila]][i] == 1 && estados[i] == 'B')
            {
                estados[i] = 'C';
                distancias[i] = distancias[fila[controle_fila]]+1;
                vertice_antecessor[i] = fila[controle_fila];
            }
        }
        estados[ver_atual] = 'P';
        controle_fila++;
    }
}

int main()
{
    int a = 0; // Controle 

    // Setando a matriz com zeros
    for(int a = 0;a < tam;a++)
        for(int b = 0;b < 7;b++)
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

    // Exibindo a fila
    printf("\n\nFila: \n");
    for(a = 0;a < tam;a++)
        printf("%d ",fila[a]);
    
    // Exibindo a distâncias
    printf("\n\nDistancias: \n");
    for(a = 0;a < tam;a++)
        printf("%d ",distancias[a]);

    printf("\n\nAntecessores: \n");
    for(a = 0;a < tam;a++)
        printf("%d ",vertice_antecessor[a]);

    return 0;
}