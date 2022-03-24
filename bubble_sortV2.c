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
int bubblesortV2(int *vet, int *tam);

int menu();

int main()
{

    int *vet;
    int *vetAux;

    double start, end;

    int tam = 20;

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
            free(vet);
            free(vetAux);
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

                printf("Vetor desordenado: ");

                imprimirVetor(vetSeq, &tam);

                start = omp_get_wtime();

                sequencial(vetSeq, &tam);

                end = omp_get_wtime();

                printf("Sequencial = %f\n", (end - start));

                printf("Vetor ordenado: ");
                imprimirVetor(vetSeq, &tam);

                free(vetSeq);

                printf("-----------------------------------------------\n");
            }
        }
        break;

        case 2:
        {
            for (int i = 1; i < 16; i++)
            {
                if (i <= 4)
                {
                    printf("---------------------------RODANDO COM 2 THREADS---------------------------\n");
                    omp_set_num_threads(2);
                }
                else if (i > 4 && i <= 8)
                {
                    printf("---------------------------RODANDO COM 4 THREADS---------------------------\n");
                    omp_set_num_threads(4);
                }
                else if (i > 8 && i <= 12)
                {
                    printf("---------------------------RODANDO COM 6 THREADS---------------------------\n");
                    omp_set_num_threads(6);
                }
                else if (i > 12 && i <= 16)
                {
                    printf("---------------------------RODANDO COM 8 THREADS---------------------------\n");
                    omp_set_num_threads(8);
                }
                int *vetParalelAleatorio;

                vetParalelAleatorio = (int *)malloc(tam * sizeof(int));

                for (int i = 0; i < tam; i++)
                {
                    vetParalelAleatorio[i] = vetAux[i];
                }

                printf("Vetor desordenado: ");

                imprimirVetor(vetParalelAleatorio, &tam);

                start = omp_get_wtime();

                paralelo(vetParalelAleatorio, &tam);

                end = omp_get_wtime();

                printf("Paralelo= %f\n", (end - start));

                printf("Vetor ordenado: ");
                imprimirVetor(vetParalelAleatorio, &tam);

                free(vetParalelAleatorio);

                printf("-----------------------------------------------\n");
            }
        }
        break;

        case 3:
        {
            for (int i = 0; i < 4; i++)
            {

                int *vetSeq;

                vetSeq = (int *)malloc(tam * sizeof(int));

                preenche_vetor_em_sequencia(vetSeq, &tam);

                vetSeq = inverte_vetor(vetSeq, &tam);

                printf("Vetor desordenado: ");

                imprimirVetor(vetSeq, &tam);

                start = omp_get_wtime();

                sequencial(vetSeq, &tam);

                end = omp_get_wtime();

                printf("Sequencial com vetor invertido = %f\n", (end - start));

                printf("Vetor ordenado: ");

                imprimirVetor(vetSeq, &tam);

                free(vetSeq);

                printf("-----------------------------------------------\n");
            }
        }
        break;

        case 4:
        {
            for (int i = 1; i < 16; i++)
            {
                if (i <= 4)
                {
                    printf("---------------------------RODANDO COM 2 THREADS---------------------------\n");
                    omp_set_num_threads(2);
                }
                else if (i > 4 && i <= 8)
                {
                    printf("---------------------------RODANDO COM 4 THREADS---------------------------\n");
                    omp_set_num_threads(4);
                }
                else if (i > 8 && i <= 12)
                {
                    printf("---------------------------RODANDO COM 6 THREADS---------------------------\n");
                    omp_set_num_threads(6);
                }
                else if (i > 12 && i <= 16)
                {
                    printf("---------------------------RODANDO COM 8 THREADS---------------------------\n");
                    omp_set_num_threads(8);
                }
                int *vetParalelInvertido;

                vetParalelInvertido = (int *)malloc(tam * sizeof(int));

                preenche_vetor_em_sequencia(vetParalelInvertido, &tam);

                vetParalelInvertido = inverte_vetor(vetParalelInvertido, &tam);

                printf("Vetor desordenado: ");

                imprimirVetor(vetParalelInvertido, &tam);

                start = omp_get_wtime();

                paralelo(vetParalelInvertido, &tam);

                end = omp_get_wtime();

                printf("Paralelo com vetor invertido = %f\n", (end - start));

                printf("Vetor ordenado: ");
                imprimirVetor(vetParalelInvertido, &tam);

                free(vetParalelInvertido);

                printf("-----------------------------------------------\n");
            }
        }
        break;

        case 5:
        {
            for (int i = 1; i < 16; i++)
            {
                if (i <= 4)
                {
                    printf("---------------------------RODANDO COM 2 THREADS---------------------------\n");
                    omp_set_num_threads(2);
                }
                else if (i > 4 && i <= 8)
                {
                    printf("---------------------------RODANDO COM 4 THREADS---------------------------\n");
                    omp_set_num_threads(4);
                }
                else if (i > 8 && i <= 12)
                {
                    printf("---------------------------RODANDO COM 6 THREADS---------------------------\n");
                    omp_set_num_threads(6);
                }
                else if (i > 12 && i <= 16)
                {
                    printf("---------------------------RODANDO COM 8 THREADS---------------------------\n");
                    omp_set_num_threads(8);
                }
                int *vetParalelV2Aleatorio;

                vetParalelV2Aleatorio = (int *)malloc(tam * sizeof(int));

                for (int i = 0; i < tam; i++)
                {
                    vetParalelV2Aleatorio[i] = vetAux[i];
                }

                printf("Vetor desordenado: ");

                imprimirVetor(vetParalelV2Aleatorio, &tam);

                start = omp_get_wtime();

                bubblesortV2(vetParalelV2Aleatorio, &tam);

                end = omp_get_wtime();

                printf("Paralelo v2 = %f\n", (end - start));

                printf("Vetor ordenado: ");
                imprimirVetor(vetParalelV2Aleatorio, &tam);

                free(vetParalelV2Aleatorio);

                printf("-----------------------------------------------\n");
            }
        }
        break;

        case 6:
        {
            for (int i = 1; i < 16; i++)
            {
                if (i <= 4)
                {
                    printf("---------------------------RODANDO COM 2 THREADS---------------------------\n");
                    omp_set_num_threads(2);
                }
                else if (i > 4 && i <= 8)
                {
                    printf("---------------------------RODANDO COM 4 THREADS---------------------------\n");
                    omp_set_num_threads(4);
                }
                else if (i > 8 && i <= 12)
                {
                    printf("---------------------------RODANDO COM 6 THREADS---------------------------\n");
                    omp_set_num_threads(6);
                }
                else if (i > 12 && i <= 16)
                {
                    printf("---------------------------RODANDO COM 8 THREADS---------------------------\n");
                    omp_set_num_threads(8);
                }
                int *vetInvertidoV2;

                vetInvertidoV2 = (int *)malloc(tam * sizeof(int));

                preenche_vetor_em_sequencia(vetInvertidoV2, &tam);

                vetInvertidoV2 = inverte_vetor(vetInvertidoV2, &tam);

                printf("Vetor desordenado: ");

                imprimirVetor(vetInvertidoV2, &tam);

                start = omp_get_wtime();

                bubblesortV2(vetInvertidoV2, &tam);

                end = omp_get_wtime();

                printf("Paralelo = %f\n", (end - start));

                printf("Vetor ordenado: ");
                imprimirVetor(vetInvertidoV2, &tam);

                free(vetInvertidoV2);

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
    printf("1 - SEQUENCIAL VETOR ALEATORIO\n");
    printf("2 - PARALELIZADO V1 ALEATORIO\n");
    printf("3 - SEQUENCIAL VETOR INVERTIDO\n");
    printf("4 - PARALELIZADO V1 INVERTIDO\n");
    printf("5 - PARALELIZADO V2 ALEATORIO\n");
    printf("6 - PARALELIZADO V2 INVERTIDO\n");
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
        vet[i] = (rand() % 10);
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
    /*
    #pragma omp parallel for default(none), shared(vet, tam)
        for (int i = 0; i < *tam - 1; i++)
        {
            // printf("%d,", i);
            if (i % 2 == 0)
            {
                for (int i = 0; i <= *tam - 1; i = i + 1)
                {
                    if (vet[i] > vet[i + 1])
                    {
                        swap(&vet[i], &vet[i + 1]);
                    }
                }
            }
            else
            {
                for (int i = 1; i <= *tam - 1; i = i + 1)
                {
                    if (vet[i] > vet[i + 1])
                    {
                        swap(&vet[i], &vet[i + 1]);
                    }
                }
            }
        }*/

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

int bubblesortV2(int *vet, int *tam)
{
    int i, troca = 1;
    while (troca != 0)
    {
#pragma omp parallel
        {
            troca = 0;
#pragma omp for reduction(+ \
                          : troca)
            for (i = 0; i < *tam - 1; i = i + 2)
            {
                if (vet[i] > vet[i + 1])
                {
                    swap(&vet[i], &vet[i + 1]);
                    ++troca;
                }
            }
#pragma omp for reduction(+ \
                          : troca)
            for (i = 1; i < *tam - 1; i = i + 2)
            {
                if (vet[i] > vet[i + 1])
                {
                    swap(&vet[i], &vet[i + 1]);
                    ++troca;
                }
            }
        }
    }
}