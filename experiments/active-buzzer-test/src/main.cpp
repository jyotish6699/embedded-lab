#include <Arduino.h>

const int BUZZER_PIN = 8;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  digitalWrite(BUZZER_PIN, HIGH); // ON
  delay(1000);

  digitalWrite(BUZZER_PIN, LOW);  // OFF
  delay(1000);
}