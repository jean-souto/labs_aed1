#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

int main(){

    int tam[2], option = -1, editar = 10, nun, i;
    conjuntos conjs[5];
    
    printf ("Digite o tamanho do primeiro conjunto: ");
    scanf ("%d", &tam[0]);

    printf ("Digite os membros do primeiro conjunto: ");
    conjs[0] = criar(tam[0]);
    
    printf ("Digite o tamanho do segundo conjunto: ");
    scanf ("%d", &tam[1]);

    printf ("\nDigite os membros do segundo conjunto: ");
    conjs[1] = criar(tam[1]);

    do {
        do {
            printf ("\nDigite a opcao desejada: \n1. Inserir membro\n2. Remover membro\n3. Uniao de A e B\n4. Interseccao de A e B\n5. Diferenca de A e B\n6. Mostrar membros\n0. Sair\n");
            scanf ("%d", &option);
        } while (option < 0 || option > 6);

        switch (option)
        {
            case 1: 
                printf ("\nDigite qual conjunto será editado (0[A] ou 1[B]): ");
                scanf ("%d", &editar);
                printf ("\nDigite o numero a ser acrescentado: ");
                scanf("%d", &nun);

                inserir (&conjs[editar], nun);
                break;

            case 2:
                printf ("\nDigite qual conjunto será editado (0[A] ou 1[B]): ");
                scanf ("%d", &editar);
                printf ("\nDigite a coordenada do numero a ser removido: ");
                scanf("%d", &nun);

                remover (&conjs[editar], nun);
                break;

            case 3: 
                conjs[2] = uniao(&conjs[0], &conjs[1]);
                printf ("\nA uniao dos dois conjuntos eh: ");
                membros(&conjs[2]);
                break;

            case 4:
                conjs[3] = interseccao(&conjs[0], &conjs[1]);
                printf ("\nA interseccao dos dois conjuntos eh: ");
                membros(&conjs[3]);
                break;

            case 5:
                conjs[4] = diferenca(&conjs[0], &conjs[1]);
                printf ("\nA diferenca dos dois conjuntos eh: ");
                membros(&conjs[4]);
                break;

            case 6: 
                printf ("\nDigite qual conjunto sera mostrado (0[A], 1[B] e assim por diante caso tenha sido criado outro conjunto): ");
                scanf ("%d", &editar);
                membros (&conjs[editar]);
                break;

            case 0:
                printf ("\nObrigado!");
                for (i = 0; i < 5; i++)
                {
                    free (conjs[i].conj);
                }
                break;
        }   
    } while (option != 0);

    return 0;
}