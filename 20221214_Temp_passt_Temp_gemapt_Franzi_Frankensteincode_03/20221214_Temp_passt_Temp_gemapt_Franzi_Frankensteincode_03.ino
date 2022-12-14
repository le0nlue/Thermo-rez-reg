
#include <Wire.h>
#include "WaveShare_MLX90614.h"

//Relais
const int RELAIS_1 = 10; // Relais-Pin am Arduino
const int RELAIS_2  = 9; // Relais-Pin am Arduino

//Motoren
const int MOTOR_PIN_1 = 12;
const int MOTOR_PIN_2 = 11; // geht 9.12.2022
const int MOTOR_PIN_3 = 5; 

WaveShare_MLX90614   MLX90614 = WaveShare_MLX90614();


void setup() {
  
Serial.begin(115200);
  
MLX90614.begin();  

// Motoren 
pinMode(MOTOR_PIN_1, OUTPUT);
pinMode(MOTOR_PIN_2, OUTPUT);
pinMode(MOTOR_PIN_3, OUTPUT);

//Relais
pinMode(RELAIS_1, OUTPUT); // Relais Pins als Ausgang deklarieren
pinMode(RELAIS_2, OUTPUT); // Relais Pins als Ausgang deklarieren

}

void loop() {

// Temperatur
Serial.print(" \tObject Temp: "); Serial.print(MLX90614.readObjectTemp()); Serial.println(" C");
  
// Relais
digitalWrite(RELAIS_1, HIGH); //RELAIS an

delay(200); //200ms Pause

digitalWrite(RELAIS_1, LOW); //RELAIS aus

delay(200); // 200ms Pause


digitalWrite(RELAIS_2, HIGH); //RELAIS an

delay(200); //200ms Pause

digitalWrite(RELAIS_2, LOW); //RELAIS aus

delay(200); // 200ms Pause


// Motoren
pinMode(MOTOR_PIN_1, HIGH); // vibration 1

delay(200); //200ms Pause

pinMode(MOTOR_PIN_2, HIGH); // vibration 2

delay(200); //200ms Pause

pinMode(MOTOR_PIN_3, HIGH); // vibration 3

delay(200); //200ms Pause


}
