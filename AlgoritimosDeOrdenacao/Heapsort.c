#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cria_heap(int* v,int i, int f)
{
    int aux = v[i];
    int j = i * 2 + 1;
    while (j <= f)
    {
        if(j < f && (v[j] < v[j+1])) j++;
        if(aux < v[j]){
            v[i] = v[j];
            i = j;
            j = 2 * i + 1;
        }else j = f + 1;
    }
    v[i] = aux;
     
}

void heap_sort(int *v, int n)
{
    int i, aux;
    for (i = (n - 1) / 2; i >= 0; i--)
        cria_heap(v, i, n-1);
    for (i = n-1; i >= 1; i--)
    {
        aux = v[0];
        v[0] = v[i];
        v[i] =  aux;
        cria_heap(v, 0, i-1);
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
    heap_sort(vetor, 10);
    print_vetor(vetor, 10);
    
    return 0;
}
