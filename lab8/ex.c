#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listacircular.h"

int main ()
{
    Lista *l1, *l2, *l3, *notasmaior, *notasmenor;
    int i;
    Aluno item;

    l1 = criar();

    printf ("Inicializando lista (inserindo inicio): \n");

    item.mat = 123;
    item.n1 = 2.5;
    strcpy (item.nome, "Alan");
    inserirInicio (l1, item);

    item.mat = 156;
    item.n1 = 8.5;
    strcpy (item.nome, "Ana");
    inserirInicio (l1, item);

    item.mat = 889;
    item.n1 = 9.5;
    strcpy (item.nome, "Maria");
    inserirInicio (l1, item);

    item.mat = 456;
    item.n1 = 7.5;
    strcpy (item.nome, "Caio");
    inserirInicio (l1, item);

    mostrar (l1);

    system("pause");

    printf ("\nInserindo no final: \n");

    item.mat = 789;
    item.n1 = 3.5;
    strcpy (item.nome, "Joao");
    inserirFim (l1, item);

    item.mat = 753;
    item.n1 = 4;
    strcpy (item.nome, "Tiago");
    inserirFim (l1, item);

    printf ("\nO tamanho da lista eh %d\n", tamanho(l1));

    mostrar (l1);

    system("pause");

    notasmaior = criar();
    notasmenor = criar();
    
    printf ("\nFiltrando notas maiores e menores que 5: \n");
    filtro (l1, notasmaior, notasmenor, 5);
    printf ("\nMaiores: "); mostrar (notasmaior); 
    printf ("\nMenores: "); mostrar (notasmenor);

    system("pause");

    printf ("\nRemovendo inicio: \n");
    removerInicio (l1);
    mostrar (l1);

    printf ("\nRemovendo fim: \n");
    removerFim(l1);
    mostrar(l1);

    system("pause");

    printf ("\nBuscando item 123: \n");
    if ((buscarItem (l1, 123, &item)) == 0) 
    {   
        printf ("Item encontrado: ");
        printf ("{%d, %s, %.2f}\n", item.mat, item.nome, item.n1);
    } 
    else
    {
        printf ("\nItem nao encontrado!\n");
    }

    printf ("\nBuscando item 000: \n");
    if ((buscarItem (l1, 000, &item)) == 0) 
    {   
        printf ("\nItem encontrado: ");
        printf ("{%d, %s, %.2f}\n", item.mat, item.nome, item.n1);
    } 
    else
    {
        printf ("Item nao encontrado!\n");
    }

    printf ("\nExistem %d elementos com a matricula 789!\n", contaElementos(l1, 789));

    system("pause");

    printf ("\nRemovendo posicao 2:\n");
    mostrar(l1);
    removerPosi(l1, 1);
    mostrar(l1);

    printf ("\nRemovendo meio:\n");
    removerMeio(l1);
    mostrar(l1);

    system("pause");

    printf ("\n**Realizando insercoes na lista 1 para testar outros recursos**\n");

    item.mat = 666;
    item.n1 = 6.5;
    strcpy (item.nome, "Joao");
    inserirFim (l1, item);

    item.mat = 413;
    item.n1 = 6.2;
    strcpy (item.nome, "Ryan");
    inserirFim (l1, item);

    item.mat = 037;
    item.n1 = 8.9;
    strcpy (item.nome, "Arthur");
    inserirFim (l1, item);

    item.mat = 951;
    item.n1 = 1.5;
    strcpy (item.nome, "Ester");
    inserirFim (l1, item);

    item.mat = 423;
    item.n1 = 3.5;
    strcpy (item.nome, "Fernanda");
    inserirFim (l1, item);
    mostrar(l1);

    printf ("\nUsando funcao de remover item unico para remover duplicacao: \n");
    removerItemUnico (l1, 789);
    mostrar(l1);

    system("pause");

    l2 = criar();
    l3 = criar();

    printf ("\nInicializando lista 2:\n");

    item.mat = 037;
    item.n1 = 8.9;
    strcpy (item.nome, "Arthur");
    inserirFim (l2, item);

    item.mat = 951;
    item.n1 = 1.5;
    strcpy (item.nome, "Ester");
    inserirFim (l2, item);

    item.mat = 423;
    item.n1 = 3.5;
    strcpy (item.nome, "Fernanda");
    inserirFim (l2, item);

    item.mat = 999;
    item.n1 = 10;
    strcpy (item.nome, "Tiago");
    inserirFim (l2, item);
    mostrar(l2);

    system ("pause");

    printf ("\nInterseccao de 1 e 2: \n");
    interseccao (l1, l2, l3);
    mostrar(l3);

    system("pause");

    printf ("\nInserir fim sem repetir: \n");

    item.mat = 624;
    item.n1 = 1;
    strcpy (item.nome, "Fernando");
    if ((inserirFimSemRepetir (l2, item)) != 0) { printf ("ERRO!\n"); } else { printf ("Sucesso!\n");}
    mostrar(l2);

    item.mat = 999;
    item.n1 = 10;
    strcpy (item.nome, "Tiago");
    if ((inserirFimSemRepetir (l2, item)) != 0) { printf ("ERRO!\n"); } else { printf ("Sucesso!\n");}
    mostrar(l2);

    system("pause");

    printf ("\nInserindo e retirando os Arthurs da lista 1: \n");
    item.mat = 037;
    item.n1 = 8.9;
    strcpy (item.nome, "Arthur");
    inserirFim (l1, item);
    mostrar(l1);
    removerItem(l1, 037);
    mostrar(l1);

    printf ("\nLimpando lista 1: \n");
    limpar(l1);
    mostrar(l1);

    printf ("\nFim!!!\n");

    free(l1);
    free(l2);
    free(l3);
    free(notasmaior);
    free(notasmenor);

    return 0;
}