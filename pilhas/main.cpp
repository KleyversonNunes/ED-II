#include "./pilha.h"
//#include <stdlib.h>
//#include <cstring>
#include <iostream>

int main()
{
    
    TipoPilha Chamada;
    FPVazia(&Chamada);
    //std::cout << Chamada.Primeiro->Prox->Item.Valor << std::endl;

    // Criando itens
    TipoItem aluno1, aluno2, aluno3, aluno4, aluno5, aluno6, aluno7;
    
    aluno1.Valor = "Ana";
    aluno2.Valor = "Beatriz";
    aluno3.Valor = "Camila";
    aluno4.Valor = "Danilo";
    aluno5.Valor = "Elizeu";
    aluno6.Valor = "Fernanda";
    aluno7.Valor = "Gregorio";

    // Inserindo os itens na lista
    Empilha(aluno1,&Chamada);
    Empilha(aluno2,&Chamada);
    Empilha(aluno3,&Chamada);
    Empilha(aluno4,&Chamada);

    // Imprimindo a lista
    Imprime(Chamada);

    // Retirando um elemento
    TipoItem retirado;
    Desempilha(&Chamada,&retirado);
    std::cout << retirado.Valor << " retirado!" << std::endl;
    Desempilha(&Chamada,&retirado);
    std::cout << retirado.Valor << " retirado!" << std::endl;

    // Imprimindo a lista
    std::cout << std::endl;
    Imprime(Chamada);

    // Inserindo os itens na lista
    Empilha(aluno5,&Chamada);
    Empilha(aluno6,&Chamada);
    Empilha(aluno7,&Chamada);

    // Imprimindo a lista
    std::cout << std::endl;
    Imprime(Chamada);

    // Retirando um elemento
    Desempilha(&Chamada,&retirado);
    std::cout << retirado.Valor << " retirado!" << std::endl;
    Desempilha(&Chamada,&retirado);
    std::cout << retirado.Valor << " retirado!" << std::endl;
    Desempilha(&Chamada,&retirado);
    std::cout << retirado.Valor << " retirado!" << std::endl;
    Desempilha(&Chamada,&retirado);
    std::cout << retirado.Valor << " retirado!" << std::endl;

    // Imprimindo a lista
    std::cout << std::endl;
    Imprime(Chamada);

    // Retirando um elemento
    Desempilha(&Chamada,&retirado);
    std::cout << retirado.Valor << " retirado!" << std::endl;
    Desempilha(&Chamada,&retirado);
    std::cout << retirado.Valor << " retirado!" << std::endl;

    // Imprimindo a lista
    std::cout << std::endl;
    Imprime(Chamada);

    TipoPilha teste;
    Desempilha(&teste,&retirado);
    return 0;
}