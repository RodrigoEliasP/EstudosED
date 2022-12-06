#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

void print_vetor(int *v, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%i, ", v[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Grafo *gr;
    gr = cria_grafo(10, 7, 0);
    insereaAresta(gr, 0, 1, 0, 0);
    insereaAresta(gr, 1, 3, 0, 0);
    insereaAresta(gr, 1, 2, 0, 0);
    insereaAresta(gr, 2, 4, 0, 0);
    insereaAresta(gr, 3, 0, 0, 0);
    insereaAresta(gr, 4, 1, 0, 0);


    int vis[5];

    busca_profundidade_Grafo(gr, 0, vis);

    print_vetor(vis, 5);

    libera_grafo(gr);
    printf("Fim da execução");
    return 0;
}
