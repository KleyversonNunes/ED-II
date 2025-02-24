typedef struct TipoNo *TipoApontador;

typedef struct TipoNo
{
    int Valor;
    TipoApontador arv_esq;
    TipoApontador arv_dir; 
}TipoNo;

TipoApontador criarNo(int);

TipoApontador buscarNo(TipoApontador,int);
TipoApontador noAnterior(TipoApontador,int);
void inserirNo(TipoApontador,TipoApontador);
void retirarNo(TipoApontador *,int);

// Métodos de percurso
void pre_ordem(TipoApontador);
void intra_ordem(TipoApontador);
void pos_ordem(TipoApontador);