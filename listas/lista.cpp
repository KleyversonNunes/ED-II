#include "./lista.h"
#include <iostream>

using namespace std;

// Implementação dos métodos da lista
void FZListaVazia(TipoLista *Lista)
{
    Lista->Primeiro = nullptr;
    Lista->Ultimo = Lista->Primeiro;
}

int Vazia(TipoLista Lista)
{   
    if(Lista.Primeiro == Lista.Ultimo)
        return TRUE;
    return FALSE;
}