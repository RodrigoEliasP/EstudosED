#include <string.h>
#include "LDDE.h"

void cria_aluno(char nome[30], float n1,  float n2,  float n3, int mat, struct aluno* al){
    strcpy(al->nome, nome);
    al->n1 = n1;
    al->n2 = n2;
    al->n3 = n3;
    al->matricula = mat;
}

int main(int argc, char const *argv[])
{
    struct aluno al;
    Lista* li = cria_lista();

    cria_aluno("joão", 10, 10, 10, 1, &al);
    insere_lista_inicio(li, al);
    cria_aluno("marcos", 10, 10, 10, 3, &al);
    insere_lista_final(li, al);
    cria_aluno("jonas", 10, 10, 10, 2, &al);
    insere_lista_ordenada(li, al);
    imprime_Lista(*li);

    remove_lista(li,2);
    imprime_Lista(*li);

    
    return 0;
}

