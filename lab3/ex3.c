#include <stdio.h>

int fat (int nun)
{
    int resultado;

    if (nun == 0 || nun == 1)
    {
        return resultado = 1;
    }
    else
    {
        return resultado = nun*fat(nun-1);
    }
}

int exponencial (int x, int y)
{
    int i, exp = 1;

    for (i = y; i > 0; i--)
    {
        exp = exp*x;
    }

    return exp;
}

float fexp (int x, int n)
{
    int i;
    float e = 1.0;

    if (n == 0)
    {
        return e;
    } else if (n == 1)
    {
        return (e+x);
    } else {
        for (i = 1; i <= n; i++)
        {
            e = e+((exponencial(x,i)*1.0)/fat(i));
        }

        return e;
    }
}

int main ()
{
    int x, n;

    printf ("Digite x e n: ");
    scanf ("%d%d", &x, &n);

    printf ("A aproximacao de e elevado a %d com %d de precisao eh %.3f", x, n, fexp(x,n));

    return 0;
}