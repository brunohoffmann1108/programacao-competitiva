// Este código resolve o problema 1261 do Beecrowd.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define tamanho_palavra 20 // Tamanho máximo de cada palavra.
#define tamanho_tabela 1000 // Quantidade máxima de palavras na tabela hash.

// Estrutura de cada palavra, com a string, seu valor em dólares e um ponteiro para colisões.
typedef struct palavra{
    char palavra[tamanho_palavra];
    int valor_palavra;
    struct palavra *proximo;
}palavra;

// Tabela hash.
palavra *tabela[tamanho_tabela];

// Seta a tabela hash como NULL em todas as posições.
void inicia_tabela(){
    for(int i = 0; i < tamanho_tabela; i++){
        tabela[i] = NULL;
    }
}

// Cria o valor hash de cada palavra com base nos valores ASCII de cada caractere.
int valor_hash(char *nova_palavra){
    int valor_hash = 0;
    int tamanho_string = strnlen(nova_palavra, tamanho_palavra);
    for(int i = 0; i < tamanho_string; i++){
        valor_hash += nova_palavra[i] * 31; // Adiciona o valor do caractere[i] multiplicado por 31 ao valor hash.
        valor_hash = valor_hash % tamanho_tabela; // Divide por 1000 e pega o resto para ficar nos limites da tabela.
    }
    return valor_hash;
}

void adiciona_na_tabela(palavra *adicionada){
    adicionada->proximo = NULL; // Começa setando a próxima como NULL pois será a última se houver colisão.
    int index = valor_hash(adicionada->palavra);
    if(tabela[index] == NULL){
        tabela[index] = adicionada;
    }
    else{
        // Itera até encontrar a última posição em uma colisão.
        palavra *atual = tabela[index];
        while(atual->proximo != NULL){ 
            atual = atual->proximo;
        }
        atual->proximo = adicionada;
    }

}

// Se econtrar a palavra no índice da tabela, retorna seu valor. Se não, retorna 0.
int retorna_valor(palavra *atual, char *procurada){
    while(atual != NULL){
        if(strcmp(atual->palavra, procurada) == 0){
            return atual->valor_palavra;
        }
        atual = atual->proximo;
    }
    return 0;
}

// Divide a string com strtok, calcula o valor de cada palavra e compara com a tabela.
int calcula_valores_linha(char *linha){
    char *palavra;
    int valor = 0;
    palavra = strtok(linha, " "); // Cria uma string q vai do [0] até econcontrar um " ".
    while(palavra != NULL){
        int index = valor_hash(palavra); // Calcula o valor hash com a palavra separada da string.
        if(tabela[index] != NULL){
            valor += retorna_valor(tabela[index], palavra); // Chama a função que percorre a lista ligada e retorna o valor se achar.
        }
        palavra = strtok(NULL, " "); // Continua dividindo a string de onde parou antes até econtrar " " novamente.
    }
    return valor;
}

int main(){
    inicia_tabela();
    int num_palavras;
    int num_descricoes;
    scanf("%i %i", &num_palavras, &num_descricoes);

    // Recebe as palavras e às adiciona na tabela hash.
    for(int i = 0; i < num_palavras; i++){
        palavra *temp = malloc(sizeof(palavra));
        scanf("%s", temp->palavra);
        scanf("%i", &temp->valor_palavra);
        adiciona_na_tabela(temp);
    }

    // recebe as descrições e calcula seus respectivos valores.
    for(int i = 0; i < num_descricoes; i++){
        int valor = 0;
        char linha[10000];
        do{
            fgets(linha, 10000, stdin);
            linha[strcspn(linha, "\n")] = '\0'; // Remove /n da linha.
            valor += calcula_valores_linha(linha);
        }while(strcmp(linha, ".") != 0);
        printf("%i\n", valor);
    }

    return 0;
}