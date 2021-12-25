#include <stdio.h>

void insertion_sort(int* v, int n){
    int i, j, aux;
    for (i = 1; i < n; i++)
    {
        aux = v[i];
        for (j = i; j > 0 && aux < v[j-1]; j--)
            v[j] = v[j-1];
        v[j] = aux;
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
    insertion_sort(vetor, n);
    print_vetor(vetor, n);
    
    return 0;
}
