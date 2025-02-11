typedef struct TipoNo *TipoApontador;

typedef struct TipoNo
{
    int Valor;
    TipoApontador arv_esd;
    TipoApontador arv_dir; 
}TipoNo;

TipoApontador criarNo(int);