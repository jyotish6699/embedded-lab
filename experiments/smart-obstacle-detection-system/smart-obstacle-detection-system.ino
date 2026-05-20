const int irPin = 2;
const int greenPin = 8;
const int yellowPin = 9;
const int redPin = 10;

int obstacleStartTime = 0;
bool obstacleDetected = false;

void setup() {
  pinMode(irPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  digitalWrite(greenPin, HIGH);
}

void loop() {
  int irValue = digitalRead(irPin);  //Read sensor

  if(irValue == LOW) {   // Obstacle detected (active LOW)
    if(!obstacleDetected) {
      obstacleDetected = true;
      obstacleStartTime = millis();
    }

    unsigned long elapsed = millis() - obstacleStartTime;
    if(elapsed < 2000) {
      // Warning
      digitalWrite(greenPin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, HIGH);
    }else{
      // Danger - Red Blinking
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, HIGH);
      delay(200);
      digitalWrite(redPin, LOW);
      delay(200);
    }
  }
  else {
    //No Obstacle - Safe
    obstacleDetected = false;
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);
  }
}
