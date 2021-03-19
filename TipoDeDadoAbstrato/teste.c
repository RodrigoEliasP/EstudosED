#include <stdio.h>
#include "pto.h"


int main() {  
    Ponto* p1 = pto_cria(2, 3);
    Ponto* p2 = pto_cria(3, 4);
    float d, x, y;

    d = pto_distancia(p1,p2);
    printf("distancia entre os pontos %.2f \n", d);

    pto_acessa(p1, &x, &y);
    printf("p1 e x:%.2f y:%.2f \n", x, y);

    pto_atribui(p1, 1, 2);
    pto_acessa(p1, &x, &y);
    printf("p1 e x:%.2f y:%.2f \n", x, y);
}