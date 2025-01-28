#include <string>

typedef struct
{
    std::string Valor;
}TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula
{
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct
{
    TipoApontador Fundo, Topo;
    int Tamanho; 
}TipoPilha;

void FPVazia(TipoPilha *);
int Vazia(TipoPilha);
void Empilha(TipoItem,TipoPilha *);
void Desempilha(TipoPilha *,TipoItem *);
int Tamanho(TipoPilha);
void Imprime(TipoPilha);