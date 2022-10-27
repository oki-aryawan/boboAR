#include <Wire.h> 
#define lampu 2 
#define trigPin1 9
#define trigPin2 7
#define echoPin1 8
#define echoPin2 6

long duration1;
long duration2; 
int distance1 = 0;
int distance2 = 0;

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup()
{


Serial.begin(9600); 
pinMode(trigPin1, OUTPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin1, INPUT); 
pinMode(echoPin2, INPUT); 
pinMode(lampu, OUTPUT); 
digitalWrite(lampu, HIGH);
delay(1000);
digitalWrite(lampu, LOW);
delay(1000);

  mySoftwareSerial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial)) { 
    Serial.print("DF Not Connected");
  }


}
void loop()
{

/*
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
*/

distance1 = hitungJarak(trigPin1, echoPin1);
Serial.print("Sensor1: ");
Serial.println(int(distance1));
delay(500);

if (distance1 < 120) // Hanya menampilkan jarak jika jaraknya kurang dari 300 cm / 3 meter
{
            myDFPlayer.volume(30); 
        myDFPlayer.play(1);
        digitalWrite(lampu,HIGH); 
        delay(1000);

digitalWrite(lampu,LOW);
delay(500);
}
/*
distance2 = hitungJarak(trigPin2, echoPin2);
Serial.print("Sensor2: ");
Serial.println(int(distance2));
delay(500);
*/
}

int hitungJarak (int trigPin, int echoPin){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  unsigned long pulseTime = pulseIn(echoPin, HIGH);
  int distance = pulseTime/58;
  return distance;
}
