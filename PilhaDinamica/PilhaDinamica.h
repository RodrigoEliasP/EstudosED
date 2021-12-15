
struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
struct elemento {
    struct aluno dados;
    struct elemento* prox;
};
typedef struct elemento* Pilha;
typedef struct elemento Elem;

Pilha* cria_pilha();
void libera_pilha(Pilha *pi);
int tamanho_pilha(Pilha *pi);
int pilha_vazia(Pilha *pi);
int imprime_pilha(Pilha *pi);
int consulta_topo_pilha(Pilha *pi, struct aluno *al);
int insere_pilha(Pilha *pi, struct aluno al);
int remove_pilha(Pilha *pi);
