#include <stdio.h>
#include <stdlib.h>

void media_maior (int *vet, int n, float *media, int *maior)
{
    int i;
    *maior = vet[0];
    for (i = 0; i < n; i++)
    {
        *media += vet[i];
        if (vet[i] > *maior)
        {
            *maior = vet[i];
        }
    }
    *media = *media/n;
}

int main ()
{
    int i, n, maior, *vetor;
    float media = 0;

    printf ("Digite quantos numeros voce quer armazenar: ");
    scanf ("%d", &n);

    vetor = (int*) calloc (n, sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf ("Digite os numeros: ");
        scanf ("%d", &vetor[i]);
    }

    media_maior (vetor, n, &media, &maior);

    printf ("O maior valor eh %d e a media eh %.1f.", maior, media);

    free(vetor);

    return 0;
}