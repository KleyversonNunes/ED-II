#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *nums,int tam)
{
    int i = 0, j = 1, k = 0, menor = 0, aux;

    for(i = 0;i < tam;i++)
    {
        menor = nums[i];
        aux = i;
        for(j = i+1;j<tam;j++)
        {
            if(menor>nums[j])
            {
                menor = nums[j];
                aux = j;
            }
        }

        nums[aux] = nums[i];
        nums[i] = menor;

        if(aux != i)
        {
            printf("i = %d: ",i);
            for(k = 0;k < tam;k++)
                printf("%d ",nums[k]);
            printf("\n");
        }
    }
}

int main()
{
    int tam = 8, i = 0;

    // Alocação dinâmica para um vetor de inteiros de tamanho n
    int *num_list = (int *)malloc(tam*sizeof(int));
    
    // Atribuição do valores para o vetor
    for(i;i < tam;i++)
        scanf("%d",&num_list[i]);

    system("cls");

    // Exibindo o vetor antes da ordenação
    printf("Vetor nao ordenado: \n");
    for(i = 0;i < tam;i++)
        printf("%d ",num_list[i]);
    printf("\n\n");

    // Chamada do Selection Sort
    selection_sort(num_list,tam);

    // Exibindo o vetor após a ordenação
    printf("\nVetor ordenado: \n");
    for(i = 0;i < tam;i++)
        printf("%d ",num_list[i]);
    printf("\n");

    // Liberação da memória alocada
    free(num_list);

    return 0;
}