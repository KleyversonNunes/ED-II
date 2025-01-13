typedef struct
{
    int Valor;
}TipoItem;

typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula
{
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct
{
    TipoApontador Primeiro, Ultimo;
}TipoLista;

void FLVazia(TipoLista *);
int Vazia(TipoLista);
void Insere(TipoItem,TipoLista *);
void Retira(TipoApontador,TipoLista *,TipoItem *);
void Imprime(TipoLista);