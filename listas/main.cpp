#include "./lista.cpp"
#include <stdio.h>
#include <stdlib.h>

//using namespace std;

int main()
{
    TipoLista Numeros;
    FLVazia(&Numeros);
    cout << "A lista esta vazia: " << Vazia(Numeros) << endl;

    // Criando items
    TipoItem i1, i2, i3, i4, i5;
    i1.Valor = 11;
    i2.Valor = 22;
    i3.Valor = 33;
    i4.Valor = 44;
    i5.Valor = 55;


    // Adicionando items
    Insere(i1,&Numeros);
    Insere(i2,&Numeros);
    Insere(i3,&Numeros);

    // Exibindo a lista
    Imprime(Numeros);

    // Retirando um elemento
    TipoApontador p = Numeros.Primeiro->Prox;
    TipoItem retirado;

    Retira(p,&Numeros,&retirado);

    // Exibindo a lista
    cout << endl;
    Imprime(Numeros);

    // Adicionando items
    Insere(i4,&Numeros);
    Insere(i5,&Numeros);

    // Exibindo a lista
    cout << endl;
    Imprime(Numeros);

    return 0;
}