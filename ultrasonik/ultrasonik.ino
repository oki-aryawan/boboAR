//ultrasonic 1
int echoPin1 =8;
int initPin1 =9;
int distance1 =0;

//ultrasonic 2
int echoPin2 =6;
int initPin2 =7;
int distance2 =0;



void setup() {
 
  pinMode(initPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(initPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  Serial.begin(9600);
 
}

void loop() {
 
  distance1 = getDistance(initPin1, echoPin1);
  printDistance(1, distance1);
  delay(150);
 
  distance2 = getDistance(initPin2, echoPin2);
  printDistance(2, distance2);
  delay(150);

  Serial.println("");
  delay(500);
 
}

int getDistance (int initPin, int echoPin){

 digitalWrite(initPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(initPin, LOW);
 unsigned long pulseTime = pulseIn(echoPin, HIGH);
 int distance = pulseTime/58;
 return distance;

}

 void printDistance(int id, int dist){
 
     Serial.print(id);
     Serial.print("------>");  
    Serial.print(dist, DEC);
    Serial.println(" cm");
   
 }