#include <Servo.h>
#include <Arduino.h>

Servo myServo;

#define TRIG_PIN 5
#define ECHO_PIN 4
#define SERVO_PIN 9

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  myServo.attach(SERVO_PIN);

  Serial.println("Aegis Radar Test Started");
}

float getDistance() {
  // Trigger HC-SR04
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return -1;
  }

  float distance = duration * 0.0343 / 2.0;

  return distance;
}

void loop() {

  // Sweep left to right
  for (int angle = 0; angle <= 180; angle += 45) {

    myServo.write(angle);
    delay(5);

    float distance = getDistance();

    Serial.print("Angle: ");
    Serial.print(angle);

    Serial.print("  Distance: ");

    if (distance < 0) {
      Serial.println("Out of Range");
    } else {
      Serial.print(distance);
      Serial.println(" cm");
    }
  }

  // Sweep right to left
  for (int angle = 180; angle >= 0; angle -= 45) {

    myServo.write(angle);
    delay(5);

    float distance = getDistance();

    Serial.print("Angle: ");
    Serial.print(angle);

    Serial.print("  Distance: ");

    if (distance < 0) {
      Serial.println("Out of Range");
    } else {
      Serial.print(distance);
      Serial.println(" cm");
    }
  }
}