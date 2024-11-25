// Este código resolve o problema 1726 do Beecrowd

#include <iostream>
#include <string>
using namespace std;

int inicio_operacao;
int fim_operacao;

void ordena_equacao(int sequencia[100], int tamanho){
    for(int j = 1; j < tamanho; j++){
        int chave = sequencia[j];
        int i = j - 1;
        while(i > -1 && sequencia[i] > chave){
            sequencia[i + 1] = sequencia[i];
            i -= 1;
        }
        sequencia[i + 1] = chave;
    }
}

string separa_elementos(string operacao, int opcao, int posicao_operacao){
    string invertido;
    string elemento;

    // Separa elemento esquerdo da operação
    if(opcao == 0){
        int i = posicao_operacao - 1;
        while(operacao[i] != '{'){
            i -= 1;
            if(operacao[i] == '{'){
                int* pinicio = &inicio_operacao;
                *pinicio = i;
            }
            else invertido += operacao[i];
        }
        for(int j = invertido.size() - 1; j > -1; j--){
            elemento += invertido[j];
        }
        return elemento;
    }

    // Separa elemento direito da operação
    else{
        int i = posicao_operacao + 1;
        while(operacao[i] != '}'){
            i += 1;
            if(operacao[i] == '}'){
                int* pfim = &fim_operacao;
                *pfim = i;
            }
            else elemento += operacao[i];
        }
        return elemento;
    }

    return "";
}

string intersec_elementos(string elemento1, string elemento2){
    string resultado = "{";
    for(unsigned i = 0; i < elemento1.size(); i++){
        if(elemento2.find(elemento1[i]) != string::npos){
            resultado += elemento1[i];
        }
    }

    return resultado += '}';
}

string soma_elementos(string elemento1, string elemento2){
    string resultado = "{" + elemento1;
    for(unsigned i = 0; i < elemento2.size(); i++){
        if(elemento1.find(elemento2[i]) == string::npos){
            resultado += elemento2[i];
        }
    }

    return resultado += '}';
}

string subtrai_elementos(string elemento1, string elemento2){
    string resultado = "{";
    for(unsigned i = 0; i < elemento1.size(); i++){
        if(elemento2.find(elemento1[i]) == string::npos){
            resultado += elemento1[i];
        }
    }

    return resultado += '}';
}

string substitui_na_string(string operacao, string substring, int inicio, int fim){
    string resto_operacao = operacao.substr(fim + 1, operacao.size());

    for(unsigned i = 0; i < substring.size(); i++){
        operacao[i + inicio] = substring[i];
    }
    operacao.resize(substring.size() + inicio);
    operacao += resto_operacao;

    return operacao;
}

int main(){
    string equacao_principal;
    string elemento1;
    string elemento2;
    string resultado;

    int intersec[55], itcc = -1;
    int soma_sub[55], ss = -1;

    getline(cin, equacao_principal);
    int tamanho_equacao = equacao_principal.size();

    // Conta a quantidade de cada operação e guarda posição na string
    for(unsigned i = 0; i < equacao_principal.size(); i++){
        if(equacao_principal[i] == '*'){
            itcc += 1;
            intersec[itcc] = i;
        }
        else if(equacao_principal[i] == '+' || equacao_principal[i] == '-'){
            ss += 1;
            soma_sub[ss] = i;
        }
    }

    for(int i = 0; i <= itcc; i++){
        // Separa elementos, intersecta e substitui resultado na string principal
        elemento1 = separa_elementos(equacao_principal, 0, intersec[i]);
        elemento2 = separa_elementos(equacao_principal, 1, intersec[i]);
        resultado = intersec_elementos(elemento1, elemento2);
        equacao_principal = substitui_na_string(equacao_principal, resultado, inicio_operacao, fim_operacao);
        cout << equacao_principal << endl;

        for(int j = 0; j < 55; j++){
            if(j > itcc && j > ss) break;
            if(j <= itcc && j != i && intersec[j] > intersec[i]){
                intersec[j] -= (tamanho_equacao - equacao_principal.size());
            }
            if(j <= ss && soma_sub[j] > intersec[i]){
                soma_sub[j] -= (tamanho_equacao - equacao_principal.size());
            }
        }

        // Modifica tamanho da string principal para valor após substituição
        tamanho_equacao = equacao_principal.size();
    }

    for(int i = 0; i <= ss; i++){
        // Separa elementos, soma/subtrai e substitui resultado na string principal
        if(equacao_principal[soma_sub[i]] == '+'){
            elemento1 = separa_elementos(equacao_principal, 0, soma_sub[i]);
            elemento2 = separa_elementos(equacao_principal, 1, soma_sub[i]);
            resultado = soma_elementos(elemento1, elemento2);
        }
        else if(equacao_principal[soma_sub[i]] == '-'){
            elemento1 = separa_elementos(equacao_principal, 0, soma_sub[i]);
            elemento2 = separa_elementos(equacao_principal, 1, soma_sub[i]);
            resultado = subtrai_elementos(elemento1, elemento2);
        }
        equacao_principal = substitui_na_string(equacao_principal, resultado, inicio_operacao, fim_operacao);
        cout << equacao_principal << endl;

        // Atualiza posições das outras operações após modificação da string
        for(int j = 0; j <= ss; j++){
            if(j != i && soma_sub[j] > soma_sub[i]){
                soma_sub[j] -= (tamanho_equacao - equacao_principal.size());
            }
        }

        // Modifica tamanho da string principal para valor após substituição
        tamanho_equacao = equacao_principal.size();
    }

    int equacao_ascii[100];
    for(unsigned i = 1; i < equacao_principal.size() - 1; i++){
        equacao_ascii[i - 1] = equacao_principal[i];
    }

    ordena_equacao(equacao_ascii, equacao_principal.size() - 2);

    for(unsigned i = 0; i < equacao_principal.size() - 2; i++){
        equacao_principal[i+1] = char(equacao_ascii[i]);
    }

    cout << equacao_principal << endl;

    return 0;
}