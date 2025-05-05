#include <Servo.h>
Servo s1;
const int trigPin = 2;
const int echoPin = 3;
long duration;
int distanceCm;
void setup()
{

Serial.begin(9600); 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

s1.attach(4);  

}
void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distanceCm= duration*0.034/2;
    Serial.println("Distance: ");
    Serial.println(distanceCm);
    delay(50);

    if(distanceCm <30){
        s1.write(90);
        delay(1000);
    }

    else{
        s1.write(0);
        delay(10);
    }

}