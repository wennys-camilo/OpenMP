#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void imprimirVetor(int *vetor, int *tamanho);
void bubbleSort(int *vetor, int *tamanho);
void swap(int *esq, int *dir);
int menu();

int main()
{

    int op = 0;
    int *vetor;
    int *vetorAux;
    int tam = 50;

    vetor = (int *)malloc(tam * sizeof(int));
    vetorAux = (int *)malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++)
    {
        vetor[i] = rand() % 100;
    }

    vetorAux = vetor;

    do
    {

        op = menu();

        switch (op)
        {
        case 0:
            printf("Saindo...!\n");
            break;

        case 1:
        {
            imprimirVetor(vetorAux, &tam);
            printf("-------------------------SEQUENCIAL-------------------------\n");
            double start = omp_get_wtime();
            bubbleSort(vetor, &tam);
            double end = omp_get_wtime();
            printf("Tempo: %f", end - start);
            printf("\n");
            // imprimirVetor(vetor, &tam);
            printf("-------------------------SEQUENCIAL-------------------------\n");
        }
        break;

        case 2:
        {
            int numThreads;

            omp_set_num_threads(4);
            double start = omp_get_wtime();
            printf("-------------------------PARALELIZADO-------------------------\n");
#pragma omp parallel
            {
                numThreads = omp_get_num_threads();

                bubbleSort(vetorAux, &tam);
            }
            printf("Número de Threads %d\n", numThreads);
            double end = omp_get_wtime();
            printf("Tempo: %f", end - start);
            printf("\n");
            // imprimirVetor(vetor, &tam);
            printf("\n");
        }
        break;

        default:
            break;
        }

    } while (op != 0);
}

int menu()
{
    int op;
    printf("0 - PARA SAIR\n");
    printf("1 - SEQUENCIAL\n");
    printf("2 - PARALELIZADO\n");
    printf("Informe a opcão desejada: ");
    scanf("%d", &op);
    return op;
}

void imprimirVetor(int *vetor, int *tamanho)
{
    int i;
    for (i = 0; i < *tamanho; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

void swap(int *esq, int *dir)
{
    int aux = *esq;
    *esq = *dir;
    *dir = aux;
}

void bubbleSort(int *vetor, int *tamanho)
{
    int i, j;
    for (i = 0; i < *tamanho - 1; i++)
        //#pragma omp parallel for
        for (j = 0; j < *tamanho - i - 1; j++)
            if (vetor[j] > vetor[j + 1])
                swap(&vetor[j], &vetor[j + 1]);
}
