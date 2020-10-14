/*
 * Centro de Informática - Universidade Federal da Paraíba     
 * Discente: Wagner Dantas Garcia - wagnergarcia@cc.ci.ufpb.br 
 * Data de Criação: 16/06/2019                                 
 ***************************************************************
 * Robô Seguidor de linha
 */

/*
 Anotação:
 No preto o valor do Sensor é maior
 No Branco o valor do Sensor é menor
 */

/* Define os Pinos */

#define MotorB_H 8
#define MotorB_A 9
#define MotorA_H 10
#define MotorA_A 11
#define LinhaD A0
#define LinhaE A1
#define VelocidadeA A2
#define VelocidadeB A3


/* Prototipos */
void frente();
void direita();
void esquerda();
void parar();
void re();

void setup() {
  pinMode(LinhaD, INPUT);
  pinMode(LinhaE, INPUT);
  pinMode(VelocidadeA, OUTPUT);
  pinMode(VelocidadeB, OUTPUT);
  pinMode(MotorB_H, OUTPUT);
  pinMode(MotorB_A, OUTPUT);
  pinMode(MotorA_H, OUTPUT);
  pinMode(MotorA_A, OUTPUT);
  Serial.begin(9600);
  Serial.println("Lendo dados do Sensor...");
}

void loop() {
    int sensorD, sensorE;
    sensorD = analogRead(LinhaD);
    sensorE = analogRead(LinhaE);

    Serial.print("\nO Sensor Direito\t-\t");  Serial.println(sensorD);
    Serial.print("O Sensor Esquerdo\t-\t"); Serial.println(sensorE);
    analogWrite(VelocidadeA, 256);
    analogWrite(VelocidadeB, 256);

    if       ((sensorD < 100) && (sensorE < 100)) frente();
    else if  ((sensorD < 100) && (sensorE > 100)) esquerda();
    else if  ((sensorD > 100) && (sensorE < 100)) direita();
    else if  ((sensorD > 100) && (sensorE > 100)) re();
}

void frente() {
  //Serial.println("Frente!");
  digitalWrite(MotorA_H, HIGH);
  digitalWrite(MotorB_H, HIGH);
  digitalWrite(MotorA_A, LOW);
  digitalWrite(MotorB_A, LOW);
  delay(200);
}
void direita() {
  //Serial.println("Direita!");
  digitalWrite(MotorA_H, HIGH);
  digitalWrite(MotorB_H, LOW);
  digitalWrite(MotorA_A, LOW);
  digitalWrite(MotorB_A, LOW);
}
void esquerda() {
  //Serial.println("Esquerda!");
  digitalWrite(MotorA_H, LOW);
  digitalWrite(MotorB_H, HIGH);
  digitalWrite(MotorA_A, LOW);
  digitalWrite(MotorB_A, LOW);
}
void parar() {
  //Serial.println("Parar!");
  digitalWrite(MotorA_H, LOW);
  digitalWrite(MotorB_H, LOW);
  digitalWrite(MotorA_A, LOW);
  digitalWrite(MotorB_A, LOW);
}
void re() {
  //Serial.println("Frio!");
  digitalWrite(MotorA_H, LOW);
  digitalWrite(MotorB_H, LOW);
  digitalWrite(MotorA_A, HIGH);
  digitalWrite(MotorB_A, HIGH);
}
