#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int **vet1, **vet2, **vetsoma; // ponteiros q serão usados para criar as matrizes
    int i, j; // índices

    srand (time (NULL));

    vet1 = (int **) calloc (3, sizeof(int *));
    vet2 = (int **) calloc (3, sizeof(int *));
    vetsoma = (int **) calloc (3, sizeof(int *));

    for (i = 0; i < 3; i++)
    {
        vet1[i] = (int *) calloc (3, sizeof(int));
        vet2[i] = (int *) calloc (3, sizeof(int));
        vetsoma[i] = (int *) calloc (3, sizeof(int));
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            vet1[i][j] = rand () % 9;
            vet2[i][j] = rand () % 9;
            vetsoma[i][j] = vet1[i][j]+vet2[i][j];
        }
    }

    printf ("matriz 1: \n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf (" %d ", vet1[i][j]);
        }
        printf ("\n");
    }

    printf ("\nmatriz 2: \n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf (" %d ", vet2[i][j]);
        }
        printf ("\n");
    }

    printf ("\nmatriz soma: \n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf (" %d ", vetsoma[i][j]);
        }
        printf ("\n");
    }

    for (i = 0; i < 3; i++)
    {
        free(vet1[i]);
        free(vet2[i]);
        free(vetsoma[i]);
    }

    free(vet1);
    free(vet2);
    free(vetsoma);

    return 0;
}