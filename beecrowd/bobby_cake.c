// Este código resolve o problema 1631 do Beecrowd

#include <stdio.h>
#include <math.h>

int main(){
    int num_cerejas;
    int x[100], y[100];
    float a, b, c;
    float menor_dist = 10000;
    float soma_d = 0, soma_e = 0;
    float subtracao;

    while(scanf("%i", &num_cerejas) == 1 && num_cerejas != 0){
        menor_dist = 10000;

        // Recebendo coordenadas dos pontos
        for(int i = 0; i < num_cerejas; i++){
            scanf("%i %i", &x[i], &y[i]);
        }  

        //Conecta dois pontos i e j, formando uma reta
        for(int i = 0; i < num_cerejas; i++){
            for(int j = i + 1; j < num_cerejas; j++){
                // Calcula os coeficientes da equação geral da reta
                a = y[i] - y[j];
                b = x[j] - x[i];
                c = x[i]*y[j] - y[i]*x[j];
                // Calcula a distância de todos os demais pontos até a reta
                for(int k = 0; k < num_cerejas; k++){
                    if((x[k] == x[i] && y[k] == y[i]) || (x[k] == x[j] && y[k] == y[j])) continue; // Para não calcular com pontos i e j
                    // Determina o x para que o ponto esteja na reta em função do seu y
                    float xideal = -1*(b*y[k] + c)/a; 
                    if (x[k] == xideal) continue; // Distância = 0
                    // Direita ou esquerda
                    if (x[k] > xideal) soma_d += fabs(a*x[k] + b*y[k] + c)/sqrt(a*a + b*b);
                    else if(x[k] < xideal) soma_e += fabs(a*x[k] + b*y[k] + c)/sqrt(a*a + b*b);
                }
                // Compara subtração atual com o menor valor e reseta as somas 
                subtracao = fabs(soma_e - soma_d);
                if(subtracao < menor_dist) menor_dist = subtracao;
                soma_d = 0;
                soma_e = 0;
            }
        }
        printf("%.3f\n", menor_dist);
    }
    return 0;
}