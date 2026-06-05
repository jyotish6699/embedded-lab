#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define TRIG_PIN 9
#define ECHO_PIN 10
#define IR_PIN 2

// create display object to control display
Adafruit_SSD1306 display (
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,    // I2C communication
    -1       // no reset button
);

float getDistance() {

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);

    float distance = duration * 0.034 / 2.0;

    return distance;
}

bool isObjectDetected() {

    return digitalRead(IR_PIN) == LOW;
}

void drawDashboard(
    float distance,
    bool irDetected,
    String state
) {
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.print("DIST : ");
    display.print(distance, 1);
    display.println(" cm");

    display.setCursor(0, 20);
    display.print("IR   : ");

    if (irDetected) {
        
        display.println("DETECTED");
    }else {
        
        display.println("CLEAR");
    }

    display.setCursor(0, 40);
    display.print("STATE: ");
    display.println(state);

    display.display();
}


void setup() {

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    pinMode(IR_PIN, INPUT);

    display.begin(
        SSD1306_SWITCHCAPVCC,
        0x3C
    );

    display.clearDisplay();
    display.display();
}

void loop() {

    float distance = getDistance();
    
    bool irDetected = isObjectDetected();

    String state;

    if(irDetected) {

        state = "ALERT";
    }else {
        state = "SAFE";
    }

    drawDashboard(
        distance, 
        irDetected,
        state
    );

    delay(200);
}

