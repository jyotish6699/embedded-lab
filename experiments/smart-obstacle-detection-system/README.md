# Smart Obstacle Detection System using Arduino and IR Sensor

A simple Arduino-based smart obstacle detection system using an IR sensor and multiple LEDs.  
This project detects nearby objects and displays different alert states using LEDs.

---

# 📌 Project Overview

This system uses an IR obstacle sensor to detect nearby objects.  
Based on obstacle detection, LEDs indicate different safety levels:

- 🟢 Green LED → Safe (No obstacle)
- 🟡 Yellow LED → Warning (Obstacle detected)
- 🔴 Red LED → Danger Alert

This project is beginner-friendly and introduces:
- Sensor interfacing
- Digital input/output
- Embedded system logic
- Event-driven behavior

---

# 🛠 Components Required

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| IR Sensor Module | 1 |
| LEDs (Green, Yellow, Red) | 3 |
| 220Ω Resistors | 3 |
| Jumper Wires | As needed |
| Breadboard (Optional) | 1 |

---

# 🔌 Circuit Connections

## IR Sensor Connections

| IR Sensor Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| OUT | D2 |

---

## LED Connections

| LED | Arduino Pin |
|---|---|
| Green LED | D8 |
| Yellow LED | D9 |
| Red LED | D10 |

> Connect all LED negative legs to GND through resistors.

---

# ⚙️ Working Principle

1. IR sensor continuously checks for obstacles.
2. If no obstacle is detected:
   - Green LED turns ON.
3. If an obstacle is detected:
   - Yellow LED turns ON.
4. If obstacle remains detected continuously:
   - Red LED blinks as a danger alert.

---

# 💻 Arduino Code

```cpp
const int irPin = 2;

const int greenLED = 8;
const int yellowLED = 9;
const int redLED = 10;

unsigned long obstacleStartTime = 0;
bool obstacleDetected = false;

void setup() {

  pinMode(irPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  digitalWrite(greenLED, HIGH);
}

void loop() {

  int sensorValue = digitalRead(irPin);

  // IR sensor usually gives LOW when obstacle detected
  if (sensorValue == LOW) {

    if (!obstacleDetected) {
      obstacleDetected = true;
      obstacleStartTime = millis();
    }

    unsigned long elapsedTime = millis() - obstacleStartTime;

    // Warning State
    if (elapsedTime < 2000) {

      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);
    }

    // Danger State
    else {

      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);

      digitalWrite(redLED, HIGH);
      delay(200);

      digitalWrite(redLED, LOW);
      delay(200);
    }
  }

  // Safe State
  else {

    obstacleDetected = false;

    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }
}
```

---

# 🚀 How to Run

1. Connect all components properly.
2. Open Arduino IDE.
3. Paste the code.
4. Select:
   - Board → Arduino UNO
   - Correct COM Port
5. Upload the code.
6. Move an object near the IR sensor.

---

# 📷 Output States

| Condition | LED Status |
|---|---|
| No Obstacle | Green ON |
| Obstacle Detected | Yellow ON |
| Continuous Obstacle | Red Blinking |

---

# 📚 Concepts Learned

- Arduino digital input/output
- IR sensor working
- Sensor signal processing
- Basic automation
- Obstacle detection systems
- Embedded logic design

---

# 🔥 Future Improvements

You can upgrade this project by adding:

- Buzzer alert system
- Servo motor barrier
- LCD display
- Multiple IR sensors
- Ultrasonic sensor
- Robot car integration
- IoT monitoring

---

# 🧠 Applications

- Obstacle avoiding robots
- Smart parking systems
- Automatic doors
- Industrial safety systems
- Smart home automation
- Robot navigation systems

---

# 👨‍💻 Author

Made with Arduino and IR Sensor for learning embedded systems and robotics fundamentals.

---
