#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// create display object to control display
Adafruit_SSD1306 display (
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,    // I2C communication
    -1       // no reset button
);


void setup() {

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // start communication

    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.println("DIST : 0 cm");

    display.setCursor(0, 20);
    display.println("IR   : CLEAR");

    display.setCursor(0, 40);
    display.println("STATE: SAFE");

    display.display();   // send everthing(RAM buffer) to screen NOW
}

void loop() {

}


