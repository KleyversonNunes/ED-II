/*
    Disciplina: Estruturas de Dados II
    Aluno: Kleyverson Nunes da Silva
    Matricula: 202311140004

    Execute, no terminal para compilar: g++ main.cpp arvore.cpp -o arvore
*/

#include "./arvore.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nost[15] = {10,15,13,8,9,6,5,11,12,18,3,16,20,23,17};
    std::vector<int> nos = {10,15,13,8,9,6,5,11,12,18,3,16,20,23,17};
    cout << "Espaco ocupado por um inteiro: " << sizeof(nos[0]) << endl;
    cout << "Espaco ocupado pelo array: " << sizeof(nost) << endl;
    cout << "Tamanho do array: " << sizeof(nost)/sizeof(nos[0]) << endl;
    TipoApontador raiz = new TipoNo;;

    for(int i = 0;i < nos.size();i++)
    {
        if(i == 0)
        {
            raiz = criarNo(nos[i]);
            inserirNo(nullptr,raiz);
        }
        else
            inserirNo(raiz,criarNo(nos[i]));
    }

    // Percurso em pre-ordem
    cout << "Pre-ordem -> ";
    pre_ordem(raiz);
    cout << endl;

    // Percurso em intra-ordem ou em ordem
    cout << "Intra-ordem -> ";
    intra_ordem(raiz);
    cout << endl;

    // Percurso em pos-ordem
    cout << "Pos-ordem -> ";
    pos_ordem(raiz);
    cout << endl;

    retirarNo(&raiz,8);
    retirarNo(&raiz,10);
    retirarNo(&raiz,18);
    retirarNo(&raiz,3);
    retirarNo(&raiz,16);
    retirarNo(&raiz,6);

    // Percurso em pre-ordem
    cout << "\nApos as remocoes\nPre-ordem -> ";
    pre_ordem(raiz);
    cout << endl;

    inserirNo(raiz,criarNo(7));
    inserirNo(raiz,criarNo(10));
    inserirNo(raiz,criarNo(14));
    inserirNo(raiz,criarNo(16));
    inserirNo(raiz,criarNo(19));
    inserirNo(raiz,criarNo(22));
    

    cout << "\nApos as insercoes\nPre-ordem -> ";
    pre_ordem(raiz);
    cout << endl;

    TipoApontador no17 = buscarNo(raiz,17);
    cout << "\n"<< no17->arv_esq->Valor << " <-- " << no17->Valor << " --> " << no17->arv_dir->Valor << endl;

    return 0;
}