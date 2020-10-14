/***************************************************************/
/* Centro de Informática - Universidade Federal da Paraíba */
/* Disciplina: Estrutura de Dados */
/* Discente: Wagner Dantas Garcia - wagnergarcia@cc.ci.ufpb.br */
/* Data de Criação: 16/06/2019 */
/***************************************************************/
/* Este programa irá salvar em um Arquivo a tabela ASCII       */
/***************************************************************/

/* Importando as Bibliotecas */
#include <HCSR04.h>

/* Define os Pinos */

#define trigger_Sensor1 12
#define echo_Sensor1 13
#define trigger_Sensor2 2
#define echo_Sensor2 3

/* Inicia os Sensores */
UltraSonicDistanceSensor sensor1(trigger_Sensor1, echo_Sensor1);
UltraSonicDistanceSensor sensor2(trigger_Sensor2, echo_Sensor2);

/* Variaveis Globais */
int primeiro = 0;
int segundo = 0;
int luzBaixo = 0;
int luzCima = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Lendo dados do Sensor...");
}

void loop() {
  //  Serial.print("Sensor 1 = ");
  //  Serial.print(sensor1.measureDistanceCm());
  //  Serial.println("CM");
  //
  //  Serial.print("Sensor 2 = ");
  //  Serial.print(sensor2.measureDistanceCm());
  //  Serial.println("CM");
  //  delay(500);
  int continuar = 1;

  while (sensor1.measureDistanceCm() < 15 && sensor2.measureDistanceCm() > 15) {
    if ((primeiro == 0) && (segundo == 0)) primeiro = 1;
    else if ((primeiro == 0) && (segundo == 1)) primeiro = 2;
    continuar = 0;
  }

  while (continuar) {
    while (sensor2.measureDistanceCm() < 15 && sensor1.measureDistanceCm() > 15) {
      if ((primeiro == 0) && (segundo == 0)) segundo = 1;
      else if ((primeiro == 1) && (segundo == 0)) segundo = 2;
    }
    continuar = 0;
  }
    
  if ((primeiro == 1) && (segundo == 0) && (luzCima == 0)){
    luzCima = 1;
    Serial.println("Acenda a Luz de Cima");
  }
  if ((primeiro == 0) && (segundo == 1) && (luzBaixo == 0)){
    luzBaixo = 1;
    Serial.println("Acenda a luz de Baixo");
  }
  if ((primeiro == 1) && (segundo == 2)) {
    Serial.println("Apague as Luzes\t\t1\t->\t2");
    primeiro = segundo = luzBaixo = luzCima = 0;
  }
  else if ((primeiro == 2) && (segundo == 1)) {
    Serial.println("Apague as Luzes\t\t2\t->\t1");
    primeiro = segundo = luzBaixo = luzCima = 0;
  }
  delay(100);
}
