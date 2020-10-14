/***************************************************************/
/* Centro de Informática - Universidade Federal da Paraíba     */
/* Discente: Wagner Dantas Garcia - wagnergarcia@cc.ci.ufpb.br */
/* Data de Criação: 16/06/2019                                 */
/***************************************************************/
/* Robô com 3 Sensores Ultrasonico       */
/***************************************************************/

/* Importando as Bibliotecas */
#include <HCSR04.h>

/* Define os Pinos */

#define MotorB_H 2
#define MotorB_A 3
#define MotorA_H 4
#define MotorA_A 5
#define trigger_SensorD 6
#define echo_SensorD 7
#define trigger_SensorF 8
#define echo_SensorF 9
#define trigger_SensorE 10
#define echo_SensorE 11
#define LinhaDD 12
#define LinhaDE 13
#define LinhaAD A0
#define LinhaAE A1


/* Inicia os Sensores */
UltraSonicDistanceSensor sensorD(trigger_SensorD, echo_SensorD);
UltraSonicDistanceSensor sensorF(trigger_SensorF, echo_SensorF);
UltraSonicDistanceSensor sensorE(trigger_SensorE, echo_SensorE);

/* Prototipos */
void frente();
void direita();
void esquerda();
void parar();
void re();

void setup() {
  pinMode(LinhaAD, INPUT);
  pinMode(LinhaAE, INPUT);
  pinMode(LinhaDD, INPUT);
  pinMode(LinhaDE, INPUT);
  pinMode(MotorB_H, OUTPUT);
  pinMode(MotorB_A, OUTPUT);
  pinMode(MotorA_H, OUTPUT);
  pinMode(MotorA_A, OUTPUT);
  Serial.begin(9600);
  Serial.println("Lendo dados do Sensor...");
}

void loop() {
  double distanciaD, distanciaF, distanciaE;
  distanciaD = sensorD.measureDistanceCm();
  distanciaF = sensorF.measureDistanceCm();
  distanciaE = sensorE.measureDistanceCm();

  Serial.print("Sensor Direita Analogico = ");
  Serial.print(digitalRead(LinhaAD));

  Serial.print("Sensor Esquerda Analogico = ");
  Serial.print(digitalRead(LinhaAE));

  Serial.print("Sensor Direita Digital = ");
  Serial.print(digitalRead(LinhaDD));

  Serial.print("Sensor Esquerda Digital = ");
  Serial.print(digitalRead(LinhaDE));

  /*
  Serial.print("\t\t\t\t\t\t\t\tSensor Direita = ");
  Serial.print(distanciaD);
  Serial.println(" CM");

  Serial.print("\t\t\t\tSensor Frente = ");
  Serial.print(distanciaF);
  Serial.println(" CM");

  Serial.print("Sensor Esquerda = ");
  Serial.print(distanciaE);
  Serial.println(" CM");
  */
  delay(100);

  if (distanciaF >= 10){
    frente();
  }
  else if (distanciaD > distanciaE){
    if (distanciaF < 5){
      re();
    }
    direita();
  }
  else if (distanciaE > distanciaD){
    if (distanciaF < 5){
      re();
    }
    esquerda();
  }
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
  delay(200);
}
void esquerda() {
  //Serial.println("Esquerda!");
  digitalWrite(MotorA_H, LOW);
  digitalWrite(MotorB_H, HIGH);
  digitalWrite(MotorA_A, LOW);
  digitalWrite(MotorB_A, LOW);
  delay(200);
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
  delay(200);
}
