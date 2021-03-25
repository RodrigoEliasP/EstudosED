#include <stdlib.h>
#include "LDED.h"

struct elemento
{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;
struct descritor{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Lista* cria_lista(){
    Lista *li = malloc(sizeof(Lista));
    if(li){
        li->inicio = NULL;
        li->final = NULL;
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista *li){
    if(li){
        Elem *no;
        while(li->inicio != NULL){
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista *li){
    if(li) return li->qtd;
    return 0;
}

int insere_lista_inicio(Lista *li, struct aluno al){
    if(!li) return 0;
    Elem *no  = (Elem*) malloc(sizeof(Elem));
    if(!no) return 0;
    no->dados = al;
    no->prox = li->inicio;
    if(!li->inicio) li->final = no;
    li->inicio = no;
    li->qtd++;
    return 1;
}
int insere_lista_final(Lista *li, struct aluno al){
    if(!li) return 0;
    Elem *no  = (Elem*) malloc(sizeof(Elem));
    if(!no) return 0;
    no->dados = al;
    no->prox = NULL;
    if(!li->inicio) li->inicio = no;
    else li->final->prox = no;
    li->final = no;
    li->qtd++;
    return 1;
}
int remove_lista_inicio(Lista *li){
    if(!li) return 0;
    if(!li->inicio) return 0;
    Elem *no = li->inicio;
    li->inicio = no->prox;
    free(no);
    if(!li->inicio) li->final = NULL;
    li->qtd--;
    return 1;
}
int remove_lista_final(Lista *li){
    if(!li) return 0;
    if(!li->inicio) return 0;
    Elem *ant, *no = li->inicio;
    while(no->prox){
        ant = no;
        no = no->prox;
    }
    if(no == li->inicio) {
        li->inicio = NULL;
        li->inicio = NULL;
    }else{
        ant->prox = no->prox;
        li->final = ant;
    }
    free(no);
    li->qtd--;
    return 1;
}