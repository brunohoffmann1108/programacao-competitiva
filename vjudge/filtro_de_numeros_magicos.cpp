// Este código resolve a questão "Filtro de Números Mágicos" do Vjudge.

#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    int casosDeTeste = 0;
    cin >> casosDeTeste;
    for(int i = 0; i < casosDeTeste; i++){
        int tamanhoArray = 0;
        cin >> tamanhoArray;
        unordered_set<int> numeros; // Tabela hash para saber se o valor já foi inserido.
        int variavelDeControle = 0; // Caso encontre um valor já inserido, muda de valor.
        for(int j = 0; j < tamanhoArray; j++){
            int numero = 0;
            cin >> numero;
            if(numeros.find(numero) != numeros.end()){ // Se encontrar o valor na tabela hash...
                variavelDeControle = 1; // ... A variável passa a ser 1 para sinalizar após o for.
            }
            else{
                numeros.insert(numero); // Se não, insere na tabela hash para sinalizar que já existe.
            }
        }
        variavelDeControle == 0 ? cout << "YES" << endl : cout << "NO" << endl;

    }
    return 0;
}