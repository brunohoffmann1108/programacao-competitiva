// Este código resolve o problema 1104 do Beecrowd

#include <stdio.h>
int main(){
    int qtd_alice = 1, qtd_betty = 1;
    int cartas_alice[100000], cartas_betty[100000];
    int pivo_alice, pivo_betty; // "Alteram" o limite do vetor para o número total de cartas não repetidas

    while(1){
        pivo_alice = 0;
        pivo_betty = 0;

        scanf("%i %i", &qtd_alice, &qtd_betty);
        if(qtd_alice == 0 && qtd_betty == 0) return 0;
        
        for(int i = 0; i < qtd_alice; i++){
            scanf("%i", &cartas_alice[i]);
            if(cartas_alice[i] == cartas_alice[i-1]) continue;
            cartas_alice[pivo_alice] = cartas_alice[i]; // Reorganização do vetor para que não hajam cartas repetidas da Alice
            pivo_alice += 1;
        }

        for(int i = 0; i < qtd_betty; i++){
            scanf("%i", &cartas_betty[i]);
            if(cartas_betty[i] == cartas_betty[i-1]) continue;
            cartas_betty[pivo_betty] = cartas_betty[i]; // Reorganização do vetor para que não hajam cartas repetidas da Betty
            pivo_betty += 1;
        }

        // Define a quantidade de trocas possíveis como o total de cartas não repetidas
        qtd_alice = pivo_alice; 
        qtd_betty = pivo_betty;

        // Ao encontrar uma carta igual, diminui uma possibilidade de troca das variáveis
        for(int i = 0; i < pivo_alice; i++){
            for(int j = 0; j < pivo_betty; j++){
                if(cartas_alice[i] == cartas_betty[j]){
                    qtd_alice -= 1;
                    qtd_betty -= 1;
                    break;
                }
            }
        }

        if(qtd_alice < qtd_betty) printf("%i\n", qtd_alice);
        else printf("%i\n", qtd_betty);
    }

    return 0;
}