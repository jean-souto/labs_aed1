#include <stdio.h>
#include <stdlib.h>

void troca (int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void inversao (int *vet, int n)
{
    int i, j = 0;
    for (i = n-1; i > n/2; i--)
    {
        troca(&vet[i], &vet[j]);
        j++;
    }
}

int main ()
{
    int i, n, *vet;

    printf ("Digite o tamanho do vetor: ");
    scanf ("%d", &n);

    vet = (int*) calloc (n, sizeof(int));

    printf ("Vetor antes: \n");
    for (i = 0; i < n; i++)
    {
        vet[i] = i;
        printf (" %d ", vet[i]);
    }

    printf ("\nVetor depois:\n ");
    inversao(vet, n);

    for (i = 0; i < n; i++)
    {
        printf (" %d ", vet[i]);
    }

    free(vet);

    return 0;
}