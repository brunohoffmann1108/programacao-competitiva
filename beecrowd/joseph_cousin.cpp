// Este código resolve o problema 1032 do Beecrowd

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int qtd_pessoas;
    cin >> qtd_pessoas;

    while(qtd_pessoas != 0){
        // Cria um vetor com o posições de 1 a 'qtd_pessoas'.
        int pessoas[3501];
        for(int i = 0; i < qtd_pessoas; i++){
            pessoas[i] = i + 1;
        }

        int iterador_fixo = -1; // Permanece na posição em que parou. "Mata" a pessoa da posição em que para.
        int j = 3; // número inicial que será testado como primo. Aumenta ao longo do código.
        int guarda_j = j;

        // Especificamente para o caso do número 2.
        if(qtd_pessoas > 1){
            iterador_fixo += 2;
            for(int k = iterador_fixo; k < qtd_pessoas - 1; k++){
                pessoas[k] = pessoas[k + 1];
            }
            qtd_pessoas -= 1;
            iterador_fixo -= 1;
        }

        while(qtd_pessoas > 1){
            // Testa se é primo.
            for(int k = 3; k <= sqrt(j); k += 2){ 
                if(j % k == 0){ // Se for divisível não é primo.
                    j += 2;
                    k = 1;
                }
            }
            guarda_j = j;

            // Caso esteja ao longo do vetor, diminui do j o que falta para iterar e posiciona o iterador no início
            if(iterador_fixo + 1 + j > qtd_pessoas){
                guarda_j -= qtd_pessoas - (iterador_fixo + 1);
                iterador_fixo = -1;
            }
            guarda_j -= qtd_pessoas * (guarda_j / qtd_pessoas); // Diminui de j a quantidade de vezes q itera totalmente pelo vetor
            if(guarda_j == 0) iterador_fixo = qtd_pessoas - 1;
            else iterador_fixo += guarda_j;

            for(int k = iterador_fixo; k < qtd_pessoas - 1; k++){
                pessoas[k] = pessoas[k + 1];
            }
            qtd_pessoas -= 1;
            j += 2;
            iterador_fixo -= 1;
        }

        cout << pessoas[0] << endl;
        cin >> qtd_pessoas;
    }
    
    return 0;
}    