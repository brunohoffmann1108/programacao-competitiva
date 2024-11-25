// Este código resolve o problema 1222 do Beecrowd

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main(){
    int num_palavras;
    int linhas_ppg;
    int char_plinha; 

    while(cin >> num_palavras){
        cin >> linhas_ppg >> char_plinha;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string historia;
        getline(cin, historia);
        int linhas = 0;

        while(historia.size() > 0){

            // Se quantidade de caracteres na string < quantidade máxima numa linha.
            if(historia.size() <= (unsigned)char_plinha){ 
                historia.erase(0, historia.size());
            }

            // Se caractere máximo for espaço.
            else if(historia[char_plinha - 1] == ' '){ 
                historia.erase(0, char_plinha);
            }

            // Se um caractere após máximo for espaço.
            else if(historia[char_plinha] == ' '){ 
                historia.erase(0, char_plinha + 1);
            }

            // Se a palavra começar e não terminar (Conta apenas até a palavra anterior).
            else{ 
                int i = char_plinha - 1;
                while(historia[i] != ' '){
                    i -= 1;
                }
                historia.erase(0, i + 1);
            }
            
            linhas += 1;
        }
        int paginas = linhas / linhas_ppg;
        if(linhas % linhas_ppg > 0) paginas += 1;
        cout << paginas << endl;
    }

    return 0;
}
