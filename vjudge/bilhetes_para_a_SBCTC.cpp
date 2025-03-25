#include <iostream>
using namespace std;

int main(){
    int numeroIngressos = 0;
    cin >> numeroIngressos;
    if(numeroIngressos % 2 == 0 && numeroIngressos > 2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}