#include <stdio.h>
#include <stdlib.h>

int pot(int x, int y, int max, int *res)
{
    int i;
    *res = x;
    for (i = y-1; i > 0; i--)
    {
        *res = *res*x;
    }
    if (*res <= max)
    {
        return 0;
    } else return 1;
}

int main ()
{
    int x, y, max, resultado = 0, son;

    printf ("Digite x, y e o max: ");
    scanf ("%d%d%d", &x, &y, &max);

    son = pot(x,y,max,&resultado);

    if (son == 1)
    {
        printf ("O resultado eh %d e eh maior que o max (%d) definido.", resultado, max);
    } else printf ("O resultado eh %d e eh menor/igual que o max (%d) definido.", resultado, max);

    return 0;
}