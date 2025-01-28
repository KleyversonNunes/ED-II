#include <string>

typedef struct TipoItem
{
    //char Valor[100];
    std::string Valor;
    //int Valor;
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
}TipoPilha;

void FPVazia(TipoPilha *);
int Vazia(TipoPilha);
void Empilha(TipoItem, TipoPilha *);
void Desempilha(TipoPilha *, TipoItem *);
void Imprime(TipoPilha);