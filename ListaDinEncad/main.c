#include <stdio.h>
#include "ListaDinamicaEncadeada.h"

int main(int argc, char const *argv[])
{
    Lista *li;
    li = cria_lista();
    int x = lista_vazia(li);
    printf("%d", x);
    struct aluno al;
    insere_lista_inicio(li, al);
    x = lista_vazia(li);
    printf("%d", x);
    remove_lista_inicio(li);
    x = lista_vazia(li);
    printf("%d", x);
    return 0;
}
