#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    // Leitura dos valores utilizados no problema;
    int viagens = 0;
    int viagens_ticket_m = 0;
    int preco_uma_viagem = 0;
    int preco_ticket_m = 0;
    cin >> viagens >> viagens_ticket_m >> preco_uma_viagem >> preco_ticket_m;

    // Número total de viagens dividido pelo número de viagens que um ticket_m cobre.
    int divisao = viagens / viagens_ticket_m;
    int resto = viagens % viagens_ticket_m;

    int menor_preco = 0;
    int preco_com_m = 0;
    int preco_com_uma = 0;
    if(divisao > 0 && resto == 0){
        preco_com_m = preco_ticket_m * divisao;
        preco_com_uma = preco_uma_viagem * viagens;
        menor_preco = min(preco_com_m, preco_com_uma);
    }
    else if(divisao > 0 && resto > 0){
        preco_com_m = preco_ticket_m * divisao;
        preco_com_uma = preco_uma_viagem * viagens_ticket_m * divisao;
        menor_preco = min(preco_com_m, preco_com_uma);
        int restante = resto * preco_uma_viagem;
        if(restante < preco_ticket_m){
            menor_preco += restante;
        }
        else{
            menor_preco += preco_ticket_m;
        }
    }
    else{
        preco_com_uma = resto * preco_uma_viagem;
        menor_preco = min(preco_com_uma, preco_ticket_m);
    }

    cout << menor_preco << endl;


    return 0;
}