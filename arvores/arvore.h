typedef struct TipoNo *TipoApontador;

typedef struct TipoNo
{
    int Valor;
    TipoApontador arv_esd;
    TipoApontador arv_dir; 
}TipoNo;

TipoApontador criarNo(int);

int buscarNo(TipoApontador,int);
void inserirNo(TipoApontador,TipoApontador);

// Métodos de percurso
void pre_ordem(TipoApontador);
void intra_ordem(TipoApontador);
void pos_ordem(TipoApontador);