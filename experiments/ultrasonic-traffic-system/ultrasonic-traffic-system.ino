// Ultrasonic Obstacle Indicator System
// HC-SR04 + 3 LEDs

// -----------------------------
// Pin Definitions
// -----------------------------
const int trigPin = 9;
const int echoPin = 10;

const int redLED = 3;
const int yellowLED = 4;
const int whiteLED = 5;

// -----------------------------
// Variables
// -----------------------------
long duration;
float distance;

// -----------------------------
// Setup
// -----------------------------
void setup() {

  // Serial Monitor
  Serial.begin(9600);

  // Ultrasonic Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // LEDs
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
}

// -----------------------------
// Main Loop
// -----------------------------
void loop() {

  // Clear trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send ultrasonic pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance
  distance = duration * 0.034 / 2;

  // Print readings
  Serial.print("Duration: ");
  Serial.print(duration);

  Serial.print(" | Distance: ");
  Serial.print(distance);

  Serial.println(" cm");

  // -----------------------------
  // LED Logic
  // -----------------------------

  // No obstacle detected
  if (duration == 0 || distance > 200) {

    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(whiteLED, LOW);

    Serial.println("No obstacle detected");
  }

  // Very close object
  else if (distance < 8) {

    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(whiteLED, LOW);

    Serial.println("Danger Zone");
  }

  // Medium distance
  else if (distance >= 8 && distance < 15) {

    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(whiteLED, LOW);

    Serial.println("Caution Zone");
  }

  // Safe distance
  else {

    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(whiteLED, HIGH);

    Serial.println("Safe Zone");
  }

  delay(200);
}
