#include <Arduino.h>
#include "sensors/pir_sensor.h"
#include "sensors/ultrasonic_sensor.h"
#include "sensors/ir_sensor.h"

void setup() {
    Serial.begin(9600);

    //init_pir();
    //init_ultrasonic();
    init_ir();

}

void loop() {

    //read_pir();
    //read_distance();
    read_ir();
}