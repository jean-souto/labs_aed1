#include <stdio.h>
#include <stdlib.h>

void data(int dd, int mm, int aaaa)
{
    printf ("%d/%d/%d", dd, mm, aaaa);
}

int main ()
{
    int dia, mes, ano;

    printf ("Digite dia, mes e ano: ");
    scanf ("%d%d%d", &dia, &mes, &ano);
    data(dia,mes,ano);

    return 0;
}