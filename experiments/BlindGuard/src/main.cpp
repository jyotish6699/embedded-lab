#include <Arduino.h>

// -----------------------------
// Pin configuration
// -----------------------------
const uint8_t TRIG_PIN = 9;
const uint8_t ECHO_PIN = 10;
const uint8_t BUZZER_PIN = 8;

// -----------------------------
// Obstacle detection threshold
// -----------------------------
const float OBSTACLE_DISTANCE_CM = 50.0;

// -----------------------------
// Function: measure distance
// -----------------------------
float measureDistanceCM()
{
    // Make sure TRIG starts LOW
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Send a 10-microsecond ultrasonic pulse
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Measure how long ECHO stays HIGH
    unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);

    // No echo received
    if (duration == 0)
    {
        return -1.0;
    }

    // Speed of sound:
    // distance = duration * 0.0343 / 2
    float distance = (duration * 0.0343) / 2.0;

    return distance;
}

// -----------------------------
// Arduino setup
// -----------------------------
void setup()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    // Start with buzzer OFF
    digitalWrite(BUZZER_PIN, LOW);

    Serial.begin(9600);

    Serial.println("================================");
    Serial.println("       BlindGuard v0.0.1");
    Serial.println("Ultrasonic Obstacle Alert System");
    Serial.println("================================");
    Serial.println();
}

// -----------------------------
// Arduino main loop
// -----------------------------
void loop()
{
    float distance = measureDistanceCM();

    // --------------------------------
    // No valid ultrasonic measurement
    // --------------------------------
    if (distance < 0)
    {
        digitalWrite(BUZZER_PIN, LOW);

        Serial.println("Distance: No echo");

        delay(100);
        return;
    }

    // --------------------------------
    // Print distance
    // --------------------------------
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm");

    // --------------------------------
    // Obstacle detection
    // --------------------------------
    if (distance <= OBSTACLE_DISTANCE_CM)
    {
        // Obstacle is inside danger range
        // KEEP BUZZER ON
        digitalWrite(BUZZER_PIN, HIGH);

        Serial.println("  -> OBSTACLE! BUZZER ON");
    }
    else
    {
        // Obstacle is outside danger range
        // Turn buzzer OFF
        digitalWrite(BUZZER_PIN, LOW);

        Serial.println("  -> SAFE");
    }

    // Small delay before next measurement
    delay(100);
}