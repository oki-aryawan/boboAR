#include <CapacitiveSensor.h>

CapacitiveSensor cs_4_2 = CapacitiveSensor (4, 2); //declaration of digital pin 4 and 2

int tresh = 500; // minimum value
int led = 12;

void setup() {
  
  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop() {
  long start = millis();
  long dada_kanan = cs_4_2.capacitiveSensor(30);

  Serial.print(millis() - start);
  Serial.print("t: ");

  Serial.print(dada_kanan);
  Serial.print("n");

  if (dada_kanan > tresh){
    digitalWrite(led, HIGH);
  } else{
    digitalWrite(led, LOW);
  }
}
