/*
   Sinal de Transito
   Altor : Wagner Dantas Garcia
   Criação : 24/10/2019
*/

// Importando as Bibliotecas
#include <HCSR04.h>

// Definindo os Pinos
#define botao_1 2
#define botao_2 4
#define echo_ultra_1 7
#define trig_ultra_1 8
#define echo_ultra_2 12
#define trig_ultra_2 13
#define r_led_1 6
#define g_led_1 5
#define b_led_1 3
#define r_led_2 9
#define g_led_2 10
#define b_led_2 11

//Inicializa o sensor nos pinos definidos acima
UltraSonicDistanceSensor ultra_1(trig_ultra_1, echo_ultra_1);
UltraSonicDistanceSensor ultra_2(trig_ultra_2, echo_ultra_2);

// Prototipos
void fechar();
void azul_1();
void azul_2();
void verde_1();
void verde_2();

// Variaveis Globais
int botao_1_press, botao_2_press;
int verde1, verde2;

void setup() {
  verde1 = verde2 = 0;
  pinMode(botao_1, INPUT);
  pinMode(botao_2, INPUT);
  pinMode(r_led_1, OUTPUT);
  pinMode(g_led_1, OUTPUT);
  pinMode(b_led_1, OUTPUT);
  pinMode(r_led_2, OUTPUT);
  pinMode(g_led_2, OUTPUT);
  pinMode(b_led_2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Lendo dados do Sensor...");
}

void loop() {
  if ((digitalRead(botao_1) == HIGH) || (digitalRead(botao_2) == HIGH)) {
    fechar();
    Serial.println("Passagem de Pedestre");
  }

  if ((ultra_1.measureDistanceCm() < 15) && (ultra_2.measureDistanceCm() > 15)) {
    if (verde1 == 0) azul_1();
    verde_1();
    Serial.println("Via um com Fluxo");
    Serial.print("\tDistacia Sensor 1 = ");
    Serial.println(ultra_1.measureDistanceCm());
    Serial.print("\tDistacia Sensor 2 = ");
    Serial.println(ultra_2.measureDistanceCm());
  }
  if ((ultra_2.measureDistanceCm() < 15) && (ultra_1.measureDistanceCm() > 15)) {
    if (verde2 == 0) azul_2;
    verde_2;
    Serial.println("Via Dois com Fluxo");
    Serial.print("\tDistacia Sensor 1 = ");
    Serial.println(ultra_1.measureDistanceCm());
    Serial.print("\tDistacia Sensor 2 = ");
    Serial.println(ultra_2.measureDistanceCm());
  }
  if ((ultra_2.measureDistanceCm() < 15) && (ultra_1.measureDistanceCm() < 15)) {
    Serial.println("Vias Um e Dois com Fluxo");
    Serial.print("\tDistacia Sensor 1 = ");
    Serial.println(ultra_1.measureDistanceCm());
    Serial.print("\tDistacia Sensor 2 = ");
    Serial.println(ultra_2.measureDistanceCm());
    if (verde1 == 1) {
      azul_2();
      verde_2();
    }
    else if (verde2 == 1) {
      azul_1();
      verde_1();
    }
    else {
      verde_1();
    }
  }
  if ((ultra_2.measureDistanceCm() > 15) && (ultra_1.measureDistanceCm() > 15)) {
    digitalWrite(r_led_1, LOW);
    digitalWrite(r_led_2, LOW);
    digitalWrite(g_led_1, LOW);
    digitalWrite(g_led_2, LOW);
    digitalWrite(b_led_1, HIGH);
    digitalWrite(b_led_2, HIGH);
    delay(1000);
    digitalWrite(b_led_1, LOW);
    digitalWrite(b_led_2, LOW);
    delay(200);
    Serial.println("Vias sem fluxo");
    Serial.print("\tDistacia Sensor 1 = ");
    Serial.println(ultra_1.measureDistanceCm());
    Serial.print("\tDistacia Sensor 2 = ");
    Serial.println(ultra_2.measureDistanceCm());
  }
}

void fechar() {
  digitalWrite(r_led_1, LOW);
  digitalWrite(r_led_2, LOW);
  digitalWrite(g_led_1, LOW);
  digitalWrite(g_led_2, LOW);
  digitalWrite(b_led_1, HIGH);
  digitalWrite(b_led_2, HIGH);
  delay(200);
  digitalWrite(r_led_1, HIGH);
  digitalWrite(r_led_2, HIGH);
  digitalWrite(g_led_1, LOW);
  digitalWrite(g_led_2, LOW);
  digitalWrite(b_led_1, LOW);
  digitalWrite(b_led_2, LOW);
  delay(2000);
}
void azul_1() {
  digitalWrite(r_led_1, HIGH);
  digitalWrite(r_led_2, LOW);
  digitalWrite(g_led_1, LOW);
  digitalWrite(g_led_2, LOW);
  digitalWrite(b_led_1, LOW);
  digitalWrite(b_led_2, HIGH);
  delay(500);
}
void verde_1() {
  verde1 = 1;
  verde2 = 0;
  digitalWrite(r_led_1, LOW);
  digitalWrite(r_led_2, HIGH);
  digitalWrite(g_led_1, HIGH);
  digitalWrite(g_led_2, LOW);
  digitalWrite(b_led_1, LOW);
  digitalWrite(b_led_2, LOW);
  delay(1000);
}
void azul_2() {
  digitalWrite(r_led_1, LOW);
  digitalWrite(r_led_2, HIGH);
  digitalWrite(g_led_1, LOW);
  digitalWrite(g_led_2, LOW);
  digitalWrite(b_led_1, HIGH);
  digitalWrite(b_led_2, LOW);
  delay(500);
}
void verde_2() {
  verde2 = 1;
  verde1 = 0;
  digitalWrite(r_led_1, HIGH);
  digitalWrite(r_led_2, LOW);
  digitalWrite(g_led_1, LOW);
  digitalWrite(g_led_2, HIGH);
  digitalWrite(b_led_1, LOW);
  digitalWrite(b_led_2, LOW);
  delay(1000);
}
