#include <stdio.h>

int soma (int n)
{
    int i, soma = 0;

    for (i=1;i<=n;i++)
    {
        soma+=i;
    }

    return soma;
}

int main ()
{
    int n;

    printf ("Digite um numero: ");
    scanf ("%d", &n);

    printf ("A soma dos numeros ate %d eh %d", n, soma(n));

    return 0;
}