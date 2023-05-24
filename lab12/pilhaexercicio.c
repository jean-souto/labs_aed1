#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main ()
{
    Pilha *p1, *p2;
    int x;

    p1 = criar();
    p2 = criar();

    push(p1, 11);
    push(p1, 34);
    pop (p1, &x);
    pop (p1, &x);
    push (p1, 23);
    push (p1, 45);
    pop (p1, &x);
    push (p1, 121);
    push (p1, 22);
    pop (p1, &x);
    pop (p1, &x);

    mostrar(p1);

    push (p2, 23);
    push (p1, 12);
    push (p2, 12);
    //push(p2, 15);

    mostrar(p1);
    mostrar(p2);

    if (comparar(p1,p2) == 0) printf ("Iguais!\n"); else printf ("Diferentes!\n");

    mostrar (p1);
    mostrar (p2);
    printf ("%d", tamanho(p1));

    return 0;
}