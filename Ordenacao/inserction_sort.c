#include <stdio.h>
#include <stdlib.h>

void insection_sort(int *nums,int tam)
{
    int atual = 0, aux = 0, i = 1, j = 0;
    for(i;i < tam;i++)
    {
        atual = i;
        for(j = i-1;j >= 0;j--)
        {
            if(nums[atual] < nums[j])
            {
                aux = nums[atual];
                nums[atual] = nums[j];
                nums[j] = aux;
                atual = j;
            }
        }
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
    printf("\n");

    insection_sort(lista,tam);

    // Exibindo a lista após à ordenação
    printf("Apos a ordenacao: ");
    for(i = 0;i < tam;i++)
        printf("%d ",lista[i]);
    printf("\n");

    // Liberando a memória alocada
    free(lista);

    return 0;
}