#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listadupla.h"

int menu1()
{
    int i = -1;
    do
    {
        printf ("\nSelecione uma opcao: \n");
        printf ("1. Cadastrar aluno\n");
        printf ("2. Remover aluno\n");
        printf ("3. Listar alunos cadastrados\n");
        printf ("4. Mostrar dados do aluno c\\ maior nota\n");
        printf ("5. Remover todos os alunos da lista\n");
        printf ("6. Sair\n");
        scanf ("%d", &i);
    }while (i < 1 && i > 6);
    return i;
}

int main ()
{
    int j = -1, matricula = -10; 
    Lista *l1;
    Aluno item;

    l1 = criar();
        
    do 
    {
        j = menu1();

        switch (j)
        {
            case 1:
                printf ("Digite o nome do aluno: \n");
                scanf ("%s", &item.nome);
                printf ("Digite a matricula: \n");
                scanf ("%d", &item.mat);
                printf ("Digite a nota: \n");
                scanf ("%f", &item.n1);
                inserirOrdem(l1, item);
            break;

            case 2:
                printf ("\nDigite a matricula do aluno a ser removido: \n");
                scanf ("%d", &matricula);
                if (removerItem(l1, matricula) == 0) printf ("Aluno removido com sucesso!\n");
                else printf ("Erro ao remover!\n");
            break;

            case 3:
                mostrar(l1);
            break;

            case 4:
                maiorNota(l1, &item);
                printf ("\nO aluno com a maior nota eh %s, matricula %d e nota %.2f.\n", item.nome, item.mat, item.n1);
            break;

            case 5:
                limpar(l1);
                printf ("\nLista limpa! ");
                mostrar(l1);
            break;

            case 6:
                printf ("\nSaindo...\n");
            break;
        }

    }while(j != 6);
    return 0;
}