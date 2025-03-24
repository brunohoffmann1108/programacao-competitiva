#include <iostream>
#include <string>
using namespace std;

int main(){
    int numPalavras = 0;
    cin >> numPalavras;
    for(int i = 0; i < numPalavras; i++){
        string palavra;
        cin >> palavra;
        string output; // Vai ser a palavra formatada para o formato requerido pela questão.
        if(palavra.size() <= 10){
            output = palavra;
        }
        else{
            output += palavra[0];
            output += to_string(palavra.size() - 2); // Transforma o (número de caracteres - 2) da palavra em string e concatena em output.
            output += palavra.back(); // Concatena o último elemento da string palavra.
        }
        cout << output << endl;
    }

    return 0;
}