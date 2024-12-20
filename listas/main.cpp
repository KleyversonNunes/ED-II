#include "./lista.cpp"
#include <stdio.h>
#include <stdlib.h>

//using namespace std;

int main()
{
    TipoLista Chamada;
    FZListaVazia(&Chamada);
    cout << "A lista esta vazia: " << Vazia(Chamada) << endl;

    return 0;
}