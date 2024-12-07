#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int num_lanternas = 0;
    int comprimento_rua = 0;
    cin >> num_lanternas >> comprimento_rua;
    vector<int> lanternas;
    for(int i = 0; i < num_lanternas; i++){
        int lanterna_atual = 0;
        cin >> lanterna_atual;
        lanternas.push_back(lanterna_atual);
    }
    sort(lanternas.begin(), lanternas.end());

    float maior_distancia = 0;    
    for(vector<int>::iterator iterador = lanternas.begin(); iterador != lanternas.end() - 1; iterador++){
        float distancia = *(iterador + 1) - *iterador;
        distancia /= 2;
        cout << distancia << endl;
        if(distancia > maior_distancia){
            maior_distancia = distancia;
        }
    }
    cout << endl;

    int distancia_extremos = comprimento_rua - lanternas.back();
    if(lanternas.front() > distancia_extremos){
        distancia_extremos = lanternas.front();
    }

    if(distancia_extremos > maior_distancia){
        maior_distancia = distancia_extremos;
    }

    printf("%.10f\n", maior_distancia);

    return 0;
}