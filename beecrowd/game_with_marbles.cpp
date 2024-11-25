// Este código resolve o problema 1647 do Beecrowd

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int num_tigelas;
    int tigelas[50];
    long long passos = 0;

    cin >> num_tigelas;
    while(num_tigelas != 0){
        passos = 0;
        for(int i = 0; i < num_tigelas; i++){
            cin >> tigelas[i];
            passos += tigelas[i] * pow(2, i); // Fatorial do expoente de base 2 multiplicado pelo número de bolas na tigela. 
        }
        
        cout << passos << endl;
        cin >> num_tigelas;
    }
    

    return 0;
}
