// Este código resolve o problema 2330 do Beecrowd

#include <stdio.h>

int main(){
    int a = 0;
    int num_vend, num_lig;
    int vendedor[1000][2], ligacao[1000000];

    scanf("%i %i", &num_vend, &num_lig); // Zera vendedores utilizados
    for(int i = 0; i < num_vend; i++){
        vendedor[i][0] = 0; // Ligacoes
        vendedor[i][1] = 0; // Minutos
    }

    for(int i = 0; i < num_lig; i++){
        int menor = 31;
        if(a == 0) scanf("%i", &ligacao[i]); 
        else a = 0; 
        for(int j = 0; j < num_vend; j++){
            if(vendedor[j][1] != 0){
                if(vendedor[j][1] < menor) menor = vendedor[j][1]; // Calcula qual vendedor tem menos minutos
                if(j == num_vend - 1){ // Se for o último vendedor
                    for(int k = 0; k < num_vend; k++){
                        vendedor[k][1] -= menor; // Diminui a menor quantidade de minutos de todos
                    }
                    i -= 1; // Volta uma iteração para não pular uma ligação
                    a = 1;  // Para não ler novamente a mesma ligação
                }
            }
            else{ 
                vendedor[j][0] += 1;
                vendedor[j][1] = ligacao[i];
                break;
            }
        }
    }

    for(int i = 0; i < num_vend; i++){
        printf("%i %i\n", i+1, vendedor[i][0]);
    }

    return 0;

}