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
    No *fim;
}Lista;

Lista *criar ();
void limpar (Lista*l);
void mostrar (Lista*l);

int listaVazia(Lista*l);
int listaCheia(Lista*l);

int inserirInicio (Lista *l, Aluno it);
int inserirFim (Lista *l, Aluno it);
int inserirFimSemRepetir (Lista *l, Aluno it);

int removerInicio (Lista *l);
int removerFim (Lista *l);
int removerPosi (Lista *l, int n);
int removerMeio (Lista *l);
int removerItemUnico (Lista *l, int item);
int removerItem (Lista *l, int item);

int buscarItem (Lista *l, int chave, Aluno *it);
int contaElementos (Lista *l, int item);
int tamanho (Lista *l);

int filtro (Lista *l1, Lista *l2, Lista *l3, float nota);
// int produto (Lista *l1, Lista *l2, Lista *l3);
int interseccao (Lista *l1, Lista *l2, Lista *l3);