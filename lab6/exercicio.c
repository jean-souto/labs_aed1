#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main ()
{
    Lista *escola;
    Aluno parametro;
    int quant = 0;

    escola = criar();
    parametro.mat = 123;
    parametro.n1 = 2.5;
    setbuf(stdin,NULL);
    scanf("%s", &parametro.nome);

    inserirInicio(escola, parametro);

    parametro.mat = 456;
    parametro.n1 = 4.5;
    setbuf(stdin,NULL);
    scanf("%s", &parametro.nome);

    inserirInicio(escola, parametro);

    parametro.mat = 789;
    parametro.n1 = 6.5;
    setbuf(stdin,NULL);
    scanf("%s", &parametro.nome);

    inserirInicio(escola, parametro);

    printf ("Inicializando a lista: \n");

    mostrar(escola);

    printf ("\nInserindo no inicio: \n");

    parametro.mat = 110;
    parametro.n1 = 7;
    setbuf(stdin,NULL);
    scanf("%s", &parametro.nome);

    inserirInicio(escola, parametro);

    mostrar(escola);

    printf ("\nInserindo no fim: \n");

    parametro.mat = 663;
    parametro.n1 = 4;
    setbuf(stdin,NULL);
    scanf("%s", &parametro.nome);

    inserirFim(escola, parametro);

    mostrar(escola);

    printf ("\nInserindo em posicao: \n");

    parametro.mat = 852;
    parametro.n1 = 3;
    setbuf(stdin,NULL);
    scanf("%s", &parametro.nome);

    inserirPosicao(escola, parametro, 2);

    mostrar(escola);

    printf ("\nremovendo inicio: \n");

    removerInicio(escola);

    mostrar(escola);

    printf ("\nremovendo fim: \n");

    removerFim(escola);

    mostrar(escola);

    printf ("\nremovendo posicao: \n");

    removerPosicao(escola, 1);

    mostrar(escola);

    printf ("\nremovendo item: \n");

    removerItem(escola, 456);

    mostrar(escola);

    return 0;
}