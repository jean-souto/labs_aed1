typedef struct no
{
    int valor;
    struct no *prox, *ant;
}No;

typedef struct no* Lista;

Lista *criar ();
int inserirInicio (Lista *l, int it);
int removerInicio (Lista *l);
void mostrar(Lista *l);
int tamanho (Lista *l);
int listaVazia (Lista *l); 
void limpar(Lista *l);
int inserirFim (Lista *l, int it);
int inserirPosicao (Lista *l, int it, int pos);
int removerFim(Lista *l);
int removerPosicao (Lista *l, int pos);
int removerItem (Lista *l, int item);
int iguais (Lista *l1, Lista *l2);
