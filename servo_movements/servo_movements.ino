#include <Servo.h>

Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);         
  myservo.write(90);         // center 
  delay(1000);
}

void loop() {
  Serial.println("Moving to 0°");
  myservo.write(0);
  delay(1000);

  Serial.println("Moving to 90°");
  myservo.write(90);
  delay(1000);

  Serial.println("Moving to 180°");
  myservo.write(180);
  delay(1000);
}
