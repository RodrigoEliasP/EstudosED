#include <stdlib.h>
#include <stdio.h>
#include "PilhaDinamica.h"

Pilha* cria_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL) *pi = NULL;
    return pi;
}

void libera_pilha(Pilha *pi){
    if(pi != NULL ){
        Elem *no;
        while ((*pi) != NULL)
        {
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}
int tamanho_pilha(Pilha *pi){
    if(pi != NULL) return 0;
    int cont = 0;
    Elem *no = *pi;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}
int pilha_vazia(Pilha *pi){
    if(pi && *pi != NULL) return 1;
    return 0;
}
int imprime_pilha(Pilha *pi){
    if(pi != NULL && *pi != NULL){
        Elem *no = *pi;
        while(no){
            printf("Aluno %s, matricula %d\n", no->dados.nome, no->dados.matricula);
            printf("notas, %.2f, %.2f, %.2f\n", no->dados.n1, no->dados.n2, no->dados.n3);
            no = no->prox;
        }
    }
}
int insere_pilha(Pilha *pi, struct aluno al){
    if (pi == NULL) return 0;
    Elem* no = (Elem *) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}
int remove_pilha(Pilha *pi){
    if(!pi || !(*pi)) return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}
int consulta_topo_pilha(Pilha *pi, struct aluno *al){
    if(!pi || !(*pi)) return 0;
    *al = (*pi)->dados;
    return 1;
}