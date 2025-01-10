# Arduino Obstacle-Avoiding Car

A smart robot car that autonomously avoids obstacles using an ultrasonic sensor. When an obstacle is detected, the car stops, alerts with LED and buzzer, then turns to find a clear path.

## Features

- Autonomous obstacle detection and avoidance
- Visual feedback with LED indicator
- Audio feedback with buzzer
- Adjustable detection distance and motor speeds
- Real-time distance monitoring via Serial output

## Hardware Requirements

- Arduino UNO
- L293D Motor Driver IC
- HC-SR04 Ultrasonic Distance Sensor
- 2x DC Motors
- LED
- Buzzer
- 220Ω Resistor (for LED)
- Breadboard
- Jumper Wires
- External Power Source (5V Battery Preferably)
- Robot Car Chassis (with wheels)

## Pin Configuration

### Ultrasonic Sensor
- VCC → Arduino 5V
- GND → Arduino GND
- Signal → Arduino Digital Pin 7

### L293D H-Bridge
- Pin 1 (Enable 1) → Arduino 5V
- Pin 2 (Input 1) → Arduino Digital Pin 5
- Pin 7 (Input 2) → Arduino Digital Pin 6
- Pin 15 (Enable 2) → Arduino 5V
- Pin 10 (Input 3) → Arduino Digital Pin 9
- Pin 15 (Input 4) → Arduino Digital Pin 10
- Pins 4, 5, 12, 13 → GND
- Pin 16, 8 (VCC, VCC2) → Arduino 5V


### Motors
Left Motor:
- Positive → L293D Pin 3
- Negative → L293D Pin 6

Right Motor:
- Positive → L293D Pin 11
- Negative → L293D Pin 14

### Indicators
- Buzzer Positive → Arduino Digital Pin 3
- Buzzer Negative → GND
- LED Positive → Arduino Digital Pin 4 (with 220Ω resistor)
- LED Negative → GND

