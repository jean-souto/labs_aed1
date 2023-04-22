#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listacircular.h"

Lista *criar () 
{
    Lista *l = (Lista*) malloc (sizeof(Lista));
    l->fim = NULL;
    
    return l;
}

void limpar (Lista*l) 
{ 
    while (listaVazia(l) != 0) removerInicio(l);
    free(l->fim);
    l = NULL;
}

int tamanho (Lista*l)
{ 
    if (l == NULL) return -1;
    if (listaVazia(l) == 0) return 0;
    
    No *noLista = l->fim;
    int cont=0;
    
    do
    {
        cont++;
        noLista = noLista->prox;
    }while(noLista != l->fim);
    
    return cont;
}

void mostrar (Lista*l)
{
    if (l != NULL)
    {
        printf ("[");
        
        if (listaVazia(l) != 0)
        {
            No *noLista = l->fim->prox;
            do
            {
                printf(" {%d, ",noLista->valor.mat);
                printf("%s, ",noLista->valor.nome);
                printf("%.2f} ",noLista->valor.n1);
                noLista = noLista->prox;
            }while(noLista != l->fim->prox);
        } printf("]\n");
    }
}

int listaVazia(Lista *l)
{
    if (l == NULL) return 2;
    if (l->fim == NULL) return 0; else return 1;
}

int listaCheia(Lista*l) { return 1; }

int inserirInicio (Lista *l, Aluno it)
{
    if (l == NULL) return 2;
    No *noaux = (No*) malloc (sizeof(No));
    noaux->valor = it;
    
    if (listaVazia(l) == 0)
    {
        l->fim = noaux;
        noaux->prox = noaux;
    } 
    else
    { 
        noaux->prox = l->fim->prox;
        l->fim->prox = noaux;
    }
    return 0;
}

int inserirFim (Lista *l, Aluno it) 
{ 
    if (l == NULL) return 2;
    No *noaux = (No*) malloc (sizeof(No));
    noaux->valor = it; 
    
    if (listaVazia(l) == 0)
    {
        l->fim = noaux;
        noaux->prox = noaux;
    }
    else
    { 
        noaux->prox = l->fim->prox;
        No *temp = l->fim;
        temp->prox = noaux;
        l->fim = noaux;
    }
    return 0;
}

int removerInicio (Lista *l) 
{
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (l->fim->prox == l->fim) 
    {
        free (l->fim);
        l->fim = NULL;
    }
    else
    {
        No *temp = l->fim->prox;
        l->fim->prox = l->fim->prox->prox;
        free(temp);
    }
    

    return 0;
}

int removerFim (Lista *l) 
{ 
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (l->fim->prox == l->fim)
    { 
        free (l->fim);
        l->fim = NULL;
        return 0;
    }
    No *anterior = NULL,*no = l->fim->prox;
    
    while (no->prox != l->fim->prox)
    {
        anterior = no;
        no = no->prox;
    }
    anterior->prox = l->fim->prox;
    l->fim = anterior;
    free(no);
    return 0;
}

int buscarItem (Lista *l, int chave, Aluno *it)
{ 
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    
    No *no = l->fim;
    
    while ((no->prox != l->fim) && ((no->valor).mat != chave)) 
    {
        no = no->prox;
    }

    if (no->valor.mat == chave)
    {
        it->mat = no->valor.mat;
        it->n1 = no->valor.n1;
        strcpy (it->nome, no->valor.nome);

        return 0;
    }
    return 1;
}

int contaElementos (Lista *l, int item)
{
    No *noaux;
    int quant = 0;

    noaux = l->fim->prox;

    do
    {
        if (noaux->valor.mat == item)
        {
            quant++;
        }
        noaux = noaux->prox;
    }while (noaux != l->fim->prox);
    return quant;
}

