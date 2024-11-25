// Este código resolve o problema 1069 do Beecrowd.

#include <stdio.h>

int conta_diamantes(char caso[]){
    int aberturas = 0;
    int diamantes = 0;
    int i = 0;
    while(caso[i] != '\0'){
        if(caso[i] == '<'){
            aberturas += 1;
        }
        else if(caso[i] == '>' && aberturas > 0){
            diamantes += 1;
            aberturas -= 1;
        }
        i += 1;
    }
    return diamantes;
}

int main(){
    int num_casos;
    scanf("%i", &num_casos);
    for(int i = 0; i < num_casos; i++){
        char caso[1000];
        scanf("%s", caso);
        int diamantes = conta_diamantes(caso);
        printf("%i\n", diamantes);
    }

    return 0;
}