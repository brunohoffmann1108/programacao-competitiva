// Este código resolve o problema 1272 do Beecrowd

#include <iostream>
#include <limits>
#include <cctype>
using namespace std;

int main(){
    int num_casos;
    char mensagens[52];

    cin >> num_casos;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for(int i = 0; i < num_casos; i++){
        cin.getline(mensagens, 52);

        int j = 0;
        while(mensagens[j] != '\0'){
            if((j == 0 && isalpha(mensagens[j])) || (isblank(mensagens[j - 1]) && isalpha(mensagens[j]))){
                cout << mensagens[j];
            }
            j += 1;
        }
        cout << endl;
    }

    return 0;
}
