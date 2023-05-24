#include <stdio.h>
#include <stdlib.h>
#include "fila1.h"

int main ()
{
    Fila *f;
    int it;

    f = criar();

    inserir(f,10);
    consultar(f,&it);
    printf (" I(%d),", it);

    inserir(f,20);
    consultar(f,&it);
    printf (" I(%d),", it);

    inserir(f,30);
    consultar(f,&it);
    printf (" I(%d),", it);

    inserir(f,45);
    consultar(f,&it);
    printf (" I(%d),", it);

    inserir(f,21);
    consultar(f,&it);
    printf (" I(%d),", it);

    mostrar(f);

    remover(f); 
    remover(f);

    consultar(f,&it);
    printf (" I(%d),", it);
    mostrar(f);

    return 0;
}