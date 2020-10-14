/***************************************************************/
/* Centro de Informática - Universidade Federal da Paraíba     */
/* Discente: Wagner Dantas Garcia - wagnergarcia@cc.ci.ufpb.br */
/* Data de Criação: 16/06/2019                                 */
/***************************************************************/
/* Teste LED RGB                                               */
/***************************************************************/

/* Define os Pinos */
#define R 8 //Canal Vermelho
#define G 9 //Canal Verde
#define B 10 //Canal Azul

void setup() {
  // put your setup code here, to run once:
  pinMode(R, INPUT);
  pinMode(G, INPUT);
  pinMode(B, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(B, LOW);
  digitalWrite(R, HIGH);
  delay(1000);
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
  delay(1000);
  digitalWrite(G, LOW);
  digitalWrite(B, HIGH);
  delay(1000);
}
