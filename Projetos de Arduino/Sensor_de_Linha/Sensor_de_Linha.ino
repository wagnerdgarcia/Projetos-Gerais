#define Linha A0

void setup() {
    pinMode(Linha, INPUT);
    Serial.begin(9600);
    Serial.println("Lendo dados do Sensor...");
}

void loop() {
    Serial.print("Sensor Linha Analogico - ");
    Serial.print(analogRead(Linha));
    Serial.print("\n");
    
    delay(100);
}
