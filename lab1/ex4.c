#include<stdio.h>

int main ()
{
    int n;
    
    printf ("Entre com o valor: ");
    scanf("%d",&n);

    int i, acc = n;
    
    for(i=n-1; i>0; i--)
    {
        acc=acc*i;
    }

    printf("O valor do fatorial de %d eh %d.", n, acc);
    
    return 0;
}