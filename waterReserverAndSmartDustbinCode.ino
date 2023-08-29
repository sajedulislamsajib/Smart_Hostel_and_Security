#include <Servo.h>

Servo myservo;  
const int trigPin = 9;
const int echoPin = 10;
const int trigPinx = 11;
const int echoPinx = 12;

int red = 5;
int yellow = 6;
int green = 7;
// defines variables
long durationx;
int distancex;
long duration;
int distance;
int relay = 13;


void setup() {
  myservo.attach(8); 
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(trigPinx, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinx, INPUT); // Sets the echoPin as an 
  pinMode(red, OUTPUT); 
  pinMode(yellow, OUTPUT);  
  pinMode(green, OUTPUT); 
  pinMode(relay, OUTPUT);
  
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  int x =SensorOne();
  int y =SensorTwo();

  Serial.print(x);
  Serial.print("  ");
  Serial.println(y);

  if(x <= 20){
    myservo.write(180);
    delay(2500);
    

  }
  else{
    myservo.write(0); 
  }


  if(y >= 15) {
    digitalWrite(relay, LOW);        
  }
  else{
    digitalWrite(relay, HIGH);
  }
}



int SensorOne() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  
  return distance;
}


int SensorTwo() {
  digitalWrite(trigPinx, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinx, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinx, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationx = pulseIn(echoPinx, HIGH);
  // Calculating the distance
  distancex = durationx * 0.034 / 2;
  
  
  return distancex;
}
