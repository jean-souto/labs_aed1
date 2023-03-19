#include <stdio.h>
#include <time.h>

int main ()
{
    char nome[] = "Carla Faria";
    double vet[10];
    int i;

    srand (time (NULL));

    for (i = 0; i < 12; i++)
    {
        printf ("%c", *(nome+i));
    }

    printf ("\n\n");

    for (i = 0; i < 10; i++)
    {
        vet[i] = rand () % 100;
        printf (" %lf ", *(vet+i));
    }

    return 0;
}