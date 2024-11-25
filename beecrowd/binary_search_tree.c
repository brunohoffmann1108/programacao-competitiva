// Este código resolve o problema 1195 do Beecrowd.

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *esquerdo;
    struct node *direito;
} node;

node *raiz = NULL;

node *cria_node(int valor){
    node *temp = malloc(sizeof(node));
    temp->esquerdo = NULL;
    temp->direito = NULL;
    temp->valor = valor;
    return temp;
}

void adiciona_node(node *novo, node **local_arvore){
    if(*local_arvore == NULL){
        *local_arvore = novo;
        return;
    }
    if(novo->valor < (*local_arvore)->valor){
        adiciona_node(novo, &(*local_arvore)->esquerdo);
    }
    else{
        adiciona_node(novo, &(*local_arvore)->direito);
    }
}

void printa_prefixo(node *node_printado){
    if(node_printado == NULL){
        return;
    }
    printf(" %i", node_printado->valor);
    printa_prefixo(node_printado->esquerdo);
    printa_prefixo(node_printado->direito);
}

void printa_infixo(node *node_printado){
    if(node_printado == NULL){
        return;
    }
    printa_infixo(node_printado->esquerdo);
    printf(" %i", node_printado->valor);
    printa_infixo(node_printado->direito);
}

void printa_posfixo(node *node_printado){
    if(node_printado == NULL){
        return;
    }
    printa_posfixo(node_printado->esquerdo);
    printa_posfixo(node_printado->direito);
    printf(" %i", node_printado->valor);
}


int main(){
    int casos_teste;
    scanf("%i", &casos_teste);
    for(int i = 0; i < casos_teste; i++){
        raiz = NULL;
        int num_nodes;
        scanf("%i", &num_nodes);
        for(int j = 0; j < num_nodes; j++){
            int node;
            scanf("%i", &node);
            adiciona_node(cria_node(node), &raiz);
        }
        printf("Case %i:\n", i + 1);
        printf("Pre.:");
        printa_prefixo(raiz);
        printf("\n");
        printf("In..:");
        printa_infixo(raiz);
        printf("\n");
        printf("Post:");
        printa_posfixo(raiz);
        printf("\n\n");
    }

    return 0;
}