#include <stdio.h>
#include <string.h>
#include "ListaSequencial.h"

int cria_aluno
(
    struct aluno *al, 
    int matricula, 
    char nome[30], 
    float notas[3]
);

int main(){
    Lista* li = cria_lista();
    struct aluno al;
    float notas[3] = {5,7,9};
    cria_aluno(&al, 1, "joao", notas);
    inserir_lista_inicio(li, al);

    cria_aluno(&al, 3, "marcos", notas);
    inserir_lista_final(li, al);

    cria_aluno(&al, 4, "jonathan", notas);
    inserir_lista_final(li, al);

    cria_aluno(&al, 2, "jonas", notas);
    inserir_lista_ordenada(li, al);
    imprimir_lista(li);

    remover_lista(li, 2);
    remover_lista(li, 3);

    cria_aluno(&al, 3, "marcos", notas);
    inserir_lista_ordenada(li, al);
    imprimir_lista(li);

    cria_aluno(&al, 2, "jonas", notas);
    inserir_lista_ordenada(li, al);

    remover_lista_final(li);

    remover_lista_inicio(li);
    
    imprimir_lista(li);


    return 0;
}

int cria_aluno
(
    struct aluno *al, 
    int matricula, 
    char nome[30], 
    float notas[3]
)   {
    if(al == NULL) return 0;
    al->matricula = matricula;
    al->n1 = notas[0];
    al->n2 = notas[1];
    al->n3 = notas[2];
    strcpy(al->nome, nome);
    return 1;
}