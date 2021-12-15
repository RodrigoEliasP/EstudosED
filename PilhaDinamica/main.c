#include "PilhaDinamica.h"
#include <string.h>
#include <stdio.h>

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
    Pilha *pi = cria_pilha();
    tamanho_pilha(pi);
    insere_pilha(pi, cria_aluno("Lara",1, 10,40,50));
    insere_pilha(pi, cria_aluno("Pedro",2, 10,20,7));
    insere_pilha(pi, cria_aluno("Lara",3, 60,60,50));
    imprime_pilha(pi);
    remove_pilha(pi);
    imprime_pilha(pi);
    return 0;
}
