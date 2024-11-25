// Este código resolve o problema 2428 do Beecrowd

#include <stdio.h>

int main(){
    int a[4];
    char resultado = 'N';
    scanf("%i %i %i %i", &a[0], &a[1], &a[2], &a[3]);

    // Se tivermos uma combinação de valores onde o produto1 = porduto2, é possível formar um retângulo
    if(a[0] * a[1] == a[2] * a[3] || a[0] * a[2] == a[1] * a[3] || a[0] * a[3] == a[1] * a[2]) resultado = 'S';
    printf("%c\n", resultado);

    return 0;
}