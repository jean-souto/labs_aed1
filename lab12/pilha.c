#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
//#include "fila1.h"

typedef struct pilha 
{
    int topo;
    int valores[MAX];
}Pilha;

Pilha *criar () 
{ 
    Pilha *p = (Pilha*) malloc (sizeof(Pilha));
    p->topo = 0;
    return p;
} 

void limpar (Pilha *p) 
{ 
    free (p);
    p = NULL;
}

int push (Pilha *p, int it)
{
    if (p == NULL) return 2;
    if (pilhaCheia(p) == 0) return 1;
    
    p->valores[p->topo] = it; 
    p->topo++;
    return 0;
}

int pop (Pilha *p, int *it)
{
    if (p == NULL) return 2;
    if (pilhaVazia(p) == 0) return 1;
    
    *it = p->valores[p->topo-1];
    p->topo--;
    return 0;
}

int consultar (Pilha *p, int *it)
{
    if (p == NULL) return 2;
    if (pilhaVazia(p)==0) return 1;
    *it = p->valores[p->topo-1]; return 0;
} 

int tamanho (Pilha *p)
{
    if (p == NULL) return -1;
    return p->topo;
}

int pilhaVazia (Pilha *p) 
{
    if (p == NULL) return 2;
    if (p->topo == 0) return 0; 
    else return 1;
} 

int pilhaCheia (Pilha *p) 
{
    if (p == NULL) return 2; 
    if (p->topo == MAX) return 0; else return 1;
}

void mostrar (Pilha *p) 
{
    if (p != NULL)
    {
        printf("[");
        int i; 
        for(i = 0;i < p->topo; i++)
        {
            printf("{%d}",p->valores[i]);
        }printf("]\n");
    }
}

int comparar (Pilha *p1, Pilha *p2)
{
    if (p1 == NULL) return 3;
    if (p2 == NULL) return 3;
    if (tamanho(p1) != tamanho(p2)) return 2;

    Pilha *aux1, *aux2;
    aux1 = criar();
    aux2 = criar();

    int i = 0, a, b;
    int tam = tamanho(p1);

    while(tamanho(p1) != 0)
    {
        pop(p1, &a);
        pop(p2, &b);
        push (aux1, a);
        push (aux2, b); 
        
        if (a != b) i++;
        if (i != 0)
        {
            while(tamanho(aux1) != 0)
            {
                pop(aux1, &a);
                pop(aux2, &b);
                push(p1, a);
                push(p2, b);
            }
            return 1;
        }
    }

    while(tamanho(aux1) != 0)
    {
        pop(aux1, &a);
        pop(aux2, &b);
        push(p1, a);
        push(p2, b);
    }

    return 0;
}

