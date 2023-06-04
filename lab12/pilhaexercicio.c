#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila1.h"

void inverteFila (Fila *f)
{
    Pilha *p;
    int i, quant = f->qtd, nun;
    p = criar();

    for (i = 0; i < quant; i++)
    {
        consultarFila(f, &nun);
        removerFila(f);
        push(p, nun);
        //printf ("a");
    }
    //mostrar(p);
    //limparFila(f);
    for (i = 0; i < quant; i++)
    {
        //printf("u");
        pop(p, &nun);
        inserirFila(f, nun);
    }
}

int main ()
{
    Pilha *p1, *p2;
    int x;
    Fila *f1, *f2;
    
    f1 = criarFila();
    f2 = criarFila();
    p1 = criar();
    p2 = criar();

    inserirFila(f1, 12);
    inserirFila(f1, 13);
    inserirFila(f1, 14);
    inserirFila(f1, 15);
    inserirFila(f1, 16);
    mostrarFila(f1);
    inverteFila(f1);
    mostrarFila(f1);

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