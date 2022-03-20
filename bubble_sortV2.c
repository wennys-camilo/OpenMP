#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void swap();
void imprimirVetor(int *vet, int *tam);
void sequencial(int *vet, int *tam);
void paralelo(int *vet, int *tam);
int *inverte_vetor(int *vet, int *tam);
void preenche_vetor_em_sequencia(int *vet, int *tam);
void preenche_vetor_aleatorio(int *vet, int *tam);
int menu();

int main()
{

    int *vet;
    int *vetAux;

    double start, end;

    int tam = 80000;

    vet = (int *)malloc(tam * sizeof(int));
    vetAux = (int *)malloc(tam * sizeof(int));

    preenche_vetor_aleatorio(vet, &tam);

    // preenche_vetor_em_sequencia(vet, &tam);

    // vet = inverte_vetor(vet, &tam);

    vetAux = vet;

    int tipoExecucao = 0;

    do
    {

        tipoExecucao = menu();

        switch (tipoExecucao)
        {
        case 0:
            printf("Saindo...!\n");
            break;

        case 1:
        {
            for (int i = 0; i < 4; i++)
            {

                int *vetSeq;

                vetSeq = (int *)malloc(tam * sizeof(int));

                for (int i = 0; i < tam; i++)
                {
                    vetSeq[i] = vetAux[i];
                }

                // printf("Vetor desordenado: ");

                // imprimirVetor(vetSeq, &tam);

                start = omp_get_wtime();

                sequencial(vetSeq, &tam);

                end = omp_get_wtime();

                printf("Sequencial = %f\n", (end - start));

                // printf("Vetor ordenado: ");
                // imprimirVetor(vetSeq, &tam);

                free(vetSeq);

                printf("-----------------------------------------------\n");
            }
        }
        break;

        case 2:
        {
            for (int i = 0; i < 4; i++)
            {
                int *vetParalel;

                vetParalel = (int *)malloc(tam * sizeof(int));

                for (int i = 0; i < tam; i++)
                {
                    vetParalel[i] = vetAux[i];
                }

                // printf("Vetor desordenado: ");

                // imprimirVetor(vetParalel, &tam);

                omp_set_num_threads(4);

                start = omp_get_wtime();

                paralelo(vetParalel, &tam);

                end = omp_get_wtime();

                printf("Paralelo= %f\n", (end - start));

                // printf("Vetor ordenado: ");
                // imprimirVetor(vetParalel, &tam);

                free(vetParalel);

                printf("-----------------------------------------------\n");
            }
        }
        break;

        default:
            break;
        }

    } while (tipoExecucao != 0);
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

void swap(int *num1, int *num2)
{

    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void imprimirVetor(int *vet, int *tam)
{
    for (int i = 0; i < *tam; i++)
    {
        printf("%d,", vet[i]);
    }
    printf("\n");
}

void preenche_vetor_aleatorio(int *vet, int *tam)
{
    for (int i = 0; i < *tam; i++)
    {
        vet[i] = rand() % 100000;
    }
}

void preenche_vetor_em_sequencia(int *vet, int *tam)
{
    for (int i = 0; i < *tam; i++)
    {
        vet[i] = i;
    }
}

void sequencial(int *vet, int *tam)
{
    int i, j;
    for (i = 0; i < *tam - 1; i++)
        for (j = 0; j < *tam - i - 1; j++)
            if (vet[j] > vet[j + 1])
                swap(&vet[j], &vet[j + 1]);
}

int *inverte_vetor(int *vet, int *tam)
{

    int *vetorInvertido;

    vetorInvertido = (int *)malloc(*tam * sizeof(int));

    for (int i = 0; i < *tam; i++)
    {
        vetorInvertido[i] = vet[*tam - i - 1];

        // printf("%d, ", vetorInvertido[i]);
    }

    return vetorInvertido;
}

void paralelo(int *vet, int *tam)
{

    int first;

    for (int i = 0; i < *tam - 1; i++)
    {
        first = i % 2;
        // printf("%d,", first);
#pragma omp parallel for default(none), shared(vet, first, tam)
        for (int j = first; j < *tam - 1; j += 1)
        {

            if (vet[j] > vet[j + 1])
            {
                swap(&vet[j], &vet[j + 1]);
            }
        }
    }
}