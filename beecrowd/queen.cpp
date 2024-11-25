// Este código resolve o problema 1087 do Beecrowd

#include <iostream>
#include <cmath>
using namespace std;

int calcula_movimentos(int x1, int y1, int x2, int y2){
    if(x2 - x1 == 0 && y2 - y1 == 0){
        return 0;
    }
    if(x2 - x1 == 0 || y2 - y1 == 0){
        return 1;
    }
    if(abs(((float)y2 - (float)y1)/((float)x2 - (float)x1)) == 1){
        return 1;
    }
    return 2;
}
    
int main(){
    int x1, y1;
    int x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    while(x1 != 0 || y1 != 0 || x2 != 0 || y2 != 0){
        cout << calcula_movimentos(x1, y1, x2, y2) << endl;
        cin >> x1 >> y1 >> x2 >> y2;
    }

    return 0;
}