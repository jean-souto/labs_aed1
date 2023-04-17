typedef struct con conjuntos;

struct con{
    int *conj;
    int tam;
};

conjuntos criar (int n);
void membros (conjuntos *conj1);
void inserir (conjuntos *conj1, int nun);
void remover (conjuntos *conj1, int nun);
conjuntos uniao (conjuntos *conjA, conjuntos *conjB);
conjuntos interseccao (conjuntos *conjA, conjuntos *conjB);
conjuntos diferenca (conjuntos *conjA, conjuntos *conjB);