#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nome[50];
    char cpf[12];
    char estd_civil[15];
    int quant_filhos;
    char **filhos;
}clientes;

int cadastro (int *quant_clientes, clientes *clients)
{
    char son;
    int i;
    clientes *temp;

        ++(*quant_clientes);

        temp = realloc (clients, (*quant_clientes)*sizeof(clientes));

        if (temp != NULL)
        {
            clients = temp;
        }

        printf ("Digite o nome do cliente: ");
        setbuf(stdin,NULL);
        scanf ("%s", clients[(*quant_clientes)-1].nome);

        printf ("Digite o CPF (somente numeros): ");
        setbuf(stdin,NULL);
        scanf ("%s", clients[(*quant_clientes)-1].cpf);

        printf ("Digite o estado civil: ");
        setbuf(stdin,NULL);
        scanf ("%s", clients[(*quant_clientes)-1].estd_civil);

        clients[(*quant_clientes)-1].quant_filhos = 0;

        printf ("O cliente tem filhos (s ou n)? ");
        scanf(" %c", &son);

        if (son == 's')
        {
            printf ("Quantos filhos? ");
            scanf ("%d", &clients[(*quant_clientes)-1].quant_filhos);

            clients[(*quant_clientes)-1].filhos = (char**) malloc (clients[(*quant_clientes)-1].quant_filhos*sizeof(char*));
            for (i = 0; i < clients[(*quant_clientes)-1].quant_filhos; i++)
            {
                clients[(*quant_clientes)-1].filhos[i] = (char*) malloc (50*sizeof(char));
                printf ("Digite o nome do filho %d: ", i);
                setbuf(stdin,NULL);
                scanf ("%s", clients[(*quant_clientes)-1].filhos[i]);
            }
        }

    return 0;
}

int main ()
{
    int i, j, quant_clientes = 0, option = 10, confirm = 10;
    clientes *clients = NULL, *temp = NULL;
    char son, excluir[12];

    clients = (clientes *) calloc (quant_clientes, sizeof(clientes));

    if (clients == NULL)
    {
        return 1;
    }

    while (option != 0)
    {
        do
        {
            printf ("\nSelecione uma opcao: 1) Inserir cliente 2) Remover cliente 3) Mostrar todos os CPFs 0) Sair");
            scanf ("%d", &option);

            if (option < 0 || option > 3)
            {
                printf ("Opcao invalida!");
            }
        } while (option < 0 || option > 3);

        if (option == 1)
        {
            confirm = cadastro(&quant_clientes, &clients);
            if (confirm == 0)
            {
                printf ("\nCliente registrado com sucesso!");
            }
        }
        if (option == 2) 
        {
            printf ("Digite o CPF do cliente a ser excluido: ");
            setbuf(stdin, NULL);
            scanf("%s", excluir);

            for (i = 0; i < quant_clientes; i++)
            {
                if (strcmp(clients[i].cpf, excluir) == 0)
                {
                    if (clients[i].quant_filhos != 0)
                    {
                        for (j = 0; j < clients[i].quant_filhos; j++)
                        {
                            free(clients[i].filhos[j]);
                        }
                        free(clients[i].filhos);
                    }
                    for (j = i; j < quant_clientes; j++)
                    {
                        clients[j] = clients[j+1];
                    }
                    
                    --quant_clientes;

                    temp = realloc (clients, quant_clientes*sizeof(clientes));
                    
                    if (temp != NULL)
                    {
                        clients = temp;
                        printf ("\nCliente excluido com sucesso.");
                    } else printf ("O processo nao pode ser concluido com exito.");
                }
            }
        }
        if (option == 3)
        {
            for (i = 0; i < quant_clientes; i++)
            {
                printf ("\nCLIENTE %d:\n\nNome: %sCPF: %sEstado civil: %s", i, clients[i].nome, clients[i].cpf, clients[i].estd_civil);
                
                if (clients[i].quant_filhos != 0)
                {
                    printf ("\nO cliente possui %d filhos: ", clients[i].quant_filhos);
                    for (j = 0; j < clients[i].quant_filhos; j++)
                    {
                        printf ("\n %s", clients[i].filhos[j]);
                    }
                }
                printf ("\n\n");
            }
        }
        if (option == 0)
        {
            printf ("\nDeseja sair s ou n(todos os dados serao perdidos)?");
            scanf (" %c", &son);

            if (son == 'n')
            {
                option = 10;
            }
            else
            {
                printf ("\nObrigado!");

                for (i = 0; i < quant_clientes; i++)
                {
                    if (clients[i].quant_filhos != 0)
                    {
                        for (j = 0; j < clients[i].quant_filhos; j++)
                        {
                            free(clients[i].filhos[j]);
                        }
                        free(clients[i].filhos);
                    }
                }
                free (clients);
            } 
        }
    }

    return 0;
}