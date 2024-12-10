// Este código resolve o problema 466A (Cheap Travel) do Codeforces.
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
    // Restante da divisão acima.
    int resto = viagens % viagens_ticket_m;

    // Calcula o preço com tickets_m para a quantidade possível, calculada anteriormente.
    int preco_com_m = preco_ticket_m * divisao;
    // Calcula a mesma coisa mas com o preço de tickets de viagem unitária.
    int preco_com_uma = preco_uma_viagem * viagens_ticket_m * divisao;
    int menor_preco = min(preco_com_m, preco_com_uma);

    // Caso haja um resto (divisão por ticket_m não foi exata), calcula se é melhor:
    if(resto > 0){
        // 1. Comprar mais um ticket_m, mesmo que sobrem viagens que não serão utilizadas.
        preco_com_m = preco_ticket_m;
        // 2. Comprar o restante com tickets de viagens unitárias.
        preco_com_uma = resto * preco_uma_viagem;
        menor_preco += min(preco_com_m, preco_com_uma); 
    }
    
    cout << menor_preco << endl;


    return 0;
}