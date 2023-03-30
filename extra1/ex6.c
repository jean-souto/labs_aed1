#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int v1[50], v2[50], *vet3, i, j, quant_acertos = 0;

    srand(time(NULL));

    printf ("Digite seus numeros: ");
    for (i = 0; i < 50; i++)
    {
        v1[i] = rand() % 100;
        scanf ("%d", &v2[i]);
    }

    for (i = 0; i < 50; i++)
    {
       for (j = 0; j < 50; j++)
       {
            if (v1[i] == v2[j])
            {    
                quant_acertos++;
            }
       }
    }
    vet3 = (int*) calloc (quant_acertos, sizeof(int));
    quant_acertos = 0;
    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 50; j++)
        {
            if (v1[i] == v2[j])
            {    
                vet3[quant_acertos] = v1[i];
                quant_acertos++;
            }
        }
    }

    printf ("Numeros sorteados: ");
    for (i = 0; i < 50; i++)
    {
        printf (" %d ", v1[i]);
    }
    printf ("\nSeus numeros: ");
    for (i = 0; i < 50; i++)
    {
        printf (" %d ", v2[i]);
    }
    printf ("\nAcertos: ");
    for (i = 0; i < quant_acertos; i++)
    {
        printf (" %d ", vet3[i]);
    }

    printf ("\nVoce obteve %d acertos!", quant_acertos);
    
    return 0;
}