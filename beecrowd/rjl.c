// Este código resolve o problema 2557 do beecrowd.

#include <stdio.h>
#include <string.h> // Para strtok().
#include <ctype.h> // Para isalpha() e isdigit(). 
#include <stdlib.h> // Para atoi().

// Separa a string da equação em dois inteiros (os números da equação) e um char (a incógnita).
void separa_string(char *equacao, char *incognita, int *constantes){
    char *token = strtok(equacao, "+="); // Copia a string até encontrar '+' ou '='.
    while(token != NULL){
        // Se o pedaço de string separado for numérico (0-9).
        if(isdigit(token[0])){
            int numero = atoi(token); // Converte string para int.
            // Checa qual dos valores é.
            if(constantes[0] == 0){
                constantes[0] = numero;
            }
            else{
                constantes[1] = numero;
            }
        }
        else{
            // Se for um caractére alfabético (a-z).
            if(isalpha(token[0])){
                *incognita = token[0];
            }
        }
        token = strtok(NULL, "+="); // Copia a string para token de onde parou, até encontrar '+' ou '='.
    }
}

int main(){
    char equacao[20];
    while(scanf("%s", equacao) != EOF){
        char incognita;
        int constantes[2] = {0, 0}; // Armazena os dois valores numéricos da equação.
        separa_string(equacao, &incognita, constantes);
        // Caso a incógnita esteja na esquerda, é uma subtração do segundo valor com o primeiro (passa da esquerda para direita subtraindo).
        if(incognita == 'R' || incognita == 'L'){
            printf("%i\n", constantes[1] - constantes[0]);
        }
        // Se a incógnita for J, é só somar os dois valores encontrados.
        else{
            printf("%i\n", constantes[0] + constantes[1]);
        }
    }

    return 0;
}