#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int* v,int inicio,int meio,  int fim)
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if (temp != NULL){
        for (i=0; i<tamanho; i++){
            if (!fim1 && !fim2){
                if (v[p1] < v[p2])
                    temp[i]=v[p1++];
                else 
                    temp[i]=v[p2++];
                if(p1> meio) fim1 = 1;
                if(p2> fim) fim2 = 1;
            }else{
                if(!fim1)
                    temp[i]=v[p1++];
                else
                    temp[i]=v[p2++];
            }
        }
        for (j=0, k=inicio; j<tamanho; j++, k++)
            v[k] = temp[j];
    }
    free(temp);
}

void merge_sort(int *v,int inicio, int fim)
{
    
    int meio;
    if (inicio < fim)
    {
        meio = floor((inicio + fim)/2);
        merge_sort(v, inicio, meio);
        merge_sort(v, meio+1, fim);
        merge(v, inicio, meio, fim);
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
    int vetor[10] = {39, 23, 43, 65, 345, 678, 365, 256, 2, 94};
    print_vetor(vetor, 10);
    merge_sort(vetor, 0 , 10);
    print_vetor(vetor, 10);
    
    return 0;
}