int filtro (Lista *l1, Lista *l2, Lista *l3, float nota)
{
    if (l1 == NULL) return 3;
    if (listaVazia(l1) == 0) return 4;
    if (l2 == NULL) l2 = criar ();
    if (l2 == NULL) return 2;
    if (l3 == NULL) l3 = criar ();
    if (l3 == NULL) return 1;

    No *aux;
    aux = l1->fim;

    while (aux->prox != l1->fim)
    {
        if (aux->valor.n1 >= nota)
        {
            inserirFim (l2, aux->valor);
        }
        else
        {
            inserirFim (l3, aux->valor);
        }

        aux = aux->prox;
    }

    return 0;
}

/*int produto (Lista *l1, Lista *l2, Lista *l3)
{
    if (l1 == NULL) return 3;
    if (listaVazia(l1) == 0) return 4;
    if (l2 == NULL) return 2;
    if (l3 == NULL) l3 = criar ();
    if (l3 == NULL) return 1;

    No *aux, *aux2; 
    aux = l1->inicio;
    aux2 = l2->inicio;
    Aluno it;
    it.mat = 000;
    strcpy (it.nome, "nnnnnnn");

    while (aux != l1->inicio && aux2 != l2->inicio)
    {
        it.n1 = aux->valor.n1*aux2->valor.n1;
        inserirFim(l3, it);
        aux = aux->prox;
        aux2 = aux2->prox;
    }

    return 0;
}*/

int removerPosi (Lista *l, int n)
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) return 2;
    if (n == 0)
    {
        removerInicio(l);
        return 0;
    }

    No *aux = l->fim->prox, *aux2 = NULL;
    int pos = 0;

    while (aux != l->fim && pos != n)
    {
        pos++;
        aux2 = aux;
        aux = aux->prox;
    }

    if (pos == n)
    {
        aux2->prox = aux->prox;
        free(aux);
    }

    return 0;
}

int removerMeio (Lista *l)
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) return 2;

    No *aux = l->fim->prox;
    int tam = 0;

    while (aux != l->fim)
    {
        tam++;
        aux = aux->prox;
    }

    tam = tam/2;
    removerPosi(l, tam);
    /*if (tam%2 == 0)
    {
        tam = tam/2;
        removerPosi(l, tam);
    }
    else
    {
        tam++;
        tam = tam/2;
        removerPosi(l, tam);
    }*/

    return 0;
}

int removerItemUnico (Lista *l, int item) // TEM PROBLEMA AQ
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) return 2;
    
    No *aux = l->fim, *aux2 = NULL;

    if (l->fim->valor.mat == item)
    {
        removerFim(l);
        return 0;
    }

    while (aux->prox != l->fim)
    {
        aux2 = aux;
        aux = aux->prox;
        if (aux->valor.mat == item)
        {
            aux2->prox = aux->prox;
            free(aux);
            return 0;
        }
        
    }
    return 1;
}

int interseccao (Lista *l1, Lista *l2, Lista *l3)
{
    if (l1 == NULL) return 3;
    if (l2 == NULL) return 3;
    if (l3 == NULL) 
    {
        l3 = criar();
        if (l3 == NULL) return 3;
    }

    No *auxL1 = l1->fim->prox;
    No *auxL2 = l2->fim->prox;

    do
    {
        do
        {
            if (auxL1->valor.mat == auxL2->valor.mat)
            {
                inserirFim(l3, auxL1->valor);
            }
            auxL2 = auxL2->prox;
        }while (auxL2 != l2->fim->prox);
        auxL2 = l2->fim->prox;
        auxL1 = auxL1->prox;
    }while (auxL1 != l1->fim->prox);

    return 0;
}

int inserirFimSemRepetir (Lista *l, Aluno it) 
{ 
    if (l == NULL) return 2;

    int quant = 1; 

    quant = contaElementos(l, it.mat);

    if (quant == 0) 
    { 
        inserirFim(l, it); 
        return 0; 
    } 
    else 
    { 
        return 3; 
    }
} 

int removerItem (Lista *l, int item)
{
    if (l == NULL) return 3;
    int i = 0, pos = 0; 
    i = contaElementos(l, item);

    if (i != 0)
    {
        for (pos = i; pos > 0; pos--)
        {
            removerItemUnico(l, item);
        }
        return 0;
    } else return 2;
}