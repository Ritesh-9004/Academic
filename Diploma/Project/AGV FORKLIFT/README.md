<p align="center">
  <h1 align="center"> Autonomous Guided Vehicle (AGV) Forklift</h1>
  <p align="center">Final Year Engineering Project • Smart Material Handling System</p>

  <!-- Badges -->
  <p align="center">
    <img src="https://img.shields.io/badge/status-complete-brightgreen?style=flat-square" alt="Status Badge">
    <img src="https://img.shields.io/badge/version-2.0-blue?style=flat-square" alt="Version Badge">
    <img src="https://img.shields.io/badge/platform-arduino-blue?style=flat-square" alt="Platform Badge">
    <img src="https://img.shields.io/badge/app-MIT%20App%20Inventor-orange?style=flat-square" alt="App Badge">

  </p>
</p>

---

# Overview
This project demonstrates the design and development of an Autonomous Guided Vehicle (AGV) Forklift, capable of path following, object detection, and automated loading/unloading of objects. The AGV was developed in multiple versions, progressively increasing in complexity and capabilities.

---
# Version 1: Track-Following AGV Forklift
## Features
- Path Following using IR Sensors.
- Obstacle/Object Detection using Ultrasonic Sensors.
- Motorized Forklift Mechanism:
- 2 × 12V 60RPM DC gear motors for rear-wheel drive.
- 1 × 12V 60RPM DC gear motor for the forklift mechanism (up/down).
- Motor Control using H-Bridge motor driver.

---
# Version 2: Bluetooth-Controlled AGV
## In the second version, the AGV was enhanced to support Bluetooth-based control via a custom Android application developed using MIT App Inventor.

## Additional Features
- Remote control of AGV movements and forklift operations via a smartphone.
- User-friendly UI for easy testing and operation.

---
# Version 3 
## The next iteration aims to make the AGV semi-autonomous with voice-controlled commands and RFID-based operations at multiple workstations.

<p style="font-size:20px;"><b>
  While I will not be continuing this project further, I believe Version 3 is a valuable next step and propose it for future development. This version aims to introduce voice-controlled commands, multi-station RFID validation, and smart unloading mechanisms—making the AGV more autonomous and scalable for real-world industrial applications.
</b></p>


## Planned Workstations:
- Station A
- Station B
- Station C

## Example Workflow (Voice-Controlled):
1. Voice Command Received: "Station A"

2. AGV Path:
- Moves 40cm forward ➝ 10cm right ➝ stops.

RFID Detection:

If RFID not found: Notify user – “RFID not found.”

- If RFID found:
    - Moves 2 steps backward.
    - Lowers fork.
    - Moves forward.
    - Lifts object.
    - Notifies user – “Object lifted. Please provide unload coordinate.”

4. Unload Command Received: "Unload A"

5. AGV Unloading Path:

- Moves right ➝ forward 5cm ➝ right again.

- Detects unloading area using Hall Sensors and Magnetic Field.

- Unloads the object.

