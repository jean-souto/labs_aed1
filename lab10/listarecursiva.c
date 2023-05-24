#include <stdio.h>
#include <stdlib.h>
#include "listarecursiva.h"

Lista *criar ()
{
    Lista *l; 
    (*l) = (No*) malloc (sizeof(No));
    (*l) = NULL; 
    return l;
}

int inserirInicio (Lista *l, int it)
{
    if (l == NULL) return 2; 
    
    No *n = (No*) malloc (sizeof(No)); 
    
    n->valor = it;
    n->prox = (*l);
    (*l) = n;
    
    return 0;
}

int removerInicio (Lista *l)
{ 
    if (l == NULL) return 2;
    if ((*l) == NULL) return 1; // (*l) == NULL 
    
    No* noLista = (*l);
    (*l) = (*l)->prox;
    free(noLista);
    
    return 0;
}

void mostrar(Lista *l) 
{
    if (l != NULL) 
    {
        printf("[");
        No *noLista = (*l);
        
        while (noLista != NULL) 
        {
            printf(" {%d} ", noLista->valor);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}

int tamanho (Lista *l)
{
    No *aux = (*l);
    int tam = 0;

    while (aux != NULL)
    {
        tam++;
        aux = aux->prox;
    }

    return tam;
}

int listaVazia (Lista *l) 
{
    if (l == NULL) return 2;
    if ((*l) == NULL) return 0;
    return 1;
}

void limpar(Lista *l) 
{
    while (listaVazia(l) != 0)
    removerFim(l);
}

int inserirFim (Lista *l, int it)
{ 
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return inserirInicio(l,it); 
    No *noLista = (*l);
    while (noLista->prox != NULL) noLista = noLista->prox; 
    No *no = (No*) malloc (sizeof(No)); 
    no->valor = it; 
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int inserirPosicao (Lista *l, int it, int pos)
{
    if (l == NULL) return 2;
    if (pos < 0) return 3;
    if ((listaVazia(l) == 0) || (pos == 0)) return inserirInicio (l,it);
    No *noLista = (*l);
    int p=1; 
    while ((noLista->prox!=NULL) && (p!=pos)) 
    { 
        p++;
        noLista = noLista->prox;
    }
    No *no = (No*) malloc (sizeof(No));
    no->valor = it;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int removerFim(Lista *l) 
{  
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    No *noAuxiliar = NULL;
    
    No *noLista = (*l);

    while (noLista->prox != NULL) 
    {
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }
    
    if (noAuxiliar == NULL) (*l) = NULL;
    else noAuxiliar->prox = NULL;

    free(noLista);
    
    return 0;
}

int removerPosicao (Lista *l, int pos)
{
    No *noAuxiliar = NULL;
    No *noLista = (*l);
    int coord = 0;

    while (noLista->prox != NULL && coord != pos) 
    {
        noAuxiliar = noLista;
        noLista = noLista->prox;
        coord++;
    }

    if (noAuxiliar == NULL) (*l) = NULL;
    else noAuxiliar->prox = NULL;

    noAuxiliar->prox = noLista->prox;

    free(noLista);

    return 0;
}

int removerItem (Lista *l, int item)
{
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    No *noAuxiliar = NULL;
    No *noLista = (*l);

    while ((noLista != NULL) && (noLista->valor != item)) 
    {
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }

    if (noAuxiliar == NULL) (*l) = NULL;
    else noAuxiliar->prox = NULL;

    noAuxiliar->prox = noLista->prox;

    free(noLista);
}

int iguais (Lista *l1, Lista *l2)
{
    if ((l1 == NULL) && (l2 == NULL)) return 0;
    if ((listaVazia (l1) == 0) && (listaVazia(l2) == 0)) return 0;
    if (tamanho(l1) != tamanho(l2)) return 1;
    No *n1 = (*l1);
    No *n2 = (*l2);
    if ((n1->valor) != (n2->valor)) return 1;
    return iguais (&n1->prox, &n2->prox);
}