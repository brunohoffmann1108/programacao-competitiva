#include <iostream>
using namespace std;

int main(){
    int casos_teste = 0;
    cin >> casos_teste;
    for(int i = 0; i < casos_teste; i++){
        int n = 0;
        long long k = 0;
        cin >> n >> k;
        int nao_divisiveis = 0;
        int num_atual = 0;
        while(nao_divisiveis < k){
            num_atual += 1;
            if(num_atual % n > 0){
                nao_divisiveis += 1;
            }
        }
        cout << num_atual << endl;
    }
}