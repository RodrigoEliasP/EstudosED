#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

void print_vetor_int(int *v, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%i, ", v[i]);
    }
    printf("\n");
}
void print_vetor_float(float *v, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%.2f, ", v[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Grafo *gr;
    gr = cria_grafo(5, 5, 1);
    int eh_digrafo = 1;
    insereaAresta(gr, 0, 1, eh_digrafo, 1);
    insereaAresta(gr, 1, 3, eh_digrafo, 3);
    insereaAresta(gr, 1, 2, eh_digrafo, 31);
    insereaAresta(gr, 2, 4, eh_digrafo, 3);
    insereaAresta(gr, 3, 0, eh_digrafo, 5);
    insereaAresta(gr, 3, 4, eh_digrafo, 16);
    insereaAresta(gr, 4, 1, eh_digrafo, 1);


    int profundidades[5];
    int larguras[5];
    int ant[5];
    float dist[5];

    busca_profundidade_Grafo(gr, 0, profundidades);
    busca_largura_Grafo(gr, 0, larguras);
    

    printf("--------Busca Profundidade--------\n");
    print_vetor_int(profundidades, 5);
    printf("--------Busca Larguras--------\n");
    print_vetor_int(larguras, 5);
    printf("--------Dijkstra--------\n");
    menorCaminho_Grafo(gr, 0, ant, dist);
    print_vetor_int(ant, 5);
    print_vetor_float(dist, 5);


    libera_grafo(gr);
    printf("Fim da execução");
    return 0;
}
