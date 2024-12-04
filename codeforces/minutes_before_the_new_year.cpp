// Este código resolve o problema 1283A (Minutes before the new year) do Codeforces.

#include <iostream>
using namespace std;

int main(){
    int casos = 0;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int horas = 0;
        int minutos = 0;
        cin >> horas >> minutos;

        int minutos_um_dia = 1440; // Quantidade de minutos em um dia (24 horas).
        int minutos_totais = 60 * horas + minutos; // Quantidade de minutos no determinado horário fornecido.

        int minutos_restantes = minutos_um_dia - minutos_totais; // Restante = Totais - que_já_foram.
        cout << minutos_restantes << '\n';
    }

    return 0;
}