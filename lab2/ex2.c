#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int *p, i;

    p = (int *) calloc (5, sizeof(int));

    for (i = 0; i < 5; i++)
    {
        printf ("Digite um numero: ");
        scanf ("%d", &p[i]);
    }

    for (i = 0; i < 5; i++)
    {
        printf (" %d ", p[i]);
    }

    free(p);

    return 0;
}