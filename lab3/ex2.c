#include <stdio.h>

int exponencial (int x, int y)
{
    int i, exp = 1;

    for (i = y; i > 0; i--)
    {
        exp = exp*x;
    }

    return exp;
}

int main ()
{
    int x, y;

    printf ("Digite o numero e o exponencial: ");
    scanf ("%d%d", &x, &y);

    printf ("O resultado de %d elevado a %d eh igual a %d", x, y, exponencial(x,y));

    return 0;
}