#include <stdio.h>
#include <stdlib.h>

int excluir (int n)
{
    int *vetor;
    int i, j, exc = 0;
    vetor = (int*) calloc (n, sizeof(int));
    printf ("\nDigite os valores: ");
    for (i = 0; i < n; i++)
    {
        scanf ("%d", &vetor[i]);
    }

    printf ("\nVetor antes: ");
    for (i = 0; i < n; i++)
    {
        printf (" %d ", vetor[i]);
    }

    for (i = 0; i < (n-1); i++)
    {
        if (vetor[i] == vetor[i+1])
        {
            for (j = i+1; j < n-1; j++)
            {
                vetor[j] = vetor[j+1];
            }
            i = -1;
            vetor = realloc (vetor, n*sizeof(int));
            n--;
            exc++;
        }
    }

    printf ("\nVetor depois: ");
    for (i = 0; i < n; i++)
    {
        printf (" %d ", vetor[i]);
    }

    return exc;
}

int main ()
{
    int n, exclusao;

    printf ("Digite o tamanho do vetor: ");
    scanf ("%d", &n);

    exclusao = excluir(n);

    printf ("\nForam feitas %d exclusoes.", exclusao);

    return 0;
}