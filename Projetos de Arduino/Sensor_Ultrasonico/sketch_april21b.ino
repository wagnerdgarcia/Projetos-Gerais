#include <HCSR04.h>

#define trigger_SensorD 7
#define echo_SensorD 8

UltraSonicDistanceSensor sensorD(trigger_SensorD, echo_SensorD);

void setup() {
// put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Lendo dados do Sensor...");
}

void loop() {
// put your main code here, to run repeatedly:
    double distanciaD, distanciaF, distanciaE;
    distanciaD = sensorD.measureDistanceCm();

    Serial.print("Sensor Direita = ");
    Serial.print(distanciaD);
    Serial.println(" CM");
    delay(1000);

}
