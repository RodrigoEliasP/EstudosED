#include "FilaDin.h"
#include <stdio.h>
#include <string.h>

struct aluno cria_aluno(char nome[30], int n1, int n2, int n3, int matricula)
{
    struct aluno al;
    al.matricula = matricula;
    al.n1 = n1;
    al.n2 = n2;
    al.n3 = n3;
    strcpy(al.nome, nome);
    return al;
}

int main(int argc, char const *argv[])
{
    /* teste os métodos aqui */
    Fila *fila = cria_fila();
    
    inserir_fila(fila, cria_aluno("pedro", 10, 10, 10, 1));
    inserir_fila(fila, cria_aluno("maria", 10, 10, 10, 2));
    inserir_fila(fila, cria_aluno("joao", 10, 10, 10, 3));
    imprime_fila(fila);
    return 0;
}
