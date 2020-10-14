/*
 * Sensor Ultrasonico com Ponte H
 * Altor : Wagner Dantas Garcia
 * Criação : 24/10/2019
 */

// Importando as Bibliotecas
#include <HCSR04.h>

// Definindo os Pinos
#define MotorB_H 4
#define MotorB_A 5
#define MotorA_H 6
#define MotorA_A 7
#define pino_trigger 12
#define pino_echo 13

//Inicializa o sensor nos pinos definidos acima
UltraSonicDistanceSensor ultrasonic(pino_trigger, pino_echo);

// Prototipos
void frente();
void direita();
void esquerda();
void parar();
void freio();

void setup() {
  pinMode(MotorB_H, OUTPUT);
  pinMode(MotorB_A, OUTPUT);
  pinMode(MotorA_H, OUTPUT);
  pinMode(MotorA_A, OUTPUT);
  Serial.begin(9600);
  Serial.println("Lendo dados do Sensor...");
}

void loop() {
   int distancia = ultrasonic.measureDistanceCm();// ultrassom.Ranging(CM) retorna a distancia em
                                     // centímetros(CM) ou polegadas(INC)
   Serial.print(distancia); //imprime o valor da variável distancia
   Serial.print(" cm\t\t");
      
   if(distancia < 10) {
    parar();
   }
   else if(distancia < 20){
    direita();
   }
   else if(distancia < 30){
    esquerda();
   }
   else if(distancia < 40){
    freio();
   }
   else{
    frente();
   }
   delay(500);
}

void frente(){
  Serial.println("Frente!");
  digitalWrite(MotorA_H, HIGH);
  digitalWrite(MotorB_H, HIGH);
  digitalWrite(MotorA_A, LOW);
  digitalWrite(MotorB_A, LOW);
}
void direita(){
  Serial.println("Direita!");
  digitalWrite(MotorA_H, HIGH);
  digitalWrite(MotorB_H, LOW);
  digitalWrite(MotorA_A, LOW);
  digitalWrite(MotorB_A, LOW);
}
void esquerda(){
  Serial.println("Esquerda!");
  digitalWrite(MotorA_H, LOW);
  digitalWrite(MotorB_H, HIGH);
  digitalWrite(MotorA_A, LOW);
  digitalWrite(MotorB_A, LOW);
}
void parar(){
  Serial.println("Parar!");
  digitalWrite(MotorA_H, LOW);
  digitalWrite(MotorB_H, LOW);
  digitalWrite(MotorA_A, LOW);
  digitalWrite(MotorB_A, LOW);
}
void freio(){
  Serial.println("Frio!");
  digitalWrite(MotorA_H, HIGH);
  digitalWrite(MotorB_H, HIGH);
  digitalWrite(MotorA_A, HIGH);
  digitalWrite(MotorB_A, HIGH);
}
