#include <stdio.h>
#include <stdlib.h>
#include "listarecursiva.h"

int main ()
{
    Lista *l, *l2;

    l = criar();
    l2 = criar();

    inserirInicio(l, 10);
    inserirInicio(l, 20);
    inserirFim(l, 5);
    inserirPosicao(l, 50, 0);
    mostrar(l);

    inserirInicio(l2, 10);
    inserirInicio(l2, 20);
    inserirFim(l2, 5);
    inserirPosicao(l2, 2, 50);
    mostrar(l2);

    if (iguais(l,l2) != 0) 
    { printf ("\nIGUAIS!!!\n"); } 
    else { printf ("Diferentes!!!"); }
    /*removerFim(l);
    mostrar(l);
    removerInicio(l);
    mostrar(l);
    removerPosicao(l, 1);
    mostrar(l);
    limpar(l);
    mostrar(l);*/

    return 0;
}