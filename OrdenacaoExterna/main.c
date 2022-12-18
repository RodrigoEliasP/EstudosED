#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

struct arquivo {
    FILE *f;
    int pos, MAX, *buffer;
};
void salvaArquivo(char *nome, int *V, int tam, int mudaLinhaFinal) {
    FILE *f = fopen(nome, "a");
    for (int i = 0; i < tam-1; i++)
    {
        fprintf(f, "%d\n", V[i]);
    }
    
    fprintf(f, mudaLinhaFinal ? "%d\n": "%d", V[tam-1]);
    fclose(f);
}

void preencheBuffer(struct arquivo* arq, int K)
{
    if(arq->f == NULL){
        return;
    }
    arq->pos = 0;
    arq->MAX = 0;
    for (int i = 0; i < K; i++)
    {
        if(!feof(arq->f)){
            fscanf(arq->f, "%d", &arq->buffer[arq->MAX++]);
        } else  {
            fclose(arq->f);
            arq->f = NULL;
            break;
        }
    }
    
};


int procuraMenor(struct arquivo* arq, int numArqs, int K, int* menor){
    int i, idx = -1;
    for ( i = 0; i < numArqs; i++)
    {
        if(arq[i].pos < arq[i].MAX){
            if(idx == -1){
                idx = i;
            } else if(arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos]) {
                idx = i;
            }
        }
    }
    if(idx != -1) {
        *menor = arq[idx].buffer[arq[idx].pos++];
        if(arq[idx].pos == arq[idx].MAX){
            preencheBuffer(&arq[idx], K);
        }
        return 1;
    }
    return 0;
}

void merge(char *nome, int numArqs, int K) {
    char novo[20];
    int i;
    int *buffer = (int*) malloc(K*sizeof(int));
    
    struct arquivo* arq = (struct arquivo*) malloc(numArqs* sizeof(struct arquivo));
    for ( i = 0; i < numArqs; i++)
    {
        sprintf(novo, "Temp%d.txt", i+1);
        arq[i].f = fopen(novo, "r");
        arq[i].MAX = 0;
        arq[i].pos = 0;
        arq[i].buffer = (int*) malloc(K*sizeof(int));
        preencheBuffer(&arq[i], K);
    }
    int menor, qtdBuffer = 0;

    while (procuraMenor(arq, numArqs, K, &menor) == 1)
    {
        buffer[qtdBuffer++] = menor;
        if(qtdBuffer == K) {
            salvaArquivo(nome, buffer, K, 1);
            qtdBuffer = 0;
        }
    }
    
    if(qtdBuffer != 0) {
        salvaArquivo(nome, buffer, qtdBuffer, 1);
    }

    for(i = 0; i < numArqs; i++){
        free(arq[i].buffer);
    }

    free(arq);
    free(buffer);
    
}

int compara(const void *a, const void *b) {
    int int1 = *(int*)a;
    int int2 = *(int*)b;
    if (int1 < int2) {
        return -1;
    } else if (int1 > int2) {
        return 1;
    } else {
        return 0;
    }
}

void criaArquivoTeste (char *nome) {
    int i;
    FILE *f = fopen(nome, "w");

    srand(time(NULL));
    for (i = 1; i < 1000; i++)
    {
        fprintf(f, "%d\n", rand());
    }
    fprintf(f, "%d", rand());
    fclose(f);
    
}
int criaArquivosDeOrdenacao(char* nome) {
    int V[N], cont = 0, total = 0;
    char novo[20];
    FILE *f = fopen(nome, "r");

    while (!feof(f))
    {
        fscanf(f, "%d", &V[total++]);
        if(total == N) {
            sprintf(novo, "Temp%d.txt", ++cont);
            qsort(V, total, sizeof(int), compara);
            salvaArquivo(novo, V, total, 0);
            total = 0;
        }
    }
    if(total > 0){
        sprintf(novo, "Temp%d.txt", ++cont);
        qsort(V, total, sizeof(int), compara);
        salvaArquivo(novo, V, total, 0);
    }
    fclose(f);
    return cont;
}
void mergeSortExterno(char *nome){
    char novo[20];
    int numArgs = criaArquivosDeOrdenacao(nome);
    int i, K = N / (numArgs + 1);
    
    remove(nome);
    merge(nome, numArgs, K);

    for (i = 0; i < numArgs; i++)
    {
        sprintf(novo, "Temp%d.txt", i+1);
        remove(novo);
    }
    
}
int main(int argc, char const *argv[])
{
    criaArquivoTeste("dados.txt");
    mergeSortExterno("dados.txt");
    return 0;
}
