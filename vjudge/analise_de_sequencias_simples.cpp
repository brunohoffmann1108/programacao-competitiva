#include <iostream>
using namespace std;

int main(){
    int casosTeste = 0;
    cin >> casosTeste;
    for(int i = 0; i < casosTeste; i++){
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        
        // Se for 1 é pq a soma resulta na condição pedida na questão.
        int validacao = 0;
        if(a + b == c || a + c == b || b + c == a){
            validacao = 1;
        }

        validacao == 1 ? cout << "YES" << endl : cout << "NO" << endl;
    }   
}