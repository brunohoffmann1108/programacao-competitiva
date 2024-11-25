// Este código resolve o problema 1089 do Beecrowd.

#include <iostream>
using namespace std;

int main(){
    int num_samples;
    cin >> num_samples;

    while(num_samples != 0){
        int* lista_samples = new int[num_samples + 2]; // Aloca um vetor com duas posições a mais.
        for(int i = 1; i <= num_samples; i++){
            cin >> lista_samples[i];
        }
        lista_samples[num_samples + 1] = lista_samples[1]; // posição final recebe primeiro valor inserido.
        lista_samples[0] = lista_samples[num_samples]; // Posição inicial recebe último valor inserido.

        int num_picos = 0;
        for(int i = 1; i <= num_samples; i++){
            if(lista_samples[i] < lista_samples[i - 1] && lista_samples[i] < lista_samples[i + 1]) num_picos += 1;
            else if(lista_samples[i] > lista_samples[i - 1] && lista_samples[i] > lista_samples[i + 1]) num_picos += 1;
        }
        cout << num_picos << endl;

        delete[] lista_samples;
        cin >> num_samples;
    }

    return 0;
}
