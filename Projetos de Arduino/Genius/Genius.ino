/***************************************************************/
/* Centro de Informática - Universidade Federal da Paraíba     */
/* Discente: Wagner Dantas Garcia - wagnergarcia@cc.ci.ufpb.br */
/* Data de Criação: 16/06/2019                                 */
/***************************************************************/
/* Robô com 3 Sensores Ultrasonico                             */
/***************************************************************/

/* Define os Pinos */

#define led_V 2   // LED Vermelho
#define led_A 3   // LED Ammarelo
#define led_Ve 4  // LED Verde
#define led_Az 5  // LED Azul

#define botao_V 8   // Botao Vermelho
#define botao_A 9   // Botao Amarelo
#define botao_Ve 10 // Botao verde
#define botao_Az 11 // Botao Azul

/* Define as Variaveis Globais */
int lista[10];
int listaAux[10];
int cont;
bool botao = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(botao_V, INPUT);
  pinMode(botao_A, INPUT);
  pinMode(botao_Ve, INPUT);
  pinMode(botao_Az, INPUT);
  pinMode(led_V, OUTPUT);
  pinMode(led_A, OUTPUT);
  pinMode(led_Ve, OUTPUT);
  pinMode(led_Az, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  for (int i = 0; i < 10; i++) {
    lista[i] = random(1, 5);
    Serial.print("Lista[");
    Serial.print(i);
    Serial.print("] = ");
    Serial.println(lista[i]);
  }
  delay(2000);
}

void loop() {
  Serial.println(digitalRead(botao_A));
  if ((digitalRead(botao_V) == HIGH) && (cont < 10)){
    listaAux[cont] = 1;
    cont++;
  }
  else if ((digitalRead(botao_A) == HIGH) && (cont < 10)){
    listaAux[cont] = 2;
    cont++;
  }
  else if ((digitalRead(botao_Ve) == HIGH) && (cont < 10)) {
    listaAux[cont] = 3;
    cont++;
  }
  else if ((digitalRead(botao_Az) == HIGH) && (cont < 10)) {
    listaAux[cont] = 4;
    cont++;
  }
  while ((digitalRead(botao_V) == HIGH) || (digitalRead(botao_Az) == HIGH) || (digitalRead(botao_Ve) == HIGH) || (digitalRead(botao_Az) == HIGH)){
    Serial.println("botao apertado!");
  }
  for (int i = 0; i < cont; i++){
      Serial.print("Lista[");
      Serial.print(i);
      Serial.print("] = ");
      Serial.println(listaAux[i]);
    }
    
    for (int i = 0; i < 3; i++) {
    digitalWrite(led_V, HIGH);
    digitalWrite(led_A, HIGH);
    digitalWrite(led_Ve, HIGH);
    digitalWrite(led_Az, HIGH);
    delay(500);
    digitalWrite(led_V, LOW);
    digitalWrite(led_A, LOW);
    digitalWrite(led_Ve, LOW);
    digitalWrite(led_Az, LOW);
    delay(250);
    }
    for (int i = 0; i < cont; i++) {
    switch (listaAux[i]) {
      case 1:
        digitalWrite(led_V, HIGH);
        break;
      case 2:
        digitalWrite(led_A, HIGH);
        break;
      case 3:
        digitalWrite(led_Ve, HIGH);
        break;
      case 4:
        digitalWrite(led_Az, HIGH);
        break;
    }
    delay(1000);
    digitalWrite(led_V, LOW);
    digitalWrite(led_A, LOW);
    digitalWrite(led_Ve, LOW);
    digitalWrite(led_Az, LOW);
    delay(500);
    }

}
