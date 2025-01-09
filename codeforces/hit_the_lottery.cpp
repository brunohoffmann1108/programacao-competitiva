// Este código resolve o problema 996A (Hit the Lottery) do Codeforces.

#include <iostream>
#include <vector>

int main(){
    std::vector<int> notas = {100, 20, 10, 5, 1}; // Vector para poder usar um for ao invés de uma abordagem por força bruta.
    int dinheiro = 0; // Armazena o dinheiro inicial e atualiza ao calcular.
    int num_notas = 0;
    std::cin >> dinheiro;
    // Cada iteração passa por um dos elementos do vetor notas.
    for(int i : notas){
        // Princial motivo para usar as notas armazenadas no vetor.
        if(dinheiro == 0){
            break;
        }
        num_notas += dinheiro / i;
        dinheiro %= i;
    }
    std::cout << num_notas << std::endl;

    return 0;
}