#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

int main ()
{
    int n = 0, tam = 0, quantx = 0; 
    TAD_string string;
    char c;
    
    printf ("Digite o tamanho: ");
    scanf ("%d", &n);

    string = criar(n);

    printf ("Digite sua string: \n");

    setbuf(stdin,NULL);
    ler (string);

    tam = tamanho(string);

    printf ("Digite o caractere para buscar: ");
    setbuf(stdin,NULL);
    scanf("%c", &c);

    quantx = contarx(string, c);

    printf ("A string tem tamanho %d e contem %d caracteres '%c'\n", tam, quantx, c);

    printar(string);

    free(string);
    
    return 0;
}