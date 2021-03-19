#include <stdlib.h>
#include <stdio.h>
#include "ListaSequencial.h"

struct ListaSequencial
{
    int qtd;
    struct aluno dados[MAX];
};

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        li->qtd = 0;
    }
    return li;
}

Lista* libera_lista(Lista *li){
    free(li);
}

int tamanho_lista(Lista *li){
    if(li == NULL){
        return -1;
    }else{
        return li->qtd;
    }
}

int lista_cheia(Lista *li){
    if(li == NULL){
        return -1;
    }else{
        return (li->qtd == MAX);
    }
}

int lista_vazia(Lista *li){
    if(li == NULL){
        return -1;
    }else{
        return (li->qtd == 0);
    }
}
int inserir_lista_final(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    if(lista_cheia(li)) return 0;
    li->dados[li->qtd++] = al;
    return 0;
}
int inserir_lista_inicio(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    if(lista_cheia(li)) return 0;
    int i;
    for (i = li->qtd - 1; i >= 0 ; i--) li->dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;
}
int inserir_lista_ordenada(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    if(lista_cheia(li)) return 0;
    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula < al.matricula) i++;
    for (k = li->qtd-1; k >= i; k--) li->dados[k+1] = li->dados[k];
    li->dados[i] = al;
    li->qtd++;
    return 1;
}
int remover_lista_final(Lista *li){
    if(li == NULL) return 0;
    if(lista_vazia(li)) return 0;
    li->qtd--;
    return 1;
}
int remover_lista_inicio(Lista *li){
    if(li == NULL) return 0;
    if(lista_vazia(li)) return 0;
    int i;
    for(i = 0; i < li->qtd-1; i++) li->dados[i] = li->dados[i+1];
    li->qtd--;
    return 1;
}
int remover_lista(Lista *li, int matricula){
    if(li == NULL) return 0;
    if(lista_vazia(li)) return 0;
    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula != matricula) i++;
    if(i == li->qtd) return 0;
    for (k = i; k < li->qtd-1; k++) li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}
int consulta_lista_pos(Lista *li, int pos , struct aluno *al){
    if(li == NULL || pos < 0 || pos >= li->qtd) return 0;
    *al = li->dados[pos];
    return 1;
}
int consulta_lista_mat(Lista *li, int mat , struct aluno *al){
    if(li == NULL) return 0;
    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat) i++;
    if( i == li->qtd) return 0;
    *al = li->dados[i];
    return 1;
}
int imprimir_lista(Lista *li){
    if(li == NULL || lista_vazia(li)) return 0;
    printf("########################\n");
    for (int i = 0; i < li->qtd; i++)
    {
        struct aluno aluno = li->dados[i];
        float nota = aluno.n1 + aluno.n2 + aluno.n3;
        
        printf("Ordem: %d Nome: %s Matricula: %d Nota: %.2f \n",
            i,
            aluno.nome,
            aluno.matricula,
            nota
        );
    }
    
}