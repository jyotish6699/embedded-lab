#include <Arduino.h>
#include "ir_sensor.h"

#define IR_PIN 3

bool ir_previous_state = HIGH;

void init_ir() {

    pinMode(IR_PIN, INPUT);
}

void read_ir() {

    bool current_state = digitalRead(IR_PIN);

    // STATE CHANGED
    if(current_state != ir_previous_state) {

        if(current_state == LOW) {
            Serial.println("OBSTACLE DETECTED");
        }
        else {
            Serial.println("NO OBSTACLE");
        }

        ir_previous_state = current_state;
    }

    delay(100);
}