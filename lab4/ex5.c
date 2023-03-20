#include <stdio.h>
#include <stdlib.h>

int* alocar (int n, int nun)
{
    int *vetor, i;

    vetor = (int*) calloc (n, sizeof(int));
    
    for (i = 0; i < n; i++)
    {
        vetor[i] = nun;
    }
    
    return vetor;
}

int main ()
{
    int n, nun, *vet, i;

    printf ("Digite o tamanho: ");
    scanf ("%d", &n);
    printf ("Digite o numero que preenchera o vetor: ");
    scanf ("%d", &nun);

    vet = alocar (n, nun);

    printf ("\nVetor preenchido como: \n");
    
    for (i = 0; i < n; i++)
    {
        printf (" %d ", vet[i]);
    }

    free (vet);

    return 0;
}