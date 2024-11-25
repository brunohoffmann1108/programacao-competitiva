// Este código resolve o problema 3357 do Beecrowd.

#include <stdio.h>
#include <stdlib.h>

#define tamanho_nome 13 // Tamanho máximo do nome de uma pessoa.

int main(){
    int num_pessoas = 0;
    scanf("%i", &num_pessoas);
    float capacidade_termica = 0.00;
    scanf("%f", &capacidade_termica);
    float capacidade_cuia = 0.00;
    scanf("%f", &capacidade_cuia);

    // Aloca uma matriz dinâmicamente num_pessoas (linhas) * tamanho_nome (colunas).
    char *pessoas = malloc(sizeof(char) * tamanho_nome * num_pessoas); 
    for(int i = 0; i < num_pessoas; i++){
        scanf("%s", (pessoas + i * tamanho_nome)); // Para cada iteração, faz pessoas[i * 27] para percorrer o vetor como uma matriz.
    }

    int num_cuias = capacidade_termica / capacidade_cuia;
    float resto = capacidade_termica - capacidade_cuia * num_cuias; // Diminui divisão inteira da divisão float (fica só o resto decimal).
    if(resto > 0){
        num_cuias += 1; // Houve um resto, que será bebido na última cuia. Logo, há uma cuia a mais.
    }
    else{
        resto = capacidade_cuia; // Se não, o número de cuias está certo (divisão exata), mas o "resto" foi a última cuia, igual às outras.
    }
    int ultima_pessoa = num_cuias % num_pessoas; // Limita a resposta ao número de pessoas. "Descarta" as voltas completas.
    if(ultima_pessoa == 0){
        ultima_pessoa = num_pessoas - 1; // Parou exatamente na última pessoa (resto 0).
    }
    else{
        ultima_pessoa -= 1; // Índice começa no 0, e não no 1. Logo, se sobrou 2, o certo é 1.
    }


    printf("%s %.1f\n", pessoas + ultima_pessoa * tamanho_nome, resto);


    return 0;
}