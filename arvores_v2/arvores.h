typedef struct TipoNo *TipoApontador;

typedef struct TipoNo
{
    int Valor, altura, FB;
    TipoApontador subArvEsq, subArvDir, noPai;
}TipoNo;

int altura(TipoApontador);

void atualizarAltura(TipoApontador);

void fatorBalanceamento(TipoApontador);

TipoApontador criarNo(int);

TipoApontador buscarNo(TipoApontador,int);

void inserirNo(TipoApontador,TipoApontador);

void removerNo(TipoApontador *,int);

void rotacaoSimplesDir(TipoApontador *,TipoApontador);

void rotacaoSimplesEsq(TipoApontador *,TipoApontador);

void rotacaoDuplaDir(TipoApontador *,TipoApontador);

void rotacaoDuplaEsq(TipoApontador *,TipoApontador);

// Métodos de percurso
void pre_ordem(TipoApontador);
void intra_ordem(TipoApontador);
void pos_ordem(TipoApontador);