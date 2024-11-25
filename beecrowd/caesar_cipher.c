// Este código resolve o problema 1253 do Beecrowd.
#include <stdio.h>
#include <string.h>

void decodifica_mensagem(char mensagem[], int num_shift){
    int i = 0;
    while(mensagem[i] != '\0'){
        mensagem[i] -= num_shift;
        if(mensagem[i] < 65){
            mensagem[i] += 26; // Adiciona 26 se código ASCII < 65 (A).
        }
        printf("%c", mensagem[i]);
        i += 1;
    }
    printf("\n");
} 

int main(){
    int num_casos;
    scanf("%i", &num_casos);
    for(int i = 0; i < num_casos; i++){
        char mensagem[50];
        scanf("%s", mensagem);
        while(getchar() != '\n');
        int num_shift;
        scanf("%i", &num_shift);
        decodifica_mensagem(mensagem, num_shift);    
    }

    return 0;
}
