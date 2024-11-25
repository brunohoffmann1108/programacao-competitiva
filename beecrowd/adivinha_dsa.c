// Este código resolve o problema 1340 do Beecrowd.

#include <stdio.h>
#include <stdlib.h>

int num_comandos;
// Variaveis array.
int tamanho;
int *array = NULL;
int *array_ordenado = NULL;
// Variáveis de possibilidade
int stack;
int queue;
int p_queue;
int possibilidades;

void ordena_array(int posicao){
    int chave = array_ordenado[posicao];
    int i = posicao - 1;
    while(i > -1 && array_ordenado[i] < chave){
        array_ordenado[i + 1] = array_ordenado[i];
        i -= 1;
    }
    array_ordenado[i + 1] = chave;
}

void adiciona_valor(int valor_comando){
    // Aloca memória.
    tamanho += 1;
    array = realloc(array, tamanho * sizeof(int));
    array_ordenado = realloc(array_ordenado, tamanho * sizeof(int));

    // Adiciona valores aos arrays.
    array[tamanho - 1] = valor_comando;
    array_ordenado[tamanho - 1] = valor_comando;
    ordena_array(tamanho - 1);
}

void remove_valor(int valor_comando){
    int encontrado = 0;
    for(int i = 0; i < tamanho; i++){
        if(array[i] == valor_comando){
            for(int j = i; j < tamanho - 1; j++){
                array[j] = array[j + 1];
            }
            i -= 1;
            tamanho -= 1;
            encontrado += 1;
        }
    }

    if(!encontrado) return;

    for(int i = 0; i < tamanho + encontrado; i++){
        if(array_ordenado[i] == valor_comando){
            for(int j = i; j < tamanho + encontrado - 1; j++){
                array_ordenado[j] = array_ordenado[j + 1];
            }
            i -= 1;
            encontrado -= 1;
        }
    }
}

void testa_valores(int valor_comando){
    if(queue == 1 && valor_comando != array[0]){
        queue = 0;
        possibilidades -= 1;
    }
    if(stack == 1 && valor_comando != array[tamanho - 1]){
        stack = 0;
        possibilidades -= 1;
    }
    if(p_queue == 1 && valor_comando != array_ordenado[0]){
        p_queue = 0;
        possibilidades -= 1;
    }
}

void checa_possibilidades(){
    switch(possibilidades){
        case 1:
        if(stack == 1){
            printf("stack\n");
            break;
        }
        if(queue == 1){
            printf("queue\n");
            break;
        }
        if(p_queue == 1){
            printf("priority queue\n");
            break;
        }

        case 0:
        printf("impossible\n");
        break;

        default:
        printf("not sure\n");
        break;
    }
}

int main(){
    while(scanf("%i", &num_comandos) != EOF){
        tamanho = 0;
        stack = 1;
        queue = 1;
        p_queue = 1;
        possibilidades = 3;
        for(int i = 0; i < num_comandos; i++){
            int comando;
            int valor_comando;
            scanf("%i", &comando);
            scanf("%i", &valor_comando);

            switch(comando){
                case 1:
                adiciona_valor(valor_comando);
                break;

                case 2:
                testa_valores(valor_comando);
                remove_valor(valor_comando);
                break;
            }
        }
        checa_possibilidades();
    }

    return 0;
}
