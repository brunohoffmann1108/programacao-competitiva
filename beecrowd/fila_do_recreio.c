// Este código resolve o problema 1548 do Beecrowd.

#include <stdio.h>
#include <stdlib.h>

void ordena_fila(int *fila, int tamanho_fila){
    for(int i = 1; i < tamanho_fila; i++){
        int chave = fila[i];
        int k = i - 1;
        while(chave > fila[k] && k > -1){
            fila[k + 1] = fila[k];
            k -= 1;
        }
        fila[k + 1] = chave;
    }
}

int main(){
    int num_casos;
    scanf("%i", &num_casos);
    for(int i = 0; i < num_casos; i++){
        int num_alunos;
        scanf("%i", &num_alunos);
        // Aloca um vetor com o número de índices igual ao número de alunos.
        int *fila_original = malloc(num_alunos * sizeof(int));
        int *copia_fila = malloc(num_alunos * sizeof(int)); // Cópia da fila que será ordenada para comparação. 
        for(int j = 0; j < num_alunos; j++){
            scanf("%i", &fila_original[j]);
            copia_fila[j] = fila_original[j];
        }
        ordena_fila(copia_fila, num_alunos);
        int posicoes_iguais = 0;
        for(int j = 0; j < num_alunos; j++){
            if(copia_fila[j] == fila_original[j]){
                posicoes_iguais += 1;
            }
        }
        printf("%i\n", posicoes_iguais);
    }

    return 0;
}
