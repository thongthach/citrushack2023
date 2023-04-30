#include<Servo.h>
#include <DHT.h>
#define DHTPIN A0     
#define DHTTYPE DHT11 
int pos = 0;    // variable to store the servo position
Servo myservo;
int led =7;


DHT dht(DHTPIN, DHTTYPE);
const int trigPin = 11;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;



void setup() {
  dht.begin();
  myservo.attach(3);
  Serial.println("DHT temperature sensor ");


  pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);

  // attaches the servo on pin 9 to the servo object
}
void Temperature_sensor(){
      
  
}
void Ultrasonic_sensor(){
  
      digitalWrite(trigPin, LOW);
delayMicroseconds(1);
digitalWrite(trigPin, HIGH);
delayMicroseconds(1); 
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
Serial.println(distanceCm); 
  
 }

void loop() {

      if(Serial.available())
      {
      String data = Serial.readStringUntil('\n');
      Serial.flush();
    
      Serial.println(data);

      }
    Serial.print(" The temperature: " );
  Serial.println(dht.readTemperature(true)) ;
  int temp = dht.readTemperature(true);
  if( temp > 74){
      digitalWrite(led,HIGH);
      delay(10);
      digitalWrite(led,LOW);
    }
  Serial.print(" The distance to the object: " );
  Ultrasonic_sensor();
  for (pos = 0; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 120; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
}
