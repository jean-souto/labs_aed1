#include <stdio.h>
#include <math.h>

void calculaHexagono (float lado, float *area, float *perimetro)
{
    *perimetro = 6*lado;
    *area = 3*((pow(lado,2)*sqrt(3))/2);
}

int main ()
{
    float lado, area, perimetro;

    printf ("Digite o valor do lado do hexagono: ");
    scanf ("%f", &lado);

    calculaHexagono (lado, &area, &perimetro);

    printf ("O perimetro eh %.2f um e a area %.2f ua.", perimetro, area);

    return 0;
}