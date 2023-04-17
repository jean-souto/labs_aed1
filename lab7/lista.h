typedef struct aluno
{ 
    int mat;
    char nome[30];
    float n1;
}Aluno;

typedef struct no
{
    Aluno valor;
    struct no *prox;
}No;

typedef struct lista
{ 
    No *inicio;
}Lista;

//auxiliares
Lista *criar();
void limpar(Lista *l);
void mostrar(Lista *l);
int listaVazia (Lista*l);

//insercao
int inserirInicio (Lista *l, Aluno it);
int inserirFim (Lista *l, Aluno it);
int inserirPosicao (Lista *l, Aluno it, int pos);

//remocao
int removerInicio (Lista*l);
int removerFim(Lista *l);
int removerPosicao (Lista *l, int pos);
int removerItem (Lista *l, int item);
int removerN (Lista *l, int n);

//busca
int buscarItemChave(Lista *l, int chave, Aluno *retorno);
int buscarPosicao (Lista *l, int Item, Aluno *retorno);

//outros
int contemItem (Lista *l, int Item);
int concatenar (Lista *l1, Lista *l2, Lista *l3);
int maiorNota (Lista *l, Aluno *retorno);