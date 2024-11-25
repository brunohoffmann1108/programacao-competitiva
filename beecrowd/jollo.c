// Este código resolve o problema 1321 do Beecrowd.
#include <stdio.h>

void ordena_princesa(int princesa[]){
    for(int i = 1; i < 3; i++){
        int j = i;
        while(princesa[j] < princesa[j - 1] && j > 0){
            int temp = princesa[j - 1];
            princesa[j - 1] = princesa[j];
            princesa[j] = temp;
            j -= 1;
        }
    }
}

int vitorias_princesa(int princesa[], int principe[]){
    int vitorias = 0;
    for(int i = 1; i > -1; i--){
        int j;
        for(j = 0; j < 3; j++){
            if(princesa[j] > principe[i]){
                princesa[j] = 0;
                vitorias += 1;
                break;
            }
        }
        if(j == 3){
            for(int k = 0; k < 3; k++){
                if(princesa[k] != 0){
                    princesa[k] = 0;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < 3; i++){
        if(princesa[i] != 0){
            princesa[0] = princesa[i];
        }
    }

    return vitorias;
}

int calcula_resultado(int vitorias, int cartas[], int carta_princesa){
    switch(vitorias){
        case 0: {
            int i = 0;
            int menor_carta = 1;
            while(i < 5){
                if(menor_carta == cartas[i]){
                    menor_carta += 1;
                    i = -1;
                }
                i += 1;
            }
            return menor_carta;
        }
        case 1: {
            int i = 0;
            int menor_carta = carta_princesa + 1;
            while(i < 5){
                if(menor_carta == 53){
                    return -1;
                }
                if(menor_carta == cartas[i]){
                    menor_carta += 1;
                    i = -1;
                }
                i += 1;
            }
            return menor_carta;
        }
        case 2: {
            return -1;
        }
    }

    return 0;
}

int main(){
    int princesa[3];
    int principe[2];
    while(1){
        // Leitura das cartas.
        for(int i = 0; i < 3; i++){
            scanf("%i", &princesa[i]);
        }
        for(int i = 0; i < 2; i++){
            scanf("%i", &principe[i]);
        }
        if(princesa[0] == 0){
            return 0;
        }
        int cartas[5] = {princesa[0], princesa[1], princesa[2], principe[0], principe[1]};
        // Ordenação das cartas.
        if(principe[0] > principe[1]){
            int temp = principe[1];
            principe[1] = principe[0];
            principe[0] = temp;
        }
        ordena_princesa(princesa);
        // Calcula vitórias da princesa.
        int vitorias = vitorias_princesa(princesa, principe);
        // Calcula a menor carta necessária para o príncipe vencer.
        printf("%i\n", calcula_resultado(vitorias, cartas, princesa[0]));
    }

    return 0;
}