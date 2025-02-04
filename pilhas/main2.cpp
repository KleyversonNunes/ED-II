#include "./pilha_ziviani.h"
#include <iostream>

int main()
{
    TipoPilha Discos;
    
    // Esvaziando a pilha
    FPVazia(&Discos);

    // Criando itens 
    TipoItem disco1, disco2, disco3, disco4, disco5, disco6, disco7;
    disco1.Valor = "Abbey Road";
    disco2.Valor = "The Dark Sido of The Moon";
    disco3.Valor = "Machine Head";
    disco4.Valor = "All Things Must Pass";
    disco5.Valor = "The Inner Mounting Flame";
    disco6.Valor = "Remains in Light";
    disco7.Valor = "Nevermind";

    // Empilhando os itens
    Empilha(disco1,&Discos);
    Empilha(disco2,&Discos);
    Empilha(disco3,&Discos);
    Empilha(disco4,&Discos);

    // Imprimindo a pilha
    Imprime(Discos);
    std::cout << std::endl;

    // Desempilhando os items
    TipoItem removido;
    Desempilha(&Discos,&removido);
    std::cout << removido.Valor << " foi removido" << std::endl;
    Desempilha(&Discos,&removido);
    std::cout << removido.Valor << " foi removido" << std::endl;

    // Empilhando os itens
    Empilha(disco5,&Discos);

    // Imprimindo a pilha
    Imprime(Discos);
    std::cout << std::endl;

    // Desempilhando os items
    Desempilha(&Discos,&removido);
    std::cout << removido.Valor << " foi removido" << std::endl;
    Desempilha(&Discos,&removido);
    std::cout << removido.Valor << " foi removido" << std::endl;

    // Empilhando os itens
    Empilha(disco6,&Discos);
    Empilha(disco7,&Discos);

    // Desempilhando os items
    Desempilha(&Discos,&removido);
    std::cout << removido.Valor << " foi removido" << std::endl;
    Desempilha(&Discos,&removido);
    std::cout << removido.Valor << " foi removido" << std::endl;
    Desempilha(&Discos,&removido);
    std::cout << removido.Valor << " foi removido" << std::endl;
    Desempilha(&Discos,&removido);
    std::cout << removido.Valor << " foi removido" << std::endl;

    // Imprimindo a pilha
    Imprime(Discos);
    std::cout << std::endl;

    return 0;
}