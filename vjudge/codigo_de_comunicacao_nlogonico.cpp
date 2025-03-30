#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    string sequencia; // Entrada do usuário.
    cin >> sequencia;
    string apenasNumeros; // Separa os números sozinhos.

    // Adiciona à string apenasNumeros se for um dígito numérico.
    for(auto i : sequencia){
        if(isdigit(i)){
            apenasNumeros += i;
        }
    }
    sort(apenasNumeros.begin(), apenasNumeros.end()); // Ordena a string.
    int i = 0, j = 0; // Iteradores que percorrerão as duas strings.
    while(i < sequencia.size()){
        sequencia.at(i) = apenasNumeros.at(j); // Substitui a original pela ordenada.
        j += 1;
        i += 2; // Pula o símbolo '+'.
    }
    cout << sequencia << endl;    


    return 0;
}