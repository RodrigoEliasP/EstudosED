#include "pilhaEstatica.h"
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
    Pilha *pi;
    pi = cria_pilha();
    tamanho_pilha(pi);
    pilha_cheia(pi);
    pilha_vazia(pi);
    insere_pilha(pi, cria_aluno("Pedro", 10, 8, 9, 1));
    insere_pilha(pi, cria_aluno("Larissa", 7, 2, 9, 2));
    insere_pilha(pi, cria_aluno("Valeria", 3, 7, 8, 3));
    struct aluno al;
    consulta_topo_pilha(pi, &al);
    remove_pilha(pi);
    libera_pilha(pi);

    return 0;
}
