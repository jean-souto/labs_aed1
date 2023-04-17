#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

Lista* criar()
{
    Lista *l = (Lista*) malloc (sizeof(Lista));
    l->inicio = NULL; 
    return l;
}

void limpar(Lista *l) 
{
    while (listaVazia(l) != 0)
    removerInicio(l);
}

void mostrar(Lista *l) 
{
    if (l != NULL) 
    {
        printf("[");
        No *noLista = l->inicio;
        
        while (noLista != NULL) 
        {
            printf(" {%d, ",noLista->valor.mat);
            printf("%s, ",noLista->valor.nome);
            printf("%.2f} ",noLista->valor.n1);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}

int listaVazia (Lista*l) 
{
    if (l == NULL) return 2;
    if (l->inicio == NULL)
    return 0;
    return 1;
}

int inserirInicio (Lista *l, Aluno it) 
{
    if (l == NULL) return 2;
    No *no = (No*) malloc (sizeof(No));
    no->valor = it;
    no->prox = l->inicio;
    l->inicio = no;
    return 0;
}

int inserirFim (Lista *l, Aluno it)
{ 
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return inserirInicio(l,it); 
    No *noLista = l->inicio;
    while (noLista->prox != NULL) noLista = noLista->prox; 
    No *no = (No*) malloc (sizeof(No)); 
    no->valor = it; 
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int inserirPosicao (Lista *l, Aluno it, int pos)
{
    if (l == NULL) return 2;
    if (pos < 0) return 3;
    if ((listaVazia(l) == 0) || (pos == 0)) return inserirInicio (l,it);
    No *noLista = l->inicio;
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

int removerInicio (Lista*l)
{
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *noLista=l->inicio;
    l->inicio = noLista->prox;
    free(noLista);
    return 0;
}

int removerFim(Lista *l) 
{  
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    No *noAuxiliar = NULL;
    
    No *noLista = l->inicio;

    while (noLista->prox != NULL) 
    {
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }
    
    if (noAuxiliar == NULL) l->inicio = NULL;
    else noAuxiliar->prox = NULL;

    free(noLista);
    
    return 0;
}

int removerPosicao (Lista *l, int pos)
{
    No *noAuxiliar = NULL;
    No *noLista = l->inicio;
    int coord = 0;

    while (noLista->prox != NULL && coord != pos) 
    {
        noAuxiliar = noLista;
        noLista = noLista->prox;
        coord++;
    }

    if (noAuxiliar == NULL) l->inicio = NULL;
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
    No *noLista = l->inicio;

    while ((noLista != NULL) && (noLista->valor.mat != item)) 
    {
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }

    if (noAuxiliar == NULL) l->inicio = NULL;
    else noAuxiliar->prox = NULL;

    noAuxiliar->prox = noLista->prox;

    free(noLista);
}

int removerN (Lista *l, int n)
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) return 2;

    No *noPrin = l->inicio;
    int pos = 0;

    while (noPrin != NULL && pos != n)
    {
        removerInicio(l);
        noPrin = noPrin->prox;
        pos++;
    }

    return 0;
}

int buscarItemChave(Lista *l, int chave, Aluno *retorno) 
{
    if (l == NULL) return 2;

    No *noLista = l->inicio;

    while ((noLista != NULL)) 
    {
        if ((noLista->valor).mat == chave) 
        {
            *retorno = noLista->valor;
            return 0;
        }
        noLista = noLista->prox;
    }

    return 1;
}

int buscarPosicao (Lista *l, int Item, Aluno *retorno)
{
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    No *noLista = l->inicio;
    int pos = 0;

    while ((l->inicio->prox != NULL) && (pos != Item)) 
    {
        noLista->valor = noLista->prox->valor;
        pos++;
    }
    strcpy(retorno->nome, noLista->valor.nome);
    retorno->mat = noLista->valor.mat;
    retorno->n1 = noLista->valor.n1;

    return 0;
}

int contemItem (Lista *l, int Item)
{
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    int found = 1;

    No *aux = l->inicio;

    while ((aux->prox != NULL) && (aux->valor.mat != Item)) 
    {
        aux = aux->prox;
    }

    if (aux->valor.mat == Item) return 0; else return 1;
}

int concatenar (Lista *l1, Lista *l2, Lista *l3)
{
    No *aux = l1->inicio;

    while (aux != NULL)
    {
        inserirInicio(l3, aux->valor);
        aux = aux->prox;
    }

    aux = l2->inicio;

    while (aux != NULL)
    {
        inserirInicio(l3, aux->valor);
        aux = aux->prox;
    }

    return 0;
}

int maiorNota (Lista *l, Aluno *retorno)
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) return 2;

    No *aux = l->inicio;
    float maior = aux->valor.n1;
    *retorno = aux->valor;

    while (aux != NULL)
    {
        if (aux->valor.n1 > maior)
        {
            maior = aux->valor.n1;
            *retorno = aux->valor;
        }
        aux = aux->prox;
    }

    return 0;
}