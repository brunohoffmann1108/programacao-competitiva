// Este código resolve o problema 1024 do Beecrowd.

#include <stdio.h>
#include <string.h>

#define tamanho_max 1000 // Tamanho máximo para uma linha.

// Desloca caracteres alfabéticos 3 posições para frente.
void desloca_tres(char *linha, int tamanho_linha){
    for(int i = 0; i < tamanho_linha; i++){
        if((linha[i] >= 'a' && linha[i] <= 'z') || (linha[i] >= 'A' && linha[i] <= 'Z')){
            linha[i] += 3;
        }
    }
}

// Cria string igual à linha e copia de trás para frente na string original.
void inverte_linha(char *linha, int tamanho_linha){
    char temp[tamanho_max];
    strcpy(temp, linha);
    int i = tamanho_linha - 1; // Itera do fim ao início de temp.
    int j = 0; // Itera do início ao fim da linha original.
    while(i >= 0){
        linha[j] = temp[i];
        i -= 1;
        j += 1;
    }
}

// Calcula metade da string e desloca todos em diante 1 posição para frente.
void desloca_metade(char *linha, int tamanho_linha){
    int metade = tamanho_linha / 2;
    for(int i = metade; i < tamanho_linha; i++){
        linha[i] -= 1;
    }
}

int main(){
    int casos_de_teste = 0;
    scanf("%i", &casos_de_teste);
    while(getchar() != '\n'); // Limpa o buffer de entrada.
    for(int i = 0; i < casos_de_teste; i++){
        char linha[tamanho_max];
        fgets(linha, tamanho_max, stdin);
        linha[strcspn(linha, "\n")] = '\0'; // Remove o \n por conta do fgets.
        int tamanho_linha = strlen(linha); // As três funções utilizam esse parâmetro (tamanho da linha).
        desloca_tres(linha, tamanho_linha);
        inverte_linha(linha, tamanho_linha);
        desloca_metade(linha, tamanho_linha);
        printf("%s\n", linha);
    }

    return 0;
}