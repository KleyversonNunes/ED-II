#include "./lista.cpp"
#include <stdio.h>
#include <stdlib.h>

//using namespace std;

int main()
{
    TipoLista Chamada;
    FZListaVazia(&Chamada);
    cout << "A lista esta vazia: " << Vazia(Chamada) << endl;

    // Criando items
    TipoItem i1, i2, i3;
    i1.Valor = 11;
    i2.Valor = 22;
    i3.Valor = 33;

    // Adicionando items
    InserirItemLista(&Chamada,i1);
    InserirItemLista(&Chamada,i2);
    InserirItemLista(&Chamada,i3);

    // Exibindo a lista
    ImprimirLista(Chamada);

    // Retirando um elemento
    TipoApontador pri = Chamada.Primeiro->Prox;
    TipoItem retirado;

    RetirarItemLista(&Chamada,&retirado,pri);

    // Exibindo a lista
    cout << endl;
    ImprimirLista(Chamada);

    return 0;
}