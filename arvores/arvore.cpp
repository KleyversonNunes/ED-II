#include "./arvore.h"
#include <iostream>

using namespace std;

TipoApontador criarNo(int Valor)
{
    TipoApontador novo = new TipoNo;
    novo->Valor = Valor;
    novo->arv_esq = nullptr;
    novo->arv_dir = nullptr;
    return novo;
}

TipoApontador buscarNo(TipoApontador raiz, int no)
{
    /*
        raiz -> Encontrou o nó
        nullptr -> Não encontrou o nó
    */
    if(raiz == nullptr)
        return nullptr;
    
    if(no == raiz->Valor)
    {   
        //cout << "\n" << no << " foi encontrado!" << endl;
        return raiz;
    }else if(no < raiz->Valor)
    {    
        return buscarNo(raiz->arv_esq,no);
    }else
    {
        return buscarNo(raiz->arv_dir,no);
    }
    return nullptr;
}

TipoApontador noAnterior(TipoApontador raiz,int no)
{
    if(no < raiz->Valor)
    {
        if(raiz->arv_esq->Valor == no)
            return raiz;
        return noAnterior(raiz->arv_esq,no);
    }
    if(no > raiz->Valor)
    {
        if(raiz->arv_dir->Valor == no)
            return raiz;
        return noAnterior(raiz->arv_dir,no);
    }
    /*
        Retornar nullptr indica que não existe nó anterior,
        ou seja, o nó que será removido é a raiz
    */
   return nullptr;
}

void inserirNo(TipoApontador raiz, TipoApontador novo)
{
    if(raiz == nullptr)
    {
        raiz = novo;
        return;
    }    

    if(buscarNo(raiz,novo->Valor))// == 1)
    {
        cout << "O no " << novo->Valor << " já está inserido na árvore" << endl;
        return;
    }
    
    //cout << raiz->Valor << " ";
    if(novo->Valor < raiz->Valor)
    {
        if(raiz->arv_esq != nullptr)
            inserirNo(raiz->arv_esq,novo);
        else
            raiz->arv_esq = novo;
    }
    else
    {
        if(raiz->arv_dir != nullptr)
            inserirNo(raiz->arv_dir,novo);
        else
            raiz->arv_dir = novo;
    }
}

void retirarNo(TipoApontador *raiz, int no)
{
    if(buscarNo(*raiz,no) == nullptr)
        return;
    else
    {
        TipoApontador no_rm = buscarNo(*raiz,no);
        TipoApontador no_anterior = noAnterior(*raiz,no);

        // Caso I - Nó sem filhos - Folha
        //if(no_rm->arv_esq == nullptr && no_rm->arv_dir == nullptr)
        if(!no_rm->arv_esq && !no_rm->arv_dir)
        {
            if(no_rm->Valor < no_anterior->Valor)
                no_anterior->arv_esq = nullptr;
            else
                no_anterior->arv_dir = nullptr;
            delete no_rm;
        }
        // Caso II - Exatamente um filho
        else if((no_rm->arv_esq && !no_rm->arv_dir) || (!no_rm->arv_esq && no_rm->arv_dir))
        {
            if(no_rm->Valor < no_anterior->Valor)
            {
                if(no_rm->arv_esq)
                    no_anterior->arv_esq = no_rm->arv_esq; 
                else
                    no_anterior->arv_esq = no_rm->arv_dir;
                delete no_rm;
            }
            else
            {
                if(no_rm->arv_esq)
                    no_anterior->arv_dir = no_rm->arv_esq;
                else
                    no_anterior->arv_dir = no_rm->arv_dir;
                delete no_rm;
            }
        }
        // Caso III - Nó com dois filhos
        else if(no_rm->arv_esq && no_rm->arv_dir)
        {
            /*
                Quando nó, a ser removido, possui dois filhos, a substituicao ocorre de duas formas:
                    * Substituir pelo nó mais a direita da sub-árvore esquerda
                    * Substituir pelo nó mais a esquerda da sub-árvore direita (convencao)
            */
            TipoApontador no_subs = no_rm->arv_dir;
            
            // Procedimento para encontrar o nó mais a esquerda da sub-árvore direita
            while(no_subs->arv_esq)
                no_subs = no_subs->arv_esq;

            TipoApontador no_subs_anterior = noAnterior(*raiz,no_subs->Valor);

                // Ajustando os ponteiros
            if(no_rm == no_subs_anterior)
            {
                if(no_rm->Valor < no_anterior->Valor)
                    no_anterior->arv_esq = no_subs;
                else
                    no_anterior->arv_dir = no_subs;
                
                no_subs->arv_esq = no_rm->arv_esq;
            }
            else
            {
                if(no_subs->arv_dir)
                    no_subs_anterior->arv_esq = no_subs->arv_dir;
                else
                    no_subs_anterior->arv_esq = nullptr;

                no_subs->arv_esq = no_rm->arv_esq;
                no_subs->arv_dir = no_rm->arv_dir;
                
                // Só é preciso ajustar o ponteiro do nó anterior, se o nó a ser removido nao for a raiz
                if(no_rm != *raiz)
                {
                    if(no_rm->Valor < no_anterior->Valor)
                        no_anterior->arv_esq = no_subs;
                    else
                        no_anterior->arv_dir = no_subs;
                }
                else
                    *raiz = no_subs;
            }

            delete no_rm;
        }
    }
}

// Iplementação algoritmos de percurso
void pre_ordem(TipoApontador no)
{
    if(no != nullptr)
    {
        cout << no->Valor << " ";
        pre_ordem(no->arv_esq);
        pre_ordem(no->arv_dir);
    }
}

void intra_ordem(TipoApontador no)
{
    if(no != nullptr)
    {
        intra_ordem(no->arv_esq);
        cout << no->Valor << " ";
        intra_ordem(no->arv_dir);
    }
}

void pos_ordem(TipoApontador no)
{
    if(no != nullptr)
    {
        pos_ordem(no->arv_esq);
        pos_ordem(no->arv_dir);
        cout << no->Valor << " ";
    }
}