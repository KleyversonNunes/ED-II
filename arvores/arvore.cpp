#include "./arvore.h"

TipoApontador criarNo(int Valor)
{
    TipoApontador novo = new TipoNo;
    novo->Valor = Valor;
    novo->arv_esd = nullptr;
    novo->arv_dir = nullptr;
    return novo;
}