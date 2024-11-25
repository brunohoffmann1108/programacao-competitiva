// Este código resolve o problema 3484 do Beecrowd.

#include <stdio.h>
#include <stdlib.h>

// Estrutura para cada altura.
typedef struct node{
    int altura;
    struct node *direito;
    struct node *esquerdo;
} node;

// Cria um node para a árvore binára com a altura fornecida.
node *cria_node(int altura){
    node *temp = malloc(sizeof(node));
    temp->altura = altura;
    temp->direito = NULL;
    temp->esquerdo = NULL;
    return temp;
}

// Adiciona node na árvore em função da altura.
void adiciona_node(node *novo, node **atual){
    if(*atual == NULL){
        *atual = novo;
        return;
    }
    if(novo->altura < (*atual)->altura){
        adiciona_node(novo, &(*atual)->esquerdo);
        return;
    }
    adiciona_node(novo, &(*atual)->direito);
}

// Retorna a quantidade de níveis, andares, que a árvore possui.
int conta_niveis(node *atual){
    if(atual == NULL){
        return -1; // -1 será nenhum node ou irá somar com 1 no retorno, dando 0.
    }
    int esquerda = conta_niveis(atual->esquerdo);
    int direita = conta_niveis(atual->direito);
    if(esquerda > direita){
        return esquerda + 1;
    }
    else{
        return direita + 1;
    }
}

// Percorre a árvore toda comparando cada node com o menor do seu nível.
void define_menores(node *atual, int nivel_atual, int *lista_menores){ // nivel_atual guarda o nível atual da árvore, começando em 0 
    if(atual == NULL){
        return;
    }
    if(atual->altura < lista_menores[nivel_atual]){
        lista_menores[nivel_atual] = atual->altura;
    }
    define_menores(atual->esquerdo, nivel_atual + 1, lista_menores);
    define_menores(atual->direito, nivel_atual + 1, lista_menores);
}

int main(){
    node *raiz = NULL;
    int num_alunos = 0;
    scanf("%i", &num_alunos);
    // Lê e adiciona as alturas.
    for(int i = 0; i < num_alunos; i++){
        int altura = 0;
        scanf("%i", &altura);
        adiciona_node(cria_node(altura), &raiz);
    }
    int niveis = conta_niveis(raiz);
    // Aloca um vetor com o número de posições = quantidade de níveis da árvore.
    int *menores = malloc(niveis * sizeof(int)); // Cada posição será a menor criança do seu nível.
    // "Zera" o vetor de menores com altura 1cm maior que o limite.
    for(int i = 0; i <= niveis; i++){
        *(menores + i) = 301;
    }
    define_menores(raiz, 0, menores);
    // Imprime os menores e seus níveis.
    for(int i = 0; i <= niveis; i++){
        printf("%i %i\n", i, menores[i]);
    }
    return 0;
}