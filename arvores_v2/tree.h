// arvores.h

#ifndef ARVORES_H
#define ARVORES_H

#include <iostream>

struct TipoNo {
    int Valor, altura, FB;
    TipoNo *subArvEsq, *subArvDir, *noPai;
};

typedef TipoNo* TipoApontador;

int altura(TipoApontador);
void atualizarAltura(TipoApontador);
void fatorBalanceamento(TipoApontador);
TipoApontador criarNo(int);
TipoApontador buscarNo(TipoApontador, int);
void inserirNo(TipoApontador&, TipoApontador);
void removerNo(TipoApontador&, int);
void rotacaoSimplesDir(TipoApontador&, TipoApontador);
void rotacaoSimplesEsq(TipoApontador&, TipoApontador);
void rotacaoDuplaDir(TipoApontador&, TipoApontador);
void rotacaoDuplaEsq(TipoApontador&, TipoApontador);
void pre_ordem(TipoApontador);
void intra_ordem(TipoApontador);
void pos_ordem(TipoApontador);

#endif // ARVORES_H