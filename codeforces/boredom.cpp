// Este código resolve o problema 455A (Boredom) do Codeforces.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    int maximo = 0;
    // Vetor que armazena o número de repetições de cada um dos valores de entrada.
    vector<int> frequencias;
    for(int i = 0; i < n; i++){
        int num = 0;
        cin >> num;
        // Se o número lido for maior que o maior número lido até agora.
        if(num > maximo){
            // Muda o tamanho do vetor de de frequências pro maior número que apareceu.
            frequencias.resize(num + 1);
            maximo = num;
        }
        frequencias.at(num) += 1;
    }
    // Vetor de pontos que armazena os pontos que cada valor faz, contando com a melhor possibilidade dos anteriores.
    // máximo + 1 pois o valor no índice 0 não é usado.
    vector<long long> pontos(maximo + 1, 0);
    pontos.at(1) = frequencias.at(1);
    long long pontos_maximos = pontos.at(1);
    if(maximo >= 2){
        pontos.at(2) = 2 * frequencias.at(2);
        pontos_maximos = max(pontos_maximos, pontos.at(2));
    }
    for(int i = 3; i < maximo + 1; i++){
        // Compara entre somar com 2 antes ou com 3 antes, caso existam índices com 0 pontos.
        pontos.at(i) = max((long long)i * (long long)frequencias.at(i) + pontos.at(i - 2), (long long)i * (long long)frequencias.at(i) + pontos.at(i - 3));
        pontos_maximos = max(pontos.at(i), pontos_maximos);
    }
    cout << pontos_maximos << endl;
    return 0;
}