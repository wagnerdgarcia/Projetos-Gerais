/*
Projeto de Sinal de Transito Simples
*/

#define vermelho 4
#define amarelo 3
#define verde 2

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  digitalWrite(vermelho, HIGH);
  delay(1000);
  digitalWrite(amarelo, HIGH);
  delay(300);
  digitalWrite(verde, HIGH);
  delay(1000);

}

void loop() {
  for(int i = 0; i < 20; i++){
    switch(i){
      case (i%2 == 0):
        digitalWrite(vermelho, HIGH);
        digitalWrite(amarelo, LOW);
        break;
      case (i%3 == 0):
        digitalWrite(amarelo, HIGH);
        digitalWrite(verde, LOW);
        break;
      case (i%6 == 0):
        digitalWrite(verde, HIGH);
        digitalWrite(vermelho, LOW);
        break;
      }
        digitalWrite(vermelho, LOW);
        digitalWrite(verde, LOW);
        digitalWrite(amarelo, LOW);
    }
}
