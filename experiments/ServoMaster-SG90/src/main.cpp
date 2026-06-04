#include <Arduino.h>
#include <Servo.h>

Servo myServo;

// Brown -> GND
// Red -> 5V
// Orange -> Signal

void setup() {

  //myServo.attach(pin, minimumPulse, maximumPulse);
  myServo.attach(9, 544, 2400);
}

// Sweep Motion
void loop() {

  for(int angle=0; angle <= 180; angle++){

    myServo.write(angle);
    delay(15);
  }

  for(int angle=180; angle>=0; angle--){

    myServo.write(angle);
    delay(15);
  }
}