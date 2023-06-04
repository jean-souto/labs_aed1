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

Fila *criarFila ();
void limparFila (Fila *f);
int consultarFila (Fila *f, int *it);
int tamanhoFila (Fila *f);
int filaVazia (Fila *f);
int filaCheia (Fila *f);
int inserirFila (Fila *f, int it);
int removerFila (Fila *f);
void mostrarFila (Fila *f);