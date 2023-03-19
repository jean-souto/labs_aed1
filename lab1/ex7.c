/*g)Crieumprogramaquepreenchaumamatriz5x10comnúmerosinteirosesomecadaumadaslinhas,armazenandooresultadodassomasemumvetor.Aseguiroprogramadeverámultiplicarcadaelementodamatrizpelasomadalinhacorrespondenteemostraramatrizresultante.*/

#include <stdio.h>

int main ()
{
    int matriz [5][10], vet[5];
    int i, j;

    for (j = 0; j < 5; j++)
    {
        vet[j] = 0;
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            matriz[i][j] = j;
            vet[i] += matriz[i][j];
        }
    }

    for (j = 0; j < 5; j++)
    {
        printf ("\nA soma da linha %d eh %d.", j, vet[j]);
    }

    return 0;
}