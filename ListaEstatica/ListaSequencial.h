#define MAX 10

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct ListaSequencial Lista;

Lista* cria_lista();
Lista* libera_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
int inserir_lista_final(Lista *li, struct aluno al);
int inserir_lista_inicio(Lista *li, struct aluno al);
int inserir_lista_ordenada(Lista *li, struct aluno al);
int remover_lista_final(Lista *li);
int remover_lista_inicio(Lista *li);
int remover_lista(Lista *li, int matricula);
int consulta_lista_pos(Lista *li, int pos , struct aluno *al);
int consulta_lista_mat(Lista *li, int mat , struct aluno *al);
int imprimir_lista(Lista *li);
