#define MAX 100

typedef struct aluno{
    char nome[30];
    int mat;
    float n1;
}Aluno;

typedef struct lista 
{
    int total;
    Aluno valores[MAX];
}Lista;

Lista *criar();
void limpar(Lista *l);
int listaCheia(Lista *l);
int listaVazia(Lista *l);
int inserirInicio(Lista *l, Aluno it);
int inserirFim(Lista *l, Aluno it);  
int removerInicio(Lista *l); 
int removerFim(Lista *l); 
int buscarItemChave(Lista *l, int chave,Aluno *retorno);
void mostrar(Lista *l);
int inserirPosicao (Lista*l, Aluno it, int pos);
int removerPosicao (Lista *l, int pos);
int contemItem(Lista * l, int Item);
int removerItem(Lista *l, int mat);
int buscarPosicao(Lista *l, int posicao, Aluno *it);
int contemItem (Lista *l, Aluno it);
void inverteLista (Lista *l);
int contarItem (Lista *l, Aluno it, int *quantidade);