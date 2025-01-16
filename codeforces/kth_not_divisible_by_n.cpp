// Este código resolve o problema 1352C (K-th Not Divisible by n) do Codeforces.

#include <iostream>
using namespace std;

int main(){
    int casos_de_teste = 0;
    cin >> casos_de_teste;
    for(int i = 0; i < casos_de_teste; i++){
        int divisor = 0; // Variável n no codeforces.
        int posicao = 0; // Variável k no codeforces.
        cin >> divisor >> posicao;
        int resultado = 0; // Guarda o resultado do código.
        if(posicao < divisor){
            // Pois não há nenhum número divisível por n nos k primeiros números. Logo, será igual a k.
            resultado = posicao;
        }
        else{
            // Se o divisor é 3, por exemplo, teremos um intervalo de 2 números que não são divisíveis por 3, entre os divisíveis.
            int intervalo = divisor - 1;
            // Quantidade de intervalos de 2 em 2 para dar k números.
            int num_intervalos = posicao / intervalo;
            // Deve ser somado no final.
            int resto = posicao % intervalo;
            /* 
            Exemplo, no 15º número não divisível por 3:
            intervalo de 2 (não divisíveis) aparece 7 vezes: 1 e 2, 4 e 5, 7 e 8, 10 e 11...
            Nesse meio tempo, passamos também por 3, 6, 9, 12, 15, 18 e 21, que são divisíveis e devem ser contabilizados também.
            Então temos os 7 intervalos de 2 (14 números + 1 de resto), somados aos 7 números divisíveis que aparecem no meio
            Com isso temos 7(divisíveis) + 15(não divisíveis) = 22.
            */
            resultado = (intervalo * num_intervalos) + resto + num_intervalos;
            // Caso o resto seja 0, um dos números divisíveis não será contabilizado, pois a posição está no intervalo de não divisíveis.
            if(resto == 0){
                resultado -= 1;
            }
            }
        cout << resultado << endl;
        }
    }
