// Este código resolve o problema 3433 do Beecrowd

#include <stdio.h>
int cartas[13] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

// Caso a carta seja 11, 12 ou 13, retorna sua pontuação real (10).
int confere_carta(int valor_carta){
    if(valor_carta == 11 || valor_carta == 12 || valor_carta == 13) return 10;
    else return valor_carta;
}

int resultado(int soma_john, int soma_mary){
    int min_john = 24 - soma_john;
    int min_mary = 23 - soma_mary;
    int result = -1;

    // Caso John
    if(min_john < 11){
        for(int i = min_john; i < 13; i++){
            if(cartas[i - 1] == 0){
                continue;
            }
            else if(soma_john + confere_carta(i) > 23 && soma_mary + confere_carta(i) <= 23){
                result = i;
                break;
            }
        }
    }

    // Caso Mary
    if(min_mary < 11){
            if(cartas[min_mary - 1] != 0){
                if(result == -1) result = min_mary;
                else if(min_mary < result) result = min_mary;
            }
    }
    return result;
}

int main(){ 
    int num_rounds, rounds[8];
    int soma[2]; // Soma[0] = John | soma[1] = Mary.
    int cartas_iniciais[2];

    // Número de rounds.
    scanf("%i", &num_rounds);

    // Lê as cartas iniciais de cada um e diminui suas quantidades no baralho.
    for(int i = 0; i < 2; i++){
        scanf("%i %i", &cartas_iniciais[0], &cartas_iniciais[1]);
        soma[i] = confere_carta(cartas_iniciais[0]) + confere_carta(cartas_iniciais[1]); 
        cartas[cartas_iniciais[0] - 1] -= 1;
        cartas[cartas_iniciais[1] - 1] -= 1;
    }

    // Lê as cartas de cada rodada, adiciona seu valor à soma de cada um e diminui sua quantidade no baralho
    for(int i = 0; i < num_rounds; i++){
        scanf("%i", &rounds[i]);
        soma[0] += confere_carta(rounds[i]);
        soma[1] += confere_carta(rounds[i]);
        cartas[rounds[i] - 1] -= 1;
    }

    printf("%i\n", resultado(soma[0], soma[1]));
    
    return 0;
}