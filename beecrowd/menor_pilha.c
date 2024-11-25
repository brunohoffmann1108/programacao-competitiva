// Este código resolve o problema 2929 do Beecrowd.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *pilha = NULL;
int tamanho = 0;

void insere_pilha(int valor){
    tamanho += 1;
    pilha = realloc(pilha, sizeof(int) * tamanho);
    pilha[tamanho - 1] = valor;
}

void remove_pilha(){
    if(tamanho == 0){
        printf("EMPTY\n");
        return;
    }   
    tamanho -= 1;
}

void mostra_menor(){
    if(tamanho == 0){
        printf("EMPTY\n");
        return;
    }
    int menor = pilha[0];
    for(int i = 1; i < tamanho; i++){
        if(pilha[i] < menor){
            menor = pilha[i];
        }
    }
    printf("%i\n", menor);
}

int main(){
    int num_operacoes;
    scanf("%i", &num_operacoes);
    for(int i = 0; i < num_operacoes; i++){
        char comando[10];
        scanf("%s", comando);
        if(strcmp(comando, "PUSH") == 0){
            int valor;
            scanf("%i", &valor);
            insere_pilha(valor);
        }
        else if(strcmp(comando, "POP") == 0){
            remove_pilha();
        }
        else if(strcmp(comando, "MIN") == 0){
            mostra_menor();
        }
        
    }

    return 0;
}
