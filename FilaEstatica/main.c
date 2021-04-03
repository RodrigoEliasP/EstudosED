#include "FilaEstatica.h"
#include <string.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    Fila *fi = cria_fila();
    struct aluno al;
    strcpy(al.nome, "pedro");
    insere_fila(fi, al);
    strcpy(al.nome, "judas");
    insere_fila(fi, al);

    remove_fila(fi);
    consulta_fila(fi, &al);
    printf("%s", al.nome);
    libera_fila(fi);
    return 0;
}
