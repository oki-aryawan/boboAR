#include <Servo.h> 

Servo servo; // servo object representing the MG 996R servo

void setup() {
  servo.attach(3); // servo is wired to Arduino on digital pin 3
}

void loop() {
  servo.write(0); // move MG996R's shaft to angle 0°
  delay(1000); // wait for one second
  servo.write(40); // move MG996R's shaft to angle 180°
  delay(1000); // wait for one second
}