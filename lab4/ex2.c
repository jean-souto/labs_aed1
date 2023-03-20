#include <stdio.h>
#include <stdlib.h>

int substituir (char *str, int n, char c)
{
    int i, quant = 0;
    for (i = 0; i < n; i++)
    {
        if (str[i] == c)
        {
            str[i] = '*';
            quant++;
        }
    }

    return quant;
}

int main ()
{
    char *str, carac;
    int quant, n;

    printf ("Digite o tamanho da string que voce quer: ");
    scanf ("%d", &n);

    str = (char*) calloc (n, sizeof(char));

    printf ("Digite a frase na string; ");
    setbuf (stdin, NULL);
    scanf ("%s", str);

    printf ("Digite o caractere para substituicao: ");
    setbuf (stdin, NULL);
    scanf (" %c", &carac);

    quant = substituir(str, n, carac);

    printf ("Foram feitas %d substituicoes e agora a frase eh: %s.", quant, str);

    free(str);

    return 0;
}