#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

Lista *criar()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l != NULL) l->total = 0;
    return l;
}

void limpar(Lista *l) 
{
    if (l != NULL) l->total = 0;
}

int listaCheia(Lista *l) 
{
    if (l == NULL) return 2;

    if (l->total == MAX) return 0;
    else return 1;
}

int listaVazia(Lista *l) 
{
    if (l == NULL) return 2;

    if (l->total == 0) return 0;
    else return 1;
}

int inserirInicio(Lista *l, Aluno it)
{
    int i;

    if (l == NULL) return 2;

    if (listaCheia(l) == 0) return 1;

    for (i=l->total;i>0;i--) 
    {
        l->valores[i] = l->valores[i-1];
    }

    l->valores[0] = it;
    l->total++;

    return 0;
}

int inserirFim(Lista *l, Aluno it) 
{
    if (l == NULL) return 2;

    if (listaCheia(l) == 0) return 1;
    
    l->valores[l->total] = it;
    l->total++;

    return 0;
}

int removerInicio(Lista *l) 
{
    int i;

    if (l == NULL) return 2;
    
    if (listaVazia(l) == 0) return 1;
    
    for (i=0;i<l->total-1;i++)
    {
        l->valores[i] = l->valores[i+1];
    }
    l->total--;

    return 0;
}

int removerFim(Lista *l) 
{
    if (l == NULL) return 2;

    if (listaVazia(l) == 0) return 1;
    {
        l->total--;
    }

    return 0;
}

int buscarItemChave(Lista *l, int chave,Aluno *retorno) 
{
    int i;

    if (l == NULL) return 2;

    if (listaVazia(l) == 0) return 1;
    
    for (i=0;i<l->total;i++)
    {
        if (l->valores[i].mat == chave)
        {   
            *retorno = l->valores[i];
            return 0;
        }
    }   
    return -1;
}

void mostrar(Lista *l) 
{
    int i;

    if (l != NULL) 
    {
        printf("[");
        
        for (i=0;i<l->total;i++) 
        {
            printf(" {%d, ",l->valores[i].mat);
            printf("%s, ",l->valores[i].nome);
            printf("%.2f} ",l->valores[i].n1);
        }
        printf("]\n");
    }
}

int inserirPosicao (Lista *l, Aluno it, int pos)
{
    int i;

    if (l == NULL) return 2;

    if (listaCheia(l) == 0) return 1;

    for (i = l->total; i >= pos; i--)
    {
        l->valores[i+1] = l->valores[i];
    }

    l->valores[pos] = it;
    l->total++;

    return 0;
}

int removerPosicao (Lista *l, int pos)
{
    int i;

    if (l == NULL) return 2;

    if (listaVazia(l) == 0) return 1;

    for (i = pos; i < l->total-1; i++)
    {
        l->valores[i] = l->valores[i+1];
    }

    l->total--;

    return 0;
}

int removerItem (Lista *l, int mat)
{
    int pos, i;

    if (l == NULL) return 2;

    if (listaVazia(l) == 0) return 1;

    for (i = 0; i < l->total; i++)
    {
        if (l->valores[i].mat == mat)
        {
            pos = i;
        }
    }

    for (i = pos; i < l->total-1; i++)
    {
        l->valores[i] = l->valores[i+1];
    }

    l->total--;


    return 0;
}

int buscarPosicao (Lista *l, int posicao, Aluno *it)
{
    if (l == NULL) return 2;

    if (listaVazia(l) == 0) return 1;

    *it = l->valores[posicao];

    return 0; 
}

int contemItem (Lista *l, Aluno it)
{
    int i, find = -1;

    if (l == NULL) return 2;

    if (listaVazia(l) == 0) return 3;
    
    for (i = 0; i < l->total; i++) 
    {
        if (l->valores[i].mat == it.mat)
        {
            find = 0;
        }
    }

    if (find == 0)
    {
        return 0;
    } else return 1;
}

void inverteLista (Lista *l)
{
    int i, j = 0;
    Aluno temp;

    for (i = l->total-1; i > l->total/2; i--)
    {
        temp = l->valores[i];
        l->valores[i] = l->valores[j];
        l->valores[j] = temp;
        j++;
    }
}

int contarItem (Lista *l, Aluno it, int *quantidade)
{
    int i, quant = 0;

    if (l == NULL) return 2;

    if (listaVazia(l) == 0) return 3;
    
    for (i = 0; i < l->total; i++) 
    {
        if (l->valores[i].mat == it.mat)
        {
            quant++;
        }
    }
    *quantidade = quant;
    return 0;
}

