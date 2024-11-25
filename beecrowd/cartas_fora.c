// Este código resolve o problema 1110 do Beecrowd.

#include <stdio.h>
#include <stdlib.h>

int *cartas_descartadas = NULL;
int *cartas_restantes = NULL;
int num_cartas;

// Aloca dinamicamente um vetor de inteiros.
int *cria_vetor(int numero_cartas){
    int *temp = malloc((numero_cartas) * sizeof(int));
    return temp;
}

// Preenche o vetor de cartas restantes com valores de 1 até num_cartas, ao contrário.
void preenche_vetor(int *ponteiro, int tamanho){ 
    for(int i = tamanho - 1; i > -1; i--){
        ponteiro[i] = tamanho - i;
    }
}

// Adiciona a última carta ao vetor de cartas descartadas.
void adiciona_descarte(int ultima){
    cartas_descartadas[num_cartas - 1 - ultima] = cartas_restantes[ultima];
}

// Remove uma posição no vetor e joga a anterior para o início do vetor.
void remove_troca(int *j){
    (*j) -= 1;
    int temp = cartas_restantes[*j];
    for(int i = *j; i > 0; i--){
        cartas_restantes[i] = cartas_restantes[i - 1];
    }
    cartas_restantes[0] = temp;
}

// Imprime a saída formatada.
void saida(){
    printf("Discarded cards: ");
        for(int i = 0; i < num_cartas - 1; i++){
            printf("%i", cartas_descartadas[i]);
            if(i < num_cartas - 2){
                printf(", ");
            }
        }
        printf("\nRemaining card: %i\n", cartas_restantes[0]);
}

int main(){
    while(scanf("%i", &num_cartas) && num_cartas != 0){
        cartas_descartadas = cria_vetor(num_cartas - 1); 
        cartas_restantes = cria_vetor(num_cartas);
        preenche_vetor(cartas_restantes, num_cartas);

        int j = num_cartas - 1;
        while(j > 0){
            adiciona_descarte(j);
            remove_troca(&j);
        }
        saida();
    }
    return 0;
}
