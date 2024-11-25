 // Este código resolve o problema 1147 do Beecrowd.
 
 #include <iostream>
 #include <string>
 using namespace std;

int main(){
  int contador = 0;
  string cavalheiro;
  getline(cin, cavalheiro);

  while(cavalheiro != "0"){
    contador += 1;
    // Calcula os movimentos de todos os peões e armazena-os.
    string peoes[8];
    string movimentos_peoes[16];
    int k = 0;
    for(int i = 0; i < 8; i++){
      getline(cin, peoes[i]);
      movimentos_peoes[k] = string(1, peoes[i][0] - 1) + string(1, peoes[i][1] + 1);
      k += 1;
      movimentos_peoes[k] = string(1, peoes[i][0] - 1) + string(1, peoes[i][1] - 1);
      k += 1;
    }

    // Calcula os movimentos do cavalo e armazena-os.
    k = 0;
    string movimentos_cavalheiro[8];
    for(int i = -2; i <= 2; i += 4){
      for(int j = -1; j <= 1; j += 2){
        movimentos_cavalheiro[k] = string(1, cavalheiro[0] + i) + string(1, cavalheiro[1] + j);
        k += 1;
        movimentos_cavalheiro[k] = string(1, cavalheiro[0] + j) + string(1, cavalheiro[1] + i);
        k += 1;
      }
    }

    // Elimina os movimentos inválidos.
    int movimentos_validos = 8;
    for(int i = 0; i < 8; i++){
      if(movimentos_cavalheiro[i][0] > 56 || movimentos_cavalheiro[i][0] < 49){
        movimentos_validos -= 1;
        continue;
      }
      if(movimentos_cavalheiro[i][1] > 'h' || movimentos_cavalheiro[i][1] < 'a'){
        movimentos_validos -= 1;
        continue;
      }
      for(int j = 0; j < 16; j++){
        if(movimentos_cavalheiro[i] == movimentos_peoes[j]){
          movimentos_validos -= 1;
          break;
        }
      }
    }
    cout << "Caso de Teste #" << contador << ": " << movimentos_validos << " movimento(s)."<< endl;

    getline(cin, cavalheiro);
  }

  return 0;
 }
