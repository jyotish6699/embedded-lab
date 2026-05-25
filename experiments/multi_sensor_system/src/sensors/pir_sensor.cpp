#include <Arduino.h>
#include "pir_sensor.h"

#define PIR_PIN 4

bool previous_state = LOW;

unsigned long motion_start_time = 0;
unsigned long motion_end_time = 0;

void init_pir() {

    pinMode(PIR_PIN, INPUT);
}

void read_pir() {

    bool current_state = digitalRead(PIR_PIN);

    if(current_state != previous_state) {

        // MOTION START
        if(current_state == HIGH) {

            motion_start_time = millis();

            Serial.println("MOTION DETECTED");
        }

        // MOTION END
        else {

            motion_end_time = millis();

            unsigned long motion_duration =
                motion_end_time - motion_start_time;

            Serial.println("NO MOTION");

            Serial.print("Motion Duration: ");
            Serial.print(motion_duration);
            Serial.println(" ms");
        }

        previous_state = current_state;
    }

    delay(100);
}