// Este código resolve o problema 1018 do Beecrowd.

#include <stdio.h>

int main(){
    int valor = 0;
    scanf("%i", &valor);
    printf("%i\n", valor);
    printf("%i nota(s) de R$ 100,00\n", valor / 100); // Imprime resultado de divisão pela nota.
    valor = valor % 100; // Transforma o valor no resto da divisão pela nota e repete com todos.
    printf("%i nota(s) de R$ 50,00\n", valor / 50);
    valor = valor % 50;
    printf("%i nota(s) de R$ 20,00\n", valor / 20);
    valor = valor % 20;
    printf("%i nota(s) de R$ 10,00\n", valor / 10);
    valor = valor % 10;
    printf("%i nota(s) de R$ 5,00\n", valor / 5);
    valor = valor % 5;
    printf("%i nota(s) de R$ 2,00\n", valor / 2);
    valor = valor % 2;
    printf("%i nota(s) de R$ 1,00\n", valor / 1);

    return 0;
}