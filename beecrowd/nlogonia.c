// Este código resolve o problema 1091 do Beecrowd.
#include <stdio.h>

int main(){
    int num_testes;
    scanf("%i", &num_testes);
    do{
        if(num_testes==0)break;
            int xponto, yponto;
            scanf("%i %i", &xponto, &yponto);
            for(int i = 0; i < num_testes; i++){
                int casa[2];
                scanf("%i %i", &casa[0], &casa[1]);
                if(casa[0] > xponto && casa[1] > yponto) printf("NE\n");
                else if(casa[0] < xponto && casa[1] > yponto) printf("NO\n");
                else if(casa[0] < xponto && casa[1] < yponto) printf("SO\n");
                else if(casa[0] > xponto && casa[1] < yponto) printf("SE\n");
                else if(casa[0] == xponto || casa[1] == yponto) printf("divisa\n");       
            }
        
        scanf("%i", &num_testes);
    } while(num_testes);
    return 0;
} 
