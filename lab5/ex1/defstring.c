#include "ex1.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

TAD_string criar (int n)
{
    char *str = NULL;
    str = (char*) calloc (n,sizeof(char));
    return str;
}

void ler (TAD_string str)
{
    scanf (" %s", str);
}

int tamanho (TAD_string str)
{
    int n;
    n = strlen(str);
    return n;
}

int contarx (TAD_string str, char x)
{
    int i, quant = 0, tam = 0;
    tam = strlen(str);
    for (i = 0; i < tam; i++)
    {
        if (str[i] == x)
        {
            quant++;
        }
    }
    return quant;
}

void printar (TAD_string str)
{
    printf ("%s", str);
} 