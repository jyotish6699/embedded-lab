#include <Arduino.h>
#include "ultrasonic_sensor.h"

#define TRIG_PIN 5
#define ECHO_PIN 8

void init_ultrasonic() {

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void read_distance() {

    // CLEAR TRIG
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // SEND 10us PULSE
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);

    // READ ECHO TIME
    long duration = pulseIn(ECHO_PIN, HIGH);

    // CALCULATE DISTANCE
    float distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500);
}