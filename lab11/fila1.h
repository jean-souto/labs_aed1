typedef struct no
{
    int valor;
    struct no *proximo;
}No;

typedef struct fila
{ 
    No *inicio, *fim;
    int qtd;
}Fila;

Fila *criar ();
void limpar (Fila *f);
int consultar (Fila *f, int *it);
int tamanho (Fila *f);
int filaVazia (Fila *f);
int filaCheia (Fila *f);
int inserir (Fila *f, int it);
int remover (Fila *f);
void mostrar (Fila *f);