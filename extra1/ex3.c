#include <stdio.h>
#include <stdlib.h>

int divisor (int x)
{
    int i, soma = 0;
    for (i = x-1; i > 0; i--)
    {
        if ((x % i) == 0)
        {
            soma += i;
        }
    }

    if (soma == x)
    {
        return 1;
    }else return 0;
}

int main ()
{
    int x, res;

    printf ("Digite um numero: ");
    scanf ("%d", &x);

    res = divisor(x);

    if (res == 1)
    {
        printf ("A soma dos divisores de %d eh %d!", x, x);
    } else printf ("A soma dos divisores de %d nao eh %d", x, x);

    return 0;
}