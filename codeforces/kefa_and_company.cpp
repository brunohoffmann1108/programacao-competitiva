// Este código resolve o problema 580B (Kefa and Company) do Codeforces.

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// Função utilizada para a ordenação funcionar corretamente.
bool comparadorSort(pair<int, int> primeiro, pair<int, int> segundo){
    return primeiro.first < segundo.first;
}

int main(){
    int numAmigos = 0;
    int diferencaDinheiro = 0;
    cin >> numAmigos >> diferencaDinheiro;
    vector<pair<int, int>> amigos(numAmigos); // Vetor de pares com dinheiro e fator de amizade de cada amigo.

    // Lê os valores de dinheiro e amizade de cada amigo.
    for(int i = 0; i < numAmigos; i++){
        cin >> amigos.at(i).first >> amigos.at(i).second;
    }

    // Ordena o vetor de amigos com base no primeiro valor do par (quantidade de dinheiro).
    sort(amigos.begin(), amigos.end(), comparadorSort);

    // Já inicia com primeiro sendo o maior e o atual sendo igual o maior.
    long long valorMax = amigos.at(0).second;
    long long valorAtual = valorMax;

    // Começa a iterar pelo segundo por conta da situação acima.
    auto it = amigos.begin() + 1;
    auto inicio = amigos.begin();
    while(it != amigos.end()){
        if(abs(it->first - inicio->first) >= diferencaDinheiro){ // Se a diferença entre os dinheiros for maior ou igual o valor para sentir pobre.
            valorAtual -= inicio->second;
            inicio += 1;
            continue; // Não avança o it para o próximo valor. Remove anteriores até chegar num compatível ou em si mesmo.
        }
        else{
            valorAtual += it->second;
            if(valorAtual > valorMax){
                valorMax = valorAtual;
            }
            it += 1; // Agora sim, avança o iterador para comparar com o próximo amigo (mais rico).
        }
    }

    cout << valorMax << endl;

    return 0;
}