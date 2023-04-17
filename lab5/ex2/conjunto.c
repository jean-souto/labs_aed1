#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>

conjuntos criar (int n)
{
    conjuntos conj1;
    int i;
    conj1.tam = n;
    conj1.conj = (int*) malloc (n*sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf ("%d", &conj1.conj[i]);
    }
    return conj1;
}

void membros (conjuntos *conj1)
{
    int i, n;
    n = conj1->tam;
    for (i = 0; i < n; i++)
    {
        printf ("%d ", conj1->conj[i]);
    }
}

void inserir (conjuntos *conj1, int nun)
{
    conjuntos temp;
    int n;
    conj1->tam++;
    n = conj1->tam;
    temp.conj = (int*) realloc (conj1->conj, n*sizeof(int));
    if (temp.conj != NULL) {conj1->conj = temp.conj;}
    conj1->conj[n-1] = nun;
}

void remover (conjuntos *conj1, int nun)
{
    conjuntos temp;
    int n, i;
    n = conj1->tam;
    for (i = nun; i < n-1; i++)
    {
        conj1->conj[i] = conj1->conj[i+1];
    }
    conj1->tam--;
    temp.conj = (int*) realloc (conj1->conj, n*sizeof(int));
    if (temp.conj != NULL) {conj1->conj = temp.conj;}
}

conjuntos uniao (conjuntos *conjA, conjuntos *conjB)
{
    int n, i, j, k;
    conjuntos conjU, temp;
    n = conjA->tam+conjB->tam;
    conjU.conj = (int*) malloc (n*sizeof(int));
    for (i=0; i < conjA->tam; i++)
    {
        conjU.conj[i] = conjA->conj[i];
    }
    for (i=conjA->tam; i < n; i++)
    {
        conjU.conj[i] = conjB->conj[i-conjA->tam];
    }

    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (conjU.conj[i] == conjU.conj[j])
            {
                for (k = j; k < n-1; k++)
                {
                    conjU.conj[k] = conjU.conj[k+1];
                }
                n--; 
                temp.conj = (int*) realloc (conjU.conj, n*sizeof(int));
                if (temp.conj != NULL) {conjU.conj = temp.conj;}
            }
        }
    }
    conjU.tam = n;
    return conjU;
}

conjuntos interseccao (conjuntos *conjA, conjuntos *conjB)
{
    int i, j, cont = 0; 
    conjuntos conjI, temp;

    conjI.conj = (int*) malloc (cont*sizeof(int));

    for (i = 0; i < conjA->tam; i++)
    {
        for (j = 0; j < conjB->tam; j++)
        {
            if (conjA->conj[i] = conjB->conj[j])
            {
                cont++;
                temp.conj = (int*) realloc (conjI.conj, cont*sizeof(int));
                conjI.conj[cont-1] = conjA->conj[i];
            }
        }
    }
    conjI.tam = cont;
    return conjI;
}

conjuntos diferenca (conjuntos *conjA, conjuntos *conjB)
{
    int i, j, cont = 0, quant = 0;
    conjuntos conjD, temp;

    conjD.conj = (int*) malloc (cont*sizeof(int));

    for (i = 0; i < conjA->tam; i++)
    {
        for (j = 0; j < conjB->tam; j++)
        {
            if (conjA->conj[i] = conjB->conj[j])
            {
                cont++;
            }
        }

        if (cont == 0)
        {
            quant++;
            temp.conj = (int*) realloc (conjD.conj, quant*sizeof(int));
            conjD.conj[quant-1] = conjA->conj[i];
        }
        else
        {
            cont = 0;
        }
    }
    conjD.tam = quant;
    return conjD;
}