// Este código resolve o problema 2600 do Beecrowd.

#include <stdio.h>

int main(){
    int num_casos;
    scanf("%i", &num_casos);
    for(int i = 0; i < num_casos; i++){
        int possibilidade = 1; // Variável que diz se é possível ter um dado clássico com as condições até agora.
        int ordem_dos_lados[6] = {0, 0, 0, 0, 0, 0}; // Vetor que armazena a ordem dos lados na iteração atual.
        int numeros_validos[6] = {1, 1, 1, 1, 1, 1}; // Se é 1, o lado já foi. Se é 0, está repetido.
        for(int j = 0; j < 6; j++){
            int lado;
            scanf("%i", &lado);
            if(lado < 1 || lado > 6 || !numeros_validos[lado - 1]){
                possibilidade = 0; // Já informa que não há possibilidade no caso de teste atual.
                continue;
            }
            numeros_validos[lado - 1] = 0; // Diz que o número atual já foi.
            ordem_dos_lados[j] = lado; // Se ainda for possível formar o dado clássico, a ordem sempre será correta.
        }
        if(!possibilidade){
            printf("NAO\n");
            continue;
        }
        // Se dois lados estão certos, o outro automaticamente está.
        if((ordem_dos_lados[0] + ordem_dos_lados[5] == 7) && (ordem_dos_lados[1] + ordem_dos_lados[3] == 7)){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
    }
    return 0;
}