// Este código resolve o problema 455A (Boredom) do codeforces.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int quantidade_numeros = 0;
    cin >> quantidade_numeros;
    vector<int> frequencia_numeros; // Guarda quantas vezes o número de cada índice aparece.
    int maior_numero = 0; // Guarda o maior número lido até o momento, para determinar o tamanho do vetor de frequências.
    for(int i = 0; i < quantidade_numeros; i++){
        int numero_atual = 0;
        cin >> numero_atual;
        // Se o número que foi lido agora, for maior que o maior lido até o momento:
        if(numero_atual > maior_numero){
            // Define o maior número como o que acabou de ser lido e:
            maior_numero = numero_atual;
            // Atualiza o tamanho do vetor de frequências para o valor que acabou de ser lido.
            frequencia_numeros.resize(numero_atual + 1);
        }
        // Incrementa a quantidade de vezes que o número atual aparece.
        frequencia_numeros.at(numero_atual) += 1;
    }
    // Vetor que guarda os pontos feitos para cada número com base nos pontos já feitos com números anteriores.
    vector<long long> pontos_por_numero(maior_numero + 1, 0);
    pontos_por_numero.at(1) = (long long)frequencia_numeros.at(1);
    // Variável que guarda a quantidade máxima de pontos feitos até o momento. Começa sendo os feitos pelo 1.
    long long maximo_pontos = pontos_por_numero.at(1);
    for(int i = 2; i <= maior_numero; i++){
        // Calcula a quantidade de pontos feitos se somados os do número atual com o de duas posições atrás.
        long long pontos_atuais = (long long)i * (long long)frequencia_numeros.at(i) + pontos_por_numero.at(i - 2);
        // Compara se fará mais pontos com o atual ou o calculado antes, pois os dois não podem ser usados simultaneamente.
        pontos_por_numero.at(i) = max(pontos_atuais, pontos_por_numero.at(i - 1));
        // Por fim, compara se o resultado escolhido é maior que a maior pontuação até o momento.
        maximo_pontos = max(maximo_pontos, pontos_atuais);
    }
    cout << maximo_pontos << endl;
}