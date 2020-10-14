#define LinhaDD 7
#define LinhaDE 8
#define LinhaAD A0
#define LinhaAE A1


void setup() {
// put your setup code here, to run once:
    pinMode(LinhaAD, INPUT);
    pinMode(LinhaAE, INPUT);
    pinMode(LinhaDD, INPUT);
    pinMode(LinhaDE, INPUT);
    Serial.begin(9600);
    Serial.println("Lendo dados do Sensor...");
}

void loop() {
// put your main code here, to run repeatedly:
    /*
    Serial.print("\n");
    Serial.print("\n");
    Serial.print("\n");
    Serial.print("Sensor Linha Direito Analogico - ");
    Serial.print(analogRead(LinhaAD));
    Serial.print("\n");

    Serial.print("Sensor Linha Direito Digital - ");
    Serial.print(digitalRead(LinhaDD));
    Serial.print("\n\n");    

    Serial.print("Sensor Linha Esquerdo Analogico - ");
    Serial.print(analogRead(LinhaAE));
    Serial.print("\n");

    Serial.print("Sensor Linha Esquerdo Digital - ");
    Serial.print(digitalRead(LinhaDE));
    Serial.print("\n");*/
    
    if(analogRead(LinhaAD) >= 100) Serial.print("Passou pelo Direito;\n");
    if(analogRead(LinhaAE) >= 100) Serial.print("Passou pelo Esquerdo;\n");

    delay(100);
}
