#include <stdio.h>

int busca_linear(int *vetor, int tamanho, int elem){
    for (int i = 0; i < tamanho; i++)
    {
        if(elem == vetor[i])
            return i;
    }
    return -1;
}
int busca_ordenada(int *vetor, int tamanho, int elem)
{
    for (int i = 0; i < tamanho; i++)
    {
        if(elem == vetor[i])
            return i;
        else if (elem < vetor[i])
            return -1;
    }
    return -1;
}
int busca_binaria(int *vetor, int tamanho, int elem)
{
    int inicio = 0, meio, final = tamanho - 1;
    while (inicio <= final)
    {
        meio = (inicio + final)/2;
        if(elem < vetor[meio])
            final = meio - 1;
        else if (elem > vetor[meio])
            inicio = meio +1;
        else return meio;
    }
    

}

int main(int argc, char const *argv[])
{
    int vetor[100] = {
        63, 24, 47, 82, 74, 42, 36, 90, 30, 19, 27, 79, 9, 12, 24, 76, 72, 98, 26, 61, 16, 61, 40, 39, 1, 10, 98, 25, 66, 89, 96, 6, 67, 26, 74, 60, 43, 92, 51, 3, 55, 96, 42, 77, 40, 53, 32, 72, 98, 82, 21, 71, 77, 44, 18, 86, 50, 54, 60, 53, 88, 24, 66, 54, 73, 2, 9, 71, 83, 65, 40, 91, 56, 99, 61, 98, 79, 80, 22, 21, 59, 26, 74, 45, 97, 74, 55, 45, 82, 36, 76, 65, 49, 80, 38, 31, 64, 71, 37, 56
    };
    int vetor_ordenado[100] = {
        1, 2, 3, 6,7, 8, 10, 12, 16, 18, 19, 21, 21, 22, 24, 24, 24, 25, 26, 26, 26, 27, 30, 31, 32, 36, 36, 37, 38, 39, 40, 40, 40, 42, 42, 43, 44, 45, 45, 47, 49, 50, 51, 53, 53, 54, 54, 55, 55, 56, 56, 59, 60, 60, 61, 61, 61, 63, 64, 65, 65, 66, 66, 67, 71, 71, 71, 72, 72, 73, 74, 74, 74, 74, 76, 76, 77, 77, 79, 79, 80, 80, 82, 82, 82, 83, 86, 88, 89, 90, 91, 92, 96, 96, 97, 98, 99, 100, 107, 110
    };
    int index = busca_linear(vetor, 100, 98);
    printf("linear %d indice %d\n", vetor[index], index);
    index = busca_ordenada(vetor_ordenado, 100, 98);
    printf("ordenada %d indice %d\n", vetor_ordenado[index], index);
    index = busca_binaria(vetor_ordenado, 100, 98);
    printf("binaria %d indice %d\n", vetor_ordenado[index], index);
    return 0;
}