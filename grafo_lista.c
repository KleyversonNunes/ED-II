/*
    Aluno: Kleyverson Nunes da Silva
    Matrícula: 202311140004
    Atividade: Implemente a representação de grafos por meio de uma lista encadeada
*/

#include <stdio.h>
#include <stdlib.h>

// Definindo as estruturas do grafo
#define MAXNUMVERTICES 100
#define MAXNUMARESTAS 4500
#define TRUE 1
#define FALSE 0

typedef int TipoValorVertice;
typedef int TipoPeso;

typedef struct TipoItem
{
    TipoValorVertice Vertice;
    TipoPeso Peso;
}TipoItem;
typedef struct TipoCelula *TipoApontador;

struct TipoCelula
{
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct TipoLista
{
    TipoApontador Primeiro, Ultimo;
}TipoLista;

typedef struct TipoGrafo
{
    TipoLista Adj[MAXNUMVERTICES + 1];
    TipoValorVertice NumVertices;
    short NumArestas;
}TipoGrafo;

// Implementando os métodos sobre lista
void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

// Implementando os métodos sobre grafo
void FGVazio(TipoGrafo *Grafo)
{
    long i;
    for(i = 0; i < Grafo->NumVertices; i++) FLVazia(&Grafo->Adj[i]);
}

void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo)
{
    TipoItem x;
    x.Vertice = *V2;
    x.Peso = *Peso;
    Insere(x,&Grafo->Adj[*V1]);
}

short ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2, TipoGrafo *Grafo)
{
    TipoApontador Aux;
    short EncontrouAresta = FALSE;
    Aux = Grafo->Adj[Vertice1].Primeiro->Prox;
    while(Aux != NULL && EncontrouAresta == FALSE)
    {
        if(Vertice2 == Aux->Item.Vertice) EncontrouAresta = TRUE;
        Aux = Aux->Prox;
    }
}

// Métodos para obter listas de adjacentes
short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo)
{
    return (Grafo->Adj[*Vertice].Primeiro == Grafo->Adj[*Vertice].Ultimo);
}

TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo)
{
    return (Grafo->Adj[*Vertice].Primeiro->Prox);
}

void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, short *FimListaAdj)
{
    *Adj = (*Prox)->Item.Vertice;
    *Peso = (*Prox)->Item.Peso;
    *Prox = (*Prox)->Prox;
    if(*Prox == NULL) *FimListaAdj = TRUE;
}

// Método para retirar da lista
void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{
    TipoApontador q;
    if(Vazia(*Lista) || p == NULL || p->Prox == NULL)
    {
        printf("Erro: Lista vazia ou posicao nao existe\n");
        return;
    }
    q = p->Prox;
    *Item = q->Item;
    p->Prox = q->Prox;
    if(p->Prox == NULL) Lista->Ultimo = p;
    free(q);
}

// Mais métodos sobre grafos
void RetiraAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo)
{
    TipoApontador AuxAnterior, Aux;
    short EncontrouAresta = FALSE;
    TipoItem x;
    AuxAnterior = Grafo->Adj[*V1].Primeiro;
    while(Aux != NULL && EncontrouAresta == FALSE)
    {
        if(*V2 == Aux->Item.Vertice)
        {
            Retira(AuxAnterior,&Grafo->Adj[*V1],&x);
            Grafo->NumArestas--;
            EncontrouAresta == TRUE;
        }
        AuxAnterior = Aux;
        Aux = Aux->Prox;
    }
}

void LiberaGrafo(TipoGrafo *Grafo)
{
    TipoApontador AuxAnterior, Aux;
    for(int i = 0;i < Grafo->NumVertices; i++)
    {
        Aux = Grafo->Adj[i].Primeiro->Prox;
        free(Grafo->Adj[i].Primeiro);
        Grafo->Adj[i].Primeiro = NULL;
        while(Aux != NULL)
        {
            AuxAnterior = Aux;
            Aux = Aux->Prox;
            free(AuxAnterior);
        }
    }
    Grafo->NumVertices = 0;
}

void ImprimeGrafo(TipoGrafo *Grafo)
{
    int i;
    TipoApontador Aux;
    for(i = 0; i < Grafo->NumVertices; i++)
    {
        printf("Vertice%2d: ",i);
        if(!Vazia(Grafo->Adj[i]))
        {
            Aux = Grafo->Adj[i].Primeiro->Prox;
            while(Aux != NULL)
            {
                printf("%3d (%d)",Aux->Item.Vertice, Aux->Item.Peso);
                Aux = Aux->Prox;
            }
        }
        putchar('\n');
    }
}

int main()
{
    TipoApontador Aux;
    TipoGrafo G1;
    TipoValorVertice V1, V2, Adj;
    TipoPeso Peso;
    TipoValorVertice NVertices;
    short NArestas;
    short FimListaAdj;

    printf("Leitura do grafo\n");
    printf("No. vertices: ");
    scanf("%d",&NVertices);
    getchar();
    printf("No. arestas: ");
    scanf("%hd",&NArestas);
    getchar();

    G1.NumVertices = NVertices;
    G1.NumArestas = 0;
    FGVazio(&G1);

    for(int i = 0; i <= NArestas-1;i++)
    {
        printf("Insere V1 -- V2 -- Peso\n");
        scanf("%d%d%d",&V1,&V2,&Peso);
        getchar();
        G1.NumArestas++;
        InsereAresta(&V1,&V2,&Peso,&G1);
        // InsereAresta(V2,V1,Peso,Grafo);
    }
    ImprimeGrafo(&G1);
    getchar();
    
    printf("Insere V1 -- V2 -- Peso\n");
    scanf("%d%d%d,&V1,&V2,&Peso");
    getchar();
    if(ExisteAresta(V1,V2,&G1))
        printf("Aresta ja existe\n");
    else
    {
        G1.NumArestas++;
        InsereAresta(&V1,&V2,&Peso,&G1);
        //InsereAresta(V2,V1,Peso,Grafo);
    }
    ImprimeGrafo(&G1);
    getchar();
    printf("Lista adjacente de: ");
    scanf("%d",&V1);
    if(!ListaAdjVazia(&V1,&G1))
    {
        Aux = PrimeiroListaAdj(&V1,&G1);
        FimListaAdj = FALSE;
        while(!FimListaAdj)
        {
            ProxAdj(&V1,&G1,&Adj,&Peso,&Aux,&FimListaAdj);
            printf("%2d (%d)",Adj,Peso);
        }
        putchar('\n');
        getchar();
    }
    
    printf("Retiar aresta V1 --- V2:");
    scanf(" %d%d,&V1,&V2");
    getchar();
    
    if(ExisteAresta(V1,V2,&G1))
    {
        G1.NumArestas--;
        RetiraAresta(&V1,&V2,&Peso,&G1);
        //RetiraAresta(V2,V1,Peso,G1);
    }
    else
        printf("Aresta nao existe\n");
    
    ImprimeGrafo(&G1);
    getchar();
    printf("Existe aresta V1 -- V2\n");
    scanf("%d%d",&V1,&V2);
    if(ExisteAresta(V1,V2,&G1))
        printf("Sim\n");
    else
        printf("Nao\n");
    LiberaGrafo(&G1);
    
    getchar();
    //printf("Apenas testando a conexao do VSCode com o GitHub\n");
    return 0;
}
