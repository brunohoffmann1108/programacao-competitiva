// Este código resolve o problema 2879 do Beecrowd.

#include <stdio.h>

int main(){
    int num_jogos;
    scanf("%i", &num_jogos);
    
    int vitorias = 0;
    int tentativa;
    for(int i = 0; i < num_jogos; i++){
        scanf("%i", &tentativa);
        if(tentativa != 1){
            vitorias += 1;
        }
    }
    printf("%i\n", vitorias);

    return 0;
}
