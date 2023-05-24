#include <stdio.h>
#include <stdlib.h>
#include "fila1.h"

Fila *criar ()
{
    Fila *f = (Fila*) malloc (sizeof(Fila));
    f->qtd = 0;
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void limpar (Fila *f)
{
    if (f == NULL) return;
    
    while (filaVazia(f) != 0)
    remover (f);
    free (f);
    f = NULL;
}

int consultar (Fila *f, int *it) 
{
    if (f == NULL) return 2;
    if(filaVazia(f) == 0) return 1;
    
    *it = f->inicio->valor;
    return 0;
}

int tamanho (Fila *f)
{
    if (f == NULL) return-1;
    return f->qtd;
}

int filaVazia (Fila *f)
{
    if (f == NULL) return 2;
    if (f->qtd == 0) return 0;
    else return 1;
}

int filaCheia (Fila *f)
{ 
    return 1;
}

int inserir (Fila *f, int it)
{
    if (f == NULL) return 2;
    No *no = (No*) malloc (sizeof(No));
    no->valor = it;
    no->proximo = NULL;
    
    if (filaVazia (f) == 0) f->inicio=no;
    else f->fim->proximo = no;
    f->fim = no;
    f->qtd++;
    return 0;
}

int remover (Fila *f) 
{ 
    if (f == NULL) return 2;
    if (filaVazia(f) == 0) return 1;
    
    No *temp = f->inicio;
    f->inicio = temp->proximo;
    free(temp);
    if (f->inicio == NULL) f->fim = NULL;
    f->qtd--;
    return 0;
}

void mostrar (Fila *f)
{ 
    if (f != NULL) 
    {
        printf ("[\n");
        No *no = f->inicio;
        while(no != NULL)
        {
            printf ("{%d}", no->valor);
            no = no->proximo;
        } 
        printf("]\n");
    }
}