typedef struct aluno
{ 
    int mat;
    char nome[30];
    float n1;
}Aluno;

typedef struct no
{
    Aluno valor;
    struct no *prox, *ant;
}No;

typedef struct lista
{ 
    No *inicio;
}Lista;

Lista *criar ();
int listaVazia (Lista *l);
int tamanho (Lista *l);
int removerInicio (Lista *l);
int removerFim (Lista *l);
int removerPosi (Lista *l, int pos);
int inserirInicio (Lista *l, Aluno item);
int limpar (Lista *l);
void mostrar (Lista*l);
int maiorNota (Lista *l, Aluno *item);
int inserirFim (Lista *l, Aluno item);
int inserirPosicao (Lista *l, Aluno item, int pos);
int inserirOrdem (Lista *l, Aluno item);
int trocarItens (Lista *l, int a, int b);
int contemItem (Lista *l, int item);
int contemItem (Lista *l, int item);
int excluiRepet (Lista *l);
int removerItem (Lista *l, int item);
