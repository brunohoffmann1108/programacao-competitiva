// Este código resolve o problema 1105 do Beecrowd

#include <iostream>
using namespace std;

// Faz os cálculos com os valores fornecidos
char retorna_resultado(int num_bancos, int num_debentures, int reservas[20], int debentures[20][3]){ 
	for(int i = 0; i < num_debentures; i++){
		reservas[debentures[i][0] - 1] -= debentures[i][2]; // Diminui o saldo do devedor na quantidade que deve
		reservas[debentures[i][1] - 1] += debentures[i][2]; // Aumenta o saldo do credor na mesma quantidade da linha anterior
	}

	for(int i = 0; i < num_bancos; i++){
		if(reservas[i] < 0) return 'N';
	}

	return 'S';
}

int main(){
	int num_bancos;
	int num_debentures;
	int reservas[20];
	int debentures[20][3];
	
	cin >> num_bancos >> num_debentures;
	while(num_bancos != 0 || num_debentures != 0){
		// Leitura de reservas
		for(int i = 0; i < num_bancos; i++){
			cin >> reservas[i];
		}
		
		// Leitura de debentures
		for(int i = 0; i < num_debentures; i++){
			cin >> debentures[i][0] >> debentures[i][1] >> debentures[i][2];
		}

		// Retorna S ou N
		cout << retorna_resultado(num_bancos, num_debentures, reservas, debentures) << endl;

		// Leitura dos próximos valores ou encerrar
		cin >> num_bancos >> num_debentures;
	}
	
	return 0;
} 
