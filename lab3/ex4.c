#include <stdio.h>

int divisao (int a, int b, int *div, int *rest)
{
    if (b != 0)
    {
        *div = a/b;
        *rest = a%b;
        return 0;
    }
    else return -1;
}

int main ()
{
    int a, b, quociente = -10, resto = -10, verify = -10;

    printf ("Digite dois numeros a/b: ");
    scanf ("%d%d", &a, &b);

    verify = divisao(a,b, &quociente, &resto);

    if (verify == 0)
    {
        printf ("O quociente da divisao de %d por %d eh %d e o resto eh %d.", a, b, quociente, resto);
    }
    else
    {
        printf ("ERRO! Valores inválidos!");
    }

    return 0;
}