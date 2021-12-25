#include <stdio.h>

void selection_sort(int* v, int n){
    int i, j, menor, aux;
    for (i = 0; i < n - 1; i++)
    {
        menor = i;
        for ( j = i+1; j < n; j++)
        {
            if(v[j] < v[menor])
                menor = j;
        }
        if (i != menor)
        {
            aux = v[i];
            v[i] = v[menor];
            v[menor] =  aux;
        }
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
    int vetor[10] = {39, 23, 43, 65, 345, 678, 365, 23, 2, 94};
    int n = sizeof vetor / sizeof vetor[0];
    print_vetor(vetor, n);
    selection_sort(vetor, n);
    print_vetor(vetor, n);
    
    return 0;
}
