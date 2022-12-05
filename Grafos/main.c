#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(int argc, char const *argv[])
{
    Grafo *gr;
    gr = cria_grafo(10, 7, 0);
    insereaAresta(gr, 0, 1, 0, 0);
    insereaAresta(gr, 1, 3, 0, 0);

    insereaAresta(gr, 1, 5, 0, 0);
    removeAresta(gr, 1, 5, 0);
    libera_grafo(gr);

    printf("Fim da execução");
    return 0;
}
