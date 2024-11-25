// Este código resolve o problema 1437 do Beecrowd.

#include <stdio.h>
#include <stdlib.h>

int conta_comandos(char *comandos, int num_comandos){
    int soma_total = 0;
    for(int i = 0; i < num_comandos; i++){
        if(comandos[i] == 'E'){
            soma_total -= 1;
        }
        else{
            soma_total += 1;
        }
    }
    soma_total = soma_total % 4; // Diminui soma total para um range de 0 a 4.
    return soma_total;
}

int main(){
    int num_comandos;
    while(scanf("%i", &num_comandos) && num_comandos != 0){
        char comandos[1000];
        scanf("%s", comandos);
        
        int soma_total = conta_comandos(comandos, num_comandos);
        if(soma_total == 0){
            printf("N\n");
        }
        else if(soma_total == 1 || soma_total == -3){
            printf("L\n");
        }
        else if(soma_total == 2 || soma_total == -2){
            printf("S\n");
        }
        else{
            printf("O\n");
        }
    }
    

    return 0;
}