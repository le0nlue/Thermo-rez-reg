#include "WaveShare_MLX90614.h"
int temp;
WaveShare_MLX90614   MLX90614 = WaveShare_MLX90614();
//Relais
const int RELAIS_1 = 10; // Relais-Pin am Arduino
const int RELAIS_2  = 9; // Relais-Pin am Arduino

//Motoren
const int MOTOR_PIN_1 = 12;
const int MOTOR_PIN_2 = 11; // geht 9.12.2022
const int MOTOR_PIN_3 = 5; 


void setup() {
  MLX90614.begin(); 
  Serial.begin(9600);
  
  // Motoren 
  pinMode(MOTOR_PIN_1, OUTPUT);  
  pinMode(MOTOR_PIN_2, OUTPUT);
  pinMode(MOTOR_PIN_3, OUTPUT);
  
  //Relais
  pinMode(RELAIS_1, OUTPUT); // Relais Pins als Ausgang deklarieren
  pinMode(RELAIS_2, OUTPUT); // Relais Pins als Ausgang deklarieren

}

void loop() {
    temp = MLX90614.readObjectTemp();
    Serial.println(temp);
      
    // Relais
    if (temp < 25){
    digitalWrite(RELAIS_1, LOW); //RELAIS aus
    digitalWrite(RELAIS_2, LOW); //RELAIS aus
    digitalWrite(MOTOR_PIN_1, HIGH); // vibration 1
    delay(200); //200ms Pause
    digitalWrite(MOTOR_PIN_1, LOW); // vibration 1
    digitalWrite(MOTOR_PIN_2, HIGH); // vibration 2
    delay(200); //200ms Pause
    digitalWrite(MOTOR_PIN_2, LOW); // vibration 1
    digitalWrite(MOTOR_PIN_3, HIGH); // vibration 3
    delay(200); //200ms Pause
    digitalWrite(MOTOR_PIN_3, LOW); // vibration 1
  }
  else {
    digitalWrite(RELAIS_1, HIGH); //RELAIS aus
    digitalWrite(RELAIS_2, HIGH); //RELAIS aus
    digitalWrite(MOTOR_PIN_1, HIGH); // vibration 1
    delay(50); //200ms Pause
    digitalWrite(MOTOR_PIN_1, LOW); // vibration 1
    digitalWrite(MOTOR_PIN_2, HIGH); // vibration 2
    delay(50); //200ms Pause
    digitalWrite(MOTOR_PIN_2, LOW); // vibration 1
    digitalWrite(MOTOR_PIN_3, HIGH); // vibration 3
    delay(50); //200ms Pause
    digitalWrite(MOTOR_PIN_3, LOW); // vibration 1
  }
}
