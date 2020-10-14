/*
   Sinal de Transito
   Altor : Wagner Dantas Garcia
   Criação : 24/10/2019
*/

// Importando as Bibliotecas

// Definindo os Pinos
#define r_led_1 6
#define g_led_1 5
#define b_led_1 3
#define r_led_2 9
#define g_led_2 10
#define b_led_2 11

// Prototipos
// Variaveis Globais
void setup() {
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
  int r, g, b;
  r = g = b = 0;
  for (r = 0; r < 256; r++) {
    for (g = 0; g < 256; g++) {
      for (b = 0; b < 256; b++) {
        analogWrite(r_led_1, r);
        analogWrite(g_led_1, g);
        analogWrite(b_led_1, b);
        analogWrite(r_led_2, b);
        analogWrite(g_led_2, g);
        analogWrite(b_led_2, r);
        delay(10);
      }
    }
  }
}
