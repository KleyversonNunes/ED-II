#include "./arvore.h"
#include <iostream>
using namespace std;

int main()
{
    TipoApontador raiz = criarNo(10);

    //
    cout << "O no raiz e o " << raiz->Valor << endl;
    return 0;
}