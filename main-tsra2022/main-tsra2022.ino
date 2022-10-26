#include <Wire.h> 
#define Buzzer 2 //mendefinisikan pin 4 Arduino sebagai pin Output Buzzer
#define trigPin 9                       //mendefinisikan pin 5 arduino sebagai trigger pin sensor ultrasonic
#define echoPin 8 //mendefinisikan pin 6 arduino sebagai echoPin sensor ultrasonic
long duration; // variabel durasi sensor ultrasonic
int distance = 0; // jarah dalam centimeter
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void setup()
{


Serial.begin(9600); // setting kecepatan pengiriman serial monitor
pinMode(trigPin, OUTPUT); // setting triggerpin sebagai output
pinMode(echoPin, INPUT); // setting echopin sebagai Input
pinMode(Buzzer, OUTPUT); // setting Buzzer sebagai Output
digitalWrite(Buzzer, HIGH);
delay(1000);
digitalWrite(Buzzer, LOW);
delay(1000);

  mySoftwareSerial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial)) { 
    Serial.print("DF Not Connected");
  }


}
void loop()
{

digitalWrite(trigPin, HIGH);// aktifkan sensor ultrasonic
delayMicroseconds(10); // selama 10 microseconds
digitalWrite(trigPin, LOW); // matikan sensor ultrasonic
duration = pulseIn(echoPin, HIGH); // baca rentan waktu dari trigPin High sampai echoPin high
distance= duration*0.034/2; //konversi selang waktu ke CM

Serial.println(int(distance)); // kirim data jarak ke PC
delay(500);
if (distance < 20) // Hanya menampilkan jarak jika jaraknya kurang dari 300 cm / 3 meter
{
            myDFPlayer.volume(15); 
        myDFPlayer.play(1);
        digitalWrite(Buzzer,HIGH); 
        delay(1000);

digitalWrite(Buzzer,LOW);
delay(500);
}
}
