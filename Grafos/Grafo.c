#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"


struct grafo {
    int ponderado;
    int n_vetices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo *cria_grafo(int n_vertices, int grau_max, int ponderado) {
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr) {
        int i;
        gr->n_vetices = n_vertices;
        gr->grau_max = grau_max;
        gr->ponderado = ponderado;
        gr->grau = (int*)calloc(n_vertices, sizeof (int));
        gr->arestas = (int**)malloc(n_vertices*sizeof(int));
        for (int i = 0; i < n_vertices; i++)
        {
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));
            if (ponderado)
            {
                gr->pesos = (float**)malloc(n_vertices*sizeof(float*));

                for (int i = 0; i < n_vertices; i++)
                {
                    gr->pesos[i] = (float*)malloc(grau_max*sizeof(float));
                }
            }
        }
    }
    return gr;
}

void libera_grafo(Grafo* gr){
    if(gr) {
        int i;
        for (int i = 0; i < gr->n_vetices; i++)
        {
            free(gr->arestas[i]);
            if(gr->ponderado) {
                free(gr->pesos[i]);
            }
        }
        if(gr->ponderado){
            free(gr->pesos);
        }
        free(gr->arestas);
        free(gr->grau);
        free(gr);
    }
}

int insereaAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    int erro = !gr || 
    (orig < 0 || orig >= gr->n_vetices) ||
    (dest < 0 || dest >= gr->n_vetices)
    ;
    if(erro) return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->ponderado){
        gr->pesos[orig][gr->grau[orig]] = peso;
    }
    gr->grau[orig]++;

    if(eh_digrafo == 0){
        insereaAresta(gr, dest, orig, 1, peso);
    }
    return 1;
}

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    int erro = !gr || 
    (orig < 0 || orig >= gr->n_vetices) ||
    (dest < 0 || dest >= gr->n_vetices)
    ;
    if(erro) return 0;

    int i = 0;
    while (i<gr->grau[orig] && gr->arestas[orig][i]!=dest)
    {
        i++;
    }
    if (i == gr->grau[orig])
    {
        return 0;
    }
    gr->grau[orig]--;
    gr->arestas[orig][i]=gr->arestas[orig][gr->grau[orig]];
    if(gr->ponderado){
        gr->pesos[orig][i]=gr->pesos[orig][gr->grau[orig]];
    }
    if(eh_digrafo == 0){
        removeAresta(gr, dest, orig, 1);
    }
    return 1;
}
void busca_profundidade(Grafo* gr, int ini, int *visitado, int cont){
    int i;
    visitado[ini] = cont;
    for (i = 0;i < gr->grau[ini];i++)
    {
        if(!visitado[gr->arestas[ini][i]]){
            busca_profundidade(gr, gr->arestas[ini][i], visitado, cont+1);
        }
    }
    
}

void busca_profundidade_Grafo(Grafo* gr, int ini, int *visitado){
    int i, cont = 1;
    for (int i = 0; i < gr->n_vetices; i++)
    {
        visitado[i] = 0;
    }

    busca_profundidade(gr, ini, visitado, cont);
}

void busca_largura_Grafo(Grafo *gr, int ini, int *visitado){
    int i, vert, NV, cont = 1, *fila, IF = 0, FF = 0;
    for (i = 0; i < gr->n_vetices; i++)
    {
        visitado[i] = 0;
    }
    NV = gr->n_vetices;
    
    fila = (int*)malloc(NV * sizeof(int));
    FF++;
    fila[FF] = ini;
    visitado[ini] = cont;
    while (IF != FF)
    {
        IF = (IF + 1) % NV;
        vert = fila[IF];
        cont++;
        for (i = 0; i < gr->grau[vert]; i++)
        {
            if (!visitado[gr->arestas[vert][i]])
            {
                FF = (FF + 1) % NV;
                fila[FF] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);
}
int procuraMenorDistancia(float *dist, int *visitado, int NV) {
    int i, menor = -1, primeiro = 1;
    for (i = 0; i < NV; i++)
    {
        if(dist[i] >= 0 && visitado[i] == 0){
            if(primeiro) {
                menor = i;
                primeiro = 0;
            }else if (dist[menor] > dist[i]){
                menor = i;
            }
        }
    }
    return menor;
}
void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist){
    int i, cont, NV, ind, *visitado, u;
    cont = NV = gr->n_vetices;
    visitado = (int *) malloc(NV * sizeof(int));
    for (i = 0; i < NV; i++)
    {
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }
    dist[ini] = 0;
    while (cont > 0)
    {
        u = procuraMenorDistancia(dist, visitado, NV);
        if (u == -1)
        {
            break;
        }
        visitado[u] = 1;
        cont --;
        for ( i = 0; i < gr->grau[u]; i++)
        {
            ind = gr->arestas[u][i];
            if (dist[ind] < 0)
            {
                dist[ind] = dist[u] + gr->pesos[u][i];
                ant[ind] = u;
            } else if (dist[ind] > dist[u] + gr->pesos[u][i]) {
                dist[ind] = dist[u] + gr->pesos[u][i];
                ant[ind] = u;
            }
            
        }
        
    }
    free(visitado);
}
