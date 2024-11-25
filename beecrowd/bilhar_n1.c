#include <stdio.h>
#include <math.h>

// Struct de menor bola para fins de organização.
typedef struct bola{
    float distancia;
    int numero_da_bola;
} bola;

// Calcula a distância entre uma bola n e a bola branca.
float calcula_distancia(float x_branca, float y_branca, float x_bola, float y_bola){
    // Distâncias x e y são as diferenças entre a branca e a bola n
    float distancia_x = fabs(x_branca - x_bola); 
    float distancia_y = fabs(y_branca - y_bola);

    // Pitágoras com as distâncias x e y.
    float distancia_bolas = sqrt(distancia_x*distancia_x + distancia_y*distancia_y);

    return distancia_bolas;
}

int main(){
    int num_de_casos = 0;
    scanf("%i", &num_de_casos);
    for(int i = 0; i < num_de_casos; i++){
        // Reseta a menor bola à cada caso de teste.
        bola menor;
        menor.distancia = 4000;
        menor.numero_da_bola = 0;

        int num_de_bolas = 0;
        scanf("%i", &num_de_bolas);
        
        // Lê a bola branca separadamente das demais.
        int x_branca = 0;
        int y_branca = 0;
        scanf("%i %i", &x_branca, &y_branca);

        // Calcula a distância de cada uma das bolas em relação a bola branca e guarda a menor.
        for(int j = 0; j < num_de_bolas; j++){
            int x_bola = 0;
            int y_bola = 0;
            scanf("%i %i", &x_bola, &y_bola);

            float distancia_bolas = calcula_distancia((float)x_branca, (float)y_branca, (float)x_bola, (float)y_bola); // Cast explícito para float, para a conta dar certo dentro da função.
            // Usa a struct para guardar os dados da menor bola.
            if(distancia_bolas < menor.distancia){
                menor.distancia = distancia_bolas;
                menor.numero_da_bola = j + 1;
            }
        }
        printf("%i\n", menor.numero_da_bola);
    }

    return 0;
}