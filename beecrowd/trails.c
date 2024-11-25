// Este código resolve o problema 1062 do Beecrowd

#include <stdio.h>
#include <stdlib.h>

int *pilha = NULL;
int posicao_topo = 0;
int max_atual = 1;

void adiciona_na_pilha(int posicao){
    if(max_atual > posicao){
        return;
    }
    while(max_atual <= posicao){
        pilha = realloc(pilha, (posicao_topo + 1) * sizeof(int));
        pilha[posicao_topo] = max_atual;
        max_atual += 1;
        posicao_topo += 1;
    }
}

int remove_da_pilha(int posicao){
    if(pilha[posicao_topo - 1] == posicao){
        posicao_topo -= 1;
        return 1;
    }
    return 0;
}

int main(){
    int num_vagoes;
    while(scanf("%i", &num_vagoes) && num_vagoes != 0){
        int posicao;
        int i = 0;
        while(scanf("%i", &posicao) && posicao != 0){
            adiciona_na_pilha(posicao);
            if(!remove_da_pilha(posicao)){
                printf("No\n");
                while(getchar() != '\n');
                i = 0;
                pilha = NULL;
                max_atual = 1;
                posicao_topo = 0;
                continue;
            }
            i += 1;
            if(i == num_vagoes){
                printf("Yes\n");
                i = 0;
                pilha = NULL;
                max_atual = 1;
                posicao_topo = 0;
            }
        }
        printf("\n");
    }

    return 0;
}