#include "pilhaEstatica.h"
#include <stdlib.h>

Pilha *cria_pilha(){
    Pilha *pi;
    pi = (Pilha*) malloc(sizeof (Pilha*));
    if(pi) 
        pi->qtd = 0;
    return pi;

}

void libera_pilha(Pilha *pi){
    free(pi);
}

int tamanho_pilha(Pilha *pi){
    if(pi)
        return pi->qtd;
    return -1;
}

int pilha_vazia(Pilha *pi){
    if(pi)
        return (pi->qtd == 0);
    return -1;
}

int pilha_cheia(Pilha *pi){
    if(pi)
        return (pi->qtd == MAX);
    return -1;
}
int insere_pilha(Pilha *pi, struct aluno al){
    if(!pi || pilha_cheia(pi)) return 0;
    pi->dados[pi->qtd] = al;
    pi->qtd++;
    return 1;
}
int remove_pilha(Pilha *pi){
    if(!pi || pilha_vazia(pi)) return 0;
    pi->qtd--;
    return 1;
}
int consulta_topo_pilha(Pilha *pi, struct aluno *al){
    if(!pi || pilha_vazia(pi)) return 0;
    *al = pi->dados[pi->qtd];
    return 1;
}


