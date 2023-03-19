/*a)Faça um programa que receba o ano de nascimento de uma pessoa e o ano atual, calcule e mostre a idade desta pessoa, e quantos anos essa pessoa terá em 2030.*/
#include <stdio.h>

int main ()
{
    int anoatual, anonasc;

    printf ("\nDigite seu ano de nascimento: ");
    scanf ("%d", &anonasc);
    printf ("\nDigite o ano atual: ");
    scanf ("%d", &anoatual);

    printf ("\nVoce possui %d anos e tera %d anos em 2030.", (anoatual-anonasc), ((anoatual-anonasc)+(2030-anoatual)));

    return 0;
}