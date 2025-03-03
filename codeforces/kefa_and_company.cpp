#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

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


    return 0;
}