#include "./lista.h"
//#include <stdlib.h>
//#include <cstring>
#include <iostream>

int main()
{
    
    TipoLista Chamada;
    FLVazia(&Chamada);
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
    
    
    /*
    strcpy(aluno1.Valor,"Ana");
    strcpy(aluno2.Valor,"Beatriz");
    strcpy(aluno3.Valor,"Camila");
    strcpy(aluno4.Valor,"Danilo");
    strcpy(aluno5.Valor,"Elizeu");
    strcpy(aluno6.Valor,"Fernanda");
    strcpy(aluno7.Valor,"Gregorio");
    */
    
   /*
    aluno1.Valor = 1;
    aluno2.Valor = 2;
    aluno3.Valor = 3;
    aluno4.Valor = 4;
    aluno5.Valor = 5;
    aluno6.Valor = 6;
    aluno7.Valor = 7;  
    */

    // Inserindo os itens na lista
    
    Insere(aluno1,&Chamada);
    Insere(aluno2,&Chamada);
    Insere(aluno3,&Chamada);
    Insere(aluno4,&Chamada);

    // Imprimindo a lista
    Imprime(Chamada);

    // Retirando um elemento
    TipoItem retirado;
    Retira(Chamada.Primeiro->Prox->Prox,&Chamada,&retirado);

    // Imprimindo a lista
    std::cout << std::endl;
    Imprime(Chamada);

    // Inserindo os itens na lista
    Insere(aluno5,&Chamada);
    Insere(aluno6,&Chamada);
    Insere(aluno7,&Chamada);

    // Imprimindo a lista
    std::cout << std::endl;
    Imprime(Chamada);

    // Provocando um erro
    TipoLista l;
    FLVazia(&l);
    /*
    Retira(Chamada.Ultimo,&Chamada,&retirado);
    Retira(NULL,&Chamada,&retirado);
    Retira(Chamada.Primeiro->Prox,&l,&retirado);
    */
    return 0;
}