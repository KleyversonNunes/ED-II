#include "tree.h"
#include <vector>

using namespace std;

int main() {
    TipoApontador raiz = nullptr;
    vector<int> lista = {10, 15, 13, 14, 11};

    for (int valor : lista) {
        TipoApontador novo = criarNo(valor);
        inserirNo(raiz, novo);
        TipoApontador Aux = buscarNo(raiz, valor)->noPai;
        while (Aux != nullptr) {
            atualizarAltura(Aux);
            fatorBalanceamento(Aux);
            if (Aux->FB > 1 && Aux->subArvEsq->FB >= 0)
                rotacaoSimplesDir(raiz, Aux);
            else if (Aux->FB < -1 && Aux->subArvDir->FB <= 0)
                rotacaoSimplesEsq(raiz, Aux);
            else if (Aux->FB > 1 && Aux->subArvEsq->FB < 0)
                rotacaoDuplaDir(raiz, Aux);
            else if (Aux->FB < -1 && Aux->subArvDir->FB > 0)
                rotacaoDuplaEsq(raiz, Aux);
            Aux = Aux->noPai;
        }
    }

    cout << "\nPercurso em pré-ordem: ";
    pre_ordem(raiz);
    cout << "\n";

    return 0;
}