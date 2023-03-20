#include <stdio.h>
#include <stdlib.h>

void multiplicar (int *vetor, int n, int constante)
{
    int i;
    for (i = 0; i < n; i++)
    {
        vetor[i] = vetor[i]*constante;
    }
}

int main ()
{
    int i, n, constante, *vet;

    printf ("Digite o tamanho do vetor: ");
    scanf ("%d", &n);

    printf ("Digite a constante: ");
    scanf ("%d", &constante);

    vet = (int*) calloc (n, sizeof(int));

    printf ("Vetor antes: \n");
    for (i = 0; i < n; i++)
    {
        vet[i] = i;
        printf (" %d ", vet[i]);
    }
    multiplicar(vet, n, constante);
    printf ("\nVetor depois: \n");
    for (i = 0; i < n; i++)
    {
        printf (" %d ", vet[i]);
    }

    return 0;
}