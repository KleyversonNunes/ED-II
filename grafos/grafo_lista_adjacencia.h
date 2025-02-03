typedef struct TipoVertice *TipoApontador;

typedef struct TipoVertice
{
    int Vertice;
    TipoApontador Proximo;
}TipoVertice;

typedef struct TipoGrafo
{
    int numVertices;
    TipoApontador *ListaAdj;
}TipoGrafo;

TipoApontador CriarVertice(int);
TipoGrafo *CriarGrafo(int);
int VerificaAresta(TipoGrafo *,int,int);
void AdicionarAresta(TipoGrafo *,int,int);
void RetiraAresta(TipoGrafo *,int,int);
void Imprime(TipoGrafo *);