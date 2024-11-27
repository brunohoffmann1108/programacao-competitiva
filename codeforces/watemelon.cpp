// Este código resolve o problema 4A do Codeforces.

#include <iostream>
using namespace std;

int main(){
    int peso = 0;
    cin >> peso;
    // Para todos os pares maiores que 2, uma combinação de pares pode ser feita.
    if(peso % 2 == 0 && peso > 2){ 
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }

    return 0;
}