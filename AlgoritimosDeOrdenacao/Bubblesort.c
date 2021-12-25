#include <stdio.h>

void bubble_sort(int *v, int n)
{
    int i, continua = 0, aux, fim = n;
    do
    {
        for ( i = 0; i < fim-1; i++)
        {
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    } while (continua != 0);
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
    bubble_sort(vetor, n);
    print_vetor(vetor, n);

    return 0;
}
