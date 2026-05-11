// LED Connections
// Pin 8  -> Yellow LED
// Pin 9  -> White LED
// Pin 10 -> Red LED

void setup() {

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}

void loop() {

  // Yellow ON
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  delay(100);

  // White ON
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  delay(100);

  // Red ON
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(100);

}
