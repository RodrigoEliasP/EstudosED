typedef struct grafo Grafo;

Grafo *cria_grafo(int n_vertices, int grau_max, int ponderado);
int insereaAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);
int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);
void libera_grafo(Grafo* gr);
void busca_profundidade_Grafo(Grafo* gr, int ini, int *visitado);
void busca_largura_Grafo(Grafo* gr, int ini, int *visitado);
void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist);