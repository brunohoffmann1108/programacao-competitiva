// Este código resolve o problema 1279 do Beecrowd

#include <stdio.h>

int main(){
    char ano[10000];
    int soma_par = 0, soma_impar = 0, i;
    int leap = 0, huluculu = 0, bulukulu = 0;
    int parte = 0;

    while(scanf("%s", ano) != EOF){
        if(soma_impar != 0 || soma_par != 0) printf("\n");
        soma_impar = soma_par = huluculu = bulukulu = leap = 0;
        for(i = 0; i < 10000; i++){
            if(ano[i] == '\0') break;
            if((i + 1) % 2 == 0) soma_par += ano[i] - '0';
            else soma_impar += ano[i] - '0';
        }
        i -= 1;

        // Últimos 4 digitos do ano fornecido
        parte = (ano[i] - '0') + (ano[i-1] - '0')*10 + (ano[i-2] - '0')*100 + (ano[i-3] - '0')*1000;
        // Validação Huluculu
        if((ano[i] - '0') % 5 == 0 && (soma_impar + soma_par) % 3 == 0) huluculu = 1;
        // Validação Leap
        if(parte % 4 == 0){
            if(parte % 100 != 0) leap = 1;
            else if(parte % 400 == 0) leap = 1;
        }
        // Validação Bulukulu
        if((soma_impar - soma_par) % 11 == 0 && parte % 5 == 0 && leap == 1) bulukulu = 1;
        // Print
        if(leap == 0 && huluculu == 0 && bulukulu == 0) printf("This is an ordinary year.\n");
        if(leap == 1) printf("This is leap year.\n");
        if (huluculu == 1) printf("This is huluculu festival year.\n");
        if(bulukulu == 1) printf("This is bulukulu festival year.\n");
    }

    return 0;
}