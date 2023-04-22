//ESTE É UM CÓDIGO FEITO COM O OBJETIVO DE TESTAR TODAS AS FUNÇÕES DA BIBLIOTECA E NÃO POSSUI FINS DE INTERAÇÃO.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

int main ()
{
    Lista *alunos, *alunos2, *concatena;
    Aluno parametro;
    int i;

    printf ("\nInicializando lista: \n");

    alunos = criar();

    parametro.mat = 123;
    parametro.n1 = 2;
    strcpy(parametro.nome,"Hannah");
    inserirInicio(alunos, parametro);

    parametro.mat = 987;
    parametro.n1 = 3;
    strcpy(parametro.nome,"Fernando");
    inserirInicio(alunos, parametro);

    parametro.mat = 456;
    parametro.n1 = 5;
    strcpy(parametro.nome,"Carla");
    inserirInicio(alunos, parametro);

    parametro.mat = 789;
    parametro.n1 = 7.5;
    strcpy(parametro.nome,"Luiza");
    inserirInicio(alunos, parametro);
    mostrar(alunos);

    printf ("\nInserindo fim: \n");

    parametro.mat = 951;
    parametro.n1 = 8;
    strcpy(parametro.nome,"Paulo");
    inserirFim(alunos, parametro);
    mostrar(alunos);

    printf ("\nInserindo posicao: \n");

    parametro.mat = 753;
    parametro.n1 = 8.2;
    strcpy(parametro.nome,"Jean");
    inserirPosicao(alunos, parametro, 1);
    mostrar(alunos);

    printf ("\nRemovendo inicio: \n");

    removerInicio(alunos);
    mostrar(alunos);

    printf ("\nRemovendo fim: \n");

    removerFim(alunos);
    mostrar(alunos);

    printf ("\nRemovendo posicao: \n");

    removerPosicao(alunos, 1);
    mostrar(alunos);

    printf ("\nRemovendo item 987: \n");

    removerItem(alunos, 987);
    mostrar(alunos);

    printf ("\nContem item 123: \n");
    i = contemItem(alunos, 123);
    if (i != 0) { printf ("Item nao encontrado!"); } else { printf ("Item encontrado!"); }

    printf ("\nContem item 234: \n");
    i = contemItem(alunos, 234);
    if (i != 0) { printf ("Item nao encontrado!"); } else { printf ("Item encontrado!"); }
    
    printf ("\n\nBuscando item pos 0: \n");
    buscarPosicao(alunos, 0, &parametro);
    printf ("{%d, %s, %.2f}\n", parametro.mat, parametro.nome, parametro.n1); 

    printf ("\nInicializando lista 2:\n");

    alunos2 = criar();

    parametro.mat = 777;
    parametro.n1 = 9;
    strcpy(parametro.nome,"Alan");
    inserirInicio(alunos2, parametro);

    parametro.mat = 666;
    parametro.n1 = 1;
    strcpy(parametro.nome,"Nila");
    inserirInicio(alunos2, parametro);

    parametro.mat = 444;
    parametro.n1 = 11.3;
    strcpy(parametro.nome,"Tiago");
    inserirInicio(alunos2, parametro);
    mostrar (alunos2);

    concatena = criar();
    concatenar(alunos, alunos2, concatena);
    
    printf ("\nLista um: \n");
    mostrar (alunos);
    printf ("\nLista dois: \n");
    mostrar (alunos2);
    printf ("\nConcatenacao:\n");
    mostrar (concatena);

    printf ("\nO tamanho da lista um eh %d, da lista dois eh %d e da lista tres eh %d.\n", tamanho(alunos), tamanho(alunos2), tamanho(concatena));

    printf ("\nA maior nota: \n");
    maiorNota(concatena, &parametro);
    printf ("{%d, %s, %.2f}\n", parametro.mat, parametro.nome, parametro.n1);

    printf ("\nRemovendo primeiros 2:\n");
    removerN(concatena, 2);
    mostrar(concatena);

    printf ("\nLimpando lista 1:\n");
    limpar(alunos);
    mostrar (alunos);

    free(alunos);
    free(alunos2);
    free(concatena);

    return 0;
}