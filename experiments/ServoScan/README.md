# ServoScan

A simple Arduino-based radar scanning project using a Servo Motor and HC-SR04 Ultrasonic Sensor.

The servo sweeps from 0° to 180° and back while the HC-SR04 measures distance at each angle. The measured distance and current angle are printed to the Serial Monitor.

---

## Features

- Servo sweep scanning
- HC-SR04 distance measurement
- Serial Monitor output
- Left-to-right and right-to-left scanning
- Simple radar prototype foundation

---

## Hardware Used

- Arduino Uno R3
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- Breadboard
- Jumper Wires
- USB Cable

---

## Wiring

### HC-SR04

| HC-SR04 | Arduino |
|----------|----------|
| VCC | 5V |
| GND | GND |
| TRIG | D5 |
| ECHO | D4 |

### Servo

| Servo | Arduino |
|--------|----------|
| Signal | D9 |
| VCC | 5V |
| GND | GND |

---

## Project Structure

```text
ServoScan/
│
├── include/
├── lib/
├── src/
│   └── main.cpp
├── test/
├── platformio.ini
└── README.md
```

---

## How It Works

1. Servo rotates to a target angle.
2. HC-SR04 sends an ultrasonic pulse.
3. Echo return time is measured.
4. Distance is calculated.
5. Angle and distance are printed to Serial Monitor.
6. Servo continues scanning across the full range.

---

## Example Output

```text
Angle: 0   Distance: 45.20 cm
Angle: 45  Distance: 38.50 cm
Angle: 90  Distance: 27.10 cm
Angle: 135 Distance: 41.80 cm
Angle: 180 Distance: 52.30 cm
```

---

## Current Version

### V0.1.0

- Servo sweep implemented
- HC-SR04 integration completed
- Distance calculation implemented
- Serial output implemented

---

## Future Improvements

- Real radar visualization
- OLED display support
- Obstacle mapping
- Multiple sensor integration
- ESP32 version
- Integration with Aegis robot platform

---

## Author

Jyotish Kumar

Learning Robotics, Embedded Systems, and Autonomous Navigation.