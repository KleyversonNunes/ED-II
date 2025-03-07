typedef struct TipoNo *TipoApontador;

typedef struct TipoNo
{
    int Valor;
    TipoApontador subArvEsq, subArvDir, noPai;
}TipoNo;

TipoApontador criarNo(int);

TipoApontador buscarNo(TipoApontador,int);

void inserirNo(TipoApontador,TipoApontador = nullptr);

void removerNo(TipoApontador *,int);

// Métodos de percurso
void pre_ordem(TipoApontador);
void intra_ordem(TipoApontador);
void pos_ordem(TipoApontador);