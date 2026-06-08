const int ECHO = 9;
const int TRIG = 8;

void setup() {

  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {

  // clear trigger
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  //send 10us pulse
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // measure echo time
  long duration = pulseIn(ECHO, HIGH);

  //convert to distance (cm)
  float distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
