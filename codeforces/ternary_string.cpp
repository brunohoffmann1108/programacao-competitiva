// Este código resolve o problema 1354B do Codeforces.

#include <iostream>
#include <string>
using namespace std;

int main(){
    int casos_de_teste = 0;
    cin >> casos_de_teste;
    cin.ignore(); // Remove \n.
    for(int i = 0; i < casos_de_teste; i++){
        string sequencia;
        getline(cin, sequencia);
        // Guarda o primeiro caractere para fins de comparação posteriormente.
        char anterior = sequencia[0]; 
        // j = 1 para começar do segundo, já que temos o primeiro na linha 14.
        int j = 1; 
        // Itera até encontrar a primeira diferença entre dois caracteres seguidos (requisito para menor substring possível).
        while(sequencia[j] != '\0' && sequencia[j] == anterior){
            j += 1;
        }

        // 1 a mais que o limite para o if no fim do código.
        int menor_sbstr = 200001; 
        // guarda o caractere atual (agora temos o anterior e o atual, para sabermos quando resetar ou finalizar uma sequência).
        char atual = sequencia[j];
        // Começa com 2 pois o atual e anterior, cada um, contam como 1.
        int quantidade = 2;
        
        j += 1;
        while((unsigned int)j < sequencia.size()){
            quantidade += 1;
            // Se o caractere no índice j for igual ao primeiro na substring (variável 'anterior'), recomeça, pois há uma substring menor.
            if(sequencia[j] == anterior){
                anterior = atual;
                atual = sequencia[j];
                quantidade = 2;
            }
            // Se o caractere no índice j for diferente do atual e anterior (ou seja, o que faltava), uma substring foi encontrada.
            else if(sequencia[j] != anterior && sequencia[j] != atual){
                // Só vai substituir o valor printado no fim se for menor que a menor substring já encontrada até agora.
                if(quantidade < menor_sbstr){
                    menor_sbstr = quantidade;
                }
                // Reseta variáveis para continuar procurando substrings.
                quantidade = 2;
                anterior = atual;
                atual = sequencia[j];
            }
            j += 1;
        }

        if(menor_sbstr == 200001){
            menor_sbstr = 0;
        }
        cout << menor_sbstr << endl;

    }
    return 0;
}