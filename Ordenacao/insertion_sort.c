#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *nums,int tam)
{
    int atual = 0, aux = 0, i = 1, j = 0, cotdr = 0;
    for(i;i < tam;i++)
    {
        atual = nums[i];
        /*for(j = i-1;j >= 0;j--)
        {
            if(nums[atual] < nums[j])
            {
                aux = nums[atual];
                nums[atual] = nums[j];
                nums[j] = aux;
                atual = j;
            }
            aux = nums[atual];
            nums[atual] = nums[j];
            nums[j] = aux;
        }*/
        j = i-1;
        while(j >= 0 && atual < nums[j])
        {
            nums[j+1] = nums[j];
            j--;
            //
        }
        nums[j+1] = atual;
    }
}

int main()
{
    int tam = 8, i = 0;
    int *lista = (int *)malloc(tam*sizeof(int));

    for(i;i < tam;i++)
        scanf("%d",&lista[i]);

    system("cls");

    // Exibindo a lista antes da ordenação
    printf("Antes da ordenacao: ");
    for(i = 0;i < tam;i++)
        printf("%d ",lista[i]);
    printf("\n\n");

    insertion_sort(lista,tam);

    // Exibindo a lista após à ordenação
    printf("Apos a ordenacao: ");
    for(i = 0;i < tam;i++)
        printf("%d ",lista[i]);
    printf("\n");

    // Liberando a memória alocada
    free(lista);

    return 0;
}