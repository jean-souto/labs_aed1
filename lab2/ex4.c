#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i, k = 0, contador = 1;
    int *p, *temp;

    while (k != -1)
    {
        printf ("Digite um numero: ");
        scanf ("%d", &k);

        if (k != -1)
        {
            temp = (int *) realloc (temp, contador+1);

            if (temp != (NULL))
            {
                p = temp;
                p[contador] = k;
                contador++;
            }
        }
    }
    
    for (i = 0; i < contador; i++)
    {
        printf ("\n%d", p[i]);
    }

    free (p);
    free (temp);

    return 0;
}