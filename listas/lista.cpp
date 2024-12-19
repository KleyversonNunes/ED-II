#include "./lista.h"
#include <iostream>

using namespace std;

// Implementação dos métodos da lista
void FZListaVazia(TipoLista *Lista)
{
    Lista->Primeiro = nullptr;
    Lista->Ultimo = Lista->Primeiro;
    cout << "A lista esta vazia";
}