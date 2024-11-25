// Este código resolve o problema 2729 do Beecrowd.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tamanho_lista 1005 // Quantidade máxima de itens numa lista.
#define tamanho_nome 25 // Quantidade máxima de caracteres em um produto.

// Estrutura de um produto.
typedef struct produto{
    char nome[tamanho_nome];
    struct produto *proximo;
} produto;

// Tabela hash de produtos.
produto *tabela[tamanho_lista];

char matriz[tamanho_lista][tamanho_nome];
int num_elementos = 0;

// Função que cria um valor hash para cada produto.
int valor_hash(char *novo){
    int valor = 0;
    int tamanho_novo = strnlen(novo, tamanho_nome);
    for(int i = 0; i < tamanho_novo; i++){
        valor += novo[i] * 31; // Adiciona o valor ASCII de cada caractere multiplicado por 31.
        valor = valor % tamanho_lista; // Coloca nos limites de 1000 itens.
    }
    return valor;
}

// Coloca todos os índices da tabela hash como NULL para iniciar o código.
void zera_tabela(){
    for(int i = 0; i < tamanho_lista; i++){
        tabela[i] = NULL;
    }
}

// Seta todos os primeiros endereços das strings como '\0' para reiniciar a matriz a cada iteração.
void zera_matriz(){
    for(int i = 0; i < tamanho_lista; i++){
        matriz[i][0] = '\0';
    }
}

// Percorre a lista ligada do índice da tabela até: encontrar o produto adicionado (ou seja, já existe) ou encontrar o fim da lista.
void percorre_e_adiciona(produto *atual, produto *adicionado){
    while(atual->proximo != NULL){
        if(strcmp(atual->nome, adicionado->nome) == 0){ // Checa se o adicionado e o atual são iguais.
            return;
        }
        atual = atual->proximo;
    }
    if(strcmp(atual->nome, adicionado->nome) == 0){ // Última checagem por conta de como o loop foi estruturado.
        return;
    }
    atual->proximo = adicionado;
    strcpy(matriz[num_elementos], adicionado->nome);
    num_elementos += 1;
}

// Checa se o índice do respectivo valor hash é NULL, e se não for, chama função que adiciona à lista ligada.
void adiciona_na_tabela(produto *adicionado){
    int index = valor_hash(adicionado->nome); 
    if(tabela[index] == NULL){
        tabela[index] = adicionado;
        strcpy(matriz[num_elementos], adicionado->nome);
        num_elementos += 1;
        return;
    }
    percorre_e_adiciona(tabela[index], adicionado); // Percorre a lista encadeada do índice caso haja conflito.
}

// Separa uma lista em palavras e adiciona cada uma na tabela (se ainda não estiver).
void separa_lista(char *lista){
    char *palavra;
    palavra = strtok(lista, " "); // Função para percorrer até encontrar um espaço (" ").
    while(palavra != NULL){
        produto *temp = malloc(sizeof(produto)); 
        temp->proximo = NULL;
        strncpy(temp->nome, palavra, tamanho_nome); // Copia a palavra separada para o produto temp.
        adiciona_na_tabela(temp); // Função que adiciona se ainda não estiver.
        palavra = strtok(NULL, " "); // Continua a separar as palavras do índice onde parou.
    }
}

// Função utilizada pelo qsort(). Compara duas strings lexicograficamente e retorna o resultado em 1, 0 ou -1.
int compara_strings(const void *a, const void *b){
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;

    return strcmp(str_a, str_b); // 1 = a dps de b | 0 = strings iguais | -1 = a antes de b.
}

int main(){
    int num_listas;
    scanf("%i", &num_listas);
    while(getchar() != '\n');
    for(int i = 0; i < num_listas; i++){
        num_elementos = 0;
        zera_matriz();
        zera_tabela();
        char lista[25000];
        fgets(lista, 25000, stdin);
        lista[strcspn(lista, "\n")] = '\0'; // Tira o '\n' do fim da string.
        separa_lista(lista);

        // Cria um array de ponteiros para cada endereço da matriz. Não sei por que mas precisou disso.
        char *array[tamanho_lista]; 
        for(int i = 0; i < num_elementos; i++){
            array[i] = matriz[i];
        }

        // Função quick sort presente na stdlib.h
        qsort(array, num_elementos, sizeof(char *), compara_strings);
        for(int i = 0; i < num_elementos; i++){
            if(i > 0){ // Se não for o primeiro elemento, printa um espaço em branco antes do elemento.
                printf(" ");
            }
            printf("%s", array[i]);
        }
        printf("\n");
    }
    return 0;
}