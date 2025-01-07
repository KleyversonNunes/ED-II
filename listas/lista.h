#define TRUE 1
#define FALSE 0

typedef struct TipoItem
{
    int Item;
}TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula
{
    TipoApontador Prox;
    TipoItem Item;
}TipoCelula;

typedef struct TipoLista
{
    TipoApontador Primeiro;
    TipoApontador Ultimo;
}TipoLista;

// Assinatura dos métodos
void FZListaVazia(TipoLista*);
int Vazia(TipoLista);
void InserirItemLista(TipoLista*,TipoItem);
TipoItem RetirarItemLista(TipoLista*,int);
void ImprimirLista(TipoLista);