// Este código resolve o problema 492B (Vanya and Lanterns) do Codeforces.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int num_lanternas = 0;
    int comprimento_rua = 0;
    cin >> num_lanternas >> comprimento_rua;
    vector<int> lanternas;
    // Itera adicionando as lanternas no vec lanternas.
    for(int i = 0; i < num_lanternas; i++){
        int lanterna_atual = 0;
        cin >> lanterna_atual;
        lanternas.push_back(lanterna_atual);
    }
    // Ordena do menor para maior.
    sort(lanternas.begin(), lanternas.end());

    float maior_distancia = 0; // Float pois dois raios juntos dividem o raio total por 2. pode dar 2.5, por exemplo.
    for(vector<int>::iterator iterador = lanternas.begin(); iterador != lanternas.end() - 1; iterador++){
        float distancia = *(iterador + 1) - *iterador;
        distancia /= 2;
        if(distancia > maior_distancia){
            maior_distancia = distancia;
        }
    }

    // Calcula a distância da primeira e última lanterna até os extremos da rua e determina o maior.
    // Os valores extremos são diferentes pois não dividem por dois, já que não há nenhuma lanterna antes ou depois.
    int distancia_extremos = comprimento_rua - lanternas.back();
    if(lanternas.front() > distancia_extremos){
        distancia_extremos = lanternas.front();
    }

    if(distancia_extremos > maior_distancia){
        maior_distancia = distancia_extremos;
    }

    // %.11f pois o problema usa um range de 10 números após a vírgula, mas estava dando errado com 10 no online judge.
    printf("%.11f\n", maior_distancia);

    return 0;
}