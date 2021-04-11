#include "FilaDin.h"
#include <stdlib.h>
struct fila{
    struct elemento *inicio, *final;
};
struct elemento
{
    struct aluno dados;
    struct elemnto *prox;
};

typedef struct elemento Elem;


Fila* cria_fila(){
    Fila *fi = (Fila*) malloc(sizeof(Fila));
    if(fi){
        fi->final = NULL;
        fi->inicio = NULL;
    }
}

void libera_fila(Fila *fi){
    if(fi){
        Elem *no;
        while(fi->inicio){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_fila(Fila *fi){
    if(!fi) return 0;
    int cont = 0;
    Elem *no = fi->inicio;
    while(no){
        cont++;
        no = no->prox;
    }
    return cont;
}

int fila_vazia(Fila *fi){
    if(!fi) return 0;
    return !fi->inicio;
}

int inserir_fila(Fila *fi, struct aluno al){
    if(!fi) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(!no) return 0;
    no->dados = al;
    no->prox = NULL;
    if(!fi->final) fi->inicio = no;
    else fi->final->prox = no;
    fi->final = no;
    return 1;
}
int remover_fila(Fila *fi){
    if(!fi || fila_vazia(fi)) return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(!fi->inicio) fi->final = NULL;
    free(no);
    return 1;
}
int consulta_fila(Fila *fi, struct aluno *al){
    if(!fi || fila_vazia(fi)) return 0;
    *al = fi->inicio->dados;
    return 1;
}