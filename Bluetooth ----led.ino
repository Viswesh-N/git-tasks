#include <SoftwareSerial.h>
const int trigPin = 5;
const int echoPin = 6;

SoftwareSerial Bluetooth(10, 9); // RX, TX
int LED = 13; // the on-board LED
int Data; // the data received
long duration;
int distance;
int safetyDistance;
 
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(4,OUTPUT);
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Waiting for command...");
  Bluetooth.println("Send 1 to turn on the LED. Send 0 to turn Off");
  pinMode(LED,OUTPUT);
 
}
 
void loop() {
  digitalWrite(4, HIGH);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance= duration*0.034/2;

  Bluetooth.println(distance);

  if (Bluetooth.available()){ //wait for data received
    Data=Bluetooth.read();
    if(Data=='1'){  
      digitalWrite(LED,1);
      Serial.println("LED On!");
      Bluetooth.println("LED On!");
    }
    else if(Data=='0'){
       digitalWrite(LED,0);
       Serial.println("LED Off!");
       Bluetooth.println("LED  On D13 Off ! ");
    }
    else{;}
    
  }
delay(100);
}