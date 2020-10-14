void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  Serial.begin(9600);
  Serial.println("Lendo Sensor");

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(2));
}
