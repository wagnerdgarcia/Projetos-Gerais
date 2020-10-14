/*
   Importando as Bibliotecas
*/
#include <IRremote.h>

IRrecv controle(11);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  controle.enableIRIn(); // Inicializa o receptor IR
}

void loop() {
  delay(1000);
  if (controle.decode(&results)) {
    //Serial.print("Valor Lido: ");
    //Serial.println(results.value, HEX);
    controle.resume(); //Le o próximo valor
    if (results.value == 16753245){
      Serial.print("Tecla 1 = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16736925){
      Serial.print("Tecla 2 = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16769565){
      Serial.print("Tecla 3 = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16720605){
      Serial.print("Tecla 4 = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16712445){
      Serial.print("Tecla 5 = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16761405){
      Serial.print("Tecla 6 = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16769055){
      Serial.print("Tecla 7 = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16754775){
      Serial.print("Tecla 8 = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16748655){
      Serial.print("Tecla 9 = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16750695){
      Serial.print("Tecla 0 = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16738455){
      Serial.print("Tecla * = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16756815){
      Serial.print("Tecla # = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16718055){
      Serial.print("Tecla Cima = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16730805){
      Serial.print("Tecla Baixo = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16734885){
      Serial.print("Tecla Direita = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16716015){
      Serial.print("Tecla Esquerda = ");
      Serial.println((int)results.value);
    }
    else if (results.value == 16726215){ 
      Serial.print("Tecla OK = ");
      Serial.println((int)results.value);
    }
    //else Serial.println("Aperte Novamente!");
  }
}
