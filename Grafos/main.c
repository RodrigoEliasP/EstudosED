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
    gr = cria_grafo(5, 5, 0);
    int eh_digrafo = 1;
    insereaAresta(gr, 0, 1, eh_digrafo, 0);
    insereaAresta(gr, 1, 3, eh_digrafo, 0);
    insereaAresta(gr, 1, 2, eh_digrafo, 0);
    insereaAresta(gr, 2, 4, eh_digrafo, 0);
    insereaAresta(gr, 3, 0, eh_digrafo, 0);
    insereaAresta(gr, 3, 4, eh_digrafo, 0);
    insereaAresta(gr, 4, 1, eh_digrafo, 0);


    int profundidades[5];
    int larguras[5];

    busca_profundidade_Grafo(gr, 0, profundidades);
    busca_largura_Grafo(gr, 0, larguras);
    

    printf("--------Busca Profundidade--------\n");
    print_vetor(profundidades, 5);
    printf("--------Busca Larguras--------\n");
    print_vetor(larguras, 5);


    libera_grafo(gr);
    printf("Fim da execução");
    return 0;
}
