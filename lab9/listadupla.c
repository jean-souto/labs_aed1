#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadupla.h"

Lista *criar ()
{
    Lista *l = (Lista*) malloc (sizeof(Lista));
    l->inicio = NULL;
    return l;
}

int listaVazia (Lista *l)
{
    if (l == NULL) return 0;
    if (l->inicio == NULL) return 0; else return 1;
}

int tamanho (Lista *l)
{
    if (l == NULL) return 3;
    if (listaVazia (l) == 0) return 0;

    No *aux = l->inicio;
    int tam = 0;

    while (aux->prox != NULL)
    {
        tam++;
        aux = aux->prox;
    }

    return tam;
}

int removerInicio (Lista *l)
{
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    No *aux = l->inicio;
    l->inicio = l->inicio->prox;
    if (l->inicio != NULL) l->inicio->ant = NULL;
    free(aux);

    return 0;
}

int removerFim (Lista *l)
{
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    No *aux = l->inicio;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    if (aux->ant != NULL) aux->ant->prox = NULL;
    else l->inicio = NULL;
    free(aux);
    return 0;
}

int removerPosi (Lista *l, int pos)
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) return 0;
    if (pos == 0) 
    {
        removerInicio(l); 
        return 0;
    }
    if (pos >= tamanho(l)-1)
    {
        removerFim(l);
        return 0;
    }

    No *aux = l->inicio;

    while (pos > 0)
    {
        aux = aux->prox;
        pos--;
    }
    
    aux->prox->ant = aux->ant;
    aux->ant->prox = aux->prox;
    free(aux);

    return 0;
}

int inserirInicio (Lista *l, Aluno item)
{
    if (l == NULL) return 3;

    No *noaux = (No*) malloc (sizeof(No));
    
    if (listaVazia(l) != 0)
    {
        noaux->valor = item;
        l->inicio->ant = noaux;
        noaux->prox = l->inicio;
        noaux->ant = NULL;
        l->inicio = noaux;
    }
    else
    {
        noaux->valor = item;
        l->inicio = noaux;
        noaux->prox = NULL;
        noaux->ant = NULL;
    }

    return 0;
}

int limpar (Lista *l)
{
    if (l == NULL) return 3;
    if (listaVazia == 0) return 0;
    while (l->inicio != NULL)
    {
        removerFim(l);
    }
    return 0;
}

void mostrar (Lista*l)
{
    if (l != NULL)
    {
        printf ("[");
        
        if (listaVazia(l) != 0)
        {
            No *noLista = l->inicio;
            do
            {
                printf(" {%d, ",noLista->valor.mat);
                printf("%s, ",noLista->valor.nome);
                printf("%.2f} ",noLista->valor.n1);
                noLista = noLista->prox;
            }while(noLista != NULL);
        } printf("]\n");
    }
}

int maiorNota (Lista *l, Aluno *item)
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) return 2;

    No *aux = l->inicio;
    float maior = aux->valor.n1;
    Aluno it;

    while (aux != NULL)
    {
        if (aux->valor.n1 > maior)
        {
            maior = aux->valor.n1;
            it.mat = aux->valor.mat;
            strcpy (it.nome, aux->valor.nome);
        }
        aux = aux->prox;
    }
    item->mat = it.mat;
    item->n1 = maior;
    strcpy (item->nome, it.nome);

    return 0;
}

int inserirFim (Lista *l, Aluno item)
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) 
    {
        inserirInicio(l, item);
        return 0;
    }

    No *aux2 = (No*) malloc (sizeof(No));
    No *aux = l->inicio;

    aux2->valor = item;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }

    aux->prox = aux2;
    aux2->prox = NULL;
    aux2->ant = aux;

    return 0;
}

int inserirPosicao (Lista *l, Aluno item, int pos)
{
    if (l == NULL) return 3;

    No *novo = (No*) malloc (sizeof(No));
    No *aux = l->inicio;
    int i = 0;

    novo->valor = item;

    if (pos == 0) 
    {
        inserirInicio(l, item);
        return 0;
    }
    if (pos > tamanho(l)-1)
    {
        inserirFim(l, item);
        return 0;
    }

    while (i != pos)
    {
        i++;
        aux = aux->prox;
    }

    aux->ant->prox = novo;
    novo->ant = aux->ant;
    novo->prox = aux;
    aux->ant = novo;

    return 0;
}

int inserirOrdem (Lista *l, Aluno item)
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) { inserirInicio(l, item); return 0; }

    No *aux = l->inicio;
    int pos = 0;

    while (aux != NULL)
    {
        if (item.mat >= aux->valor.mat)
        {
            pos++;
        }
        aux=aux->prox;
    }
    inserirPosicao(l, item, pos);
    return 0;
}

int trocarItens (Lista *l, int a, int b)
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) return 2;
    int pos = 0;

    No *item1 = l->inicio;
    No *item2 = l->inicio;
    No *aux;

    while (item1->prox != NULL && pos != a)
    {
        pos++;
        item1 = item1->prox;
    }
    pos = 0;
    while (item2->prox != NULL && pos != b)
    {
        pos++;
        item2 = item2->prox;
    }

    aux = item1;
    aux->prox = item2->prox;
    item2->ant->prox = aux;
    aux->ant = item2->ant;
    item2->prox->ant = aux;

    item2->prox = item1->prox;
    item1->ant->prox = item2;
    item2->ant = item1->ant;
    item1->prox->ant = item2;
    
    return 0;
}

int contemItem (Lista *l, int item)
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) return 2;

    No *aux = l->inicio;

    while (aux->prox != NULL)
    {
        if (aux->valor.mat == item)
        {
            return 0;
        }
        aux = aux->prox;
    }
    return 1;
}

int contaItem (Lista *l, int item)
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) return 2;

    No *aux = l->inicio;
    int contem = 0;

    while (aux->prox != NULL)
    {
        if (aux->valor.mat == item)
        {
            contem++;
        }
        aux = aux->prox;
    }
    return contem;
}

int excluiRepet (Lista *l)
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) return 2;

    No *aux = l->inicio, *aux2; 
    int pos1 = 0, pos2 = 0;

    while (aux->prox != NULL)
    {
        aux2 = aux->prox;
        pos2 = pos1+1;
        while (aux2->prox != NULL)
        {
            if (aux2->valor.mat == aux->valor.mat)
            {
                removerPosi(l, pos2);
            }
            pos2++;
        }
        pos1++;
        aux = aux->prox;
    }
    return 0;

}

int removerItem (Lista *l, int item)
{
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) return 2;

    No *aux = l->inicio;

    while (aux->prox != NULL && aux->valor.mat != item)
    {
        aux = aux->prox;
    }

    if (aux->valor.mat == item)
    {
        if (aux->ant == NULL)
        {
            removerInicio(l);
            return 0;
        }
        if (aux->prox == NULL)
        {
            removerFim(l);
            return 0;
        }
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        free (aux);
        return 0;
    } else return 1;
}