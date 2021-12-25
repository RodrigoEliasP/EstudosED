#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int particiona(int* v,int inicio, int fim)
{
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo =  v[inicio];
    while (esq < dir)
    {
        while (v[esq] <= pivo)
            esq++;
        while (v[dir] > pivo)
            dir--;
        if(esq < dir) {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}

void quick_sort(int *v,int inicio, int fim)
{
    
    int pivo;
    if (inicio < fim)
    {
        pivo = particiona(v, inicio, fim);
        quick_sort(v, inicio, pivo-1);
        quick_sort(v, pivo+1, fim);
    }
    

} 
void print_vetor(int *v, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%i, ", v[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    int vetor[10] = {39, 23, 2, 65, 345, 678, 365, 256, 43, 94};
    print_vetor(vetor, 10);
    quick_sort(vetor, 0 , 10);
    print_vetor(vetor, 10);
    
    return 0;
}
